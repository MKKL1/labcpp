cmake_minimum_required(VERSION 3.21)
project(ekosystem)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "E:/Qt/6.2.3/mingw_64/")

find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)
find_package(Qt6Quick REQUIRED)

include_directories(headers)

add_executable(ekosystem src/main.cpp
        src/organizm/organizmy/bakteria.cpp
        src/utils/generatorlosowy.cpp
        src/organizm/organizmy/glon.cpp
        src/organizm/organizmy/grzyb.cpp
        src/nisza.cpp
        src/organizm/organizm.cpp
        src/utils/sasiedztwo.cpp
        src/srodowisko.cpp
        src/organizm/RejestrMieszkancow.cpp headers/UstawieniaOrganizmu.h src/ustawieniasymulacji.cpp src/UstawieniaOrganizmu.cpp src/ListaMieszkancow.cpp src/wyswietlanie/WyjscieGraficzne.cpp headers/WyjscieGraficzne.h src/wyswietlanie/WyswietlaczKonsolowy.cpp headers/WyswietlaczKonsolowy.h src/organizm/organizmy/archea.cpp headers/archea.h src/wyswietlanie/WyswietlaczOkienkowy.cpp headers/WyswietlaczOkienkowy.h src/wyswietlanie/OknoEkosystemu.cpp headers/OknoEkosystemu.h src/wyswietlanie/WatekSymulacji.cpp headers/WatekSymulacji.h)

target_link_libraries(ekosystem Qt6::Core)
target_link_libraries(ekosystem Qt6::Widgets)
target_link_libraries(ekosystem Qt6::Quick)