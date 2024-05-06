//Authors: Jack Donelson [Partner 2], Cade Evans [Partner 1]
//Purpose: User can load, display or edit pre-stored image file and save it as another image.
#include <stdio.h>
#include <stdbool.h>

#define MACRO 50
#define IN "pic.txt"

int loadImg(int pic[][50]);

//explicit *pointer
int main() {

	int ch = 0;
	int pic[1][1];
	
	do{
	
	printf("**ERINSTAGRAM**\n");
	printf("1: Load image\n");
	printf("2: Display image\n");
	printf("3: Edit image\n");
	printf("0: Exit\n");
	
	printf("\nChoose from one of the options above: ");
	scanf("%d", &ch);
	
	
	if(ch == 1){
		loadImg(pic[1][1]);
	} else if(ch == 2){
	
	} else if(ch == 3){
	
	} else if(ch == 0){
		printf("\nGoodbye!\n\n");
	} else {
		printf("Invalid option, please try again.\n");
	}
	
	
	
	} while(ch != 0);
}

int loadImg(int pic[][MACRO]) {

	FILE *in_Fp;
	
    	in_Fp = fopen(IN, "r");
    	
	if(in_Fp == NULL){
		printf("File could not be opened\n");
		return 0;
	}
	
	for(int i = 0; i < MACRO; i++){
		for(int k = 0; k < MACRO; k++){
		}
	}
}

char convertImg() {

}

void displayImage() {

}

int editMenu() {

}

void cropImg(){

}

void dimImg(){

}

void brightenImg(){

}
