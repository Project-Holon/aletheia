#ifndef GAME_OV004_EVENT_WORLDTRADE_H
#define GAME_OV004_EVENT_WORLDTRADE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_worldtrade.c, prototypes copied from their definitions. */

struct Pair;
struct GameEvent;
struct WorldTradeEventWork;
typedef struct Pair Pair;
typedef struct WorldTradeEventWork WorldTradeEventWork;

#include "../types.h"

int EVENT_WORLDTRADE_Entry(int gameSystem, Pair *request);
int EVENT_WORLDTRADE_Create(int gameSystem, int fieldMap, int unused);
u32 EVENT_WORLDTRADE_Main(struct GameEvent *event, u32 *seq, WorldTradeEventWork *work);
/* END mkheaders: generated region */

#endif
