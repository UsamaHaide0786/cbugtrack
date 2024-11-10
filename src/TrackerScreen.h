#ifndef TRACKERSCREEN_H
#define TRACKERSCREEN_H

#include <FL/Fl_Window.H>   // FLTK base window class
#include <FL/Fl_Button.H>   // FLTK Button class
#include <FL/Fl_Timer.H>    // FLTK Timer class

class TrackerScreen : public Fl_Window {
public:
    TrackerScreen(int x, int y, int w, int h, const char* title);
    ~TrackerScreen();

    // UI elements for time tracking
    Fl_Button *start_button;
    Fl_Button *stop_button;

    static void onStartClick(Fl_Widget* widget, void* data); // Start Timer callback
    static void onStopClick(Fl_Widget* widget, void* data);  // Stop Timer callback
};

#endif // TRACKERSCREEN_H