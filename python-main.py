import time
import random

def blob_detect(picture, x, y, size):
    if x < 0 or x >= size or y < 0 or y >= size:
        return 0

    if picture[x][y] != 'X':  # Check if the pixel is not a blob
        return 0

    picture[x][y] = 0  # Change the blob into 0
    
    return (1 + blob_detect(picture, x - 1, y - 1, size) +
            blob_detect(picture, x + 1, y - 1, size) +
            blob_detect(picture, x + 1, y, size) +
            blob_detect(picture, x + 1, y + 1, size) +
            blob_detect(picture, x - 1, y, size) +
            blob_detect(picture, x - 1, y + 1, size) +
            blob_detect(picture, x, y - 1, size) +
            blob_detect(picture, x, y + 1, size))

def generate_picture(size):
    picture = [[random.choice([0, 'X']) for _ in range(size)] for _ in range(size)]
    return picture

def print_picture(picture):
    for row in picture:
        print(' '.join(map(str, row)))

if __name__ == "__main__":
    seed = int(input("Enter seed: "))
    random.seed(seed)
    size = int(input("Enter the size of the picture, r * c: "))
    
    start_time = time.time()

    for test in range(1, 6):
        print(f"Test {test}")
        picture = generate_picture(size)
        
        print("Generated picture:")
        print_picture(picture)

        numblobs = 0

        for r in range(size):
            for c in range(size):
                if blob_detect(picture, r, c, size) > 0:
                    numblobs += 1
        print(f"There are {numblobs} blob(s) in this picture.")
        print("\n")
        
end_time = time.time()
runtime = end_time - start_time
print(f"Runtime: {runtime} seconds")
