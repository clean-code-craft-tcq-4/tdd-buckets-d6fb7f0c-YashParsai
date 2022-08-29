#include <stdio.h>

void compute_range(int* reading, int size);
void write_data_to_file(int head, int tail, int range);
int get_next_reading(int index, int size, int* reading);
void getRanges(int* reading, int size);
void getHead(int range_count, int head, int* head_reading);
void evaluateRange(int* reading, int size, int index, int head, int next_reading, int* range_count, int *);
