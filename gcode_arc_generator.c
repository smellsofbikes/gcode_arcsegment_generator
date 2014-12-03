#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void main(int argc, char *argv[])
{
  /* assume 0,0 is the center of the hole, generate G03 moves at radius R
     plus cutter offset D/2 */

  float arc_radius, cutter_diameter;
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

  if ((file = fopen("output.ngc", "w")) == 0)
  {
cut-n-paste screwed up.
