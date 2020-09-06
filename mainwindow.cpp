#include "mainwindow.h"
#include "sprite.h"
#include "ui_mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 800, 600);
    ui->graphicsView->setScene(scene);

    sprite = new Sprite();
    scene->addItem(sprite);

    scene->addItem(new Sprite);

    sprite->setPos(400, 400);
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_D)
        sprite->setPos(sprite->scenePos() + QPointF(20, 0));
    else if(event->key() == Qt::Key_A)
        sprite->setPos(sprite->scenePos() + QPointF(-20, 0));
}

MainWindow::~MainWindow()
{
    delete ui;
}

