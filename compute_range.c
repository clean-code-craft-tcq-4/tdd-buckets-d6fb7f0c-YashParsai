#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "compute_range.h"

int main()
{
  int range_reading[10] = {0,1,2,3,0,6,7,0,10,12};
  compute_range(range_reading, (sizeof(range_reading)/sizeof(int)));
}


void compute_range(int* reading, int size)
{
  int index =0;
  int head;
  int range_count = 0;
  int next_reading;
  int head_reading;
  int tail_reading;
  
  sortReading(reading, size);
  
  for(index; index < size ;index++)
  {
    head = reading[index];
    if(head == 0)
    {
      continue;
    }
    
    next_reading = get_next_reading(index, size, reading);
    
    if((next_reading!=0) && (head == next_reading) || (head+1 == next_reading))
    {
      if(range_count == 0)
      {
        head_reading = head;
      }
      range_count++;
    }
    else if(range_count)
    {
      tail_reading = reading[index-1];
      write_data_to_csv(head_reading, tail_reading, range_count+1);
      range_count = 0;
    }
  }
}

void write_data_to_file(int head, int tail, int range)
{
  FILE* fp = fopen("range_record.txt", "a");
  if(fp==NULL)
    assert(0);
  fprintf(fp,"%d-%d, %d\n",head, tail, range);
  fclose(fp);
}

int get_next_reading(int index, int size, int* reading)
{
  if(index < size)
  {
    return reading[index+1];
  }
  return 0;
}

//Sorting ranges in asceding order
void sortReading(int* reading, int size)
{
  int temp;
  
  for (int i = 0; i < size; i++) 
  {     
      for (int j = i+1; j < size; j++) 
      {     
         if(reading[i] > reading[j]) 
         {    
             temp = reading[i];    
             reading[i] = reading[j];    
             reading[j] = temp;    
         }     
      }     
  }
}
