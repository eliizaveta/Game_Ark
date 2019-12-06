#ifndef PADDLE_H
#define PADDLE_H

#include <QBrush>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Paddle: public QGraphicsRectItem
{
public:

  Paddle(QGraphicsItem* parent = nullptr);
  double getCenterX();
  void mouseMoveEvent(QGraphicsSceneMouseEvent* event);

};

#endif
