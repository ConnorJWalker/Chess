cmake_minimum_required(VERSION 3.22)
project(Chess)

set(CMAKE_CXX_STANDARD 23)

add_executable(Chess src/Main.cpp src/Game.cpp src/Game.h src/Board.cpp src/Board.h src/AssetManagers/TextureManager.cpp src/AssetManagers/TextureManager.h src/Enums/PieceType.h src/Enums/PieceColour.h src/Pieces/Piece.h src/Pieces/Pawn.h src/Players/Player.cpp src/Players/Player.h src/Pieces/Castle.h src/Pieces/Knight.h src/Pieces/Bishop.h src/Pieces/King.h src/Pieces/Queen.h src/Helpers/PossibleLocationHelper.h src/Helpers/VectorHash.h src/Enums/GameMode.h src/UI/UI.cpp src/UI/UI.h)

include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Chess sfml-system sfml-window sfml-graphics)