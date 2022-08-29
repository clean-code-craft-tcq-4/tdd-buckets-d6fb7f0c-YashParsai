#include <stdio.h>
#include <stdlib.h>

void compute_range(int* reading, int size)
{
  int index =0;
  int head;
  int tail;
  int range_count = 0;
  FILE* csv_fp = fopen(range_record.csv, "a");
  
  sortReading(readings, size);
  
  for(index; index < size ;)
  {
    head = reading[index];
    if(head == 0)
    {
      index++;
      continue;
    }
    if(index < size)
    {
      next_reading = reading[index+1];
    }
    if((head == next_reading) || (head+1 == next_reading))
    {
      if(range_count == 0)
      {
        head_reading = head;
      }
      range_count++;
      index++;
    }
    else if(range_count)
    {
      tail_reading = reading[index-1];
      fprintf(csv_fp,"%d-%d, %d\n",head_reading,tail_reading);
      range_count = 0;
    }
  }
  fclose(csv_fp);
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
