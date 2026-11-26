#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <math.h>

void task_919();
void task_924();
void task_968();
void task_1001();
void task_1015();

int main()
{
	int taskNumber;
	while (1)
	{
		printf("Enter task number (919, 924, 968, 1001, 1015) or 0 to exit: ");
		if (scanf_s("%d", &taskNumber) != 1)
		{
			printf("Invalid input. Please enter a valid task number.\n");
			while (getchar() != '\n');
			continue;
		}
		if (taskNumber == 0)
		{
			printf("Exiting the program.\n");
			break;
		}
		switch (taskNumber)
		{
		case 919:
			task_919();
			break;
		case 924:
			task_924();
			break;
		case 968:
			task_968();
			break;
		case 1001:
			task_1001();
			break;
		case 1015:
			task_1015();
			break;
		default:
			printf("Invalid task number. Please try again.\n");
		}
	}

	return 0;
}

void task_919()
{
	printf("Task 919.\n");

	int rows = 0;
	int cols = 0;

	while (1)
	{
		printf("Enter number of rows: ");
		if (scanf_s("%d", &rows) != 1)
		{
			printf("Invalid input. Please enter a valid number of rows.\n");
			while (getchar() != '\n');
			continue;
		}
		if (rows <= 0)
		{
			printf("Number of rows must be a positive integer.\n");
			continue;
		}
		break;
	}

	while (1)
	{
		printf("Enter number of columns: ");
		if (scanf_s("%d", &cols) != 1)
		{
			printf("Invalid input. Please enter a valid number of columns.\n");
			while (getchar() != '\n');
			continue;
		}
		if (cols <= 0)
		{
			printf("Number of columns must be a positive integer.\n");
			continue;
		}
		break;
	}

	int** matrix = (int**)malloc(rows * sizeof(int*));
	if (matrix == NULL) 
	{
		printf("Memory allocation error!\n");
		return;
	}

	for (int i = 0; i < rows; i++)
	{
		matrix[i] = (int*)malloc(cols * sizeof(*matrix[i]));
		if (matrix[i] == NULL)
		{
			printf("Memory allocation error!\n");
			return;
		}
	}

	printf("Enter the elements of the matrix:\n");			
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("Enter element [%d][%d]: ", i, j);
			if (scanf_s("%d", &matrix[i][j]) != 1 )
			{
				printf("Invalid input. Please enter a valid integer.\n");
				while (getchar() != '\n');
				j--;
			}
		}
	}

	printf("Initial matrix\n");
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < cols; j++) 
		{
			printf("%4d", matrix[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < rows / 2; i++) 
	{
		int symetryk_row = rows - 1 - i;
		for (int j = 0; j < cols; j++) 
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[symetryk_row][j];
			matrix[symetryk_row][j] = temp;
		}

	}

	printf("Matrix after row swapping\n");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%4d", matrix[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < rows; i++)
	{
		free(matrix[i]);
	}
	free(matrix);

	return;
}

void task_924() //Знайти максимальний елемент серед мінімальних елементів стовпців двовимірного масиву. Визначити номер рядка та стовпця для такого елемента.
{
	printf("Task 924.\n");

	int rows = 0;
	int cols = 0;

	while (1)
	{
		printf("Enter number of rows: ");
		if (scanf_s("%d", &rows) != 1)
		{
			printf("Invalid input. Please enter a valid number of rows.\n");
			while (getchar() != '\n');
			continue;
		}
		if (rows <= 0)
		{
			printf("Number of rows must be a positive integer.\n");
			continue;
		}
		break;
	}

	while (1)
	{
		printf("Enter number of columns: ");
		if (scanf_s("%d", &cols) != 1)
		{
			printf("Invalid input. Please enter a valid number of columns.\n");
			while (getchar() != '\n');
			continue;
		}
		if (cols <= 0)
		{
			printf("Number of columns must be a positive integer.\n");
			continue;
		}
		break;
	}

	int** matrix = (int**)malloc(rows * sizeof(int*));

	if (matrix == NULL) 
	{
		printf("Memory allocation error!\n");
		return;
	}

	for (int i = 0; i < rows; i++)
	{
		matrix[i] = (int*)malloc(cols * sizeof(*matrix[i]));

		if (matrix[i] == NULL) {
			printf("Memory allocation error!\n");
			return;
		}
	}

	printf("Enter the elements of the matrix:\n");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("Enter element [%d][%d]: ", i, j);
			if (scanf_s("%d", &matrix[i][j]) != 1 )
			{
				printf("Invalid input. Please enter a valid integer.\n");
				while (getchar() != '\n');
				j--;
			}
		}
	}

	printf("Initial matrix\n");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%4d", matrix[i][j]);
		}
		printf("\n");
	}

	int max_of_mins = INT_MIN;
	int res_row = -1;
	int res_col = -1;

	for (int j = 0; j < cols; j++) 
	{
		int min_in_col = matrix[0][j]; 
		int min_row_idx = 0;           

		for (int i = 1; i < rows; i++)
		{
			if (matrix[i][j] < min_in_col)
			{
				min_in_col = matrix[i][j];
				min_row_idx = i;
			}
		}

		
		if (min_in_col > max_of_mins)
		{
			max_of_mins = min_in_col;
			res_row = min_row_idx; 
			res_col = j;           
		}
	}

	printf("\nResult\n");
	printf("The maximum element among the column minima: %d\n", max_of_mins);
	printf("Its coordinates: row %d, column %d\n", res_row, res_col);

	for (int i = 0; i < rows; i++)
	{
		free(matrix[i]);
	}
	free(matrix);

	return;
}

