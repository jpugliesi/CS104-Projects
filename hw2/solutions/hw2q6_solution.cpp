/*
 * Try all combinations and find the one that gives 
 * the maximum learning without exceeding work capacity. 
 */
double findMaxLearning(double work[], double learning[], int classCount, double workSoFar, double learningSoFar, double maxWork, double &maxLearning)
{
	for(int i = 0; i < classCount; i++)			
	{

		workSoFar = workSoFar + work[i];	
		learningSoFar = learningSoFar + learning[i];

		if (workSoFar <= maxWork)			
		{
			if(learningSoFar > maxLearning)
				maxLearning = learningSoFar;
		
			findMaxLearning (work, learning, i, workSoFar, learningSoFar, maxWork, maxLearning); 
		}

		workSoFar = workSoFar - work[i];	
		learningSoFar = learningSoFar - learning[i];
	}

	return maxLearning;
}
