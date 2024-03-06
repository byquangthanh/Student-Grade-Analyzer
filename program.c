#include <stdio.h>
#include <stdlib.h>

/*
GOALS OF THE PROGRAM:
1. Allow the user to input the number of students (max 50)
2. Allow the user to input the grades of the students (0 - 100)
3. Calculate and display the average grade of the students
*/


void	inputGrades(int grades[], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("Enter grade for student %d: ", i + 1);
		scanf("%d", &grades[i]);

		// Check if the grade is valid (between 0 and 100)
		if (grades[i] < 0 || grades[i] > 100)
		{
			printf("Invalid grade. Please enter a valid grade between 0 and 100\n");
			continue;
		}

		// Break the loop if -1 is entered as the grade
		if (grades[i] == -1)
		{
			break ;
		}
		i++;
	}
}

// Function to calculate the average grade
float	calculateAverage(int grades[], int n)
{
	int		i;
	float	average;
	float	sum;

	i = 0;
	sum = 0;
	while (i < n)
	{
		sum = sum + grades[i];
		i++;
	}
	average = sum / n;
	return (average);
}

// Function to display students above average
void	displayAboveAverage(int grades[], int n, float average)
{
	int	i;

	i = 0;
	printf("The students who are above average:\n");
	while (i < n)
	{
		if (grades[i] > average)
		{
			printf("- Student %d: %d\n", i + 1, grades[i]);
		}
		i++;
	}
}

int	main(void)
{
	int		n;
	float	average;
	int		*grades;

	n = 0;
	while (n < 1 || n > 50)
	{
		printf("Enter the number of students (max 50): ");
		scanf("%d", &n);
		if (n < 1 || n > 50)
		{
			printf("Invalid number of students. Please enter a number between 1 and 50\n");
		}
	}
	// Allocate memory for the grades array dynamically
	grades = malloc(n * sizeof(int));

	inputGrades(grades, n);
	average = calculateAverage(grades, n);

	printf("Average grade: %f\n", average);
	displayAboveAverage(grades, n, average);

	// Free the dynamically allocated memory
	free(grades);

	return (0);
}
