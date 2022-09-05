#include <stdio.h>
#include "assert.h"

int main()
{
  char buffer_range[120] = {0};
  int range_reading[10] = {0,1,2,3,0,6,7,0,10,11};
  char actual_range_string = "1-3, 3\n6-7, 2\n10-11, 2\n"
   
  compute_range(buffer_range, range_reading, (sizeof(range_reading)/sizeof(int)));
  
  if(!strcmp(buffer_range,actual_range_string))
  {
    assert(0);
  }
}
