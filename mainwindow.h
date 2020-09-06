#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QMainWindow>
#include <sprite.h>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool eventFilter(QObject *object, QEvent* event) override;

    void handleInput();

    QGraphicsScene *scene;
    Sprite *sprite;
    int moveSpriteX = 0;
    QTimer *inputHandlerTimer;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
