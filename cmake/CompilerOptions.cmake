if (MSVC)
    set(${PROJECT_NAME}_CXX_FLAGS_DEBUG
        "/W3"
        "/WX"
    )
    set(${PROJECT_NAME}_CXX_FLAGS_RELEASE "/O2")
else()
    set(${PROJECT_NAME}_CXX_FLAGS_DEBUG
        "-pedantic"
        "-pedantic-errors"
        "-W"
        "-Wall"
        "-Wdouble-promotion"
        "-Werror"
        "-Wextra"
        "-Wfloat-equal"
        "-Wformat=1"
        "-Wimplicit-fallthrough"
        "-Winit-self"
        "-Winline"
        "-Wno-long-long"
        "-Wpointer-arith"
        "-Wshadow"
        "-Wsign-promo"
        "-Wundef"
        "-Wno-attributes"
    )
    set(${PROJECT_NAME}_CXX_FLAGS_RELEASE "-O3")
endif()
