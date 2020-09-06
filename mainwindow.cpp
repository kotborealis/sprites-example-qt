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
    this->installEventFilter(this);

    inputHandlerTimer = new QTimer();
    inputHandlerTimer->start(25);

    connect(inputHandlerTimer, &QTimer::timeout, this, &MainWindow::handleInput);

    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 800, 600);
    ui->graphicsView->setScene(scene);

    sprite = new Sprite();
    scene->addItem(sprite);
    scene->addItem(new Sprite);
    sprite->setPos(400, 400);
}

bool MainWindow::eventFilter(QObject *object, QEvent* event) {
    if(event->type() == QEvent::KeyPress) {
        auto keyEvent = static_cast<QKeyEvent *>(event);
        if(keyEvent->key() == Qt::Key_D)
            moveSpriteX = 1;
        else if(keyEvent->key() == Qt::Key_A)
            moveSpriteX = -1;
    }
    if(event->type() == QEvent::KeyRelease) {
        auto keyEvent = static_cast<QKeyEvent *>(event);
        if(keyEvent->key() == Qt::Key_D)
            moveSpriteX = 0;
        else if(keyEvent->key() == Qt::Key_A)
            moveSpriteX = 0;
    }
}

void MainWindow::handleInput() {
    sprite->setPos(sprite->scenePos() + QPointF(20 * moveSpriteX, 0));
}

MainWindow::~MainWindow()
{
    delete ui;
}

