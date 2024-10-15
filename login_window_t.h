#ifndef LOGIN_WINDOW_T_H
#define LOGIN_WINDOW_T_H

#include <QWidget>

namespace Ui {
class login_window_t;
}

class login_window_t : public QWidget
{
    Q_OBJECT

public:
    explicit login_window_t(QWidget *parent = nullptr);
    ~login_window_t();

private:
    Ui::login_window_t *ui;
};

#endif // LOGIN_WINDOW_T_H
