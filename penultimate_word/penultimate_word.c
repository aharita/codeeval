#include <stdio.h>

int main(int argc, char* argv[])
{
  FILE *file;
  int i = 0, c = 0, word_length = 1000, index = 0, space_count = 0, current_space_count = 0;
  char word[word_length];

  file = fopen(argv[1], "r");
  while ((c = fgetc(file)) != EOF) {
    if (c == '\n')
    {
      // 1. print penultimate word
      for (i = 0; i < word_length; i++)
      {
        if (word[i] == ' ')
        {
          current_space_count++;
        }

        if (word[i] != ' ' && current_space_count == (space_count - 1))
        {
          printf("%c", word[i]);
        }
      }

      // 2. clean
      current_space_count = 0;
      space_count = 0;
      index = 0;
      for (i = 0; i < word_length; i++)
      {
        word[i] = 0;
      }
      printf("\n");
    }
    else
    {
      if (c == ' ')
      {
        space_count++;
      }

      word[index] = c;
      index++;
    }
  }

  fclose(file);
  return 0;
}
