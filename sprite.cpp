#include "sprite.h"

#include <QTimer>
#include <QPainter>
#include <QDebug>

Sprite::Sprite(QObject *parent)
    : QObject(parent), QGraphicsItem()
{
    currentFrame = 0;
    spriteImage = new QPixmap(":qpixmap_sprite.png");

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Sprite::nextFrame);
    timer->start(25);
}

QRectF Sprite::boundingRect() const {
    return QRectF(-10, -10, 20, 20);
}

void Sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(-10, -10, *spriteImage, currentFrame, 0, 20, 20);
}

void Sprite::nextFrame() {
    currentFrame += 20;
    if(currentFrame >= 300) currentFrame = 0;
    this->update(-10, -10, 20, 20);
}
