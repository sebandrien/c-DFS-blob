#include <stdio.h>
#include <stdlib.h>

int blobDetect(int ** picture, int x, int y, int size);

void generatePicture(int ** picture, int size) // Generate a picture with random 1s and 0s
{ 
    for (int r = 0; r < size; ++r)
        for (int c = 0; c < size; ++c)
            picture[r][c] = rand() % 2; // Generate random number between 0 and 1
}

void printPicture(int ** picture, int size) // Print the picture
{ 
    for (int r = 0; r < size; ++r) {
        for (int c = 0; c < size; ++c) 
        {
            printf("%d ", picture[r][c]);
        }
        printf("\n");
    }
}

int main() 
{
    
  int seed;
  int size;
  
  printf("Enter seed: ");
  
  scanf("%d", &seed);
  srand(seed); // Set seed

  printf("Enter the size of the picture, r * c: ");
  
  scanf("%d", &size);

  int ** picture = (int **) malloc(size * sizeof(int *));   // Allocate memory for the picture
  
  if(picture == NULL) {
      
      printf("Failed to allocate memory!\n");
      return 1;
      
  }
  
  for (int i = 0; i < size; ++i) {
      
    picture[i] = (int *) malloc(size * sizeof(int));
    if(picture[i] == NULL) {
        
        printf("Failed to allocate memory!\n");
        return 1;
        
    }
    
  }

  for (int test = 1; test <= 5; ++test) 
  {
      
    printf("Test %d\n", test);
    
    generatePicture(picture, size);

    printf("Generated picture:\n");
    
    printPicture(picture, size);

    int numblobs = 0;

    for (int r = 0; r < size; ++r)
      for (int c = 0; c < size; ++c)
        if (blobDetect(picture, r, c, size) > 0)
          ++numblobs;
    printf("There are %d blob(s) in the picture.\n", numblobs);
    
  }

  for (int i = 0; i < size; ++i) // Free the allocated memory
    free(picture[i]);
    
  free(picture);
  return 0;
  
}

int blobDetect(int ** picture, int x, int y, int size) 
{
  if (x < 0 || x >= size || y < 0 || y >= size) 
  {
    return 0;
  }

  if (picture[x][y] == 0) 
  {
    return 0;
  } 
  else 
  {
    picture[x][y] = 0;
    return 1 + blobDetect(picture, x - 1, y - 1, size) +
           blobDetect(picture, x + 1, y - 1, size) +
           blobDetect(picture, x + 1, y, size) +
           blobDetect(picture, x + 1, y + 1, size) +
           blobDetect(picture, x - 1, y, size) +
           blobDetect(picture, x - 1, y + 1, size) +
           blobDetect(picture, x, y - 1, size) +
           blobDetect(picture, x, y + 1, size);
  }
}
