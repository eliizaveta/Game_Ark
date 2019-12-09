#include "Game.h"

typedef void(Game::*StartLevelPointer)();

Game::Game(int lvl, QWidget* parent): QGraphicsView(parent), lvl(lvl)
{
  scene = new QGraphicsScene(0,0,644,700);
  setScene(scene);

  //don't need to press key
  setMouseTracking(true);
}

void Game::start()
{ 
  static const StartLevelPointer startLevel[] =
  {
    &Game::createLevel1,
    &Game::createLevel2,
    &Game::createLevel3
  };

  Ball* ball = new Ball(this);
  ball->setPos(300,600);
  scene->addItem(ball);

  Paddle* paddle = new Paddle();
  paddle->setPos(300,670);
  scene->addItem(paddle);
  paddle->grabMouse();

  colors.emplace(0,Qt::red);
  colors.emplace(1,Qt::darkRed);
  colors.emplace(2,Qt::yellow);
  colors.emplace(3,Qt::green);
  colors.emplace(4,Qt::blue);
  colors.emplace(5,Qt::magenta);

  (this->*startLevel[lvl - 1])();
}

void Game::createBlockColumn(int x, int y, int n)
{
  for (int i = y; i < n; ++i)
  {
    Block* block = new Block(colors[i]);
    blockVec.push_back(block);
    block->setPos(x,i*42);
    scene->addItem(block);
  }
}

void Game::createLevel1()
{
  for (int i = 0; i < 7; ++i)
  {
    createBlockColumn(i*92, 0, 6);
  }
}

void Game::createLevel2()
{
  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      Block* block = new Block(Qt::gray, false);
      block->setPos(i*92+184, j*42+126);
      scene->addItem(block);
    }
  }

  for (int i = 0; i < 7; ++i)
  {
    createBlockColumn(i*92, 0, 3);
  }

  for (int i = 0; i < 2; ++i)
  {
    createBlockColumn(i*92, 3, 6);
  }

  for (int i = 5; i < 7; ++i)
  {
    createBlockColumn(i*92, 3, 6);
  }
}

void Game::createLevel3()
{
  for (int i = 1; i < 6; i+=2)
  {
    createBlockColumn(i*92, 0, 6);
  }

  Block* block1 = new Block(Qt::gray, false);
  block1->setPos(92, 252);
  scene->addItem(block1);

  Block* block2 = new Block(Qt::gray, false);
  block2->setPos(276, 252);
  scene->addItem(block2);

  Block* block3 = new Block(Qt::gray, false);
  block3->setPos(460, 252);
  scene->addItem(block3);
}
