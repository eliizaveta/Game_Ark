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

void Game::createBlockColumn(double x)
{
  for (int i = 0; i < 1; ++i)
  {
    Block* block = new Block(colors[i]);
    blockVec.push_back(block);
    block->setPos(x,i*42);
    scene->addItem(block);
  }
}

void Game::createLevel1()
{
  for (double i = 0; i < 1; ++i)
  {
    createBlockColumn(i*92);
  }
}

void Game::createLevel2()
{
  Block* block = new Block(Qt::gray, false);
  //blockVec.push_back(block);
  block->setPos(400,400);
  scene->addItem(block);

  for (double i = 0; i < 3; ++i)
  {
    createBlockColumn(i*92);
  }
}

void Game::createLevel3()
{
  Block* block = new Block();
  blockVec.push_back(block);
  block->setPos(500,400);
  scene->addItem(block);
}
