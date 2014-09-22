/*
 * ClassSelection.cpp
 *
 *  Created on: Sep 21, 2014
 *      Author: kempe
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* Our solution uses a number of global variables.
 * We could instead pass all of these values into the search function every time,
 * but that would create a lot of arguments. We think that this may be easier to
 * understand, even if it's slightly worse style.
 */

int n;  // number of classes in the input
double W;  // our work budget

string* name; // array for the names of classes
double* work; // array for the work amounts of classes
double* learning; // array for the learning of classes

double search (int currentClass, double currentWork, double currentLearning)
/* This is the recursive function. When it is called, currentClass is the next
 * class to evaluate for addition. At this point, we've made (temporary) commitments
 * for all classes with lower indices, which resulted in the given currentWork and
 * currentLearning values. The job of the search function is to (using recursion) try all
 * possible combinations of classes to take with indices currentClass ... (n-1).
 */
{
	if (currentWork < W) // so far, we haven't exceeded the work "budget"
	{
		if (currentClass == n)
			// we've made decisions for all classes already - this is the base case
			return currentLearning;
		else // at least one more class to make decisions for
			return max (search (currentClass + 1, currentWork, currentLearning),
					search (currentClass + 1, currentWork+work[currentClass], currentLearning+learning[currentClass]));
			/* recursive calls for trying the decisions for the next class.
			 * There are two options: don't take the currentClass, or take it.
			 * In the former case, no work or learning is added, and we continue (recursively) exploring
			 * options from the next class onward.
			 * In the latter case, we add the amount of work and learning for the current class, and
			 * recursively explore all the options for the remaining classes.
			 * We then take the better of those two options and return it.
			 */
	}
	else return 0;
	/* this is the return value for infeasible solutions, so we don't accidentally
	 * take on some arbitrary way too large values. */
}

int main (int numparams, char* params[])
{
	if (numparams == 2)
	{
		filebuf fb;
		if (fb.open(params[1], ios::in))
		{
			istream iS (&fb);
			iS >> n >> W; // reading basic problem parameters
			cout << n << " " << W << "\n";

			// allocating memory for classes and reading them
			name = new string [n];
			work = new double [n];
			learning = new double [n];
			for (int i = 0; i < n; i ++)
				iS >> name[i] >> work[i] >> learning [i];
			for (int i = 0; i < n; i ++)
				cout << name[i] << " " << work[i] << " " << learning[i] << "\n";

			/* this starts the recursion. We will first try class 0, and have a total
			learning and work of 0 from classes numbered lower than 0 (because there are no such classes). */
			cout << "Best Learning: " << search (0, 0, 0) << "\n";

			// deallocating memory for classes and closing file
			delete [] name;
			delete [] work;
			delete [] learning;
			fb.close ();
			return 0;
		}
		else
		{
			cout << "Could not open file\n";
			return 1;
		}
	}
	else
	{
		cout << "Usage: ClassSelection <filename>\n";
		return 1;
	}
}
