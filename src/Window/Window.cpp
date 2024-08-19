#include "Window/Window.hpp"

Window::Window() :
    box(Gtk::ORIENTATION_VERTICAL),

    menu_file("File"),
    menu_file_menu(),
    menu_file_new("New"),
    menu_file_open("Open"),
    menu_file_save("Save"),
    menu_file_save_as("Save As"),
    menu_file_quit("Quit"),

    menu_edit("Edit"),
    menu_edit_menu(),
    menu_edit_undo("Undo"),
    menu_edit_redo("Redo"),
    menu_edit_cut("Cut"),
    menu_edit_copy("Copy"),
    menu_edit_paste("Paste"),
    menu_edit_delete("Delete"),
    
    menu_help("Help"),
    menu_help_menu(),
    menu_help_about("About"),

    scan("scan/images.jpeg")
{
    set_title("Analyse Scanner Cerebral");
    set_default_size(800, 600);
    
    init_menu_file();
    init_menu_edit();
    init_menu_help();

    menu_bar.append(menu_file);
    menu_bar.append(menu_edit);
    menu_bar.append(menu_help);

    box.pack_start(menu_bar, Gtk::PACK_SHRINK);
    box.pack_start(scan, Gtk::PACK_EXPAND_WIDGET);
    add(box);
    show_all_children();
}

Window::~Window() {
}

void Window::on_button_clicked() {
    std::cout << "Hello, World!" << std::endl;
}

void Window::init_menu_file() {
    menu_file.set_submenu(menu_file_menu);

    menu_file_menu.append(menu_file_new);
    menu_file_new.signal_activate().connect(sigc::mem_fun(*this, &Window::on_menu_file_new));
    menu_file_new.add_accelerator("activate", get_accel_group(), GDK_KEY_n, Gdk::CONTROL_MASK, Gtk::ACCEL_VISIBLE);

    menu_file_menu.append(menu_file_open);
    menu_file_open.signal_activate().connect(sigc::mem_fun(*this, &Window::on_menu_file_open));
    menu_file_open.add_accelerator("activate", get_accel_group(), GDK_KEY_o, Gdk::CONTROL_MASK, Gtk::ACCEL_VISIBLE);

    menu_file_menu.append(menu_file_save);
    menu_file_save.signal_activate().connect(sigc::mem_fun(*this, &Window::on_menu_file_save));
    menu_file_save.add_accelerator("activate", get_accel_group(), GDK_KEY_s, Gdk::CONTROL_MASK, Gtk::ACCEL_VISIBLE);

    menu_file_menu.append(menu_file_save_as);
    menu_file_save_as.signal_activate().connect(sigc::mem_fun(*this, &Window::on_menu_file_save_as));
    menu_file_save_as.add_accelerator("activate", get_accel_group(), GDK_KEY_s, Gdk::CONTROL_MASK | Gdk::SHIFT_MASK, Gtk::ACCEL_VISIBLE);

    menu_file_menu.append(menu_file_quit);
    menu_file_quit.signal_activate().connect(sigc::mem_fun(*this, &Window::on_menu_file_quit));
    menu_file_quit.add_accelerator("activate", get_accel_group(), GDK_KEY_q, Gdk::CONTROL_MASK, Gtk::ACCEL_VISIBLE);
}

void Window::init_menu_edit() {
    menu_edit.set_submenu(menu_edit_menu);

    menu_edit_menu.append(menu_edit_undo);
    menu_edit_undo.signal_activate().connect(sigc::mem_fun(*this, &Window::on_menu_edit_undo));
    menu_edit_undo.add_accelerator("activate", get_accel_group(), GDK_KEY_z, Gdk::CONTROL_MASK, Gtk::ACCEL_VISIBLE);

    menu_edit_menu.append(menu_edit_redo);
    menu_edit_redo.signal_activate().connect(sigc::mem_fun(*this, &Window::on_menu_edit_redo));
    menu_edit_redo.add_accelerator("activate", get_accel_group(), GDK_KEY_z, Gdk::CONTROL_MASK | Gdk::SHIFT_MASK, Gtk::ACCEL_VISIBLE);

    menu_edit_menu.append(menu_edit_cut);
    menu_edit_cut.signal_activate().connect(sigc::mem_fun(*this, &Window::on_menu_edit_cut));
    menu_edit_cut.add_accelerator("activate", get_accel_group(), GDK_KEY_x, Gdk::CONTROL_MASK, Gtk::ACCEL_VISIBLE);

    menu_edit_menu.append(menu_edit_copy);
    menu_edit_copy.signal_activate().connect(sigc::mem_fun(*this, &Window::on_menu_edit_copy));
    menu_edit_copy.add_accelerator("activate", get_accel_group(), GDK_KEY_c, Gdk::CONTROL_MASK, Gtk::ACCEL_VISIBLE);

    menu_edit_menu.append(menu_edit_paste);
    menu_edit_paste.signal_activate().connect(sigc::mem_fun(*this, &Window::on_menu_edit_paste));
    menu_edit_paste.add_accelerator("activate", get_accel_group(), GDK_KEY_v, Gdk::CONTROL_MASK, Gtk::ACCEL_VISIBLE);

    menu_edit_menu.append(menu_edit_delete);
    menu_edit_delete.signal_activate().connect(sigc::mem_fun(*this, &Window::on_menu_edit_delete));
    menu_edit_delete.add_accelerator("activate", get_accel_group(), GDK_KEY_Delete, Gdk::ModifierType(0), Gtk::ACCEL_VISIBLE);
    menu_edit_delete.add_accelerator("activate", get_accel_group(), GDK_KEY_BackSpace, Gdk::ModifierType(0), Gtk::ACCEL_VISIBLE);
}

void Window::init_menu_help() {
    menu_help.set_submenu(menu_help_menu);

    menu_help_menu.append(menu_help_about);
    menu_help_about.signal_activate().connect(sigc::mem_fun(*this, &Window::on_menu_help_about));
    menu_help_about.add_accelerator("activate", get_accel_group(), GDK_KEY_F1, Gdk::ModifierType(0), Gtk::ACCEL_VISIBLE);
}

void Window::on_menu_file_new() {
    std::cout << "File -> New" << std::endl;
}

void Window::on_menu_file_open() {
    std::cout << "File -> Open" << std::endl;
}

void Window::on_menu_file_save() {
    std::cout << "File -> Save" << std::endl;
}

void Window::on_menu_file_save_as() {
    std::cout << "File -> Save As" << std::endl;
}

void Window::on_menu_file_quit() {
    std::cout << "File -> Quit" << std::endl;
}

void Window::on_menu_edit_undo() {
    std::cout << "Edit -> Undo" << std::endl;
}

void Window::on_menu_edit_redo() {
    std::cout << "Edit -> Redo" << std::endl;
}

void Window::on_menu_edit_cut() {
    std::cout << "Edit -> Cut" << std::endl;
}

void Window::on_menu_edit_copy() {
    std::cout << "Edit -> Copy" << std::endl;
}

void Window::on_menu_edit_paste() {
    std::cout << "Edit -> Paste" << std::endl;
}

void Window::on_menu_edit_delete() {
    std::cout << "Edit -> Delete" << std::endl;
}

void Window::on_menu_help_about() {
    std::cout << "Help -> About" << std::endl;
}