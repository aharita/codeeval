#include <stdio.h>

int main(int argc, char* argv[]) {
  FILE *file;
  int i = 0, k = 0, line_length = 100, repetition = 0, repetition_length = 0;
  char line[line_length], word[line_length];

  // Clean up
  for(i = 0; i < line_length; i++) {
    word[i] = 0;
  }

  file = fopen(argv[1], "r");
  while(fgets(line, line_length, file) != NULL) {

    for(i = 0; i < line_length; i++) {
      if (line[i] == '\n') {
        break;
      }

      if (word[k] == line[i]) {
        repetition_length++;
        k++;
      }
      else if (word[k] != line[i]) {
        word[i] = line[i];
        repetition++;
        k = 0;
        repetition_length = 0;
      }

      if (repetition_length == repetition) {
        repetition_length = 0;
        k = 0;
      }
    }

    printf("%i\n", repetition);
    for(i = 0; i < line_length; i++) {
      word[i] = 0;
    }
    repetition = 0;
    repetition_length = 0;
    k = 0;
  }

  fclose(file);
  return 0;
}
