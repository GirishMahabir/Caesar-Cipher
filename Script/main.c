#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Declaring some Global variables.
char message[200], character;
int key,i,char_count, choice;

void menu(){
    /*
    This fucntion will display a menu of the available functions and then 
    return which function of the program the user want to use.
    */
    printf("Choose from the following options: \n");
    printf("1. Encrypt the string.\n");
    printf("2. Decrypt the string.\n");
    printf("3. Frequency Analysis.\n");
    printf("4. A guide on Ceasar Cipher.\n");
    printf("5. Assumptions.\n");
    printf("Enter your choice: ");
    // Taking User Input Choice and saves it to a global variable.
    scanf("%d",&choice);
    /*
    When scanf is used, it leaves an extra line that affects our next user 
    input that we expects using fgets. Fgets reads the full line blank.
    To adjust this we are using a getchar function that'll
    consume the extra line that scanf leaves.
    */
    getchar();
}

void encrypt(char message[20], int key){
    /*
    This function take character by character and go through the algorithm 
    below.
    Args:
        message = User input to encrypt. 
        key = encryption_key.
    Returns:
        The encrypted character.

    I prefered to use directly ASCII numbers to better present the formula.

    a = 95  A = 97
    z = 90  Z = 122
    */
   // Looping Till end of string.
    for (i = 0; message[i] != '\0'; i++){
        // Saving the character in the character variable.
        character = message[i];
        // Checking if the character is whitespace.
        if(character != ' '){
            // Checking if character is between a and z.
            if(character >= 97 && character <= 122){
                // Adding the Character's ASCII value to
                // the key to get a new encrypted character.
                character = (character + key);
                // Checking if the character is greater than
                // z. It will be a symbol if it is. Per the ASCII
                // Table.
                if(character > 122){
                    /*
                    Adjusting to get it in the alphabet only
                    range. 
                    (Character - 122 ) = key
                    Then we add 97 which is a.
                    -1 to adjust for expected answer.
                    */
                    character = character - 122 + 97 - 1;
                }
                // Printing character directly one after each
                // forming a string.
                printf("%c", character);
            }
            // Checking if character is between A and Z.
            if (character >= 65 && character <= 90){
                // Adding the Character's ASCII value to
                // the key to get a new encrypted character.
                character = (character + key);
                // Checking if the character is greater than
                // Z.
                if(character > 90){
                    // Same equation.
                    character = character - 90 + 65 - 1;
                }
                printf("%c", character);
            }
        }
        // If whitespace, print whitespace.
        if (character == ' '){
            printf(" ");
        }
    }
}

void decrypt(char message[20],int key){
    /*
    This function take character by character
    and go through the algorithm below.

    Args:
        message = User input to decrypt. 
        key = encryption_key.
    Returns:
        The encrypted character.

    I prefered to use directly ASCII numbers to
    better present the formula.

    a = 95  A = 97
    z = 90  Z = 122
   */
   // Looping Till end of string.
   for (i = 0; message[i] != '\0'; i++){
       // Saving the character in the character variable.
        character = message[i];
        // Checking if the character is whitespace.
        if(character != ' '){
            // Checking if character is between a and z.
            if(character >= 97 && character <= 122){
                // Substracting the key from the Character's ASCII
                // value to the key to get the decrypted character.
                character = (character - key);
                // Checking if the character is less than
                // a. It will be a symbol if it is. Per the ASCII
                // Table.
                if(character < 97){
                     /*
                    Adjusting to get it in the alphabet only
                    range. 
                    (Character + 122 - 97) gets us back in the
                    alphabet zone, +1 is to adjust the formula.

                    Formula by trial and errors.
                    */
                    character = character + 122 - 97 + 1;
                }
                // Printing character directly one after each
                // forming a string.
                printf("%c", character);
            }
            // Checking if character is between A and Z.
            if (character >= 65 && character <= 90){
                // Substracting the key to the Character's ASCII value
                // to get a decrypted character.
                character = (character - key);
                // Checking if the character is greater than
                // Z.
                if(character < 65){
                    // Same equation.
                    character = character + 90 - 65 + 1;
                }
                printf("%c", character);
            }
        }
        // If whitespace, print whitespace.
        if (character == ' '){
            printf(" ");
        }
    }
}

