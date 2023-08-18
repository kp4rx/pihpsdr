/* Copyright (C)
* 2017 - John Melton, G0ORX/N6LYT
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <https://www.gnu.org/licenses/>.
*
*/

#include <gtk/gtk.h>
#include "css.h"
#include "message.h"

//
// Normally one wants to inherit everything from the GTK theme.
// In some cases, however, this does not work too well. But the
// principle here is to change as little as possible.
//
// Here is a list of CSS definitions we make here:
//
// boldlabel           This is used to write texts in menus and the slider area,
//                     therefore it contains 3px border
//
// big_tet             This is a large bold text. Used for the "pi label" on the
//                     discovery screen, and the "Start" button there
//
// med_txt             This is a large text. Used for the status bar, etc.
//
// small_txt           This is a small text, used where space is scarce.
//
// close_button        Style for the "Close" button in the menus, so it can be
//                     easily recognized
//
// small_button        15px text with minimal paddding. Used in menus where one wants
//                     to make the buttons narrow.
//
// small_toggle_button Used for the buttons in action dialogs, and the filter etc.
//                     menus where the current choice needs proper high-lighting
//
// popup_scale         Used to define the slider that "pops up" when e.g. AF volume
//                     is changed via GPIO/MIDI but no sliders are on display
//
// checkbutton         Very difficult to see on RaspPi with a light GTK theme. So we
//                     draw a grey border which should be OK for both the light and
//                     dark theme.
//
// radiobutton         see checkbutton.
//
char *css =
  "  #boldlabel {\n"
  "    padding: 3px;\n"
  "    font-family: Sans;\n"
  "    font-weight: bold;\n"
#ifdef __APPLE__
  "    font-size: 14px;\n"
#endif
  "  }\n"
  "  #big_txt {\n"
  "    font-family: Sans;\n"
  "    font-size: 22px;\n"
  "    font-weight: bold;\n"
  "    }\n"
  "  #med_txt {\n"
  "    font-family: Sans;\n"
  "    font-size: 18px;\n"
  "    }\n"
  "  #small_txt {\n"
  "    font-family: Sans;\n"
  "    font-weight: bold;\n"
  "    font-size: 12px;\n"
  "    }\n"
  "  #close_button {\n"
  "    padding: 5px;\n"
  "    font-family: Sans;\n"
  "    font-size: 15px;\n"
  "    font-weight: bold;\n"
  "    border: 1px solid rgb(50%, 50%, 50%);\n"
  "    }\n"
  "  #small_button {\n"
  "    padding: 1px;\n"
  "    font-family: Sans;\n"
  "    font-size: 15px;\n"
  "    }\n"
  "  #small_toggle_button {\n"
  "    padding: 1px;\n"               
  "    font-family: Sans;\n"
  "    font-size: 15px;\n"
  "    background-image: none;\n"
  "    }\n"
  "  #small_toggle_button:checked {\n"
  "    padding: 1px;\n"
  "    font-family: Sans;\n"
  "    font-size: 15px;\n"
  "    background-image: none;\n"
  "    background-color: rgb(100%, 20%, 20%);\n"    // background if selected
  "    color: rgb( 60%,100%,100%);\n"               // text if selected
  "    }\n"
  "  #popup_scale slider {\n"
  "    background: rgb(  0%,  0%, 100%);\n"         // Slider handle
  "    }\n"
  "  #popup_scale trough {\n"
  "    background: rgb( 50%,50%, 100%);\n"         // Slider bar
  "    }\n"
  "  #popup_scale value {\n"
  "    color: rgb(100%, 10%, 10%);\n"              // digits
  "    }\n"
  "  checkbutton check {\n"
  //"    background-image: none;\n"
  //"    background-color: rgb(75%, 75%, 75%);\n"    // good for light and dark theme
  //"    color: rgb(00%, 00%, 100%);\n"
  "    border: 1px solid rgb(50%, 50%, 50%);\n"
  "    }\n"
  "  radiobutton radio {\n"
  //"    background-image: none;\n"
  //"    background-color: rgb(75%, 75%, 75%);\n"    // good for light and dark theme
  //"    color: rgb(00%, 00%, 100%);\n"
  "    border: 1px solid rgb(50%, 50%, 50%);\n"
  "    }\n"
  ;

void load_css() {
  GtkCssProvider *provider;
  GdkDisplay *display;
  GdkScreen *screen;
  t_print("%s\n", __FUNCTION__);
  provider = gtk_css_provider_new ();
  display = gdk_display_get_default ();
  screen = gdk_display_get_default_screen (display);
  gtk_style_context_add_provider_for_screen (screen,
      GTK_STYLE_PROVIDER(provider),
      GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
  gtk_css_provider_load_from_data(provider, css, -1, NULL);
  g_object_unref (provider);
}
