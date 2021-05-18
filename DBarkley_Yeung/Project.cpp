#include "matplotlibcpp.h"
#include <chrono>
#include <cmath>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
namespace plt = matplotlibcpp;
using namespace std;
vector<double> xtickValue;
vector<string> xtickNames;

void readFile(string fileName, string commodity, bool doTicks) {
  tm datetm;

  memset(&datetm, 0, sizeof(datetm));

  std::ifstream input(fileName, std::ios::in);

  if (!input.is_open()) {
    std::cout << "failed to open  \n";
    return;
  }
  if (!input) {
    std::cout << "...could not open file, ending.";
    return;
  }
  vector<double> x, y;
  vector<string> xNames;
  string line;
  getline(input, line);
  while (!input.eof()) {
    getline(input, line);
    size_t firstComma = line.find(',');
    string date = line.substr(firstComma + 1, 10); // date as string
    int year = stoi(date);                         // year
    int month = stoi(date.substr(5));
    int day = stoi(date.substr(8));
    cout << "year:" << year << " month:" << month << " day:" << day << "\n";
    size_t secondComma = line.find(',', firstComma + 1);
    double price = stod(line.substr(secondComma + 1));
    y.push_back(price);
    datetm.tm_mday = day;
    datetm.tm_mon = month;
    datetm.tm_year = year;
    time_t time = mktime(&datetm); // date turned into int
    x.push_back(time);
    xNames.push_back(date);
  }
  plt::named_plot(commodity, x, y);
  if (doTicks) {
    for (int i = 0; i < 7; i++) {
      int index = i * x.size() / 7;
      xtickValue.push_back(x.at(index));
      xtickNames.push_back(xNames.at(index));
    }
    xtickValue.push_back(x.at(x.size() - 1));
    xtickNames.push_back(xNames.at(xNames.size() - 1));

    plt::xticks(xtickValue, xtickNames);
  }
}

int main(int argc, char **argv) {
  bool save = false;
  string saveArg = "--save";
  if (argc >= 2 && saveArg == argv[1])
    save = true;
  plt::figure_size(1200, 780);
  plt::title("Prices");
  readFile("BTC_USD_2013-09-30_2021-04-29-CoinDesk.csv", "Bitcoin", true);
  readFile("ETH_USD_2015-08-08_2021-04-29-CoinDesk.csv", "Ethereum", false);

  // Enable legend.
  plt::legend();
  if (save) {
    plt::save("plot.png");
  } else {
    plt::show();
  }
}
