#ifndef SETTING_WINDOW_T_H
#define SETTING_WINDOW_T_H

#include <QWidget>

namespace Ui {
class setting_window_t;
}

class setting_window_t : public QWidget
{
    Q_OBJECT

public:
    explicit setting_window_t(QWidget *parent = nullptr);
    ~setting_window_t();

private:
    Ui::setting_window_t *ui;
};

#endif // SETTING_WINDOW_T_H
