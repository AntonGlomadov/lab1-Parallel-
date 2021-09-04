#include <iostream>

//Библиотека для работы с OpenMP
#include <omp.h>

int main() {
    //выставление кол-ва потоков
    omp_set_num_threads(5);
    /*
     * Задача 1 - Вывести номер потока и их кол-во
     */
    std::cout<<"Задача 1 - Вывести номер потока и их кол-во:\n";
    //Определяет параллельную область, которая является кодом, который будет выполняться несколькими потоками параллельно.
    #pragma omp parallel default(none)
    {
        //Указывает, что код должен выполняться только в одном потоке за раз.
        #pragma omp critical
        std::cout << "I am  " << omp_get_thread_num() << " thread from " << omp_get_num_threads() << " threads"
                  << std::endl;
    }
    /*
     * Задача 2 - Вывести номер потока с четными номерами и кол-во потоков
     */
    std::cout<<"\nЗадача 2 - Вывести номер потока с четными номерами и кол-во потоков:\n";
    //Определяет параллельную область, которая является кодом, который будет выполняться несколькими потоками параллельно.
    #pragma omp parallel default(none)
    {
        //Указывает, что код должен выполняться только в одном потоке за раз.
        #pragma omp critical
        if (omp_get_thread_num()%2==0)
        std::cout << "I am  " << omp_get_thread_num() << " thread from " << omp_get_num_threads() << " threads"
                  << std::endl;
    }
    /*
     * Задача 3 - Создать K потоков. Создать переменную rank. C помощью переменной rank выести номера нечетных потоков;
     */
    int rank;
    int numOfThreads;
    std::cout<<"\nЗадача 3 - Создать K потоков. Создать переменную rank. C помощью переменной rank выести номера нечетных потоков;\n";
    std::cout<<"Введите кол-во потоков:\n";
    std::cin>>numOfThreads;
    //выставление кол-ва потоков
    omp_set_num_threads(numOfThreads);
    //Определяет параллельную область, которая является кодом, который будет выполняться несколькими потоками параллельно.
    #pragma omp parallel private (rank)
    {
        //присваеваем пременной rank номер потока
        rank = omp_get_thread_num();
        if (rank%2==1)
            std::cout << rank<<std::endl;
    }
    return 0;
}
