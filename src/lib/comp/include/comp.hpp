
#include <queue>
#include <string>
#include <tuple>

namespace lib
{
    namespace comp
    {
        class Component
        {
            public:
                typedef std::tuple<int, int> message_t;

                Component(std::string name);
                virtual ~Component() = 0;

                void start();
                void stop();

                const std::string get_name() const;
                void send_message(message_t) const;

            protected:
                message_t read_message();
                virtual void process_message(message_t) = 0;

            private:
                mutable std::queue<message_t> message_queue;
                std::string name;
                bool running = false;

                Component();
        };
    }
}