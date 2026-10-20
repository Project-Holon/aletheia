#ifndef GAME_OV010_MYSTERY_GIFT_MON_H
#define GAME_OV010_MYSTERY_GIFT_MON_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mystery_gift_mon.c, prototypes copied from their definitions. */

struct PokemonParam;
struct GiftMon;
struct GameData;
typedef struct GiftMon GiftMon;

struct PokemonParam *MYSTERY_GIFT_CreateMon(const GiftMon *gift, int heapId, struct GameData *gameData);
/* END mkheaders: generated region */

#endif
