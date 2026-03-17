#include "game.h"
#include "io.h"
#include "timer.h"

int main() {
    board_init();     // LEDs, buttons, timer setup
    game_init();      // İlk oda ve oyuncu durumunu ayarla

    while(1) {
        handle_input();   // Butonları oku, state machine güncelle
        update_leds();    // Oyuncu durumu veya itemleri LED ile göster
        timer_check();    // Timer eventlerini çalıştır
    }

    return 0;
}
