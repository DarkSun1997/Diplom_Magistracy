#include "uses_things.h"

int main() {
    omp_set_num_threads(8); // ��������� ���������� �������. � ������ ������ 8 (����� ����)
    calculation("output/", 50.0, 0.01);
    return 0;
}