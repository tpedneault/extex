#ifndef APPLICATION_H
#define APPLICATION_H

#include "window.hpp"

#include <spdlog/spdlog.h>

class ExtexApplication {
public:
    ExtexApplication() = default;
    virtual ~ExtexApplication() = default;

    STATUS Start();
private:
    Window* m_Window;
};

#endif /* APPLICATION_H */
