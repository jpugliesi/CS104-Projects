#include <iostream>
#include "INSERT YOUR LIST STACK IMPLEMENTATION'S HEADER HERE"
#include "INSERT YOUR ARRAY STACK IMPLEMENTATION'S HEADER HERE"
using namespace std;

/* Test that an empty stack is truly empty */
void testEmptyStack(IStack<int>* s) {
	if (s->isEmpty()) {
		cout << "Stack is empty and it should be, yay!" << endl;
	}
	else {
		cout << "Failed. Stack was not empty and it should be :(" << endl;
	}

	try {
		s->top();
		cout << "Top on an empty stack did not throw and it should have." << endl; //TODO: check with below
	}
	catch (const exception& e) { //TODO: check if should throw and if there's a specific type
		cout << "Top threw and it should throw. Nice work!" << endl;
	}
}

/* Test pushing/popping n items */
void testPushPop(IStack<int>* s, int n) {
	for (int i = 0; i < n; ++i) {
		s->push(i);
	}
	cout << "Testing that pushed items actually go to the top, and the size is changing..." << endl;
	for (int i = n-1; i >= 0; --i) {
		if (s->isEmpty() || (s->top() != i)) {
			cout << "Failed adding 5 items to the stack.. Top isn't what it should be." << endl;
		}
		s->pop();
	}
	// Stack should now be empty
	testEmptyStack(s);
}

