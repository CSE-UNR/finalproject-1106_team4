//Authors: Jack Donelson, [Partner 2]
//Purpose: User can load, display or edit pre-stored image file and save it as another image.
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10000

int width, height;
int pixels[MAX_SIZE][MAX_SIZE];

int loadImg(char *fileName);
void displayImage();
void editMenu();
void cropImg();
void dimImg();
void brightenImg();
int saveImg(char *fileName);




//explicit *pointer
int main() {

	char fileName[100];

	int selection;
	
	while(true){

	printf(" Menu: \n");
	printf("1. Load the Image: \n");
	printf("2. Display the Image: \n");
	printf("3. Edit the Image: \n");
	printf("4. Exit: \n");
	printf("Enter your choice: \n");
	scanf("%d", &selection);
	
	switch (selection){
	
		case 1:
		printf("Enter your file name: ");
<<<<<<< HEAD
		fgets(fileName, 100, stdin);
=======
		scanf("%s", fileName);
>>>>>>> 79ff484c27892b01ad0f9443ae60bec3d2ac1ed6
		loadImg(fileName);
		break;
		
		case 2:
		displayImage();
		break;
		
		case 3:
		editMenu();
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

int loadImg(char *fileName) {
	FILE *image = fopen(fileName, "r");
	if (image == NULL){
	printf("ERROR: Unable to open file for saving.\n");
	return 0;
	}
	fscanf(image, "%d %d", &width, &height);
	for (int j = 0; j < width; j++){
		for(int k = 0; k <height; k++){
		fscanf(image, "%d", &pixels[j][k]);	
		}
	}
	fclose(image);
}
void displayImage() {

	char can;
	
	for(int i = 0; i < 1000; i++){
		for(int k = 0; can != 1 ; k++){
			if(img[i][k] == "\n"){
				can = 1;
			} else {
				printf("%c", img[i][k]);
			}
		}
	}
}

void editMenu(){


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
		cropImg();
		break;
		
		case 2:
		dimImg();
		break;
		
		case 3:
		brightenImg();
		break;
		
		case 4:
		saveImg("edited_Image.txt");
		break;
		
		case 5:
		break;
		
		
		default:
		printf("Invalid selection. Please try again.\n");
		break;
		}
	}					

}

void cropImg(){
	for(int j = 0; j < height; j++){
	   for(int k = 0; k < width; k++){
	     if(pixels[j][k] > 0){
		pixels[j][k]--;
			}
		}
	}
	
}

void dimImg(){
	for(int j = 0; j < height; j++){
	   for(int k = 0; k < width; k++){
	     if(pixels[j][k] > 0){
		pixels[j][k]--;
			}
		}
	}
	
	}

void brightenImg(){
	for(int j = 0; j < height; j++){
	   for(int k = 0; k < width; k++){
	     if(pixels[j][k] < 4){
		pixels[j][k]++;
			}
		}
	}
	
}


int saveImg(char *fileName){

	FILE *image = fopen(fileName, "w");
	if (image == NULL){
	printf("ERROR: Unable to open file for saving.\n");
	return 0;
	}
	fscanf(image, "%d %d", &width, &height);
	for (int j = 0; j < width; j++){
		for(int k = 0; k <height; k++){
		fprintf(image, "%d", pixels[j][k]);	
		}
		fprintf(image, "\n");
	}
	fclose(image);

}
