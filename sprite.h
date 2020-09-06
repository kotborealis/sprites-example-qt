#ifndef SPRITE_H
#define SPRITE_H

#include <QObject>
#include <QGraphicsItem>

class Sprite : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Sprite(QObject *parent = nullptr);

private slots:
    void nextFrame();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

    QTimer *timer;
    QPixmap *spriteImage;
    int currentFrame;
};

#endif // SPRITE_H
