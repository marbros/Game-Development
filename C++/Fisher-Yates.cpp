#include <iostream>
#include <math.h>

using namespace std;

int someArray[9] = {1,2,3,4,5,6,7,8,9};
int theLength = someArray.size() - 1;
int toSwap;
int temp;

int main() {

	for (int i = theLength; i > 0; i--) { 
	    toSwap = Math.floor(math.random() * i);
	    temp = someArray[i];
	    someArray[i] = someArray[toSwap];
	    someArray[toSwap] = temp;
	}	
	return 0;
}

