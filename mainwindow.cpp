#include "mainwindow.h"
#include "sprite.h"
#include "ui_mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    sprite = new Sprite();
    scene->addItem(sprite);
}

MainWindow::~MainWindow()
{
    delete ui;
}

