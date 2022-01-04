#ifndef INC_190928_UNIVERSITY_USES_THINGS_H
#define INC_190928_UNIVERSITY_USES_THINGS_H

#include <math.h>
#include <vector>
#include <omp.h>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>

static const double C = 1, d =0, delta_x = 0.01, delta_t = 0.0001, h = 1.0,eps=0.01, beta=1.009,k=2;

void rungeKutta(std::vector<double> &u,
                std::vector<double> &uDel,
                std::vector<double> &k1,
                std::vector<double> &k2,
                std::vector<double> &k3,
                std::vector<double> &k4,
                std::vector<double> &k5,
                std::vector<double> &k6);

void pushToQueue(std::vector<double> &u,
                 std::vector<double> &k1,
                 std::vector<double> &k2,
                 std::vector<double> &k3,
                 std::vector<double> &k4,
                 std::vector<double> &k5,
                 std::queue<std::vector<double>> &uQueue,
                 std::queue<std::vector<double>> &k1Queue,
                 std::queue<std::vector<double>> &k2Queue,
                 std::queue<std::vector<double>> &k3Queue,
                 std::queue<std::vector<double>> &k4Queue,
                 std::queue<std::vector<double>> &k5Queue);

void getFromQueue(std::vector<double> &u,
                  std::vector<double> &k1,
                  std::vector<double> &k2,
                  std::vector<double> &k3,
                  std::vector<double> &k4,
                  std::vector<double> &k5,
                  std::queue<std::vector<double>> &uQueue,
                  std::queue<std::vector<double>> &k1Queue,
                  std::queue<std::vector<double>> &k2Queue,
                  std::queue<std::vector<double>> &k3Queue,
                  std::queue<std::vector<double>> &k4Queue,
                  std::queue<std::vector<double>> &k5Queue);

void calculation(std::string path, double finishTime, double writeFileTimeStep);

#endif //INC_190928_UNIVERSITY_USES_THINGS_H
