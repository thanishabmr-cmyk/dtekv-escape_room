#ifndef GAME_H
#define GAME_H

// ---- Data Structures ----
typedef struct {
    char name[20];
    char description[100];
    int neighbors[4];   // 0=N, 1=E, 2=S, 3=W
    int has_key;
} Room;

typedef struct {
    int current_room;
    int has_key;
    int health;
} Player;

// ---- Functions ----
void init_world();
void print_status();
void move_player(int dir);
void pickup_item();
int check_win();
#endif
