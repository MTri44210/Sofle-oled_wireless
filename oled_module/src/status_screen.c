/* Custom static OLED screen for Sofle Wireless / ZMK v0.3 / LVGL 8.
 * Target screen: 128x32 monochrome; uses two text labels.
 */
#include <lvgl.h>
#include <zmk/display/status_screen.h>

lv_obj_t *zmk_display_status_screen(void) {
    lv_obj_t *screen = lv_obj_create(NULL);
    lv_obj_clear_flag(screen, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(screen, lv_color_black(), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(screen, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_set_style_border_width(screen, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_all(screen, 0, LV_PART_MAIN);

    lv_obj_t *title = lv_label_create(screen);
#if defined(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
    lv_label_set_text(title, "SOFLE LEFT");
#else
    lv_label_set_text(title, "SOFLE RIGHT");
#endif
    lv_obj_set_style_text_color(title, lv_color_white(), LV_PART_MAIN);
    lv_obj_align(title, LV_ALIGN_TOP_MID, 0, 0);

    lv_obj_t *subtitle = lv_label_create(screen);
    lv_label_set_text(subtitle, "OLED DEMO 02");
    lv_obj_set_style_text_color(subtitle, lv_color_white(), LV_PART_MAIN);
    lv_obj_align(subtitle, LV_ALIGN_BOTTOM_MID, 0, 0);

    return screen;
}
