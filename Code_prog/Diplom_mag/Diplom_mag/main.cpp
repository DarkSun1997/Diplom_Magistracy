#include "uses_things.h"

int main() {
    omp_set_num_threads(8); // Указываем количество потоков. В данном случае 8 (число ядер)
    calculation("output/", 10000.0, 0.01);
    return 0;
}