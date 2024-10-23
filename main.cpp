#include "global.h"

#ifndef TEST

#include "main_window_t.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    main_window_t window;
    window.show();

    return app.exec();
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
    std::vector<ball_t> * request_obj_container_ptr = new std::vector<ball_t>();

    char arr[10];
    arr[2] = 0b11111110;

    ::logic_thread_request_msg = &arr[1];
    byte_t *byte = static_cast<byte_t *>(::logic_thread_request_msg);
    byte_t *model = static_cast<byte_t *>((void *)&arr[2]);

    byte->b1 = model->b1;

    std::thread phy_th([=](std::vector<ball_t> ** request_obj_container_pptr) {
        physics_machine_t phy_machine(request_obj_container_pptr);
        phy_machine.main_loop();
    }, &request_obj_container_ptr);

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    request_obj_container_ptr->push_back(ball_t(1.9, CIRCLE, 9.9, vector_t(1.0, 2.0)));
    request_obj_container_ptr->push_back(ball_t(2.9, CIRCLE, 9.9, vector_t(1.0, 2.0)));
    request_obj_container_ptr->push_back(ball_t(3.7, CIRCLE, 9.9, vector_t(1.0, 2.0)));

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    {
        std::lock_guard<std::mutex> lk(::mtx);
        byte->b1 = model->b2;
        byte->b2 = model->b2;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    {
        std::lock_guard<std::mutex> lk(::mtx);
        byte->b1 = model->b2;
        byte->b2 = 0;
    }


    phy_th.join();
    return 0;
}

#endif
