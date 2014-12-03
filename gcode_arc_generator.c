#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[])
{
  /* assume 0,0 is the center of the hole, generate G03 moves at radius R
     plus cutter offset D/2 */

  float arc_radius, cutter_diameter, offset;
  char input_string[20];
  char switch_id[5];
  int c, switch_iterator;
  char buffer[10], parsed[10];
  FILE *file;

  printf("Enter radius to cut:\n");
  fflush(stdout);
  fgets(buffer, sizeof(buffer), stdin);
  arc_radius = atof(buffer);

  printf("Enter cutter diameter:\n");
  fflush(stdout);
  fgets(buffer, sizeof(buffer), stdin);
  cutter_diameter = atof(buffer);

  printf("Calculating cut radius %f using cutter diameter %f\n", arc_radius, cutter_diameter);
  offset = arc_radius + (cutter_diameter/2);

  if ((file = fopen("output.ngc", "w")) == NULL)
  {
    printf("Failed to open output file, dumping output to screen\n");
    printf("G0 X%f Y-%f\n", 0.0, offset);
    printf("G03 X%f Y%f I%f J%f F100\n", offset, 0.0, 0.0, offset);
    printf("G03 X%f Y%f I%f J%f\n", 0.0, offset, offset, 0.0);
  }
  else /* have opened file for output */
  {
    fprintf(file, "G0 X%f Y-%f\n", 0.0, offset);
    fprintf(file, "G03 X%f Y%f I%f J%f F100\n", offset, 0.0, 0.0, offset);
    fprintf(file, "G03 X%f Y%f I%f J%f\n", 0.0, offset, offset, 0.0);
    fclose(file);
    printf("Code written to 'output.ngc'\n");
  }
  return 0;
}
