#include <stdio.h>
#define MAXLENGTH 100

int main(int argc, char* argv[]) {
  FILE *file;
  int i, k, repetition;
  char line[MAXLENGTH];

  file = fopen(argv[1], "r");
  while(fgets(line, MAXLENGTH, file) != NULL) {
    repetition = 1;
    k = 0;

    for(i = 1; i < MAXLENGTH; i++) {
      if (line[i] == '\n') {
        break;
      }
      else if (line[k] == line[i]) {
        k++;
      }
      else if (line[k] != line[i]) {
        repetition++;
        k = 0;
      }
    }

    printf("%i\n", repetition);
  }

  fclose(file);
}
