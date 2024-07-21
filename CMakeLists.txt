cmake_minimum_required(VERSION 3.10)

project(flappy)

add_executable(${PROJECT_NAME} main.cpp sdl_starter.cpp sdl_assets_loader.cpp)

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2_IMAGE REQUIRED SDL2_image)
pkg_search_module(SDL2_MIXER REQUIRED SDL2_mixer)
pkg_search_module(SDL2_TTF REQUIRED SDL2_ttf)

target_link_libraries(${PROJECT_NAME} PRIVATE
	${SDL2_LIBRARIES}
	${SDL2_IMAGE_LIBRARIES}
    ${SDL2_MIXER_LIBRARIES}
	${SDL2_TTF_LIBRARIES}
	SDL2main
)

if(PLATFORM_PSP)
	create_pbp_file(
		TARGET ${PROJECT_NAME}
		ICON_PATH NULL
		BACKGROUND_PATH NULL
		PREVIEW_PATH NULL
		TITLE ${PROJECT_NAME}
	)
elseif(VITA)
	set(VITA_TITLEID "FLAPPY001") #title length == 9

	include("$ENV{VITASDK}/share/vita.cmake" REQUIRED)

	vita_create_self(${PROJECT_NAME}.self ${PROJECT_NAME})
	vita_create_vpk(${PROJECT_NAME}.vpk ${VITA_TITLEID} ${PROJECT_NAME}.self
		VERSION "01.00"
		NAME ${PROJECT_NAME}
		FILE platform/vita/sce_sys sce_sys
		FILE res/fonts/square_sans_serif_7.ttf square_sans_serif_7.ttf
		FILE res/sounds/laser.ogg laser.ogg
		FILE res/sounds/die.wav die.wav
		FILE res/sounds/magic.wav magic.wav
		FILE res/sounds/point.wav point.wav
		FILE res/sounds/wing.wav wing.wav
		FILE res/sprites/0.png 0.png 
		FILE res/sprites/1.png 1.png 
		FILE res/sprites/2.png 2.png 
		FILE res/sprites/3.png 3.png 
		FILE res/sprites/4.png 4.png 
		FILE res/sprites/5.png 5.png 
		FILE res/sprites/6.png 6.png 
		FILE res/sprites/7.png 7.png 
		FILE res/sprites/8.png 8.png 
		FILE res/sprites/9.png 9.png 
		FILE res/sprites/background-day.png background-day.png 
		FILE res/sprites/base.png base.png 
		FILE res/sprites/message.png message.png 
		FILE res/sprites/new-birds.png new-birds.png 
		FILE res/sprites/pipe-green-180.png pipe-green-180.png 
		FILE res/sprites/pipe-green.png pipe-green.png 
		FILE res/sprites/yellow-bird.png yellow-bird.png 
		FILE res/sprites/yellowbird-midflap.png yellowbird-midflap.png 
		FILE res/high-score.txt high-score.txt 
	)
endif()

file(COPY res/fonts/square_sans_serif_7.ttf DESTINATION ${CMAKE_BINARY_DIR})
file(COPY res/sounds/laser.ogg DESTINATION ${CMAKE_BINARY_DIR})
file(COPY res/sounds/die.wav DESTINATION ${CMAKE_BINARY_DIR})
file(COPY res/sounds/magic.wav DESTINATION ${CMAKE_BINARY_DIR})
file(COPY res/sounds/point.wav DESTINATION ${CMAKE_BINARY_DIR})
file(COPY res/sounds/wing.wav DESTINATION ${CMAKE_BINARY_DIR})
file(COPY res/sprites/0.png DESTINATION ${CMAKE_BINARY_DIR})
file(COPY res/sprites/1.png DESTINATION ${CMAKE_BINARY_DIR})
file(COPY res/sprites/2.png DESTINATION ${CMAKE_BINARY_DIR})
file(COPY res/sprites/3.png DESTINATION ${CMAKE_BINARY_DIR})
file(COPY res/sprites/4.png DESTINATION ${CMAKE_BINARY_DIR})
file(COPY res/sprites/5.png DESTINATION ${CMAKE_BINARY_DIR})
file(COPY res/sprites/6.png DESTINATION ${CMAKE_BINARY_DIR})
file(COPY res/sprites/7.png DESTINATION ${CMAKE_BINARY_DIR})
file(COPY res/sprites/8.png DESTINATION ${CMAKE_BINARY_DIR})
file(COPY res/sprites/9.png DESTINATION ${CMAKE_BINARY_DIR})
file(COPY res/sprites/background-day.png DESTINATION ${CMAKE_BINARY_DIR})
file(COPY res/sprites/base.png DESTINATION ${CMAKE_BINARY_DIR})
file(COPY res/sprites/message.png DESTINATION ${CMAKE_BINARY_DIR})
file(COPY res/sprites/new-birds.png DESTINATION ${CMAKE_BINARY_DIR})
file(COPY res/sprites/pipe-green-180.png DESTINATION ${CMAKE_BINARY_DIR})
file(COPY res/sprites/pipe-green.png DESTINATION ${CMAKE_BINARY_DIR})
file(COPY res/sprites/yellow-bird.png DESTINATION ${CMAKE_BINARY_DIR})
file(COPY res/sprites/yellowbird-midflap.png DESTINATION ${CMAKE_BINARY_DIR})
file(COPY res/high-score.txt DESTINATION ${CMAKE_BINARY_DIR})

