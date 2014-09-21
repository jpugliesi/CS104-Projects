/*
 * Try all combinations and find the one that gives 
 * the maximum learning without exceeding work capacity. 
 */
double findMaxLearning(double work[], double learning[], int classCount, double workSoFar, double learningSoFar, double maxWork, double &maxLearning)
{
	// Look through all the classes from 0 to the given max.
	for(int i = 0; i < classCount; i++)			
	{

		workSoFar = workSoFar + work[i];	
		learningSoFar = learningSoFar + learning[i];

		// If adding that class doesn't exceed maximum work, then try adding it.
		// Otherwise we'll stop exploring this combination branch.
		if (workSoFar <= maxWork)			
		{
			// If adding this class increases the maximum learning, set it as the new maximum learning.
			if(learningSoFar > maxLearning)
				maxLearning = learningSoFar;
		
			// Recurse on all classes up to this class.
			findMaxLearning (work, learning, i, workSoFar, learningSoFar, maxWork, maxLearning); 
		}

		// Undo the calculations so we can try again on a different class.
		workSoFar = workSoFar - work[i];	
		learningSoFar = learningSoFar - learning[i];
	}

	return maxLearning;
}
