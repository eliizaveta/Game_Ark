#include "Paddle.h"

Paddle::Paddle(QGraphicsItem*)
{
  setRect(0,0,100,16);
  QBrush brush;
  brush.setColor(Qt::red);
  brush.setStyle(Qt::SolidPattern);
  setBrush(brush);
}

double Paddle::getCenterX()
{
  return x()+rect().width()/2;
}

void Paddle::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
  double mouseX = mapToScene(event->pos()).x();
  setPos(mouseX,y());
}
