#ifndef GAME_BEACON_SEARCH_SHARED_TYPES_H
#define GAME_BEACON_SEARCH_SHARED_TYPES_H

#include "../arm9/game_beacon_types.h"

struct MyStatus;
struct Strbuf;

/* ------------------------------------------------------------------ *
 * The table of received beacons, 0xB08 bytes.
 * ------------------------------------------------------------------ */
typedef struct GameBeaconInfoTable {
    GameBeaconInfo info[30];    /* 0x000 */
    u16 receiveTime[30];        /* 0xAC8: hour << 8 | minute */
    u8  head;                   /* 0xB04: ring start */
    u8  count;                  /* 0xB05 */
} GameBeaconInfoTable;

#endif
