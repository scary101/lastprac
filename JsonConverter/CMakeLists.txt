cmake_minimum_required(VERSION 3.10)

project(JsonConverter)

set(CMAKE_CXX_STANDARD 17)

# Подключение nlohmann/json
include(FetchContent)
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.10.5
)
FetchContent_MakeAvailable(json)

# Добавление директории include для поиска заголовочных файлов
include_directories(${PROJECT_SOURCE_DIR}/include)

# Создание статической библиотеки
add_library(JsonConverter STATIC src/JsonConverter.cpp)

# Ссылки на библиотеку nlohmann::json
target_link_libraries(JsonConverter PRIVATE nlohmann_json::nlohmann_json)
