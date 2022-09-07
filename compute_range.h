#include <stdio.h>

void compute_range(char *buffer_range, int* reading, int size);
void write_data_to_file(char* buffer_range, int head, int tail, int range);
int get_next_reading(int index, int size, int* reading);
void getRanges(char* buffer_range, int* reading, int size);
void getHead(int range_count, int head, int* head_reading);
void evaluateRange(char* buffer_range, int* reading, int size, int index, 
	int head, int next_reading, int* range_count, int *);
