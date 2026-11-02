# Zephyr v3.5-compatible module. Source is included into ZMK app.
if(CONFIG_ZMK_DISPLAY AND CONFIG_ZMK_DISPLAY_STATUS_SCREEN_CUSTOM)
  target_sources(app PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/status_screen.c
  )
endif()
