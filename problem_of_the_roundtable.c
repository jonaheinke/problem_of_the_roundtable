//Compilieren und Ausführen:
//  gcc -std=c99 -fopenmp problem_of_the_roundtable.c -o problem_of_the_roundtable
//  .\problem_of_the_roundtable 16

//Bei Fehler "cannot find -lpthread" -> mingw32-pthreads-w32 installieren (https://stackoverflow.com/questions/23554716/using-openmp-on-windows-with-mingw-cannot-find-lpthread)

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

unsigned long long parallel_calculation() {
    return 0;
}

unsigned long long problem_of_the_roundtable(unsigned char a, unsigned char b) {
    #pragma omp parallel for schedule(static)
    for(int i = 0; i < b; i++) {
        parallel_calculation();
    }
    return 0;
}

int main(int argc, char* argv[]) {
    omp_set_dynamic(argc > 1 ? atoi(argv[1]) : 4); //TODO: Setzt das überhaupt die Anzahl der Threads richtig? Es heißt ja dynamic und nicht static
    omp_set_num_threads(argc > 1 ? atoi(argv[1]) : 4);
    printf("%llu", problem_of_the_roundtable(5, 3));
    return 0;
}