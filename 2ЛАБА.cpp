// 2ЛАБА.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
/* Author: Kuchina M.A.*
 * Date : 06.10.2026   *
 * Option 12           *
 * Name : 2 labs       *
 ***********************/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
   double initialTemperature;
   double solidificationTemperature;
   double coolingCoefficient;
   double linearCoefficient;
   double solidificationTime;
   double currentTime;
   double averageTemperature;

   cout << "Enter initial temperature (t_zh): ";
   cin >> initialTemperature;

   cout << "Enter solidification temperature (t_tv): ";
   cin >> solidificationTemperature;

   cout << "Enter cooling coefficient (0.021): ";
   cin >> coolingCoefficient;

   cout << "Enter linear coefficient (0.0151): ";
   cin >> linearCoefficient;

   solidificationTime = (1.0 / coolingCoefficient) * log(initialTemperature / solidificationTemperature);

   cout << "\nSolidification time: " << solidificationTime << " min" << endl;
   cout << "Time\tAverage Temperature" << endl;

   currentTime = 10.0;
   do {
        averageTemperature = initialTemperature * exp(-coolingCoefficient * currentTime);
        cout << currentTime << "\t" << averageTemperature << endl;
        currentTime += 10.0;
   } while (currentTime < solidificationTime);

   currentTime = 50.0;
   while (currentTime <= 100.0) {
        averageTemperature = solidificationTemperature - linearCoefficient * (currentTime - solidificationTime);
        cout << currentTime << "\t" << averageTemperature << endl;
        currentTime += 50.0; 
   }

   return 0;
}