#include "Block.h"

Block::Block(Qt::GlobalColor color, bool dist,  QGraphicsItem* parent):
  QGraphicsRectItem(parent), dist(dist)
{
  setRect(0,0,90,40);
  QBrush brush;
  brush.setColor(color);
  brush.setStyle(Qt::SolidPattern);
  setBrush(brush);
}
