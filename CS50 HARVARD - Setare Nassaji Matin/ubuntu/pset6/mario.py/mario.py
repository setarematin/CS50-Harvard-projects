from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break
for j in range(height):

    # prints spaces (first we want space)
    for spaces in range(height-j-1):
        print(" ", end="")
    # (then hashes)
    for i in range(j+1):
        print("#", end="")


    print("\n", end ="")