#ifndef GAME_WINDOW_T_H
#define GAME_WINDOW_T_H

#include <QWidget>
#include <QTimer>
#include <QPainter>

namespace Ui {
class game_window_t;
}

class game_window_t : public QWidget
{
    Q_OBJECT

public:
    explicit game_window_t(QWidget *parent = nullptr);
    ~game_window_t();

private:
    Ui::game_window_t *ui;
    void paintEvent(QPaintEvent * event);
    void timerHandler();

    QTimer timer;

};

#endif // GAME_WINDOW_T_H
