TITLE:
    Voice-Controlled Arduino Using Python


WORKING PROCESS:
    1. Voice-Controlled Arduino Using Python is a project that enables users to control an Arduino device using voice commands. 
    2. It includes a Python script for speech recognition and an Arduino sketch for handling serial commands and performing actions accordingly. The Python script captures and processes audio input from a microphone, recognizes spoken words using Google's speech recognition service, and maps recognized commands to specific serial commands for the Arduino. 
    The Arduino sketch receives the serial commands and executes corresponding actions based on the commands received. The project allows users to interact with the Arduino device by speaking commands, enabling hands-free control of the device. 
    The project can be customized by modifying the Python script to recognize additional voice commands and the Arduino sketch to define additional actions for specific commands. 
    The hardware setup can also be customized to include additional components or sensors as needed.


REQUIREMENTS:
    1. Arduino board
    2. Microphone
    3. Speaker
    4. Computer with USB port
    5. ILI9341 TFT display
    6. Arduino IDE
    7. Python (with SpeechRecognition library installed)


SOFTWARE IDEs:
    1. VS code
    2. Arduino IDe


SETUP:
    1. Connect the Arduino board to your computer via USB.
    2. Upload the provided Arduino sketch (arduino_serial_control.ino) to the Arduino board using the Arduino IDE.
    3. Connect a microphone to your computer.
    4. Install the required Python packages by running pip install -r requirements.txt in the terminal.
    5. Modify the ser = serial.Serial('com4', 9600) line in the Python script (voice_control.py) to match your Arduino's serial port.
    6. Run the Python script (voice_control.py) to start the voice recognition system.


USAGE:
    1. Launch the Python script (voice_control.py) to start listening for voice commands.
    2. Speak commands into the microphone.
    3. The Python script will recognize the commands and send corresponding serial commands to the Arduino board.
    4. The Arduino board will execute actions based on the received commands, such as displaying images on an optional ILI9341 TFT display.


CUSTOMIZATION:
    1. Modify the Arduino sketch to define additional actions for specific serial commands.
    2. Update the Python script to recognize additional voice commands by adding more entries to the command_mapping dictionary.
    3. Customize the hardware setup to include additional components or sensors as needed.

COMMANDS TO INSTALL PACKAGES RELATED TO PYTHON:
    1. pip install SpeechRecognition
    2. pip install pyserial



PICTURES:
    Format: BMP (Bitmap)
    Resolution: 240(horizontal) X 320(vertical)
    Description:
    BMP is a straightforward image format that stores bitmap images pixel by pixel, with each pixel represented by a specific color value. 
    The format supports various color depths, including 1-bit monochrome, 4-bit indexed color, 8-bit indexed color, 16-bit high color, and 24-bit true color. 
    In this project, it appears that the BMP images used may be of 24-bit true color depth.
    Usage: 
    The Arduino-compatible board reads BMP image files from an SD card or flash memory and displays them on the ILI9341 TFT display. 
    The code includes logic to load specific BMP images based on user input received through speech recognition or serial communication. 
    The displayed images likely serve as visual feedback or responses to user commands or interactions with the system.
    ADD More Pictures:
    You can add pictures of your own
    After adding each picture modify the commands as required both in voice_control.py and arduino_serial_control.ino files.

    
ADVANTAGES:
    Hands-free Control:Voice commands allow users to communicate with the Arduino device, making it convenient and hands-free to use the system. When manual input is not feasible or feasible, this can be especially helpful.
    Customizability:The project provides customisation options for both software and hardware. Customising the Arduino sketch to define new actions for particular commands and modifying the Python script to recognise additional voice commands allow users to customise the functionality to meet specific needs.
    Ease of Use: Because the project makes use of well-known tools and technologies like Arduino and Python, a variety of users, including novices, can easily understand and utilise it. An easy implementation process is made possible by the setup instructions and documentation that are provided.
    Integration Potential: As the project makes use of commonly-used platforms and libraries like Python's SpeechRecognition and Arduino, it can be readily integrated with other systems and technologies. This creates opportunities for integrating voice control with current systems or adding it to bigger projects.
    Feedback Mechanism: The project provides real-time visual confirmation of commands and system responses, thereby improving user interaction through the use of a display (ILI9341 TFT display) and images as visual feedback. This can enhance usability and user experience, particularly when auditory feedback alone might not be enough.


Disadvantages:
    Dependency on Internet Connection: The project uses Google's speech recognition service, which necessitates an internet connection, to process audio input. This limits the project's dependability in offline environments by adding a potential point of failure in the event that the internet connection is erratic or unavailable.
    Speech Recognition Accuracy: Variations in background noise, accent diversity, and speech patterns can all affect how accurate a system is at recognising speech. Sometimes users misunderstand voice commands, which can result in inadvertent actions or frustration.
    Hardware Requirements: Some components of the project's hardware, like an Arduino board, speaker, microphone, and ILI9341 TFT display, may not be easily accessible to all users. The project becomes more complex and expensive when these components are acquired and assembled.
    Limited Command Set: The predetermined set of voice commands mapped to particular actions limits the voice-controlled system's efficacy. It might be necessary to make considerable changes to the codebase and conduct more testing in order to add new commands or expand functionality.
    Maintenance and Support: To fix bugs, compatibility problems, or updates to external dependencies, as with any software project, continuous maintenance and support may be needed. The project's longevity and compatibility with upcoming platforms or libraries might be jeopardised in the absence of regular maintenance.


**NOTE:
    1.SD card should be of (FAT32 format)File Allocation Table 32, is a 32-bit version of the file allocation table (FAT) file system.
    2.For improved connectivity, incorporate resistors into the setup.
    3.There should exist predefined words with corresponding image names for display on a TFT screen when detected by a microphone.
      For example, if the microphone detects "hi," an image named "hi.bmp" should be displayed on the TFT screen.

