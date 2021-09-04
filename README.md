# Лабораторная работа № 1

Базовые представления об OpenMP
***
####Работы выполнена в СLion IDE  
I. Для работы с openMP на MacBook неообходимо скачать библиотеку через терминал
```commandline
brew install libomp
```
[Установка `brew`](https://brew.sh/index_ru)  
II. В CMake файл добавить
```cmake
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(Lab1Paralel PUBLIC OpenMP::OpenMP_CXX)
endif()
```
