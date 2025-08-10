#include<iostream>
using namespace std;

const int CITIES = 3;
const int DAYS = 7;

float getavg(int count, int data[]) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += data[i];
    }
    return (float)sum / count;
}

int main() {
    int temperature[CITIES][DAYS];

    for (int i = 0; i < CITIES; i++) {
        cout << "Enter temperatures for City " << i + 1 << ":\n";
        for (int j = 0; j < DAYS; j++) {
            cout << "  Day " << j + 1 << ": ";
            cin >> temperature[i][j];
        }
    }

    cout << "\nTemperature Data (°C):\n";
    cout << "City\\Day\t";
    for (int d = 0; d < DAYS; d++) {
        cout << "D" << d + 1 << "\t";
    }
    cout << "Weekly Avg\n";

    for (int i = 0; i < CITIES; i++) {
        cout << "City " << i + 1 << "\t";
        float weekly_avg = getavg(DAYS, temperature[i]);
        for (int j = 0; j < DAYS; j++) {
            cout << temperature[i][j] << "\t";
        }
        cout << weekly_avg << "\n";
    }

    cout << "\nAverage Temperature Per Day:\n";
    for (int j = 0; j < DAYS; j++) {
        int daily_total = 0;
        for (int i = 0; i < CITIES; i++) {
            daily_total += temperature[i][j];
        }
        float daily_avg = (float)daily_total / CITIES;
        cout << "Day " << j + 1 << ": " << daily_avg << "°C\n";
    }

    return 0;
}