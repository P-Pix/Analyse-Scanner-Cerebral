#pragma once

#include "Scan.hpp"
#include <gtkmm/drawingarea.h>

/**
 * @brief La classe DrawingOnScan permet de dessiner sur un scan puis de télécharger le scan modifié
 */
class DrawingOnScan : public Gtk::DrawingArea {
public:
    DrawingOnScan();
    DrawingOnScan(std::string path);

    virtual ~DrawingOnScan();

    void set_Scan(std::string path);

    Scan get_Drawing(void);

    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
protected:

private:
    Scan scan;
    double x, y;
    void draw_point(const Cairo::RefPtr<Cairo::Context>& cr, double x, double y);
};