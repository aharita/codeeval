#include <stdio.h>

int main(int argc, char* argv[])
{
  FILE *file;
  int c = 0;

  file = fopen(argv[1], "r");
  while ((c = fgetc(file)) != EOF) {
    if (c >= 97 && c <= 122)
    {
      printf("%c", (c - 32));
    }
    else if (c >= 65 && c <= 90)
    {
      printf("%c", (c + 32));
    }
    else
    {
      printf("%c", c);
    }
  }

  fclose(file);
  return 0;
}
