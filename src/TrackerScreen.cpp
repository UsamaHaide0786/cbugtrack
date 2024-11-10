#include "TrackerScreen.h" // Include the header file
#include <FL/fl_ask.H>
TrackerScreen::TrackerScreen(int x, int y, int w, int h, const char* title)
    : Fl_Window(x, y, w, h, title) {
    // Create start button
    start_button = new Fl_Button(50, 50, 100, 30, "Start");
    start_button->callback(onStartClick, this);  // Set callback for start button

    // Create stop button
    stop_button = new Fl_Button(200, 50, 100, 30, "Stop");
    stop_button->callback(onStopClick, this);  // Set callback for stop button

    end();  // Finalize the window setup
}

TrackerScreen::~TrackerScreen() {
    // Cleanup resources if needed
}

void TrackerScreen::onStartClick(Fl_Widget* widget, void* data) {
    // Logic to start time tracking
    // For example, you could start a timer here
    fl_message("Timer Started");
}

void TrackerScreen::onStopClick(Fl_Widget* widget, void* data) {
    // Logic to stop time tracking
    // For example, stop the timer here
    fl_message("Timer Stopped");
}