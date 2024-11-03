#include "game_window_t.h"
#include "ui_game_window_t.h"


game_window_t::game_window_t(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::game_window_t)
{
    ui->setupUi(this);

    // 设置帧率即刷新频率
    this->timer.setInterval(1000/60);

    // 连接timer信号和槽
    connect(&this->timer, &QTimer::timeout, this, &game_window_t::timerHandler);

    // 启动timer
    this->timer.start();
}

game_window_t::~game_window_t()
{
    delete ui;
}

void game_window_t::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
}

void game_window_t::timerHandler()
{
    // 重绘, 刷新
    this->repaint();
}
