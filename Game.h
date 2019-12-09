#ifndef GAME_H
#define GAME_H

#include <map>
#include <vector>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "Ball.h"
#include "Block.h"
#include "Paddle.h"

class Game: public QGraphicsView
{
public:

  Game(int lvl, QWidget* parent = nullptr);

  void start();

  void createLevel1();
  void createLevel2();
  void createLevel3();

  const static int numberOfLevels = 3;

  void createBlockColumn(int x, int y, int n);

  QGraphicsScene* scene;

  std::vector<QGraphicsItem*> blockVec;

  std::map<int, Qt::GlobalColor> colors;

  int lvl;

};

#endif
