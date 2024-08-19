#include <iostream>
#include <cstdlib>

#include "Window/Window.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;
    auto app = Gtk::Application::create("org.gtkmm.examples.base");
    Window window;
    return app->run(window);
}