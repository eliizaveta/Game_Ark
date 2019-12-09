#include "Ball.h"

extern Game* game;
MainWindow* w;

Ball::Ball(QObject* parent): QObject(parent), QGraphicsEllipseItem()
{
  setRect(0,0,35,35);
  QBrush brush;
  brush.setColor(Qt::gray);
  brush.setStyle(Qt::SolidPattern);
  setBrush(brush);

  vX = 0;
  vY = -5;

  gameOver = false;

  QTimer* timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(move()));
  timer->start(15);
}

double Ball::getCenterX()
{
  return x() + rect().width()/2;
}

void Ball::move()
{
  moveBy(vX,vY);
  paddleCollision();
  outBorders();
  if (!gameOver)
  {
    blockCollision();
  }
}

void Ball::outBorders()
{
  double sceneW = game->width();
  double sceneH = game->height();

  // left
  if (mapToScene(rect().topLeft()).x() <= 0)
  {
    vX = -1 * vX;
  }

  // right
  if (mapToScene(rect().topRight()).x() >= sceneW)
  {
    vX = -1 * vX;
  }

  // top
  if (mapToScene(rect().topLeft()).y() <= 0)
  {
    vY = -1 * vY;
  }

  // bottom - game over
  if (mapToScene(rect().topRight()).y() >= sceneH)
  {
    gameOver = true;
    w->errMessage();
  }
}

void Ball::paddleCollision()
{
  QList<QGraphicsItem*> colItems = collidingItems();
  for (int i = 0, n = colItems.size(); i < n; ++i)
  {
    Paddle* paddle = dynamic_cast<Paddle*>(colItems[i]);
    if (paddle)
    {
      vY = -1 * vY;

      double ballX = getCenterX();
      double paddleX = paddle->getCenterX();
      double difference = ballX - paddleX;
      vX = (vX + difference)/15;

      return;
    }
  }
}

void Ball::blockCollision()
{
  QList<QGraphicsItem*> colItems = collidingItems();
  for (int i = 0, n = colItems.size(); i < n; ++i)
  {
    Block* block = dynamic_cast<Block*>(colItems[i]);
    if (block)
    {
      double distanse = 15;
      double ballX = pos().x();
      double ballY = pos().y();
      double blockX = block->pos().x();
      double blockY = block->pos().y();

      //from bottom
      if (ballY > (blockY + distanse) && vY < 0)
      {
        vY = -1 * vY;
      }

      //from top
      if (blockY > (ballY + distanse) && vY > 0 )
      {
        vY = -1 * vY;
      }

      //from right
      if (ballX > (blockX + distanse) && vX < 0)
      {
        vX = -1 * vX;
      }

      //from left
      if (blockX > (ballX + distanse) && vX > 0)
      {
        vX = -1 * vX;
      }

      if (block->dist)
      {
        game->scene->removeItem(block);
        delete block;
        game->blockVec.pop_back();
      }

      if (game->blockVec.empty())
      {
        w->newLevel(game->lvl + 1);
      }
    }
  }
}