int main() {
	// A nice motivational graphic. Note: Please resize your terminal window to be >=86 chars wide... Sorry it's not standard but it'll be worth it..

    cout << " test ALL the things!!!                                                               " << endl;
    //... but these actually aren't exhaustive... add your own stuff)
    cout << "                 ,:,                                       *#:          ,:.,          " << endl;
    cout << "                 ,:,                                       *#:          ,:.,          " << endl;
    cout << "                 ,::,                                       +,        ,.::,,          " << endl;
    cout << "                 ,.::.,         ,,         ,                       ,,.:::.            " << endl;
    cout << "                  .:::.,         .        ,.             ,,,,    ,,.::::,             " << endl;
    cout << "                  ,::::.,       ,:,       ..            ,.:,.  ,.::::::.              " << endl;
    cout << "                  ,::::::,       .:,     ,::          ,.::.,*,,::::::::,              " << endl;
    cout << "                   .::::::.,     .::,    .::,        ,.::., W.::::::::,               " << endl;
    cout << "                   ,:::::::.,,  ,.::.   ,:::,      ,,::::,,,W::::::::.                " << endl;
    cout << "                   ,:::::::::.,  .:::, ,,:::.     ,.::::..::@:::::::.                 " << endl;
    cout << "                    .:::::::::., .::::, ,::::    ,.:::::::::+:::::::,                 " << endl;
    cout << "                    ,::::::::::.,.:::::,,::::  ,,::::::::::::::::::,                  " << endl;
    cout << "                    ,:::::::::::.:::::::.::::,,.:::::::::::..:::::.                   " << endl;
    cout << "                     .::::::::::::::::..+@@.:.:::::::::::::.::::::,                   " << endl;
    cout << "                     ,::::::::::::::.W.,,,,,W.::::::@:W::::.:::::.                    " << endl;
    cout << "        ,.,,         ,:::::::::::::@#,,,,,,,.W:::::+ ,,@:::+:::::,,                   " << endl;
    cout << "        ,,::.,       ,.::::::::::::::::,,,,,,@@@#*W ,  ::::#::::.                     " << endl;
    cout << "          ,:::.,      ,:::::::::::::::.W,W: ,  ,  W,  ,*:::@:::.,                     " << endl;
    cout << "           ,::::.,    ,.::::::::::::::.W ,       ,##,  @.::W:::,                      " << endl;
    cout << "            ,.::::.,   ,::::::::::::*W@      ,W@@@,*W@,,W::#::.,                      " << endl;
    cout << "     ,,      ,::::::,,, :::::::::::W  ,:,, ,W:,   W,    ,.::::,                       " << endl;
    cout << "     + ,      ,:::::::.,.:::::::::.,: ,@  W  WWWWWW#     W.:::,                       " << endl;
    cout << "     *,@       ,::::::::::::::::::.:   W@ +WWWWWWWWW      ..:.                     ,, " << endl;
    cout << "     ...#,      .::::::::::::::::::#  .+,WWWWWWWWWWW     ,.::,                  ,,.., " << endl;
    cout << "  .@,...,:      ,.::::::::::::::::::.+ **WWWWWWWWWWWW,   ,+:.    ,,,,        ,,.::.,  " << endl;
    cout << " ,+.......#,,    ,:::::::::::::::::::W +WWWWWWWWWWWWW,    W:.,,,..::,     ,,.::::.,   " << endl;
    cout << " ,,........*   ,,,,.:::::::::::::::::+ ,.WWWWWWWWWWWW    ,W:.::::::,  , ,,.:::::,     " << endl;
    cout << " ,,........,*  ,.::::::::::::::::::::* ,  WWWWWWWWWWW,   *@:::::::,   ,,.:::::.,      " << endl;
    cout << "  W,........+,  ,:::::::::::::::::::::W,   WWWWWWWWWW,   W#.:::::, ,,.:::::::.,       " << endl;
    cout << " ,,.........,,   ,::::::::::::::::::::.     WWWWWWWW#   ,@+.::::. ,.::::::::,,        " << endl;
    cout << "   W.........W    ,::::::::::::::::::::W,   WWWWWWWW ,   *+@:::.,.::::::::.,          " << endl;
    cout << "   ,W,.......+   , ,:::::::::::::::::::,:  ,WWWWWWW,W   @++@:::.:::::::::,            " << endl;
    cout << "    ,....,.,W,      ,::::::::::::::::.W.W   :#WWWW,. , ,*+++:::::::::::.,             " << endl;
    cout << "      *W@@W##W,     ,,::::::::::::::#::::,,  #WW###:   #+++++:::::::::.,              " << endl;
    cout << "        ,  W##*,,,...:::::::::::::.@.::::W   ,   ,,,, ,*++++@::::::::.                " << endl;
    cout << "           ,@##.:::::::::::::::::W:::::::.@,,      ,  @+++++#:::::::.,                " << endl;
    cout << "          ,..###.::::::::::::::*:::::::::::W+ ,,  ,,@+++++++*.:::::.,                 " << endl;
    cout << "           ,,+##@.:::::::::::.@:::::::::::.*+**@@@***++++++++:::::.,,,,,,, ,          " << endl;
    cout << "    ,,....,, ,###W:::::::::.W.:::::::::::::@+++++++++++++++++@:::::::::........,,,   ," << endl;
    cout << "     ,::::::.,,@##W:::::::*::::::::::::::::.*++++++++++++++++@::::::::::::::::::::.,, " << endl;
    cout << "      ,:::::::::W##*::::.@::::::::::::::::::@++++++++++++++++*.:::::::::::::::::::::.," << endl;
    cout << "      ,.::::::::.@##:::@.:::::::::::::::::::++++++++++++++++++::::::::::::::::::::::.," << endl;
    cout << "       ,:::::::::.###*::::::::::::::::::::::.*++++++++++++++++@:::::::::::::::::.,,,  " << endl;
    cout << "      ,,.::::::::::#@@.::::::::::::::::::::::@++++++++++++++++@::::::::::::::.,,      " << endl;
    cout << "        ,::::::::::*##@.:::::::::::::::::::::+++++++++++++++++*:::::::::::.,,         " << endl;
    cout << "        ,.::::::::::@#*W:::::::::::::::::::::+++++++++++++++++*::::::::..,            " << endl;
    cout << "         ,:::::::::::W###::::::::::::::::::::*++++++++++++++++*::::::.,,              " << endl;
    cout << "          ,:::::::::::@##.:::::::::::::::::::#++++++++++++++++*.:::.,                 " << endl;
    cout << "          ,.::::::::::.###.::::::::::::::::::@++++++++++++++++*.::.,                  " << endl;
    cout << "           ,.:::::::::::*#@.:::::::::::::::::@++++++++++++++++*.:::.,                 " << endl;
    cout << "            ,.::::::::::*##W:::::::::::::::::*++++++++++++++++*.:::::,                " << endl;

	IStack<int>* list_stack = new ListStack<int>;
	IStack<int>* array_stack = new ArrayStack<int>;
	cout << "Testing the ListStack implementation." << endl;
	// New stack should be empty
	testEmptyStack(list_stack);
	// Try adding/removing 1 item
	testPushPop(list_stack, 1);
	// Try adding/removing 5 items
	testPushPop(list_stack, 5);
	cout << "Done." << endl;

	cout << "Testing the ArrayStack implementation." << endl;
	testEmptyStack(array_stack);
	testPushPop(array_stack, 1);
	testPushPop(array_stack, 5);	
	cout << "Done." << endl;

	delete list_stack;
	delete array_stack;

	return 0;
}