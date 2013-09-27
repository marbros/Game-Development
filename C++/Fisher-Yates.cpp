#include <iostream>
#include <cmath.h>

using namespace std;

int someArray[9] = {1,2,3,4,5,6,7,8,9};
int theLength = someArray.size() - 1;
int toSwap;
int temp;

void drawCards() {

}

 void shuffle() {
        cout << "Cards before shuffle:" << cards;
        for (int i = theLength; i > 0; i--) {
            toSwap = math.floor(math.random() * i);
            tempCard = cards[i];
            cards[i] = cards[toSwap];
            cards[toSwap] = tempCard;
        }
        cout << "Cards after shuffle: " << cards;
        drawCards();
    }

int main() {

	for (int i = theLength; i > 0; i--) { 
	    toSwap = math.floor(math.random() * i);
	    temp = someArray[i];
	    someArray[i] = someArray[toSwap];
	    someArray[toSwap] = temp;
	}	
	return 0;
}

