#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>

int main() {
    Fl_Window *window = new Fl_Window(400, 300, "FLTK Example");
    Fl_Button *button = new Fl_Button(150, 100, 100, 50, "Click Me");
    window->end();
    window->show();
    return Fl::run();
}