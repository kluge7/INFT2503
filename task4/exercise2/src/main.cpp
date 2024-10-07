#include <gtkmm.h>

class Window : public Gtk::Window {
public:
  Gtk::Box box;
  Gtk::Entry entry;
  Gtk::Button button;
  Gtk::Label label;
  Gtk::Label first_name;
  Gtk::Label last_name;
  Gtk::Entry entry2;

  Window() : box(Gtk::Orientation::ORIENTATION_VERTICAL) {
    set_title("Øving 4");
    button.set_label("Combine names");
    first_name.set_label("First name");
    last_name.set_label("Last name");

    box.pack_start(first_name);
    box.pack_start(entry);
    box.pack_start(last_name);
    box.pack_start(entry2);
    box.pack_start(button);
    box.pack_start(label);

    add(box);
    show_all();

    button.set_sensitive(false);

    entry.signal_changed().connect([this]() {
      if (!entry.get_text().empty() && !entry2.get_text().empty()) {
        button.set_sensitive(true);
      } else {
        button.set_sensitive(false);
      }
    });

    entry2.signal_changed().connect([this]() {
      if (!entry.get_text().empty() && !entry2.get_text().empty()) {
        button.set_sensitive(true);
      } else {
        button.set_sensitive(false);
      }
    });

    button.signal_clicked().connect([this]() {
      label.set_text(entry.get_text() + " " + entry2.get_text());
    });
  }
};

int main() {
  auto app = Gtk::Application::create();
  Window window;
  return app->run(window);
}
