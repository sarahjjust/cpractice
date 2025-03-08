#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  if (argc > 2) {
    printf("TOO MANY ARGUMENTS!!!\n");
    return 1;
  } else if (argc < 2) {
    printf("NOT ENOUGH ARGUMENTS!!!\n");
    return 1;
  }
  
  char *toshum = argv[1];
  int i = 0;
  int vowelnum = 0;
  while(toshum[i] != '\0' && vowelnum < 2) {
    char *vowels = "aeiouAEIOU";
    if (strchr(vowels, toshum[i]) != NULL) {
      vowelnum++;
    }
    i++;
  }
  char root[i+1];
  strncpy(root, toshum, i);
  root[i] = '\0';

  printf("%sshumi\n", root);
  return 0;
}
