#include "main_window_t.h"
#include "./ui_main_window_t.h"
#include <QDebug>

main_window_t::main_window_t(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::main_window_t)
{
    ui->setupUi(this);

    this->login_window = new login_window_t(nullptr);
    this->login_window->setWindowModality(Qt::ApplicationModal);

    this->game_window = new game_window_t(nullptr);
    this->game_window->setWindowModality(Qt::ApplicationModal);

    this->setting_window = new setting_window_t(nullptr);
    this->setting_window->setWindowModality(Qt::ApplicationModal);
}

main_window_t::~main_window_t()
{
    delete ui;
}

void main_window_t::on_game_btn_clicked()
{
    qDebug() << "Clicked";
    this->game_window->show();
}


void main_window_t::on_login_btn_clicked()
{
    this->login_window->show();
}


void main_window_t::on_exit_btn_clicked()
{
    this->close();
}


void main_window_t::on_setting_btn_clicked()
{
    this->setting_window->show();
}

