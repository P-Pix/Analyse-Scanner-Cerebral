#pragma once

#include <iostream>
#include <cstdlib>
#include <gtkmm.h>
#include <memory>

class Scan : public Gtk::Image {
public:
    Scan(std::string path);
    virtual ~Scan();

protected:
    void next();
    void previous();

    bool on_button_press_event(GdkEventButton* event);

private:
    std::string path;
};