void characterCount(char message[200]){
    int alpha_freq[26], others = 0;
    int char_len = strlen(message);
    int L1 = 0, L2 = 0, L3 = 0, L4 = 0, LX = 0;
    char A ,B ,C ,D ;

    for(i=0; i<26; i++){
        // initializing array spaces to zero.
        alpha_freq[i] = 0;
    }

    for(i=0; i<char_len; i++){
        // If message[i] >= 97 && message[i] <= 122.
        if(message[i]>='a' && message[i]<='z'){
            /*
            Incrementing the count of the character
            in the array.
            */
            alpha_freq[message[i] - 97]++; 
        }
        // If message[i] >= 97 && message[i] <= 122.
        else if(message[i]>='A' && message[i]<='Z'){
            /*
            Incrementing the count of the character
            in the array.
            */
            alpha_freq[message[i] - 65]++;
        }
        else{
            // Count for other character that are
            // not in the above alphabet range.
            others = others + 1;
        }
    }
    
    /*
    Finding the first character with the most occurrence. Classic method, 
    L1 is set to 0 and the largest number is found looping through the 
    array of characters. Also, In the same loop the largest Number's 
    character is also saved in the variable A.
    */
    for (i=0; i<26; i++){
        if(alpha_freq[i] > L1){
            L1 = alpha_freq[i];
            A = i + 65; // 65 = ASCII A. 
        }
    }
    /*
    The rest now has a small trick.
    Our condition is that:
        The number should be > 0. (> L2)
        less or equal to the first largest. (L1)
        Then:
            Make sure that again its not 0 because
            the value of L2 will be changing.
            Plus make sure its not the same character
            of the previous one (A).
    */
    for (i=0; i<26; i++){
        if(alpha_freq[i] > L2 && alpha_freq[i] <= L1){
            if (alpha_freq[i] > LX && (i+65) != A){
                L2 = alpha_freq[i];
                B = i + 65;
            }
        }
    }
    /*
    Our condition is that:
        The number should be > 0. (> L3)
        less or equal to the second largest. (L2)
        Then:
            Make sure that again its not 0 because
            the value of L3 will be changing.
            Plus make sure its not the same character
            of the two previous one(A and B).
    */
    for (i=0; i<26; i++){
        if(alpha_freq[i] > L3 && alpha_freq[i] <= L2){
            if (alpha_freq[i] > LX && (i+65) != A && (i+65) != B){
                L3 = alpha_freq[i];
                C = i + 65;
            }
        }
    }
    /*
    Our condition is that:
        The number should be > 0. (> L4)
        less or equal to the second largest. (L3)
        Then:
            Make sure that again its not 0 because
            the value of L4 will be changing.
            Plus make sure its not the same character
            of the two previous one(A,B and C).
    */
    for (i=0; i<26; i++){
        if(alpha_freq[i] > L4 && alpha_freq[i] <= L3){
            if (alpha_freq[i] > LX && (i+65) != A && (i+65) != B &&\
            (i+65) != C){
                L4 = alpha_freq[i];
                D = i + 65;
            }
        }
    }
    
    printf("Here’s the text analysis: \n");
    /*
    Looping through the array and printing all the character
    along with its frequency.
    */
    for(i=0; i<26; i++){
            printf("%c : %d\n", (i + 65), alpha_freq[i]);
    }
    printf("Others: %d\n", (others-1));
    printf("First four Letter with highest frequency: %c, %c, %c and %c\n",\
     A, B, C, D);
}

void getUserInput(){
    /*
    This Function takes the user input. The message that the user will enter.
    The key that the user will enter. Note that the message and the key will
    be stored as global variables to get easy access throught the program.
    */
    // Using fgets to read the full line of the user input.
    fgets(message, sizeof(message), stdin);
    printf("Enter Encryption/Decryption Key: ");
    scanf("%d", &key);
    getchar();
}

void CaesarCipherMan(){
    /*
    This function will output a small manual about Caesar Cipher.
    */
    printf("        Welcome To Caesar Cipher.        \n");
    printf("\
    Also known as Caesar's Cipher. This is one of the simplest\n\
    method of encryption. It can be think of a method of cipher\n\
    substitution. The Caesar Cipher consists of 2 main inputs.\n\
    First is the character the user wants to encrypt and Second\n\
    is the encryption/decryption key. i.e make as if the \n\
    character is A and the key is 2, according to the caesar's\n\
    cipher the algorithm needs to shift A, 2 character's ahead\n\
    and the result is C.\n\n\n\
    As seen above it is clear now how the encryption is done.\n\
    The decryption is also simple, well atleast for those who have\n\
    the key. The character just have to be moved backword using\n\
    the key, i.e to decrypt C with the key 2, we shift C 2 characters\n\
    before, the result is now A.\n\n\
    Source:https://www.geeksforgeeks.org/caesar-cipher-in-cryptography/ \n");
}
void assumptions(){
    /*
    Assumptions made while writing this script.
    */
    printf("        ASSUMPTIONS:    \n");
    printf("\
    -> Max Length of input string is of 200 characters.\n\
    -> Max word length is of 20 characters.\n\
    -> Key is only accepted in integer.(i.e one/two/six etc not\n\
    -> understandable by program.)\n\
    -> For re-try, the script only accept y/n.");
}
void programMain(){
    /*
    Function to interpret the user choice and point back
    or call the appropriate function that needs to be served
    to the user.
    */
    if (choice == 1 || choice == 2){
        if (choice == 1){
            printf("Enter Message you want to Encrypt: ");
            getUserInput(); // Take user message and key.
            // pass message and key to the encrypt function.
            encrypt(message, key); // encrypt and output.
        }
        if (choice == 2){
            printf("Enter Message you want to Decrypt: ");
            getUserInput();// Take user message and key.
            // pass message and key to the decrypt function.
            decrypt(message, key); // decrypt and output.
        }
    }
    if (choice == 3){
        printf("Enter Message you want to Analyse: ");
        fgets(message, sizeof(message), stdin);
        // pass message to characterCount.
        characterCount(message); 
    }
    if(choice == 4){
        // Display a short description about the Caesar Cipher.
        CaesarCipherMan();
    }
    if (choice == 5){
        // Display the assumptions made in our script.
        assumptions();
    }
    printf("\n");
}

int main(void){
    /*
    Main function on our script. The main function will be a loop that 
    asking if the user wants to try other features about our program and on 
    user input n break and end the program.
    */
    char reTry = 'y';
    while (reTry == 'y'){
        menu();
        programMain();
        printf("Do you want to try another function? y/n : ");
        scanf("%c", &reTry);
        getchar();
    }
}