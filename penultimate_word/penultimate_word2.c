#include <stdio.h>

int main(int argc, char* argv[])
{
  FILE *file;
  int i = 0, k = 0, line_length = 1000, found = 0;
  char line[line_length], word[line_length];

  file = fopen(argv[1], "r");

  for (i = 0; i < line_length; i++)
  {
    line[i] = 0;
    word[i] = 0;
  }

  while (fgets(line, line_length, file) != NULL)
  {
    for(i = line_length; i >= 0; i--)
    {
      if (line[i] == ' ')
      {
        i--;
        for (k = 0; k < line_length; k++)
        {
          if (line[i] == ' ' || i <= 0)
          {
            break;
          }

          word[k] = line[i];
          i--;
        }
        break;
      }
    }

    found = 0;
    for (i = line_length; i >= 0; i--)
    {
      printf("%c", word[i]);
    }

    for (i = 0; i < line_length; i++)
    {
      line[i] = 0;
      word[i] = 0;
    }

    printf("\n");
  }

  fclose(file);
  return 0;
}
