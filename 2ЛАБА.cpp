/***************************************
* Автор:   Кучина Мария                *
* Задание: Циклы с пред-и постусловием *
* Вариант: 12                          *
****************************************/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  double firstPhaseStartTime = 10.0;
  double firstPhaseStep = 10.0;
  double secondPhaseStartTime = 50.0;
  double secondPhaseEndTime = 100.0;
  double secondPhaseStep = 50.0;
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

  cout << "\nSolidification time: " << solidificationTime << " min" << "Time\tAverage Temperature" << endl;

  currentTime = firstPhaseStartTime;
    do {
        averageTemperature = initialTemperature * exp(-coolingCoefficient * currentTime);
        cout << currentTime << "\t" << averageTemperature << endl;
        currentTime += firstPhaseStep;
    } while (currentTime < solidificationTime);

   currentTime = secondPhaseStartTime;
    while (currentTime <= secondPhaseEndTime) {
        averageTemperature = solidificationTemperature - linearCoefficient * (currentTime - solidificationTime);
        cout << currentTime << "\t" << averageTemperature << endl;
        currentTime += secondPhaseStep;
    }

    return 0;
}