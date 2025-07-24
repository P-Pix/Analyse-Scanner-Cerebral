#include "Window/DrawingOnScan.hpp"

DrawingOnScan::DrawingOnScan() {
    x = 0;
    y = 0;
}

DrawingOnScan::DrawingOnScan(std::string path) {
    x = 0;
    y = 0;
    scan = Scan(path);
}

DrawingOnScan::~DrawingOnScan() {
}

void DrawingOnScan::set_Scan(std::string path) {
    this->scan.set(path);
}

Scan DrawingOnScan::get_Drawing(void) {
    return this->scan.get();
}

bool DrawingOnScan::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    cr->set_source_rgb(0.0, 0.0, 0.0);
    cr->set_line_width(1.0);
    /*
    for (auto &point : scan.get_Points()) {
        draw_point(cr, point.get_X(), point.get_Y());
    }
    */
    return true;
}

void DrawingOnScan::draw_point(const Cairo::RefPtr<Cairo::Context>& cr, double x, double y) {
    cr->move_to(x, y);
    cr->line_to(x + 1, y + 1);
    cr->stroke();
}