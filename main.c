#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare functions
void get_input();
int is_valid_number();
int get_random_number();

// Global variables
char text_input[32];
int running = 1;
int number_range = 10;

// Main Section
int main() {

  while (running == 1) {
    if (strcmp(text_input, "q") == 0) {
      running = 0;
      printf("Goodbye!\n");
    }
    else {
      get_input();
      if(is_valid_number() == 0) {
        int guess;
        guess = get_random_number();

        printf("Your guess was %s\n", text_input);
        printf("The number was %d\n", guess);
      }
    }
  }

  return 0;

}

// Define functions
void get_input() {

  // Get the string
  printf("Please enter a number or (q) to quit\n");
  fgets(text_input, 32, stdin);
  
  // Get the length of the string
  int length = strlen(text_input) -1;

  // Remove the newline at the end of the string if it existss
  if (text_input[length] == '\n') {
    text_input[length] = '\0';
  }

}

// Check if string is a valid number
int is_valid_number() {

  char *ptr;
  
  strtol(text_input, &ptr, 10);
  
  if (strlen(ptr) == 0) {
    return 0;
  } else {
    printf("Not a valid number\n");
    return 1;
  }

}

// Get random number
int get_random_number() {
   return rand() % number_range + 1;
}
