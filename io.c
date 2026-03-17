#include "io.h"

// Board memory map örneği (DTEK-V)
#define LED_BASE   0x04000000
#define BTN_BASE   0x040000d0

void board_init() {
    // LEDs ve butonları ayarlama kodları
}

int button_pressed(int button_id) {
    // Buton okuma (0 veya 1 döndür)
    return 0;
}

void update_leds() {
    // Oyuncu durumunu LED ile göster
}
