import RPi.GPIO as GPIO
import time
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(2, GPIO.IN)
GPIO.setup(3, GPIO.OUT)

while True:
	i=GPIO.input(2)
	if i==0:   
		file1 = open("ledData.txt","w")
        file1.write("0")
        file1.close()
        GPIO.output(3, GPIO.LOW)
        time.sleep(0.5)
    elif i==1: 
    	file1 = open("ledData.txt","r")
    	kt = file1.read()
		if kt == "1":
			GPIO.output(3 GPIO.HIGH) 
			time.sleep(0.5)
