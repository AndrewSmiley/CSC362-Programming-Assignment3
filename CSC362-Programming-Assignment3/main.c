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
void encryptMessage(char*, int*, int, int);
void loaddata(FILE *fp, char *dataArray);
void print(char*);

int main(int argc, const char * argv[]) {
    //all variables need to be declared at the top
    char messgeArray[MAX_MESSAGE_LENGTH];
    char *message =  &messgeArray[0];
    int encryptionArray[10] = {5, 2, -1, 2, -3, 2, -4, -2, 6, 4};
    int *encryption = &encryptionArray[0];
    FILE *fp = fopen("message1.txt", "r");
    //get the data
    loaddata(fp, messgeArray);
    fclose(fp);
    encryptMessage(message, encryption, 10, 10);
    message =  &messgeArray[0];

    print(message);
//    printf("%d", (int) 'a');
    return 0;
}


void loaddata(FILE *fp, char *dataArray){
    int counter=0;
    int c;
    while ((c=fgetc(fp)) != EOF) {
        dataArray[counter] = c;
        counter++;
    }
    
    counter++;
    dataArray[counter] = '\0';
//    *(dataArray+counter) = '\0';
}
void encryptMessage(char *message, int *encryption, int encryptionLength, int control){
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
        
        //wrap around case
        //this should probably be changed to pointer dereferenceing but fuck eeet
//        if(*message > 'z' || *message > 'Z'){
//            *message=  (char)((int) *message +*encryption) -26;
//        }else if (*message < 'A' || *message < 'a'){
//            *message=  (char)((int) *message +*encryption) + 26;
//        }
//        else{
        *message= (char)((int) *message + *encryption);
        if (*message > 'z' || *message > 'Z') {
            *message = (char)((int) *message -26);
        }
        if (*message < 'a' || *message < 'A') {
            *message = (char)((int) *message +26);
        }
//        }
        message++;
        encryption++;
        index++;
        
        
    }
}
void print(char* message){
    while (*message != '\0') {
        printf("%c", *message);
        message++;
    }
    
    
}