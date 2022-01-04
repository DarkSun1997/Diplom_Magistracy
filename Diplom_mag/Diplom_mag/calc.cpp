#include "uses_things.h"

void writeFile(std::vector<double> &u, std::string fileName)
{
    std::ofstream out(fileName);
    for (auto i = 0; i < u.size(); ++i) {
        out << delta_x * i << '\t' << u[i] << '\n';
    }
    out.close();
}

void generateStartCondition(std::vector<double> &u,
                            std::vector<double> &uDel,
							double t)
{

	u[0]=1;
	u[1]=2;
    /*for (auto i = 0; i < u.size(); ++i) {
        u[i] = sin(i*3.14159265*delta_x)*0.5 ;
    }*/
    uDel = u;
}

/*
Diplom_mag_new
 path - путь сохранения файлов с результатами
 finishTime - время окончания счета
 writeFileTimeStep - шаг по времени для записи файлов
*/
void calculation(std::string path, double finishTime, double writeFileTimeStep)
{
	
////вводим количество вещественных чисел
//	freopen("output1.txt","wt",stdout);
	cout<<"FUCK!\n";

	std::vector<double> Beta;
	Beta.push_back(171);
	Beta.push_back(173);
	Beta.push_back(175);
	Beta.push_back(177);
	Beta.push_back(179);
	Beta.push_back(181);
	Beta.push_back(183);
	Beta.push_back(185);
	Beta.push_back(187);
	Beta.push_back(189);

	double f=1.1;
	double minr,maxr;
	for(int hh20=0;hh20<Beta.size();hh20++)
	{
		f=1+eps*eps*Beta[hh20];
		minr=10000;
		maxr=-1000;
		std::vector<double> u(static_cast<unsigned int>(2)),
							k1(static_cast<unsigned int>(2)),
							k2(static_cast<unsigned int>(2)),
							k3(static_cast<unsigned int>(2)),
							k4(static_cast<unsigned int>(2)),
							k5(static_cast<unsigned int>(2)),
							k6(static_cast<unsigned int>(2)),
							uDel(static_cast<unsigned int>(2));
		std::queue<std::vector<double>> uQueue;
		std::string fileName = "";
		double t = -h;
		unsigned long long counter = 0, writeLayerNum = static_cast<unsigned long>(writeFileTimeStep / delta_t) ;
		generateStartCondition(u, uDel,t);
		while (t <= 0)
		{
			generateStartCondition(u, uDel,t);
			uQueue.push(u);
			//if (counter % writeLayerNum == 0)
			//{
			//	/*fileName = path + "u" + std::to_string(counter / writeLayerNum) + ".txt";
			//	writeFile(u, fileName);*/
			//	std::cout <<u[0] << '\n';
			//}
			t += delta_t;
			++counter;
		}

		while (t <= finishTime)
		{
			uDel = uQueue.front();
			uQueue.pop();
			rungeKutta(u, uDel, k1, k2, k3, k4, k5, k6,f);
			uQueue.push(u);
			//if (counter % writeLayerNum == 0)
			//{
			//	/*fileName = path + "u" + std::to_string(counter / writeLayerNum) + ".txt";
			//	writeFile(u, fileName);*/
			//	std::cout <<u[0]<< '\n';
			//}
			if(t>9000)
			{
				if(minr>u[0])
					minr=u[0];
				if(maxr<u[0])
					maxr=u[0];
			}
			t += delta_t;
			++counter;
		}
		std::cout<<f<<" "<<minr<<" "<<maxr<<'\n';
	}
}