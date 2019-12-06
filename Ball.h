#ifndef BALL_H
#define BALL_H

#include <QTimer>
#include <QBrush>
#include <QPainter>
#include <QMessageBox>
#include <QApplication>
#include <QGraphicsEllipseItem>

#include "Block.h"
#include "Game.h"
#include "Paddle.h"
#include "mainwindow.h"

class Ball: public QObject, public QGraphicsEllipseItem
{
  Q_OBJECT

public:

  Ball(QObject* parent = nullptr);
  double getCenterX();

public slots:

  void move();

private:

  double vX;
  double vY;

  void outBorders();
  void paddleCollision();
  void blockCollision();

  bool gameOver;

};

#endif
