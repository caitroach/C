#include <stdio.h>

int main() {
    
    //initializing variables to use in the loop

    int current_char;

    int word_count = 0;
    int line_count = 0;
    int char_count = 0;

    int in_word = 0; //0: not in a word; 1: in a word. using 0s and 1s in place of Boolean values
    

    //printf("Please type something!\n"); this is an optional statement i included for debugging but it doesn't match real wc behaviour

        //this loop iterates through each character in the input until it reaches EOF
        while ((current_char = getchar()) != EOF) {
            
            char_count++; //we have a current_char != EOF so our current char counts

            //check if the current character is a delimiter
           if (current_char == ' ' || current_char == '\n' || current_char == '\t') {

            in_word = 0; //if so, then we are not in a word

                if (current_char == '\n') {
                    line_count++; //if it's a newline then increase line count 
                }
           }

           else { //if the word is a non-delimiter and the in_word flag is set to false (0), then switch it back and increase the word count
                if (in_word == 0) {
                    word_count++; 
                    in_word = 1;
                }
           }
    }
    
    //finally, print results in linux wc format 
    printf("%d %d %d\n", line_count, word_count, char_count); 

    //main expects to return an int so return 0
    return 0;
}