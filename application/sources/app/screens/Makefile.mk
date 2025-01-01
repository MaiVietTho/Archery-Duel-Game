CFLAGS		+= -I./sources/app/screens
CPPFLAGS	+= -I./sources/app/screens

VPATH += sources/app/screens

# CPP source files
SOURCES_CPP += sources/app/screens/scr_startup.cpp
SOURCES_CPP += sources/app/screens/scr_setting.cpp
SOURCES_CPP += sources/app/screens/scr_inform.cpp
SOURCES_CPP += sources/app/screens/scr_check_connect.cpp
SOURCES_CPP += sources/app/screens/scr_menu.cpp
SOURCES_CPP += sources/app/screens/scr_idle.cpp
SOURCES_CPP += sources/app/screens/scr_archery_game.cpp
SOURCES_CPP += sources/app/screens/scr_charts_game.cpp
SOURCES_CPP += sources/app/screens/scr_game_over.cpp
SOURCES_CPP += sources/app/screens/scr_game_setting.cpp
SOURCES_CPP += sources/app/screens/scr_menu_game.cpp

# CPP soure file data bitmap
SOURCES_CPP += sources/app/screens/screens_bitmap.cpp
