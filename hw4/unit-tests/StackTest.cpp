#include <iostream>
#include "INSERT YOUR LIST STACK IMPLEMENTATION'S HEADER HERE"
#include "INSERT YOUR ARRAY STACK IMPLEMENTATION'S HEADER HERE"
using namespace std;

/* Test that an empty stack is truly empty */
void testEmptyStack(IStack<int>* s) {
	if (s->isEmpty()) {
		cout << "Pass: Stack is empty and it should be, yay!" << endl;
	}
	else {
		cout << "Fail: Stack was not empty and it should be :(" << endl;
	}

	try {
		s->top();
		cout << "Fail: Top on an empty stack did not throw an ExmptyStackException, and it should have." << endl;
	}
	catch (const EmptyStackException& e) {
		cout << "Pass: Top threw an EmptyStackException as it should. Nice work!" << endl;
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
			cout << "Fail: Adding 5 items to the stack.. Top isn't what it should be." << endl;
		}
		s->pop();
	}
	// Stack should now be empty
	testEmptyStack(s);
}

int main() {
	// A nice motivational graphic.
    cout << " test ALL the things!!!" << endl; //... but these actually aren't exhaustive... add your own stuff)
    cout << "              ...                                    .=..       ...:=.         " << endl;
    cout << "              .:+:..                                  O8     .  .:==..         " << endl;
    cout << "              ..=+=~..      ....     .,.          .    7. ...,~+++:...         " << endl;
    cout << "              ..~+++=:.     .,=.     .=:         ..:=~.=..~++++++,.. .         " << endl;
    cout << "               .,=++++=:..  ..+=.....~+=.     ..,~++:.:~=++++++=..             " << endl;
    cout << "              . .~+++++++~...,+++,...=++.. .  .=+++~,~I+++++++=...             " << endl;
    cout << "                 ,+++++++++~.,++++~.:+++:. .,=++++++++7=+++++=.                " << endl;
    cout << "                ..=++++++++++~+++++==+++~.:=++++++++++Z+++++~. .               " << endl;
    cout << "      ....       ..+++++++++++++=?OZ+~=8?+++++=7$+++++Z++++=.                  " << endl;
    cout << "    . .::,...     .~++++++++++++Z7::,:,,,$+++I?...O++=7+++=..                  " << endl;
    cout << "     .  ,=+=:..    .=+++++++++++++=8+O?......O~. .Z++=?++=...                  " << endl;
    cout << "         .,=++=:... ,++++++++++++IZ,  ....7$$,O87Z,?+?=++,                     " << endl;
    cout << "   ...    ..~++++=~..~+++++++++8...O..~M.7NNMM+.  .:+$=+~.                     " << endl;
    cout << "  .=O:$..  ..:+++++++++++++++++8...OO.7MMMMMMMM,    $Z+=..            .   ..,. " << endl;
    cout << "+78=:::+= ... :++++++++++++++++++8~Z=MMMMMMMMMM8.   =Z+,.......     ...,:=+=,. " << endl;
    cout << "+O:::::::D .. ..~++++++++++++++++Z .DMMMMMMMMMMM    ?7=:~==++~......:=+++=,.   " << endl;
    cout << "=~::::::::O..,=++++++++++++++++++++...MMMMMMMMMM    D?+++++=....,~=++++~. ..   " << endl;
    cout << ".I,:::::::~=...~++++++++++++++++++?: ..7MMMMMMM$. . Z8=+++~..:=++++++:..       " << endl;
    cout << "  7::::::::7.. .,=+++++++++++++++++Z:..:MMMMMMO=.. OI7?++=~+++++++=,..         " << endl;
    cout << "  .+I::~+$8.. ....:+++++++++++++=IZ=O..,?+D8O,7,..I77IO+++++++++=,..           " << endl;
    cout << "   ....  DOO+.,::==+++++++++++=O++++=D .. ..  .. ,Z777Z++++++++:...            " << endl;
    cout << "        .:$OOO=++++++++++++=$7=++++++=M?.   . .?O7777777+++++=..               " << endl;
    cout << "  .........~DOD=++++++++=+8=+++++++++++$I77777I7777777I8++++~,:,,,,,..........." << endl;
    cout << "    :+++++=~,DO8I++++++O+++++++++++++++$7777777777777777?++++++++++++++++++=,. " << endl;
    cout << "    .:++++++++$OOO+=IZ=+++++++++++++++++OI7777777777777IO+++++++++++++++++++=:." << endl;
    cout << "    ..~+++++++++DOM=++++++++++++++++++++?777777777777777Z++++++++++++++=~,..  ." << endl;
    cout << "     ..=++++++++=DOO?+++++++++++++++++++=8I77777777777777+++++++++=~,.. .    . " << endl;
    cout << "     . .=+++++++++$OOZ++++++++++++++++++=8777777777777777?+++++=,... .         " << endl;
    cout << "        .=++++++++++8OD=+++++++++++++++++$777777777777777?++=,..               " << endl;

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