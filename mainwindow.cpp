#include "mainwindow.h"
#include "ui_mainwindow.h"

Game* game;

MainWindow::MainWindow(QWidget* parent):
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::errMessage()
{
  QMessageBox::StandardButton reply = QMessageBox::question(this, QObject::tr("GAME OVER"),
                                                            tr("RESTART ?"),
                                                            QMessageBox::Yes | QMessageBox::No);
  if (reply == QMessageBox::No)
  {
    QApplication::quit();
  }
  else if (reply == QMessageBox::Yes)
  {
    on_pushButton_clicked();
  }
}

void MainWindow::winMessage()
{
  QMessageBox::StandardButton reply = QMessageBox::question(this, QObject::tr("YOU WON"),
                                                            tr("RESTART ?"),
                                                            QMessageBox::Yes | QMessageBox::No);
  if (reply == QMessageBox::No)
  {
    QApplication::quit();
  }
  else if (reply == QMessageBox::Yes)
  {
    on_pushButton_clicked();
  }
}

void MainWindow::newLevel(int lvl)
{
  if (lvl == game->numberOfLevels + 1)
  {
    winMessage();
    return;
  }

  delete game;
  game = new Game(lvl);
  game->show();
  game->start();
}

void MainWindow::on_pushButton_clicked()
{
  delete game;
  game = new Game(1);
  game->show();
  game->start();
}

void MainWindow::on_actionAbout_control_triggered()
{
  ui->statusbar->showMessage("Use the mouse to move the paddle");
}

void MainWindow::on_actionAbout_win_triggered()
{
  ui->statusbar->showMessage("To win you need to knock down all the blocks!");
}
