#ifndef BLOCK_H
#define BLOCK_H

#include <QBrush>
#include <QGraphicsRectItem>

class Block: public QGraphicsRectItem
{
public:

  Block(Qt::GlobalColor color = Qt::black, bool dist = true,  QGraphicsItem* parent = nullptr);

  bool dist;

};

#endif
