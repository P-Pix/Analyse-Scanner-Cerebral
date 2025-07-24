#include "Window/Scan.hpp"

Scan::Scan() :
    Gtk::Image()
{
    add_events(Gdk::EventMask::BUTTON_PRESS_MASK);
    signal_button_press_event().connect(sigc::mem_fun(*this, &Scan::on_button_press_event));
}

Scan::Scan(std::string path) :
    Gtk::Image(),
    path(path)
{
    set(path);
    add_events(Gdk::EventMask::BUTTON_PRESS_MASK);
    signal_button_press_event().connect(sigc::mem_fun(*this, &Scan::on_button_press_event));
}

Scan::Scan(const Scan& scan) :
    Gtk::Image(scan),
    path(scan.get_path())
{
    set(scan.get_path());
    add_events(Gdk::EventMask::BUTTON_PRESS_MASK);
    signal_button_press_event().connect(sigc::mem_fun(*this, &Scan::on_button_press_event));
}

Scan::~Scan() {
}

void Scan::next() {
    std::cout << "Next" << std::endl;
}

void Scan::previous() {
    std::cout << "Previous" << std::endl;
}

bool Scan::on_button_press_event(GdkEventButton* event) {
    if (event->button == 1 || event->button == 4) {
        next();
    } else if (event->button == 3 || event->button == 5) {
        previous();
    }
    return true;
}

void Scan::set(std::string path) {
    this->path = path;
    set(path);
}

Scan Scan::get() {
    return *this;
}

std::string Scan::get_path() {
    return this->path;
}

Scan Scan::operator=(const Scan& scan) {
    return Scan(scan.get());
}