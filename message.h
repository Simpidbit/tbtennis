#ifndef MESSAGE_H
#define MESSAGE_H

#include "global.h"

// for message_t
enum message_type_e {
    MSG_OBJ_ADD
};

class message_t
{
public:
    message_t();
    ~message_t();

public:
    message_type_e msgtype;
    void * attach;
    uint64_t attach_size;
};

#endif // MESSAGE_H
