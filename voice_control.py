import speech_recognition as sr
import serial

ser = serial.Serial('com4', 9600)

def func():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        r.adjust_for_ambient_noise(source)
        while True:
            print('Say something')
            audio = r.listen(source)
            try:
                a = r.recognize_google(audio)
                print("you said " + a.lower())

                if a.lower() == 'goodbye' or a.lower() == 'good bye' or a.lower() == 'bye':
                    ser.write('2'.encode())
                elif a.lower() == 'good morning' or a.lower() == 'thankyou' or a.lower() == 'thank you':
                    ser.write('1'.encode())
                a_lower = a.lower()
                if a_lower == 'angry':
                    ser.write('3'.encode())
                elif a_lower == 'aunt':
                    ser.write('4'.encode())
                elif a_lower == 'baby':
                    ser.write('5'.encode())
                elif a_lower == 'bag':
                    ser.write('6'.encode())
                elif a_lower == 'bathroom':
                    ser.write('7'.encode())
                elif a_lower == 'bed':
                    ser.write('8'.encode())
                elif a_lower == 'book':
                    ser.write('9'.encode())
                elif a_lower == 'bored':
                    ser.write('10'.encode())
                elif a_lower == 'bro':
                    ser.write('11'.encode())
                elif a_lower == 'brother':
                    ser.write('12'.encode())
                elif a_lower == 'car':
                    ser.write('13'.encode())
                elif a_lower == 'chair':
                    ser.write('14'.encode())
                elif a_lower == 'clock':
                    ser.write('15'.encode())
                elif a_lower == 'clothes':
                    ser.write('16'.encode())
                elif a_lower == 'cold':
                    ser.write('17'.encode())
                elif a_lower == 'color':
                    ser.write('18'.encode())
                elif a_lower == 'computer':
                    ser.write('19'.encode())
                elif a_lower == 'confused':
                    ser.write('20'.encode())
                elif a_lower == 'cousin':
                    ser.write('21'.encode())
                elif a_lower == 'curious':
                    ser.write('22'.encode())
                elif a_lower == 'dad':
                    ser.write('23'.encode())
                elif a_lower == 'daughter':
                    ser.write('24'.encode())
                elif a_lower == 'day':
                    ser.write('25'.encode())
                elif a_lower == 'dont know':
                    ser.write('26'.encode())
                elif a_lower == 'door':
                    ser.write('27'.encode())
                elif a_lower == 'download':
                    ser.write('28'.encode())
                elif a_lower == 'drink':
                    ser.write('29'.encode())
                elif a_lower == 'early':
                    ser.write('30'.encode())
            except:
                print(" ")

while 1:
    func()