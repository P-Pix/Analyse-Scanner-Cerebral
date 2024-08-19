#pragma once

#include <iostream>
#include <cstdlib>
#include <gtkmm.h>
#include <memory>

#include "Window/Scan.hpp"

class Window : public Gtk::Window {
public:
    Window();
    virtual ~Window();
protected:
    void on_button_clicked();

private:

#pragma region Menu
    Gtk::Menu menu;
    Gtk::MenuBar menu_bar;

    #pragma region Menu_File
        Gtk::MenuItem menu_file;
        Gtk::Menu menu_file_menu;
        void init_menu_file();
        Gtk::MenuItem menu_file_new;
        void on_menu_file_new();
        Gtk::MenuItem menu_file_open;
        void on_menu_file_open();
        Gtk::MenuItem menu_file_save;
        void on_menu_file_save();
        Gtk::MenuItem menu_file_save_as;
        void on_menu_file_save_as();
        Gtk::MenuItem menu_file_quit;
        void on_menu_file_quit();
    #pragma endregion

    #pragma region Menu_Edit
        Gtk::MenuItem menu_edit;
        Gtk::Menu menu_edit_menu;
        void init_menu_edit();
        Gtk::MenuItem menu_edit_undo;
        void on_menu_edit_undo();
        Gtk::MenuItem menu_edit_redo;
        void on_menu_edit_redo();
        Gtk::MenuItem menu_edit_cut;
        void on_menu_edit_cut();
        Gtk::MenuItem menu_edit_copy;
        void on_menu_edit_copy();
        Gtk::MenuItem menu_edit_paste;
        void on_menu_edit_paste();
        Gtk::MenuItem menu_edit_delete;
        void on_menu_edit_delete();
    #pragma endregion

    #pragma region Menu_Help
        Gtk::MenuItem menu_help;
        Gtk::Menu menu_help_menu;
        void init_menu_help();
        Gtk::MenuItem menu_help_about;
        void on_menu_help_about();
    #pragma endregion

#pragma endregion

    Scan scan;
    Gtk::Box box;
};