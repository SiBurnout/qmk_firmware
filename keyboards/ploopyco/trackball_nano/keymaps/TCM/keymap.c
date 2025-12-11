/* Copyright 2021 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2019 Hiroyuki Okada
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define INITIALIZATION_TIMEOUT 1000

#define DELTA_X_THRESHOLD 60
#define DELTA_Y_THRESHOLD 15

 //Set this to one of the led_t values that you want to monitor.
 //* It can be either num_lock, caps_lock or scroll_lock at the moment.

#define SCROLL_LED scroll_lock
#define RESET_LED num_lock


//state
static bool     initialized       = false;
static bool     scroll_enabled    = false;
static int8_t   delta_x           = 0;
static int8_t   delta_y           = 0;

static led_t initial_led_state;



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {{{ KC_NO }}};




report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (scroll_enabled) {
        delta_x += mouse_report.x;
        delta_y += mouse_report.y;

        if (delta_x > DELTA_X_THRESHOLD) {
            mouse_report.h = 1;
            delta_x        = 0;
        } else if (delta_x < -DELTA_X_THRESHOLD) {
            mouse_report.h = -1;
            delta_x        = 0;
        }

        if (delta_y > DELTA_Y_THRESHOLD) {
            mouse_report.v = -1;
            delta_y        = 0;
        } else if (delta_y < -DELTA_Y_THRESHOLD) {
            mouse_report.v = 1;
            delta_y        = 0;
        }
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}
// wait for led state sync

uint32_t initialization_timeout(uint32_t trigger_time, void *cb_arg) {
    initial_led_state = host_keyboard_led_state();
    initialized = true;
    return 0;
}

void keyboard_post_init_user(void) {
    defer_exec(INITIALIZATION_TIMEOUT, initialization_timeout, NULL);
}

bool led_update_user(led_t led_state) {
    if (!initialized)
        return true;

scroll_enabled = led_state.SCROLL_LED != initial_led_state.SCROLL_LED;
return true;

}


void suspend_power_down_user(void) {
    // Switch off sensor + LED making trackball unable to wake host
    adns5050_power_down();
}

void suspend_wakeup_init_user(void) {
    adns5050_init();
}
