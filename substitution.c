#include <ctype.h>
#include <stdio.h>
#include <string.h>

void PrintUsage();
int ValidateKey(char *key);
int CheckDuplicates(char *key);
void EncryptText(char *key, char *text);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    PrintUsage();
    return 1;
  }

  if (strcmp(argv[1], "-h") == 0) {
    PrintUsage();
    return 0;
  }

  char *key = argv[1];
  if (!ValidateKey(key))
    return 1;

  char str[] = "Hello, world!";
  EncryptText(key, str);

  return 0;
}

void PrintUsage() {
  printf("Usage: ./substitution key\n");
  printf("Key must be 26 characters long and contain only unique alfabetic "
         "characters.\n");
}

// Validates the key and makes sure that all characters is uppercased.
// 1 means that all is okay. Also checks duplicates.
int ValidateKey(char *key) {
  if (strlen(key) != 26) {
    PrintUsage();
    return 0;
  }

  for (int i = 0; i < 26; i++) {
    char character = key[i];

    if (!isalpha(character)) {
      PrintUsage();
      return 0;
    }

    key[i] = toupper(key[i]);
  }

  if (CheckDuplicates(key))
    return 0;

  return 1;
}

// Takes uppercased key value and ckecks if there is any duplicates.
// 1 means that duplicates is found, 0 means otherwise.
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

// TODO: add code to take user input.

// Encrypts text based on uppercased key.
void EncryptText(char *key, char *text) {
  int textLength = (int)strlen(text);
  char encryptedText[textLength];
  encryptedText[textLength] = '\0'; // Ensure that string is terminated.

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
  
  printf("\nEncrypted text: %s\n", encryptedText);
}
