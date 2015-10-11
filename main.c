#include <stdio.h>
#include <string.h>

// Declare functions
void get_input();

// Global variables
char text_input[32];
int running = 1;

// Main Section
int main() {

  while (running == 1) {
    if (strcmp(text_input, "q") == 0) {
      running = 0;
      printf("Goodbye!\n");
    }
    else {
      get_input();
      printf("The message is %s\n", text_input);
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
