# Student Grades Analyzer

The program's goal is to help educators analyze students' performance.

## Features

- Input the number of students (up to a maximum of 50).
- Input individual grades for each student (grades must be between 0 and 100).
- Calculate and display the average grade of the class.
- List the students who have grades above the class average.
- Ensure memory allocated for storing grades is properly freed to prevent leaks.

## How to Run

Ensure you have a C compiler installed (like GCC). Compile the program using:

```bash
cc program.c -o program
```

Then run the compiled program:

```bash
./program
```

## Usage

1. When prompted, enter the number of students. The number must be between 1 and 50.
2. Enter the grade for each student as prompted. Each grade should be between 0 and 100. If an invalid grade is entered, the program will ask for the grade again.
3. After all grades are entered, the program will display the average grade and a list of students performing above average.

## Testing

### Test Case 1 - Normal Input
- Enter the number of students as 5.
- Enter the grades as 90, 80, 70, 60, 50.
- Expected: The average should be 70. Students 1 and 2 should be listed as above average.

### Test Case 2 - Invalid Number of Students
- Enter -1 or 51 when prompted for the number of students.
- Expected: The program should request a valid number between 1 and 50.

### Test Case 3 - Invalid Grades
- Enter a grade over 100 or below 0 when prompted.
- Expected: The program should ask again for a valid grade between 0 and 100.

### Test Case 4 - Edge Case with Single Student
- Enter the number of students as 1 and grade as 100.
- Expected: The average should be 100, with no students listed as above average.

### Test Case 5 - Identical Grades
- Enter the same grade for all students.
- Expected: No students should be listed as above average.

### Test Case 6 - Character Input
- Enter a non-integer when prompted for the number of students or grades.
- Expected: The program should reject the input and ask again for a valid number.

## Contributions

Feel free to fork this repository and submit pull requests to enhance the functionalities or improve the user experience. For major changes, please open an issue first to discuss what you would like to change.
