#include <Adafruit_GFX.h>         // Core graphics library
#include <Adafruit_ILI9341.h>     // Hardware-specific library
#include <SdFat.h>                // SD card & FAT filesystem library
#include <Adafruit_SPIFlash.h>    // SPI / QSPI flash library
#include <Adafruit_ImageReader.h> // Image-reading functions

// Comment out the next line to load from SPI/QSPI flash instead of SD card:
#define USE_SD_CARD

// Pin definitions for 2.4" TFT FeatherWing vary among boards...

#if defined(ESP8266)
  #define TFT_CS   0
  #define TFT_DC   15
  #define SD_CS    2
#elif defined(ESP32) && !defined(ARDUINO_ADAFRUIT_FEATHER_ESP32S2)
  #define TFT_CS   15
  #define TFT_DC   33
  #define SD_CS    14
#elif defined(TEENSYDUINO)
  #define TFT_DC   10
  #define TFT_CS   4
  #define SD_CS    8
#elif defined(ARDUINO_STM32_FEATHER)
  #define TFT_DC   PB4
  #define TFT_CS   PA15
  #define SD_CS    PC5
#elif defined(ARDUINO_NRF52832_FEATHER) // BSP 0.6.5 and higher!
  #define TFT_DC   11
  #define TFT_CS   31
  #define SD_CS    27
#elif defined(ARDUINO_MAX32620FTHR) || defined(ARDUINO_MAX32630FTHR)
  #define TFT_DC   P5_4
  #define TFT_CS   P5_3
  #define STMPE_CS P3_3
  #define SD_CS    P3_2
#else // Anything else!
  #define TFT_CS   8
  #define TFT_DC   10
  #define SD_CS    4
  #define TFT_RST    9
#endif

#if defined(USE_SD_CARD)
  SdFat                SD;         // SD card filesystem
  Adafruit_ImageReader reader(SD); // Image-reader object, pass in SD filesys
#else
  // SPI or QSPI flash filesystem (i.e. CIRCUITPY drive)
  #if defined(__SAMD51__) || defined(NRF52840_XXAA)
    Adafruit_FlashTransport_QSPI flashTransport(PIN_QSPI_SCK, PIN_QSPI_CS,
      PIN_QSPI_IO0, PIN_QSPI_IO1, PIN_QSPI_IO2, PIN_QSPI_IO3);
  #else
    #if (SPI_INTERFACES_COUNT == 1)
      Adafruit_FlashTransport_SPI flashTransport(SS, &SPI);
    #else
      Adafruit_FlashTransport_SPI flashTransport(SS1, &SPI1);
    #endif
  #endif
  Adafruit_SPIFlash    flash(&flashTransport);
  FatVolume        filesys;
  Adafruit_ImageReader reader(filesys); // Image-reader, pass in flash filesys
#endif

Adafruit_ILI9341       tft    = Adafruit_ILI9341(TFT_CS, TFT_DC,TFT_RST );
Adafruit_Image         img;        // An image loaded into RAM
int32_t                width  = 0, // BMP image dimensions
                       height = 0;
ImageReturnCode stat;
int st=0;
void setup(void) {

  

  Serial.begin(9600);
  while(!Serial)  delay(100);       // Wait for Serial Monitor before continuing

  tft.begin();          // Initialize screen

  // The Adafruit_ImageReader constructor call (above, before setup())
  // accepts an uninitialized SdFat or FatVolume object. This MUST
  // BE INITIALIZED before using any of the image reader functions!
  Serial.print(F("Initializing filesystem..."));
#if defined(USE_SD_CARD)
  // SD card is pretty straightforward, a single call...
  if(!SD.begin(SD_CS, SD_SCK_MHZ(25))) { // ESP32 requires 25 MHz limit
    Serial.println(F("SD begin() failed"));
    for(;;); // Fatal error, do not continue
  }
#else
  // SPI or QSPI flash requires two steps, one to access the bare flash
  // memory itself, then the second to access the filesystem within...
  if(!flash.begin()) {
    Serial.println(F("flash begin() failed"));
    for(;;);
  }
  if(!filesys.begin(&flash)) {
    Serial.println(F("filesys begin() failed"));
    for(;;);
  }
#endif
  Serial.println(F("OK!"));

 
  tft.fillScreen(ILI9341_BLUE);

 


  
  delay(2000); // Pause 2 seconds before moving on to loop()
}

