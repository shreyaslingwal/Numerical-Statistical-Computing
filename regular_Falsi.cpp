#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to find the root
double fx(double x) {
    return x * log10(x) - 1.2;
}

// Function to find an initial interval where fx changes sign
vector<double> roots() {
    vector<double> L;
    for (int i = 1; i <= 5; i++) {
        if (fx(i) * fx(i - 1) < 0) { // Sign change condition
            L.push_back(i - 1);
            L.push_back(i);
            break; // Stop after finding the first valid interval
        }
    }
    cout << "Initial Interval: [" << L[0] << ", " << L[1] << "]\n";
    return L;
}

// Formula for Regula Falsi (False Position) method
double Formula(vector<double> L) {
    return L[1] - ((L[1] - L[0]) * fx(L[1])) / (fx(L[1]) - fx(L[0]));
}

// Function implementing the Regula Falsi method
void R_Falsi(vector<double> L, int iterations = 5) {
    double x;
    for (int j = 0; j < iterations; j++) {
        x = Formula(L);
        double y = fx(x);

        cout << "Iteration " << j + 1 << ": x = " << x << ", fx(x) = " << y << "\n";

        // Update the interval
        if (fx(L[0]) * y < 0) {
            L[1] = x;
        } else {
            L[0] = x;
        }

        // Stop if the function value is close to zero
        if (abs(y) < 1e-6) {
            cout << "Root found: " << x << "\n";
            return;
        }
    }
    cout << "Approximate root after " << iterations << " iterations: " << x << "\n";
}

int main() {
    vector<double> a = roots();
    if (a.size() == 2) { // Ensure a valid interval was found
        R_Falsi(a);
    } else {
        cout << "No valid root interval found.\n";
    }
    return 0;
}
