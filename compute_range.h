#include <stdio.h>

void compute_range(int* reading, int size);
void sortReading(int* reading, int size);
void write_data_to_csv(int head, int tail, int range);
int get_next_reading(int index, int size, int* reading);
