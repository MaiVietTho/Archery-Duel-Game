CFLAGS	 += -I./sources/app/game/game_T
CPPFLAGS += -I./sources/app/game/game_T

VPATH += sources/app/game/game_T

# CPP source files
# Archery game
SOURCES_CPP += sources/app/game/game_T/game_archery.cpp
SOURCES_CPP += sources/app/game/game_T/game_archery_person_2.cpp
SOURCES_CPP += sources/app/game/game_T/game_arrow.cpp
SOURCES_CPP += sources/app/game/game_T/game_arrow_person_2.cpp
# SOURCES_CPP += sources/app/game/game_T/game_meteoroid.cpp
SOURCES_CPP += sources/app/game/game_T/game_border.cpp
SOURCES_CPP += sources/app/game/game_T/game_border_person_2.cpp
SOURCES_CPP += sources/app/game/game_T/game_bang.cpp