void loop() {

  if(st==0)
  {
    st=1;
  
  Serial.print(F("Loading purple.bmp to screen..."));
  stat = reader.drawBMP("/1.bmp", tft, 0, 0);
  reader.printStatus(stat);   // How'd we do?
    delay(3000); // Pause 2 sec.
}

  if(Serial.available())
  {
    
  int x=Serial.read();
  if(x=='1')
  {
    st=0;
     tft.fillScreen(ILI9341_RED);
    delay(2000); 
    stat = reader.drawBMP("/tq.bmp", tft, 0, 0);
    reader.printStatus(stat);   // How'd we do?
    delay(6000); // Pause 2 sec.
  }
  if(x=='2')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(2000); 
    stat = reader.drawBMP("/gb.bmp", tft, 0, 0);
    reader.printStatus(stat);
    delay(6000); // Pause 2 sec.
  }
  if(x=='3')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/angry.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if(x=='4')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/aunt.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if(x=='5')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/baby.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
    if(x=='6')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(2000); 
    stat = reader.drawBMP("/bag.bmp", tft, 0, 0);
    reader.printStatus(stat);   // How'd we do?
    delay(6000); // Pause 2 sec.
  }
  if(x=='7')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(2000); 
    stat = reader.drawBMP("/bathroom.bmp", tft, 0, 0);
    reader.printStatus(stat);   // How'd we do?
    delay(6000); // Pause 2 sec.
  }
  if(x=='8')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/bed.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if(x=='9')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/book.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if(x=='10')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/bored.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
    if(x=='11')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(2000); 
    stat = reader.drawBMP("/bro.bmp", tft, 0, 0);
    reader.printStatus(stat);   // How'd we do?
    delay(6000); // Pause 2 sec.
  }
  if(x=='12')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(2000); 
    stat = reader.drawBMP("/brother.bmp", tft, 0, 0);
    reader.printStatus(stat);   // How'd we do?
    delay(6000); // Pause 2 sec.
  }
  if(x=='13')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/car.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if(x=='14')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/chair.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if(x=='15')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/clock.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
    if(x=='16')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(2000); 
    stat = reader.drawBMP("/clothes.bmp", tft, 0, 0);
    reader.printStatus(stat);   // How'd we do?
    delay(6000); // Pause 2 sec.
  }
  if(x=='17')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(2000); 
    stat = reader.drawBMP("/cold.bmp", tft, 0, 0);
    reader.printStatus(stat);   // How'd we do?
    delay(6000); // Pause 2 sec.
  }
  if(x=='18')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/color.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if(x=='19')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/computer.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if(x=='20')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/confused.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='21')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/cousin.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='22')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/curious.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
    if (x=='23')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/dad.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='24')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/daughter.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='25')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/day.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='26')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/dont know.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='27')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/door.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='28')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/download.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='29')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/drink.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='30')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/early.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='31')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/earth.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='32')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/eat.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='33')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/embarrassed.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='34')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/evening.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='35')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/false.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='36')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/father.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='37')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/finish.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='38')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/food.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='39')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/fork.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='40')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/friend.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='41')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/frustrated.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='42')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/future.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='43')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/gift.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='44')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/glasses.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='45')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/good morning.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='46')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/good night.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='47')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/goodbye.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='48')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/grandfather.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='49')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/grandmother.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='50')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/happy.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='51')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/hat.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='52')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/hello.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='53')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/help.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='54')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/hi.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='55')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/home.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='56')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/hot.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='57')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/hour.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='58')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/how many.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='59')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/how much.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
  if (x=='60')
  {
    st=0;
     tft.fillScreen(ILI9341_BLUE);
    delay(200);
    stat = reader.drawBMP("/how.bmp", tft, 0,0);
    reader.printStatus(stat);
    delay(6000);
  }
}
}