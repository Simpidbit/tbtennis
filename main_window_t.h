#ifndef MAIN_WINDOW_T_H
#define MAIN_WINDOW_T_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class main_window_t;
}
QT_END_NAMESPACE

class main_window_t : public QWidget
{
    Q_OBJECT

public:
    main_window_t(QWidget *parent = nullptr);
    ~main_window_t();

private:
    Ui::main_window_t *ui;
};
#endif // MAIN_WINDOW_T_H
