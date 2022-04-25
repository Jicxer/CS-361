from cProfile import run
import time
import os 


while True:
    num = input('Enter 1 to generate a new image or 2 to exit: ')
    text = 'run'
    print(num)
    if(num == 1):
        print('Chose option 1')
        fw = open('prng-service.txt', 'w')
        fw.write(text) #Write 'run' onto prng-service.txt
        fw.close()
        print('Writing run to prng-service.txt')

        time.sleep(5.0)
        os.system('python Prng.py')
        fr = open('prng-service.txt', 'r') 
        read = fr.read()
        value = int(read)
        print(value)            #Read and place randomly generated value into value
        fr.close()

        f2w = open('image-service.txt' , 'w')
        print('Clearing image-service.txt')
        time.sleep(5.0)
        f2w.truncate()
        print('Writing value to txt file.')
        time.sleep(5.0)
        f2w.write(str(value))
        f2w.close()
        time.sleep(5.0)
        print('Outputting image path to txt file')
        os.system('python imgsrv.py') #Clear file and write randomly generated value
        
        f2r = open('image-service.txt' , 'r')
        read_f2r = f2r.read()
        print(read_f2r) #Read the URL file and print
        f2r.close()
    elif(num == 2):
        break
    else:
        print("Unknown Input! \n Try again!")
    