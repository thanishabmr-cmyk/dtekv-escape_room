/*#include "game.h"
#include "io.h"

Player player;

void game_init() {
    player.room_id = 0;
    player.has_key = 0;
    player.health = 3;
}

void handle_input() {
    if(button_pressed(0)) move_player(0); // örnek: 0 = kuzey
    if(button_pressed(1)) move_player(1); // örnek: 1 = güney
}

void move_player(int direction) {
    // Minimal state machine
    if(direction == 0) player.room_id++;
    if(direction == 1 && player.room_id > 0) player.room_id--;
}*/

#include "game.h"
#include <stdio.h>
#include <string.h>

// ---- Global World ----
#define NUM_ROOMS 9
Room world[NUM_ROOMS];
Player player;

// ---- Init World ----
void init_world() {
    // [0] Entrance
    world[0] = (Room) {
        "Entrance",
        "You are at the entrance of the dungeon.",
        {1, -1, -1, -1},
        0
    };

    // [1] Hallway
    world[1] = (Room) {
        "Hallway",
        "A narrow hallway leading deeper into the dungeon.",
        {3, 2, 0, -1},
        0
    };

    // [2] Armory
    world[2] = (Room) {
        "Armory",
        "Dusty weapons and rusty shields are scattered here.",
        {-1, -1, -1, 1},
        1  // key placed here
    };

    // [3] Puzzle Room
    world[3] = (Room) {
        "Puzzle Room",
        "The walls are inscribed with strange runes.",
        {4, -1, 1, -1},
        0
    };

    // [4] Library
    world[4] = (Room) {
        "Library",
        "Shelves of ancient books. One passage mentions a secret lab.",
        {6, 5, 3, -1},
        0
    };

    // [5] Secret Lab
    world[5] = (Room) {
        "Secret Lab",
        "Hidden behind the library, filled with alchemical tools.",
        {-1, -1, -1, 4},
        0
    };

    // [6] Guard Room
    world[6] = (Room) {
        "Guard Room",
        "A hostile guard blocks part of the way!",
        {7, -1, 4, -1},
        0
    };

    // [7] Boss Antechamber
    world[7] = (Room) {
        "Boss Antechamber",
        "The air feels heavy... The boss room is just ahead.",
        {8, -1, 6, -1},
        0
    };

    // [8] Boss Room
    world[8] = (Room) {
        "Boss Room",
        "The final chamber. The Boss awaits!",
        {-1, -1, 7, -1},
        0
    };

    // init player
    player.current_room = 0;
    player.has_key = 0;
    player.health = 3;
}

// ---- Status ----
void print_status() {
    Room *r = &world[player.current_room];
    printf("\n== %s ==\n", r->name);
    printf("%s\n", r->description);

    if (r->has_key)
        printf("There is a key here.\n");

    printf("Health: %d\n", player.health);
    if (player.has_key)
        printf("[Inventory: Key]\n");
}

// ---- Movement ----
void move_player(int dir) {
    Room *r = &world[player.current_room];
    int next = r->neighbors[dir];
    if (next == -1) {
        printf("You can't go that way.\n");
    } else if (next == 8 && !player.has_key) {
        printf("The boss door is locked. You need a key!\n");
    } else {
        player.current_room = next;
    }
}

// ---- Pickup ----
void pickup_item() {
    Room *r = &world[player.current_room];
    if (r->has_key) {
        printf("You picked up the key!\n");
        r->has_key = 0;
        player.has_key = 1;
    } else {
        printf("There is nothing to pick up.\n");
    }
}

// ---- Win Condition ----
int check_win() {
    if (player.current_room == 8 && player.has_key) {
        return 1;
    }
    return 0;
}