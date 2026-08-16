// ============================================================
//   ESP32-WROOM-32 + ST7789 240x320
// ============================================================

#define ST7789_DRIVER
#define TFT_WIDTH  240
#define TFT_HEIGHT 320

// SPI пины
#define TFT_MOSI 23
#define TFT_SCLK 18
// #define TFT_MISO 19   // ЗАКОММЕНТИРОВАНО - не используем

#define TFT_CS   5
#define TFT_DC   2
#define TFT_RST  4

// Частота SPI (для ESP32-WROOM стабильна 40MHz)
#define SPI_FREQUENCY  40000000
#define SPI_READ_FREQUENCY  20000000

// Шрифты (оставляем как есть)
#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8
#define LOAD_GFXFF
#define SMOOTH_FONT