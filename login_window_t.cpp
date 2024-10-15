#include "login_window_t.h"
#include "ui_login_window_t.h"

login_window_t::login_window_t(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::login_window_t)
{
    ui->setupUi(this);
}

login_window_t::~login_window_t()
{
    delete ui;
}
