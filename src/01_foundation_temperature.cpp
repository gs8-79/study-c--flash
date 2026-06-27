#include <iostream>
#include <vector>
using namespace std;

int findMax(const vector<int>& values) {
    int best = values[0];
    for (int i = 1; i < (int)values.size(); ++i) {
        if (values[i] > best) {
            best = values[i];
        }
    }
    return best;
}

int findMin(const vector<int>& values) {
    int best = values[0];
    for (int i = 1; i < (int)values.size(); ++i) {
        if (values[i] < best) {
            best = values[i];
        }
    }
    return best;
}

int findMode(const vector<int>& values) {
    int mode = values[0];
    int bestCount = 1;

    for (int i = 0; i < (int)values.size(); ++i) {
        int count = 0;
        for (int j = 0; j < (int)values.size(); ++j) {
            if (values[j] == values[i]) {
                ++count;
            }
        }

        if (count > bestCount || (count == bestCount && values[i] < mode)) {
            bestCount = count;
            mode = values[i];
        }
    }

    return mode;
}

int longestRisingStreak(const vector<int>& values) {
    if (values.empty()) {
        return 0;
    }

    int best = 1;
    int current = 1;

    for (int i = 1; i < (int)values.size(); ++i) {
        if (values[i] > values[i - 1]) {
            ++current;
        } else {
            current = 1;
        }

        if (current > best) {
            best = current;
        }
    }

    return best;
}

int main() {
    int n;
    cout << "Input number of days: ";
    cin >> n;

    if (n <= 0) {
        cout << "No data" << endl;
        return 0;
    }

    vector<int> temperatures(n);
    cout << "Input temperatures: ";
    for (int i = 0; i < n; ++i) {
        cin >> temperatures[i];
    }

    cout << "Max: " << findMax(temperatures) << endl;
    cout << "Min: " << findMin(temperatures) << endl;
    cout << "Mode: " << findMode(temperatures) << endl;
    cout << "Longest rising streak: " << longestRisingStreak(temperatures) << endl;

    return 0;
}
