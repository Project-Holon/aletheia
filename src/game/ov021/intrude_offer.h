#ifndef GAME_OV021_INTRUDE_OFFER_H
#define GAME_OV021_INTRUDE_OFFER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of intrude_offer.c, prototypes copied from their definitions. */

struct IntrudeOfferLog;
struct IntrudeOfferSlot;
struct IntrudeOfferSpot;
struct GameEvent;
struct GameSystem;
typedef struct IntrudeOfferLog IntrudeOfferLog;
typedef struct IntrudeOfferSlot IntrudeOfferSlot;
typedef struct IntrudeOfferSpot IntrudeOfferSpot;

#include "../types.h"

int INTRUDE_FindOfferSlotAt(IntrudeOfferLog *log, int zoneId, int x, int y, int z);
void INTRUDE_TakeOfferSlot(IntrudeOfferLog *log, int index, IntrudeOfferSlot *dest);
const IntrudeOfferSpot *INTRUDE_GetNextOfferSpot(IntrudeOfferLog *log, int *index);
int INTRUDE_OfferEventMain(struct GameEvent *event, u32 seq, const IntrudeOfferSlot *offer);
struct GameEvent *INTRUDE_StartOfferEvent(struct GameSystem *gameSystem, u32 heapId, int slotIndex);
/* END mkheaders: generated region */

#endif
