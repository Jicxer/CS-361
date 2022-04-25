import random
import time



string = 'run'
while True:
    time.sleep(1.0)
    f = open("prng-service.txt", "r")
    read = f.read()

    if string in read:
        print("Found", string)
        num = random.randrange(999)
        
        read = read.replace('run', '')
        f.close()
        f = open("prng-service.txt", "w")
        f.write(read)
        f.write(str(num))
        f.close()

        break
    else:
        print("Not found")
        f.close()
        break

exit
    
