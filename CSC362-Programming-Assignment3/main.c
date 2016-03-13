//
//  main.c
//  CSC362-Programming-Assignment3
//
//  Created by Andrew Smiley on 3/9/16.
//  Copyright © 2016 Andrew Smiley. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
static const int MAX_MESSAGE_LENGTH = 5000;
static const int MAX_ENCRYPTION_LENGTH = 10;
void encryptMessage(char*, int*, int, int);
void dencryptMessage(char*, int*, int, int);
void loaddata(FILE *fp, char *dataArray);
void print(char*);

int main(int argc, const char * argv[]) {
    //all variables need to be declared at the top
    char messgeArray[MAX_MESSAGE_LENGTH];
    char *message =  &messgeArray[0];
    int encryptionArray[MAX_ENCRYPTION_LENGTH] = {5, 2, -1, 2, -3, 2, -4, -2, 6, 4};
    int *encryption = &encryptionArray[0];
    FILE *fp = fopen("message1.txt", "r");
    //get the data
    loaddata(fp, messgeArray);
    fclose(fp);
    encryptMessage(message, encryption, 10, 10);
    message =  &messgeArray[0];
    putchar('\n');
    printf("Encrypted Message: \n");
    print(message);
    dencryptMessage(message, encryption, 10, 10);
    message =  &messgeArray[0];
    printf("Dencrypted Message: \n");
    print(message);
    return 0;
}


void loaddata(FILE *fp, char *dataArray){
    //declare variables at the top
    int counter=0;
    char c;
    //read each character into the
    while ((c=fgetc(fp)) != EOF) {
        dataArray[counter] = c;
        counter++;
    }
    
    //add the termnation character
    dataArray[counter] = '\0';
}
void encryptMessage(char *message, int *encryption, int encryptionLength, int control){
    int index = 0;
    //iterate till we reach the end
    while(*message != '\0'){
        //if it's not a letter, just skip it.
        if(!isalpha(*message)){
            message++;
            continue;
        }
        //do our check to see if we need to reset the pointer or not
        if (index == control){
            encryption = encryption - control;
            index = 0;
        }
        
        //wrap around case
        if(islower(*message)){
            //make hte change
            *message= (char)((int) *message + *encryption);
            //check to see if it falls out of hte range of valid chars...
            if(*message > 'z'){
                *message = (char)((int) *message - 26);
            }else if (*message < 'a'){
            
                *message = (char)((int) *message + 26);

            }
        }else if (isupper(*message)){
            *message= (char)((int) *message + *encryption);
            //check to see if it falls out of hte range of valid chars...
            if(*message > 'Z'){
                *message = (char)((int) *message - 26);
                //                *message=  (char)((int) *message +*encryption) -26;
                
            }else if (*message < 'A'){
                
                *message = (char)((int) *message + 26);
                
            }
        }
        message++;
        encryption++;
        index++;
        
        
    }
}

void dencryptMessage(char *message, int *encryption, int encryptionLength, int control){
    int index = 0;
    
    while(*message != '\0'){
        //if it's not a letter, just skip it.
        if(!isalpha(*message)){
            message++;
            continue;
        }
        //do our check to see if we need to reset the pointer or not
        if (index == control){
            encryption = encryption - control;
            index = 0;
        }
        //check if it's lowercase
        if(islower(*message)){
            
            //since we're decrypting, we can just multiply by -1 to reverse the op
            *message= (char)((int) *message + (*encryption *-1));
            if(*message > 'z'){
                *message = (char)((int) *message - 26);
            }else if (*message < 'a'){
                *message = (char)((int) *message + 26);
            }
        }else if (isupper(*message)){
            //since we're decrypting, we can just multiply by -1 to reverse the op
            *message= (char)((int) *message + (*encryption *-1));
            if(*message > 'Z'){
                *message = (char)((int) *message - 26);
            }else if (*message < 'A'){
                
                *message = (char)((int) *message + 26);
                
            }
        }
        //point to the next address in memory
        message++;
        //point to the next address in memory
        encryption++;
        index++;
        
        
    }
}
void print(char* message){
    while (*message != '\0') {
        putchar(*message);
        message++;
    }
    putchar('\n');
    putchar('\n');
    
    
}