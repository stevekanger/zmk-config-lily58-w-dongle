#include <lvgl.h>
#include <zmk/display/status_screen.h>
#include <zmk/display/widgets/battery_status.h>
#include <zmk/display/widgets/layer_status.h>
#include <zmk/display/widgets/output_status.h>

static lv_obj_t *screen;
static struct battery_status_widget battery_left;
static struct battery_status_widget battery_right;
static struct output_status_widget output_widget;
static struct layer_status_widget layer_widget;

lv_obj_t *zmk_display_status_screen(void) {
  screen = lv_obj_create(NULL);
  lv_obj_remove_style_all(screen);

  zmk_battery_status_init(&battery_left, true);   // true = left half
  zmk_battery_status_init(&battery_right, false); // false = right half
  zmk_output_status_init(&output_widget);
  zmk_layer_status_init(&layer_widget);

  lv_obj_align(battery_left.widget, LV_ALIGN_TOP_LEFT, 0, 0);
  lv_obj_align(battery_right.widget, LV_ALIGN_TOP_RIGHT, 0, 0);
  lv_obj_align(output_widget.widget, LV_ALIGN_BOTTOM_LEFT, 0, 0);
  lv_obj_align(layer_widget.widget, LV_ALIGN_BOTTOM_RIGHT, 0, 0);

  return screen;
}
