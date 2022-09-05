#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "compute_range.h"


int compareForAscending (const void * a, const void * b) 
{
   return ( *(int*)a - *(int*)b );
}


void write_data_to_file(char* buffer_range, int head, int tail, int range)
{
  FILE* fp = fopen("range_record.txt", "a");
  char *buff=buffer_range;
  if(fp==NULL)
    assert(0);
  
  fprintf(fp,"%d-%d, %d\n",head, tail, range);
  
  buff=strchr(buffer_range, 0);
  sprintf(buff,"%d-%d, %d\n",head, tail, range);

  fclose(fp);
}


void getHead(int range_count, int head, int* head_reading)
{
  if(range_count == 0)
  {
    *head_reading = head;
  }
}


int get_next_reading(int index, int size, int* reading)
{
  if(index < size)
  {
    return reading[index+1];
  }
  return 0;
}


void evaluateRange(char* buffer_range, int* reading, int size, int index, 
		   int head, int next_reading, int* range_count, int * head_reading)
{

    int tail_reading;


    if((next_reading!=0) && (head == next_reading) || (head+1 == next_reading))
    {
      getHead(*range_count,head,head_reading);
      (*range_count)++;
    }
    else if(*range_count)
    {
      tail_reading = reading[index];
      write_data_to_file(buffer_range, *head_reading, tail_reading, (*range_count)+1);
      *range_count = 0;
    }

}


void getRanges(char* buffer_range, int* reading, int size)
{
  int index =0;
  int head;
  int range_count = 0;
  int next_reading;
  int head_reading;
  
  for(; index < size ;index++)
  {
    head = reading[index];
    if(head == 0)
    {
      continue;
    }
    
    next_reading = get_next_reading(index, size, reading);
    evaluateRange(buffer_range, reading, size, index, head, next_reading, &range_count,&head_reading);
  }
}


void compute_range(char* buffer_range, int* reading, int size)
{
   qsort(reading, size, sizeof(int), compareForAscending);
   getRanges(buffer_range, reading, size);
}


int main()
{
  char buffer_range[120] = {0};
  int range_reading[10] = {0,1,2,3,0,6,7,0,10,11};
  compute_range(buffer_range, range_reading, (sizeof(range_reading)/sizeof(int)));

  printf("%s",buffer_range);
}
