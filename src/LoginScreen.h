#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <FL/Fl_Window.H>   // FLTK base window class
#include <FL/Fl_Button.H>   // FLTK Button class
#include <FL/Fl_Input.H>    // FLTK Input class

class LoginScreen : public Fl_Window {
public:
    LoginScreen(int x, int y, int w, int h, const char* title);
    ~LoginScreen();

    // UI elements
    Fl_Input *username_input;
    Fl_Input *password_input;
    Fl_Button *login_button;

    static void onLoginClick(Fl_Widget* widget, void* data); // Callback for login button click
};

#endif // LOGINSCREEN_H