#pragma once

#include <iostream>
#include <cstdlib>
#include <gtkmm.h>
#include <memory>

class Scan : public Gtk::Image {
public:
    Scan();
    Scan(std::string path);
    Scan(const Scan& scan);
    virtual ~Scan();

    Scan operator=(const Scan& scan);
    
    Scan get();
    void set(std::string path);
    std::string get_path();

protected:
    void next();
    void previous();

    bool on_button_press_event(GdkEventButton* event);

private:
    std::string path;
};