void task_968() 
{
	printf("Task 968.\n");

	#define ROWS 20
	#define COLS 10
	srand(time(NULL));

	int grades[ROWS][COLS];

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			grades[i][j] = rand() % 100 + 1;
		}
	}

	int student_index = 4;

	printf("Grades of the 5th student:\n");
	for (int j = 0; j < COLS; j++)
	{
		printf("%d ", grades[student_index][j]);
	}
	printf("\n\n");

	int sum = 0;
	for (int j = 0; j < COLS; j++) {
		sum += grades[student_index][j];
	}

	double average = (double)sum / COLS;
	printf("Average grade of the 5th student: %.2f\n", average);
	printf("\n");

	return;
}

int get_triangle_size(int n)
{
	return n * (n + 1) / 2;
}

void task_1001() 
{
	printf("Task 1001.\n");

	int N = 0;
	while (1) 
	{
		printf("Enter the dimension of the square matrix (N): ");
		if (scanf_s("%d", &N) != 1 || N <= 0) 
		{
			printf("Invalid input. Please enter a valid number for N.\n");
			while (getchar() != '\n');
			continue;
		
		}
		break;
	}
	
	int size_1d = get_triangle_size(N);
	int* upper_triangle = (int*)malloc(size_1d * sizeof(int));

	if (upper_triangle == NULL) 
	{
		printf("Memory allocation error (1D)!\n");
		return;
	}

	for (int k = 0; k < size_1d; k++) 
	{
		upper_triangle[k] = k + 1;
	}

	int** matrix = (int**)malloc(N * sizeof(int*));

	if (matrix == NULL) 
	{
		printf("Memory allocation error (2D)!\n");
		free(upper_triangle); 
		return;
	}
	for (int i = 0; i < N; i++) 
	{
		matrix[i] = (int*)malloc(N * sizeof(int));
		if (matrix[i] == NULL)
		{
			printf("Memory allocation error (row %d)!\n", i);
			return;
		}
	}

	int k = 0;
	for (int i = 0; i < N; i++) 
	{
		for (int j = i; j < N; j++) 
		{
			int val = upper_triangle[k];
			matrix[i][j] = val;
			matrix[j][i] = val; 
			k++;
		}
	}

	printf("\nRestored matrix\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) 
		{
			printf("%4d ", matrix[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < N; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
	free(upper_triangle);

	return;
}

void task_1015() 
{
	printf("Task 1015.\n");

	int rows = 0;
	int cols = 0;

	while (1)
	{
		printf("Enter number of rows: ");
		if (scanf_s("%d", &rows) != 1)
		{
			printf("Invalid input. Please enter a valid number of rows.\n");
			while (getchar() != '\n');
			continue;
		}
		if (rows <= 0)
		{
			printf("Number of rows must be a positive integer.\n");
			continue;
		}
		break;
	}

	while (1)
	{
		printf("Enter number of columns: ");
		if (scanf_s("%d", &cols) != 1)
		{
			printf("Invalid input. Please enter a valid number of columns.\n");
			while (getchar() != '\n');
			continue;
		}
		if (cols <= 0)
		{
			printf("Number of columns must be a positive integer.\n");
			continue;
		}
		break;
	}

	if (rows != cols)
	{
		printf("\nError: The matrix is NOT orthonormal!\n");
		printf("Reason: An orthonormal matrix must be square (rows must equal columns).\n");
		return;
	}

	double** matrix = (double**)malloc(rows * sizeof(double*));

	if (matrix == NULL) 
	{
		printf("Memory allocation error!\n");
		return;
	}

	for (int i = 0; i < rows; i++)
	{
		matrix[i] = (double*)malloc(cols * sizeof(double));
		if (matrix[i] == NULL) 
		{
			printf("Memory allocation error!\n");
			return;
		}
	}

	printf("Enter the elements of the matrix:\n");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("Enter element [%d][%d]: ", i, j);
			if (scanf_s("%lf", &matrix[i][j]) != 1)
			{
				printf("Invalid input. Please enter a valid integer.\n");
				while (getchar() != '\n');
				j--;
			}
		}
	}

	printf("Matrix\n");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%6.4lf  ", matrix[i][j]);
		}
		printf("\n");
	}


	int is_orthonormal = 1; 
	double eps = 0.000001; 

	
	for (int i = 0; i < rows; i++)
	{
		for (int j = i + 1; j < rows; j++)
		{
			double dot_product = 0.0;
			for (int k = 0; k < cols; k++)
			{
				dot_product += matrix[i][k] * matrix[j][k];
			}

			if (fabs(dot_product) > eps)
			{
				is_orthonormal = 0;
				break;
			}
		}
		if (!is_orthonormal)
			break;
	}

	if (is_orthonormal)
	{
		for (int i = 0; i < rows; i++)
		{
			double norm = 0.0;
			for (int k = 0; k < cols; k++)
			{
				norm += matrix[i][k] * matrix[i][k];
			}


			if (fabs(norm - 1.0) > eps)
			{
				is_orthonormal = 0;
				break;
			}
		}
	}

	printf("\nReult\n");
	if (is_orthonormal) 
	{
		printf("The matrix is ​​orthonormal.\n");
	}
	else 
	{
		printf("The matrix is ​​NOT orthonormal.\n");
	}

	for (int i = 0; i < rows; i++) 
	{
		free(matrix[i]);
	}
	free(matrix);

	return;
}