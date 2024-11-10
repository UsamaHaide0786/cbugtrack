#include <FL/Fl.H>              // FLTK base for running the application
#include <FL/Fl_Window.H>        // FLTK base for creating windows
#include "LoginScreen.h"         // Import LoginScreen header
#include "TrackerScreen.h"       // Import TrackerScreen header

int main() {
    // Instantiate the LoginScreen first
    LoginScreen loginScreen(100, 100, 400, 200, "Login Screen");

    // Show the login screen
    loginScreen.show();

    // Start the FLTK event loop
    return Fl::run();
}