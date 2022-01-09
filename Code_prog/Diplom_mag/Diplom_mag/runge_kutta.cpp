#include "uses_things.h"

double F(double yDel,
				double f)
{
	return f*sin(yDel);
}

double u(double xCur, double yCur, double xDel, double yDel,double flag,
				double f)
{
	if(flag==0)
		return yCur;
	else
	    return (F(yDel,f)-yCur-k*eps*xCur)/eps*C;
}

double k1(double xCur, double yCur, double xDel, double yDel,double flag,
				double f)
{
    return delta_t * u(xCur, 
					   yCur, 
					   xDel, 
					   yDel, 
					   flag,f);
}

double k2(double xCur, double yCur, double xDel, double yDel,double flag,
          double k1xCur, double k1yCur,
				double f)
{
    return delta_t * u(xCur+ 0.5 * k1xCur, 
					   yCur+ 0.5 * k1yCur, 
					   xDel, 
					   yDel, 
					   flag,f);
}

double k3(double xCur, double yCur, double xDel, double yDel,double flag,
          double k1xCur, double k1yCur,
          double k2xCur, double k2yCur,
				double f)
{
    return delta_t * u(xCur+ 0.25 * (k1xCur+k2xCur), 
					   yCur+ 0.25 * (k1yCur+k2yCur), 
					   xDel, 
					   yDel, 
					   flag,f);
}

double k4(double xCur, double yCur, double xDel, double yDel,double flag,
          double k2xCur, double k2yCur,
          double k3xCur, double k3yCur,
				double f)
{
    return delta_t * u(xCur - k2xCur + 2.0 * k3xCur, 
					   yCur - k2yCur + 2.0 * k3yCur, 
					   xDel, 
					   yDel, 
					   flag,f);
}

double k5(double xCur, double yCur, double xDel, double yDel,double flag,
          double k1xCur, double k1yCur,
          double k2xCur, double k2yCur,
          double k4xCur, double k4yCur,
				double f)
{
    return delta_t * u(xCur - (7.0 * k1xCur + 10.0 * k2xCur + k4xCur) / 27.0, 
					   yCur - (7.0 * k1yCur + 10.0 * k2yCur + k4yCur) / 27.0, 
					   xDel, 
					   yDel, 
					   flag,f);
    
}

double k6(double xCur, double yCur, double xDel, double yDel,double flag,
          double k1xCur, double k1yCur,
          double k2xCur, double k2yCur,
          double k3xCur, double k3yCur,
          double k4xCur, double k4yCur,
          double k5xCur, double k5yCur,
				double f)
{
    return delta_t * u(xCur + (28.0 * k1xCur - 125.0 * k2xCur + 546.0 * k3xCur + 54.0 * k4xCur - 378.0 * k5xCur) / 625.0, 
					   yCur + (28.0 * k1yCur - 125.0 * k2yCur + 546.0 * k3yCur + 54.0 * k4yCur - 378.0 * k5yCur) / 625.0, 
					   xDel, 
					   yDel, 
					   flag,f);
}

double defectValue(double k1Cur, double k3Cur, double k4Cur, double k5Cur, double k6Cur)
{
    return (42.0 * k1Cur + 224.0 * k3Cur + 21.0 * k4Cur - 162.0 * k5Cur - 125.0 * k6Cur) / 336.0;
}

void k1Calc(std::vector<double>& uVec,
            std::vector<double>& uDelVec,
            std::vector<double>& k1Vec,
				double f)
{
	k1Vec[0] = k1(uVec[0], uVec[1], uDelVec[0], uDelVec[1], 0,f);
	k1Vec[1] = k1(uVec[0], uVec[1], uDelVec[0], uDelVec[1], 1,f);
}

void k2Calc(std::vector<double>& uVec,
            std::vector<double>& uDelVec,
            std::vector<double>& k1Vec,
            std::vector<double>& k2Vec,
				double f)
{
	k2Vec[0] = k2(uVec[0], uVec[1], uDelVec[0], uDelVec[1], 0,
				k1Vec[0], k1Vec[1],f);
	k2Vec[1] = k2(uVec[0], uVec[1], uDelVec[0], uDelVec[1], 1,
				k1Vec[0], k1Vec[1],f);
}

