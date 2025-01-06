#include <ctype.h>
#include <stdio.h>
#include <string.h>

int PrintUsage();
int CheckDuplicates(char *key);
void EncryptText(char *key, char *text);

int main(int argc, char *argv[]) {
  // TODO: maybe refactor this code to more readable function.
  if (argc != 2) {
    PrintUsage();
  } else {
    char *key = argv[1];

    if (strlen(key) != 26) {
      PrintUsage();
    } else {
      for (int i = 0; i < 26; i++) {
        char character = key[i];

        if (!isalpha(character))
          PrintUsage();

        key[i] = toupper(key[i]);
      }

      int isHaveDuplicates = CheckDuplicates(key);

      if (isHaveDuplicates) {
        PrintUsage();
      }

      char str[] = "Hello, world!";

      EncryptText(key, str);
    }
  }
}

int PrintUsage() {
  printf("Usage: ./substitution key\n");
  printf("Key must be 26 characters long and contain only unique alfabetic "
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
void EncryptText(char *key, char *text) {
  int textLength = (int)strlen(text);
  char encryptedText[textLength];

  for (int i = 0; i <= textLength; i++) {
    if (isalpha(text[i])) {
      int charPosition = toupper(text[i]) - 'A';

      if (islower(text[i])) {
        encryptedText[i] = tolower(key[charPosition]);
      } else {
        encryptedText[i] = key[charPosition];
      }
    } else {
      encryptedText[i] = text[i];
    }
  }

  printf("%s\n", encryptedText);
  printf("%i\n", textLength);
}
