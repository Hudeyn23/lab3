cmake_minimum_required(VERSION 3.15)
project(lab3)

set(CMAKE_CXX_STANDARD 17)
set(GCC_COVERAGE_COMPILE_FLAGS "-static")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
add_executable(lab3 main.cpp Board.cpp Board.h Cell.cpp Cell.h VirusWarView.cpp VirusWarView.h VirusWarController.cpp VirusWarController.h VirusWarModel.cpp VirusWarModel.h VirusWarModelException.cpp VirusWarModelException.h VirusWarUtil.cpp VirusWarUtil.h Player.cpp Player.h Bot.cpp Bot.h Human.cpp Human.h ConsoleView.cpp ConsoleView.h VirusWarGame.cpp VirusWarGame.h)