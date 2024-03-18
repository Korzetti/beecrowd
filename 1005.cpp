#include <iostream>
#include <iomanip>

using namespace std;

double A, B, MEDIA;
int main(){
	cin >> A >> B;
	MEDIA = (A * 3.5 + B * 7.5) / 11;
	
	if (MEDIA > 10){
		MEDIA = 10;
	}
	
	cout << fixed << showpoint;
	cout << setprecision(5);
	cout << "MEDIA = " << MEDIA << endl;
	
	return 0;
}
