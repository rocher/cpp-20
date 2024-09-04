#include <comp.h>

lib::comp::Component::Component(std::string p_name) : name(p_name) {}

void lib::comp::Component::start()
{
    running = true;
}

void lib::comp::Component::stop()
{
    running = false;
}

const std::string lib::comp::Component::get_name() const
{
    return name;
}

void lib::comp::Component::send_message(message_t msg)
{
    message_queue.append(msg);
}

void lib::comp::Component::read_message(message_t msg)
{
    while (running) {}
}
