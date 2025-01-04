#include <ctype.h>
#include <stdio.h>
#include <string.h>

int PrintUsage();
int CheckDuplicates(char *key);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    PrintUsage();
  } else {
    char *key = argv[1];

    // TODO: add check for dublicates
    if (strlen(key) != 26) {
      PrintUsage();
    } else {
      for (int i = 0; i < 26; i++) {
        char character = key[i];

        if (!isalpha(character))
          PrintUsage();

        key[i] = toupper(key[i]);
      }

      printf("%s\n", key);

      int isHaveDuplicates = CheckDuplicates(key);

      if (isHaveDuplicates) {
        printf("\n");
        printf("There is duplicates, key must have unique characters. \n");
        printf("\n");
        PrintUsage();
      }
    }
  }
}

int PrintUsage() {
  printf("Usage: ./substitution key\n");
  printf("Key must be 26 characters long and contain only alfabetic "
         "characters.\n");
  return 1;
}

// Takes uppercased key value and ckecks if there is any duplicates.  
// 1 means that duplicates is found, 0 means otherwise
int CheckDuplicates(char *key) {
  for (int i = 0; i < 26; i++) {
    char iChar = key[i];

    for (int j = i + 1; j < 26; j++) {
      char jChar = key[j];

      if (iChar == jChar) {
        return 1;
      }
    }
  }

  return 0;
}

// TODO: add code to take user input

// TODO: add code for processing and encrypting text
// output must preserve case

// TODO:
