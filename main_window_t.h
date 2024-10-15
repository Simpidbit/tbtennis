#ifndef MAIN_WINDOW_T_H
#define MAIN_WINDOW_T_H

#include <QWidget>
#include "game_window_t.h"
#include "login_window_t.h"
#include "setting_window_t.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class main_window_t;
}
QT_END_NAMESPACE

class main_window_t : public QWidget
{
    Q_OBJECT

public:
    game_window_t * game_window;
    login_window_t * login_window;
    setting_window_t * setting_window;

    main_window_t(QWidget *parent = nullptr);
    ~main_window_t();

private slots:
    void on_game_btn_clicked();

    void on_exit_btn_clicked();

    void on_login_btn_clicked();

    void on_setting_btn_clicked();

private:
    Ui::main_window_t *ui;
};
#endif // MAIN_WINDOW_T_H
