#include "macro.h"

#ifndef TEST

#include "main_window_t.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    main_window_t w;
    w.show();

    return a.exec();
}

#else

#include "physics.h"
#include <mutex>
#include <vector>
#include <thread>
#include <cstdlib>
#include <chrono>

extern void * logic_thread_request_msg;
extern std::mutex mtx;


int main(int, char **)
{
    std::vector<ball_t> * obj_container_ptr = new std::vector<ball_t>();

    char arr[10];
    arr[2] = 0b11111110;

    ::logic_thread_request_msg = &arr[1];
    byte_t *byte = static_cast<byte_t *>(::logic_thread_request_msg);
    byte_t *model = static_cast<byte_t *>((void *)&arr[2]);

    byte->b1 = model->b1;

    std::thread phy_th([=](std::vector<ball_t> ** obj_container_pptr) {
        physics_machine_t phy_machine(obj_container_pptr);
        phy_machine.main_loop();
    }, &obj_container_ptr);

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    byte->b1 = model->b2;

    phy_th.join();
    return 0;
}

#endif
