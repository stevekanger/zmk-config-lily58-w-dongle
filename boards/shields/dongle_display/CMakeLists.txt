if(CONFIG_ZMK_DISPLAY AND CONFIG_ZMK_DISPLAY_STATUS_SCREEN_CUSTOM AND ((NOT CONFIG_ZMK_SPLIT) OR CONFIG_ZMK_SPLIT_ROLE_CENTRAL))
    zephyr_library()
    zephyr_library_include_directories(${ZEPHYR_LVGL_MODULE_DIR})
    zephyr_library_include_directories(${ZEPHYR_BASE}/lib/gui/lvgl/)
    zephyr_library_include_directories(${ZEPHYR_BASE}/drivers)
    zephyr_library_include_directories(${CMAKE_SOURCE_DIR}/include)

    zephyr_library_sources(
        custom_status_screen.c
        ${CMAKE_SOURCE_DIR}/src/display/widgets/output_status.c  # Adjust this path as needed
    )

    zephyr_library_sources(custom_status_screen.c)
    zephyr_library_sources(widgets/battery_status.c)
    zephyr_library_sources(widgets/layer_status.c)
    # zephyr_library_sources(widgets/hid_indicators.c)
endif()


