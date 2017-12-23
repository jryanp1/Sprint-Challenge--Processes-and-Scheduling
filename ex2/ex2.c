int **alloc_2d(int rows, int cols)
{
  int i, j;
  for(i = 0; i < rows; i++) {
    for(j = 0; j < 100; j++) {
	     columns[i][j] = i * j;
    }
  }
}

void alloc_2d_example(void)
{
	int **my_array = alloc_2d(5, 10);

	// First array index is row, second is column:
	my_array[2][3] = 3490;

	// The same array access could be made with pointer arithmetic:
	*(*(my_array+2)+3) = 3490;

	// By the C spec, the array notation and pointer arithmetic notation
	// are 100% equivalent.

	printf("my_array[2][3] = %d\n", my_array[2][3]);
}
