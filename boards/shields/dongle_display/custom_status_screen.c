/*
 * Copyright (c) 2024 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include "custom_status_screen.h"
#include "widgets/battery_status.h"
#include "widgets/layer_status.h"
#include <zmk/display/widgets/output_status.h>

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

static lv_style_t global_style;
static lv_style_t output_status_style;

static struct zmk_widget_output_status output_status_widget;
static struct zmk_widget_layer_status layer_status_widget;
static struct zmk_widget_dongle_battery_status dongle_battery_status_widget;

lv_obj_t *zmk_display_status_screen() {
    lv_obj_t *screen;
    screen = lv_obj_create(NULL);

    // Global style for the screen
    lv_style_init(&global_style);
    lv_style_set_text_font(&global_style, &lv_font_montserrat_20);
    lv_style_set_text_letter_space(&global_style, 1);
    lv_style_set_text_line_space(&global_style, 1);
    lv_obj_add_style(screen, &global_style, LV_PART_MAIN);

    // Create a specific style for the output status widget
    lv_style_init(&output_status_style);
    lv_style_set_text_font(&output_status_style,
                           &lv_font_montserrat_16); // Different font size

    // Output status widget
    zmk_widget_output_status_init(&output_status_widget, screen);
    lv_obj_t *output_status_obj =
        zmk_widget_output_status_obj(&output_status_widget);
    lv_obj_add_style(output_status_obj, &output_status_style, LV_PART_MAIN);
    lv_obj_align(output_status_obj, LV_ALIGN_TOP_LEFT, 0, 0);

    // Layer status widget
    zmk_widget_layer_status_init(&layer_status_widget, screen);
    lv_obj_align(zmk_widget_layer_status_obj(&layer_status_widget),
                 LV_ALIGN_BOTTOM_LEFT, 0, 0);

    // Battery status widget
    zmk_widget_dongle_battery_status_init(&dongle_battery_status_widget,
                                          screen);
    lv_obj_align(
        zmk_widget_dongle_battery_status_obj(&dongle_battery_status_widget),
        LV_ALIGN_TOP_RIGHT, 0, 0);

    return screen;
}
