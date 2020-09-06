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
            moveSpritePositiveX = true;
        else if(keyEvent->key() == Qt::Key_A)
            moveSpriteNegativeX = true;
    }
    if(event->type() == QEvent::KeyRelease) {
        auto keyEvent = static_cast<QKeyEvent *>(event);
        if(keyEvent->key() == Qt::Key_D)
            moveSpritePositiveX = false;
        else if(keyEvent->key() == Qt::Key_A)
            moveSpriteNegativeX = false;
    }
}

void MainWindow::handleInput() {
    auto direction = moveSpriteNegativeX * -1 + moveSpritePositiveX * 1;
    sprite->setPos(sprite->scenePos() + QPointF(20 * direction, 0));
}

MainWindow::~MainWindow()
{
    delete ui;
}

