#include <zmk/display/status_screen.h>
#include <lvgl.h>

// ==========================================
// 1. MẢNG DỮ LIỆU LOGO MCOI (128x32)
// ==========================================
static const uint8_t mcoi_logo_map[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    // ... (Giữ nguyên các dòng dữ liệu mảng hex của bạn ở đây)
};

static const lv_img_dsc_t mcoi_logo_dsc = {
    .header.always_zero = 0,
    .header.w = 128,
    .header.h = 32,
    .data_size = sizeof(mcoi_logo_map),
    .header.cf = LV_IMG_CF_ALPHA_1_BIT,
    .data = mcoi_logo_map,
};

// ==========================================
// 2. HÀM HIỂN THỊ MÀN HÌNH (STATUS SCREEN)
// ==========================================
lv_obj_t *zmk_display_status_screen() {
#if IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
    // --- MÀN HÌNH BÊN TRÁI (MASTER): DÙNG MẶC ĐỊNH CỦA ZMK ---
    return zmk_display_status_screen_builtin();
#else
    // --- MÀN HÌNH BÊN PHẢI (SLAVE): HIỂN THỊ LOGO MCOI ---
    lv_obj_t *screen = lv_obj_create(NULL);
    lv_obj_t *img = lv_img_create(screen);
    lv_img_set_src(img, &mcoi_logo_dsc);
    lv_obj_align(img, LV_ALIGN_CENTER, 0, 0);
    return screen;
#endif
}