void k3Calc(std::vector<double>& uVec,
            std::vector<double>& uDelVec,
            std::vector<double>& k1Vec,
            std::vector<double>& k2Vec,
            std::vector<double>& k3Vec,
				double f)
{
	k3Vec[0] = k3(uVec[0], uVec[1], uDelVec[0], uDelVec[1], 0,
				k1Vec[0], k1Vec[1],
				k2Vec[0], k2Vec[1],f);
	k3Vec[1] = k3(uVec[0], uVec[1], uDelVec[0], uDelVec[1], 1,
				k1Vec[0], k1Vec[1],
				k2Vec[0], k2Vec[1],f);
}

void k4Calc(std::vector<double>& uVec,
            std::vector<double>& uDelVec,
            std::vector<double>& k2Vec,
            std::vector<double>& k3Vec,
            std::vector<double>& k4Vec,
				double f)
{
	k4Vec[0] = k4(uVec[0], uVec[1], uDelVec[0], uDelVec[1], 0,
				k2Vec[0], k2Vec[1],
				k3Vec[0], k3Vec[1],f);
	k4Vec[1] = k4(uVec[0], uVec[1], uDelVec[0], uDelVec[1], 1,
				k2Vec[0], k2Vec[1],
				k3Vec[0], k3Vec[1],f);
}

void k5Calc(std::vector<double>& uVec,
            std::vector<double>& uDelVec,
            std::vector<double>& k1Vec,
            std::vector<double>& k2Vec,
            std::vector<double>& k4Vec,
            std::vector<double>& k5Vec,
				double f)
{
	k5Vec[0] = k5(uVec[0], uVec[1], uDelVec[0], uDelVec[1], 0,
				k1Vec[0], k1Vec[1],
				k2Vec[0], k2Vec[1],
				k4Vec[0], k4Vec[1],f);
	k5Vec[1] = k5(uVec[0], uVec[1], uDelVec[0], uDelVec[1], 1,
				k1Vec[0], k1Vec[1],
				k2Vec[0], k2Vec[1],
				k4Vec[0], k4Vec[1],f);
}

void k6Calc(std::vector<double>& uVec,
            std::vector<double>& uDelVec,
            std::vector<double>& k1Vec,
            std::vector<double>& k2Vec,
            std::vector<double>& k3Vec,
            std::vector<double>& k4Vec,
            std::vector<double>& k5Vec,
            std::vector<double>& k6Vec,
				double f)
{
	
	k6Vec[0] = k6(uVec[0], uVec[1], uDelVec[0], uDelVec[1], 0,
				k1Vec[0], k1Vec[1],
				k2Vec[0], k2Vec[1],
				k3Vec[0], k3Vec[1],
				k4Vec[0], k4Vec[1],
				k5Vec[0], k5Vec[1],f);
	k6Vec[1] = k6(uVec[0], uVec[1], uDelVec[0], uDelVec[1], 1,
				k1Vec[0], k1Vec[1],
				k2Vec[0], k2Vec[1],
				k3Vec[0], k3Vec[1],
				k4Vec[0], k4Vec[1],
				k5Vec[0], k5Vec[1],f);
}

void nextLayerCalculation(std::vector<double> &u,
                          std::vector<double> &k1,
                          std::vector<double> &k3,
                          std::vector<double> &k4,
                          std::vector<double> &k5,
                          std::vector<double> &k6,
				double f)
{
#pragma omp parallel for
    for (int i = 0; i < u.size(); ++i) {
        u[i] += (k1[i] + 4.0 * k3[i] + k4[i]) / 6.0 - defectValue(k1[i], k3[i], k4[i], k5[i], k6[i]);
    }
}

void rungeKutta(std::vector<double> &u,
                std::vector<double> &uDel,
                std::vector<double> &k1,
                std::vector<double> &k2,
                std::vector<double> &k3,
                std::vector<double> &k4,
                std::vector<double> &k5,
                std::vector<double> &k6,
				double f)
{
    k1Calc(u, uDel, k1,f);
    k2Calc(u, uDel, k1, k2,f);
    k3Calc(u, uDel, k1, k2, k3,f);
    k4Calc(u, uDel, k2, k3, k4,f);
    k5Calc(u, uDel, k1, k2, k4, k5,f);
    k6Calc(u, uDel, k1, k2, k3, k4, k5, k6,f);
    nextLayerCalculation(u, k1, k3, k4, k5, k6,f);
}