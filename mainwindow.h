#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>

#include "Game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:

  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

  void errMessage();
  void winMessage();
  void newLevel(int lvl);

public slots:

  void on_pushButton_clicked();

private slots:

  void on_actionAbout_control_triggered();

  void on_actionAbout_win_triggered();

private:

  Ui::MainWindow* ui;

};

#endif
