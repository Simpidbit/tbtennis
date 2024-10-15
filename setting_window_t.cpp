#include "setting_window_t.h"
#include "ui_setting_window_t.h"

setting_window_t::setting_window_t(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::setting_window_t)
{
    ui->setupUi(this);
}

setting_window_t::~setting_window_t()
{
    delete ui;
}
