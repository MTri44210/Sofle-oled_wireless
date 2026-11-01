#include <zmk/display/status_screen.h>
#include <zmk/split/bluetooth/central.h>
#include <zmk/battery.h>
#include <zmk/ble.h>
#include <zmk/endpoints.h>
#include <zmk/keymap.h>
#include <lvgl.h>

/* --- MẢNG BYTE MÃ HÓA LOGO MCOI (Kích thước thu gọn cho OLED 128x32) --- */
static const uint8_t mcoi_logo_map[] = {
    /* Mảng dữ liệu hex hình ảnh logo của bạn sau khi convert sang LVGL 1-bit */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    // (Dán toàn bộ mảng hex logo MCOI đã được resize về chuẩn 128x32 hoặc nhỏ hơn vào đây)
};

static const lv_img_dsc_t mcoi_logo_dsc = {
    .header.always_zero = 0,
    .header.w = 128,
    .header.h = 32,
    .data_size = sizeof(mcoi_logo_map),
    .header.cf = LV_IMG_CF_ALPHA_1_BIT,
    .data = mcoi_logo_map,
};

lv_obj_t *zmk_display_status_screen() {
    lv_obj_t *screen = lv_obj_create(NULL);

#IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
    {
        // --- MÀN HÌNH BÊN TRÁI (MASTER): THÔNG TIN PIN, BLE, LAYER ---
        lv_obj_t *label = lv_label_create(screen);
        lv_obj_set_style_text_font(label, &lv_font_montserrat_12, 0);
        
        // Đoạn này ZMK sẽ tự động render các widget tiêu chuẩn gồm: Pin Left/Right, BLE Profile (1, 2, 3), Layer
        // Bạn có thể dùng built-in status screen của ZMK cho bên trái để hiển thị đầy đủ nhất:
        return zmk_display_status_screen_builtin();
    }
#else
    {
        // --- MÀN HÌNH BÊN PHẢI (SLAVE): HIỂN THỊ LOGO MCOI ---
        lv_obj_t *img = lv_img_create(screen);
        lv_img_set_src(img, &mcoi_logo_dsc);
        lv_obj_align(img, LV_ALIGN_CENTER, 0, 0);
    }
#endif

    return screen;
}
