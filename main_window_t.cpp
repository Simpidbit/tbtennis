#include "main_window_t.h"
#include "./ui_main_window_t.h"

main_window_t::main_window_t(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::main_window_t)
{
    ui->setupUi(this);
}

main_window_t::~main_window_t()
{
    delete ui;
}
