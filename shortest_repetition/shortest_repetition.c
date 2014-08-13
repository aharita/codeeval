#include <stdio.h>

int main(int argc, char* argv[]) {
  FILE *file;
  int i = 0, k = 0, m = 0, line_length = 100, repetition = 0, found = 0;
  char line[line_length], word[line_length];
  
  file = fopen(argv[1], "r");
  while(fgets(line, line_length, file) != NULL) {
    for(i = 0; i < line_length; i++) {
      if (line[i] == '\n') {
        break;
      }

      word[i] = line[i];
      repetition++;
      found = 1;

      for(m = 0; m < line_length; m = m + repetition) {
        if (line[m] == '\n') {
          break;
        }

        for(k = 0; k < repetition; k++) {
          if (word[k] != line[m + k]) {
            found = 0;
            break;
          }
        }
      }

      if (found == 1) {
        break;
      }
    }

    printf("%i\n", repetition);
    repetition = 0;
    found = 0;
    for(i = 0; i < line_length; i++) {
      line[i] = 0;
      word[i] = 0;
    }
  }

  fclose(file);
  return 0;
}
