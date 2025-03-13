# C Connected Component Analysis (CCA) Algorithm

Generates a binary image of random 1s and 0s and then counts the number of "blobs" (connected clusters of 1s) within the image. The main function prompts the user to enter a seed for random generation and a size for the square picture matrix. Memory is dynamically allocated to create a 2D array representing the picture. generatePicture() fills the array with random 1s and 0s, while printPicture() outputs the array to visualize the generated picture. For each test, blobDetect() is called to detect blobs by recursively visiting and "zeroing out" each connected 1 in a cluster. This function checks all eight neighboring cells to find connected components. After counting all blobs, it prints the result, cleans up the allocated memory, and exits. The program runs five tests by generating new pictures and counting blobs each time.


Example:

```c
Input:
Enter seed: 2
Enter the size of the picture, r * c: 12
```

```c
Test 1
Generated picture:
0 1 0 1 1 0 0 1 1 1 0 1 
1 1 1 1 0 1 1 0 0 0 1 1 
1 1 0 0 0 1 1 0 0 0 1 0 
0 1 1 1 1 1 0 0 0 1 0 0 
0 1 0 1 1 0 0 0 1 1 0 1 
0 0 1 1 0 0 1 0 0 0 1 1 
0 1 1 0 0 1 1 0 1 1 1 0 
1 0 1 0 1 1 1 1 1 0 0 1 
1 1 1 1 0 0 0 0 1 1 0 1 
1 1 0 0 1 1 0 0 1 1 1 0 
1 0 0 0 1 0 0 0 0 1 1 0 
0 1 0 1 0 0 1 1 0 1 1 1 
There are 2 blob(s) in the picture.
Test 2
Generated picture:
0 0 1 0 1 0 0 0 1 0 1 0 
1 1 0 1 0 1 1 0 0 1 0 0 
1 1 0 1 0 1 0 0 1 0 0 1 
0 1 1 1 1 0 1 0 1 1 1 0 
0 0 0 0 1 0 1 1 1 1 0 1 
0 1 0 0 1 0 1 1 1 0 1 1 
1 0 1 0 0 1 0 0 1 1 1 1 
1 0 0 1 1 0 0 1 1 0 1 0 
1 0 0 0 1 1 1 0 1 1 0 1 
0 1 0 1 0 1 0 1 1 0 0 0 
1 1 1 0 1 1 1 0 1 1 1 0 
0 0 0 1 1 1 1 1 0 1 1 0 
There are 1 blob(s) in the picture.
Test 3

Generated picture:
0 1 1 1 0 0 1 1 1 0 1 0 
1 0 1 1 1 0 1 1 0 0 1 0 
1 0 1 1 1 0 1 1 0 0 0 0 
0 1 1 1 1 0 0 1 1 1 0 0 
1 1 0 1 1 1 1 0 1 1 1 0 
1 0 1 1 1 1 1 1 0 0 1 1 
1 1 0 0 0 0 0 1 0 0 0 1 
1 0 0 0 1 1 0 0 0 1 0 1 
0 1 0 0 0 1 0 1 0 0 1 0 
1 1 1 1 0 0 0 1 0 0 0 1 
0 0 1 0 0 1 1 0 1 1 1 1 
1 1 0 1 1 1 0 0 0 1 1 0 
There are 3 blob(s) in the picture.

Test 4
Generated picture:
1 0 0 1 0 0 0 0 0 0 0 0 
1 1 1 0 1 0 1 0 1 1 1 0 
0 1 1 1 1 0 1 0 0 1 0 1 
1 0 1 0 0 0 0 0 1 1 0 0 
1 0 0 0 1 0 1 0 1 0 1 0 
0 0 1 1 0 1 0 1 1 1 1 0 
1 0 0 1 1 0 1 1 0 0 1 0 
0 0 0 1 0 1 0 1 1 1 0 1 
0 0 1 1 1 0 1 1 0 1 0 0 
0 1 1 0 1 0 0 1 1 0 1 1 
1 1 0 1 0 0 0 0 0 1 1 0 
0 1 1 0 0 1 0 0 0 1 1 0 
There are 5 blob(s) in the picture.

Test 5
Generated picture:
0 1 1 1 0 0 0 1 1 1 0 1 
1 1 1 0 0 1 0 0 0 1 1 0 
0 1 1 0 1 0 0 1 1 0 0 1 
0 0 1 0 1 1 1 1 0 1 1 1 
0 1 1 0 0 0 0 0 0 1 0 1 
1 1 0 1 1 0 0 1 0 1 1 0 
1 1 1 1 0 0 0 0 1 0 0 1 
0 0 1 0 0 1 1 1 0 1 0 1 
1 1 1 0 0 0 0 1 1 1 1 1 
1 1 1 0 1 1 1 0 0 0 0 0 
1 0 1 0 1 0 1 1 1 0 1 1 
1 1 1 0 0 0 0 1 1 1 1 1

There are 2 blob(s) in the picture.
```
