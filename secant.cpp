#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double fx(double x) {
    return pow(x,4)-x-10;
}


vector<double> initial_guesses() {
    vector<double> L;
    for (int i = 1; i <= 5; i++) {
        if (fx(i) * fx(i - 1) < 0) { 
            L.push_back(i - 1); 
            L.push_back(i);    
            break;
        }
    }
    cout << "Initial Guesses: x0 = " << L[0] << ", x1 = " << L[1] << "\n";
    return L;
}


void SecantMethod(vector<double> L, int iterations = 5) {
    double x0 = L[0], x1 = L[1], x2;

    for (int i = 0; i < iterations; i++) {
        double f0 = fx(x0);
        double f1 = fx(x1);

        if (f1 - f0 == 0) {
            cout << "Division by zero error in iteration " << i + 1 << "\n";
            return;
        }

        x2 = x1 - f1 * (x1 - x0) / (f1 - f0);
        double f2 = fx(x2);

        cout << "Iteration " << i + 1 << ": x = " << x2 << ", fx(x) = " << f2 << "\n";

        
        if (abs(f2) < 1e-6) {
            cout << "Root found: " << x2 << "\n";
            return;
        }

    
        x0 = x1;
        x1 = x2;
    }
    cout << "Approximate root after " << iterations << " iterations: " << x2 << "\n";
}

int main() {
    vector<double> a = initial_guesses();
    if (a.size() == 2) {
        SecantMethod(a);
    } else {
        cout << "No valid initial guesses found.\n";
    }
    return 0;
}
