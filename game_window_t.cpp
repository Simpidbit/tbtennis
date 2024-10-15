#include "game_window_t.h"
#include "ui_game_window_t.h"

game_window_t::game_window_t(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::game_window_t)
{
    ui->setupUi(this);
}

game_window_t::~game_window_t()
{
    delete ui;
}
