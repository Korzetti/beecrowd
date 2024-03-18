#include <iostream>
#include <iomanip>

using namespace std;
 
double n, raio, area;
int main() {
    n = 3.14159;
    
    cin >> raio;
    area = n * (raio * raio);
    cout << fixed << showpoint;
    cout << setprecision(4);
    cout << "A=" << area << endl;
 
    return 0;
}
