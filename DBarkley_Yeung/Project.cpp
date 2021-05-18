#include "matplotlibcpp.h"
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
namespace plt = matplotlibcpp;
using namespace std;
int main()
{
	tm datetm;
	memset(&datetm,0,sizeof(datetm));

    std::ifstream input("BTC_USD_2013-09-30_2021-04-29-CoinDesk.csv",
                        std::ios::in);

	if (!input.is_open())
	{
		std::cout << "failed to open  \n";
	}
	else {
		if (!input)
		{
			std::cout << "...could not open file, ending.";
			return -1;
		}
		vector<double> x,y;
        string line;
		getline(input,line);
		while (!input.eof())
		{
            getline(input,line);
            size_t firstComma =line.find(',');
            string date=line.substr(firstComma+1,10);// date as string
			int year =stoi(date);// year
			int month= stoi(date.substr(5));
			int day= stoi(date.substr(8));
			cout<<"year:"<<year<<" month:"<<month<<" day:"<<day<<"\n";
			size_t secondComma =line.find(',', firstComma+1);
			double price=stod(line.substr(secondComma +1));
			y.push_back(price);
			datetm.tm_mday=day;
			datetm.tm_mon= month;
			datetm.tm_year= year;
			time_t time =mktime(&datetm);// date turned into int 
			x.push_back(time);
        }
	    plt::figure_size(1200, 780);
		plt::named_plot("Bitcoin", x, y);
		plt::title("Prices");
		// Enable legend.
		plt::legend();
		plt::show();

    }
			
}