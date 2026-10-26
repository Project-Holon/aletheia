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

struct GameEvent *EVENT_WORLDTRADE_Entry(struct GameSystem *gameSystem, Pair *request);
struct GameEvent *EVENT_WORLDTRADE_Create(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int unused);
int EVENT_WORLDTRADE_Main(struct GameEvent *event, int *seq, void *work);
/* END mkheaders: generated region */

#endif
