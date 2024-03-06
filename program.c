#include <stdio.h>
#include <stdlib.h>

/*
GOALS OF THE PROGRAM:
1. Allow the user to input the number of students (max 50)
2. Allow the user to input the grades of the students (0 - 100)
3. Calculate and display the average grade of the students
4. Display the students who are above average
5. At the end of function, free the dynamically allocated memory to prevent memory leaks
6. Test the program with different test cases to ensure it is working as expected
(Test cases are at the end of this file)
*/

// Function to input the grades of the students
void	inputGrades(int grades[], int n)
{
	int	i;
	int result;

	i = 0;
	while (i < n)
	{
		printf("Enter grade for student %d: ", i + 1);
		result = scanf("%d", &grades[i]);

		// Check if the input is valid
		// If a user inputs a valid integer, scanf will return 1 
		// If the user enters a character, scanf will return 0
		if (result == 1)
		{
			// Check if the grade is valid (between 0 and 100)
			if (grades[i] < 0 || grades[i] > 100)
			{
				printf("Invalid grade. Please enter a valid grade between 0 and 100\n");
			}
			else
			{
				i++;
			}
		}
		else
		{
			printf("Invalid input. Please enter a valid grade between 0 and 100\n");

			// Clear the input buffer to prevent an infinite loop
			while (getchar() != '\n');
		}
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

	// Calculate the sum of all the grades
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
	int	count;

	i = 0;
	count = 0;
	printf("The students who are above average:\n");

	// Display the students who are above average
	while (i < n)
	{
		// If the grade is above average, display the student number and the grade
		if (grades[i] > average)
		{
			count++;
			printf("- Student %d: %d\n", i + 1, grades[i]);
		}
		i++;
	}
	if (count == 0)
	{
		printf("There are no students who are above average\n");
	}
}

int	main(void)
{
	int		n;
	float	average;
	int		*grades;
	int		result;

	n = 0;
	while (n < 1 || n > 50)
	{
		printf("Enter the number of students (max 50): ");
		result = scanf("%d", &n);

		// Check if the number of students is valid (between 1 and 50)
		// If a user inputs an invalid integer, scanf will return 0
		if (result == 0)
		{
			printf("Invalid input. Please enter a valid number between 1 and 50\n");

			// Clear the input buffer to prevent an infinite loop
			while (getchar() != '\n');
		}
		else if (n < 1 || n > 50)
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

	// Free the dynamically allocated memory to prevent memory leaks
	free(grades);

	return (0);
}

/*
---------------Test Cases-----------------
Test Case 1 - Normal Input:
1. Enter the number of students as 5
2. Enter the grades of the students as 90, 80, 70, 60, 50
3. The average grade is 70
4. The students who are above average are:
	- Student 1: 90
	- Student 2: 80
5. The program should display the above output

Test Case 2 - Invalid number of students:
1. Enter the number of students as -1
2. The program should display "Invalid number of students. Please enter a number between 1 and 50"
3. Enter the number of students as 51
4. The program should display "Invalid number of students. Please enter a number between 1 and 50"

Test Case 3 - Invalid grades:
1. Enter the number of students as 3
2. Enter the grades of the students as 90, 101
3. The program should display "Invalid grade. Please enter a valid grade between 0 and 100"
4. Enter the grades of the students as 90, -1
5. The program should display "Invalid grade. Please enter a valid grade between 0 and 100"
6. Enter the grades of the students as 90, 80, 70
7. The average grade is 80
8. The students who are above average are:
	- Student 1: 90
	- Student 2: 80
	- The program should display the above output

Test Case 4 - Edge Case:
1. Enter the number of students as 1
2. Enter the grade of the student as 100
3. The average grade is 100
4. The students who are above average are: 
	- The program should display "There are no students who are above average"

Test Case 5 - All students have the same grade:
1. Enter the number of students as 5
2. Enter the grades of the students as 80, 80, 80, 80, 80
3. The average grade is 80
4. The students who are above average are:
	- The program should display "There are no students who are above average"

Test Case 6 - the input is a character:
1. Enter the number of students as a
2. The program should display "Invalid input. Please enter a valid number between 1 and 50"
3. Enter the number of students as 3
4. Enter the grades of the students as 90, b
5. The program should display "Invalid input. Please enter a valid grade between 0 and 100"
*/
