//Authors: Jack Donelson, [Partner 2], Cade Evans, [Partner 1] 
//Purpose: User can load, display or edit pre-stored image file and save it as another image.
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 3

int row(char *fileName);
int column(char *fileName);
int loadImg(char *fileName, int pixels[MAX_SIZE][MAX_SIZE]);
void displayImage(int pixels[MAX_SIZE][MAX_SIZE], char img[MAX_SIZE][MAX_SIZE], int row, int col);
int editMenu(int pixels[][MAX_SIZE]);
void cropImg(int pixels[][MAX_SIZE]);
void dimImg(int pixels[][MAX_SIZE]);
void brightenImg(int pixels[][MAX_SIZE]);
int saveImg(char *fileName, int pixels[][MAX_SIZE]);




//explicit *pointer
int main() {

	char fileName[100];
	char img[MAX_SIZE][MAX_SIZE];
	int pixels[MAX_SIZE][MAX_SIZE];

	int selection;
	
	int columns = 0;
	int rows = 0;
	
	while(true){

	printf(" Menu: \n");
	printf("1. Load the Image: \n");
	printf("2. Display the Image: \n");
	printf("3. Edit the Image: \n");
	printf("4. Exit: \n");
	printf("Enter your choice: ");
	scanf("%d", &selection);
	printf("\n");
	
	switch (selection){
	
		case 1:
		printf("Enter your file name: ");

		fgets(fileName, 100, stdin);

		scanf("%s", fileName);
		
		columns = column(fileName);
		rows = row(fileName);
		printf("%d", rows);
		printf("%d", columns);
		loadImg(fileName, pixels);
		break;
		
		case 2:
		displayImage(pixels, img, rows, columns);
		break;
		
		case 3:
		editMenu(pixels);
		break;
		
		case 4:
		
		return 0;
		break;
		
		default:
		printf("Invalid selection. Please try again.\n");
		break;
		}
	}					

}

int row(char *fileName){
	int column = 0;
	int r = 0;
	int c = 0;
	char temp;
	
	FILE *image = fopen(fileName, "r");
	if (image == NULL){
		printf("ERROR: Unable to open file for saving.\n");
		return 0;
	}
	while(fscanf(image, "%c", &temp) == 1){
			if(temp == '\n'){
				r++;
				column = c;
				c = 0;
				
			} else if(temp != '\n'){
				c++;
			}
		}
	fclose(image);
	return r;
}

int column(char *fileName){
	int column = 0;
	int r = 0;
	int c = 0;
	char temp;
	
	FILE *image = fopen(fileName, "r");
	if (image == NULL){
		printf("ERROR: Unable to open file for saving.\n");
		return 0;
	}
	while(fscanf(image, "%c", &temp) == 1){
			if(temp == '\n'){
				r++;
				column = c;
				c = 0;
				
			} else if(temp != '\n'){
				c++;
			}
		}
	fclose(image);
	return column;
}

int loadImg(char *fileName, int pixels[MAX_SIZE][MAX_SIZE]) {
	int r = 0;
	int c = 0;
	char temp;
	FILE *image = fopen(fileName, "r");
	if (image == NULL){
		printf("ERROR: Unable to open file for saving.\n");
	return 0;
	}
		while(fscanf(image, "%c", &temp) == 1){
			if(temp == '\n'){
				r++;
				c = 0;
				
			} else if(temp != '\n'){
				fscanf(image, "%d", &pixels[r][c]);
				c++;
			}
		}
	fclose(image);
}


void displayImage(int pixels[MAX_SIZE][MAX_SIZE], char img[MAX_SIZE][MAX_SIZE], int row, int col) {
	
	for(int i = 0; i < row; i++){
		for(int k = 0; k < col ; k++){
				if(pixels[i][k] == 0){
					img[i][k] = 'p';
					printf("%c", img[i][k]);
				} else if(pixels[i][k] == 1){
					img[i][k] = '.';
					printf("%c", img[i][k]);
				} else if (pixels[i][k] == 2){
					img[i][k] = 'o';
					printf("%c", img[i][k]);
				} else if (pixels[i][k] == 3){
					img[i][k] = 'O';
					printf("%c", img[i][k]);
				} else if (pixels[i][k] == 4){
					img[i][k] = '0';
					printf("%c", img[i][k]);
				}
		}
	}
	
}

int editMenu(int pixels[][MAX_SIZE]){


	char fileName[100];

	int selection;
	
	while(true){

	printf(" Menu: \n");
	printf("1. Crop Image: \n");
	printf("2. Dim the Image: \n");
	printf("3. Brighten the Image: \n");
	printf("4. Save Image: \n");
	printf("5. Back to main menu: \n");
	printf("Enter your choice: \n");
	scanf("%d", &selection);
	
	switch (selection){
	
		case 1:
		cropImg(pixels);
		break;
		
		case 2:
		dimImg(pixels);
		break;
		
		case 3:
		brightenImg(pixels);
		break;
		
		case 4:
		saveImg("edited_Image.txt", pixels);
		break;
		
		case 5:
		return 0;
		break;
		
		
		default:
		printf("Invalid selection. Please try again.\n");
		break;
		}
	}					

}

void cropImg(int pixels[][MAX_SIZE]){
	for(int j = 0; j < MAX_SIZE; j++){
	   for(int k = 0; k < MAX_SIZE; k++){
	     if(pixels[j][k] > 0){
		pixels[j][k]--;
			}
		}
	}
	
}

void dimImg(int pixels[][MAX_SIZE]){
	for(int j = 0; j < MAX_SIZE; j++){
	   for(int k = 0; k < MAX_SIZE ; k++){
	     if(pixels[j][k] > 0){
		pixels[j][k]--;
			}
		}
	}
	
}

void brightenImg(int pixels[][MAX_SIZE]){
	for(int j = 0; j < MAX_SIZE; j++){
	   for(int k = 0; k < MAX_SIZE; k++){
	     if(pixels[j][k] < 4){
		pixels[j][k]++;
			}
		}
	}
	
}


int saveImg(char *fileName, int pixels[][MAX_SIZE]){

	FILE *image = fopen(fileName, "w");
	if (image == NULL){
	printf("ERROR: Unable to open file for saving.\n");
	return 0;
	}
	for (int j = 0; j < MAX_SIZE; j++){
		for(int k = 0; k < MAX_SIZE; k++){
		fprintf(image, "%d", pixels[j][k]);	
		}
		fprintf(image, "\n");
	}
	fclose(image);

}
