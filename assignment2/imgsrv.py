
import time

while True:
    time.sleep(1.0)
    f = open("image-service.txt", "r")
    readline = f.read()
    f.close()

    readline = int(readline)
    print(readline)
    
    num = int(readline % 4) + 1
    print("Found")
    f = open("image-service.txt", "w")
    f.write('/chanjohn/cs361/assignment2/images/' + str(num) +'.jpg')
    f.close()
    break

    
