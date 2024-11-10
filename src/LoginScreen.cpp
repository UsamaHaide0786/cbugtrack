#include "LoginScreen.h"  // Include the header file
#include "TrackerScreen.h"  // Include the header file
#include <FL/Fl_Input.H>

LoginScreen::LoginScreen(int x, int y, int w, int h, const char* title)
    : Fl_Window(x, y, w, h, title) {
    // Create username input field
    username_input = new Fl_Input(120, 50, 200, 30, "Username:");

    // Create password input field
    password_input = new Fl_Input(120, 100, 200, 30, "Password:");

    // Create login button
    login_button = new Fl_Button(150, 150, 100, 30, "Login");
    login_button->callback(onLoginClick, this);  // Set callback for login button

    end();  // Finalize the window setup
}

LoginScreen::~LoginScreen() {
    // Cleanup resources if needed
}

void LoginScreen::onLoginClick(Fl_Widget* widget, void* data) {
    LoginScreen* screen = (LoginScreen*)data;
    // Logic for login validation can go here
    // For now, we just show the tracker screen
    screen->hide();  // Hide the login screen
    TrackerScreen* tracker = new TrackerScreen(100, 100, 400, 300, "Tracker Screen");
    tracker->show();
}