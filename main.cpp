#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int check(vector<vector<int>> persons, int day) {
    int poisonIndex = -1;
    string poisonHint = "";

    for (int i = 0; i < persons.size(); i++) {
        if (persons[i][0] == 1) {
            poisonIndex = i;
            switch (day) {
                case 1:
                    poisonHint = " which ranges from " + to_string(i * 100) + "-" + to_string(i * 100 + 99);
                    break;
                case 2:
                    poisonHint = " which contains in number in form of X" + to_string(i) + "X";
                    break;
                case 3:
                    poisonHint = " which contains in number in form of XX" + to_string(i);
                    break;
                default:
                    break;
            }
            cout << "Person " << (i + 1) << " is the one that drank poison" << poisonHint << endl;
            break;
        }
    }

    return poisonIndex;
}

vector<int> findPoison(vector<int> arr, int start, int end) {
    if (start == end) {
        return { arr[start], start };
    }
    int midValue = (start + end) / 2;
    vector<int> leftValues = findPoison(arr, start, midValue);
    vector<int> rightValues = findPoison(arr, midValue + 1, end);
    if (leftValues[0] >= rightValues[0]) {
        return leftValues;
    }
    return rightValues;
}

vector<int> fillRandomWine(vector<int> arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        arr[i] = 0;
    }
    int random = rand() % 1000;
    cout << random << endl;
    arr[random] = 1;
    return arr;
}

void slaveTesting(vector<int> arr) {
    vector<vector<int>> secondSlaveArray(10, vector<int>(100)), thirdSlaveArray(10, vector<int>(100));
    vector<int> sD3Array(10), eArray(10);
    vector<string> strArray(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        strArray[i] = to_string(arr[i]);
    }
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 10; j++) {
            string iString = to_string(i);
            if (iString.size() > 1 && iString.substr(1, 1) == to_string(j)) {
                secondSlaveArray[j][eArray[j]] = stoi(strArray[i]);
                eArray[j]++;
            }
            if (iString.size() > 2 && iString.substr(2, 1) == to_string(j)) {
                thirdSlaveArray[j][sD3Array[j]] = stoi(strArray[i]);
                sD3Array[j]++;
            }
        }
    }
    int start = 0, end = 99;
    vector<vector<int>> firstSlaveArray(10), secondSlaveArray2(10), thirdSlaveArray2(10);
    for (int i = 0; i < 10; i++) {
        firstSlaveArray[i] = findPoison(arr, i * 100, (i + 1) * 100 - 1);
        secondSlaveArray2[i] = findPoison(secondSlaveArray[i], start, end);
        thirdSlaveArray2[i] = findPoison(thirdSlaveArray[i], start, end);
    }
    int day1 = check(firstSlaveArray, 1);
    cout << " in day 1" << endl;
    int day2 = check(secondSlaveArray2, 2);
    cout << " in day 2" << endl;
    int day3 = check(thirdSlaveArray2, 3);
    cout << " in day 3" << endl;

    cout<<"Therefore, the posioned bottle is: "<<day1<<day2<<day3;
}

int main() {
    srand(time(NULL));
    vector<int> arr(1000);
    for (int i = 0; i < 1000; i++) {
        arr[i] = i;
    }
    arr = fillRandomWine(arr);
    slaveTesting(arr);

    return 0;
}