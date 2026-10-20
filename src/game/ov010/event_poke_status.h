#ifndef GAME_OV010_EVENT_POKE_STATUS_H
#define GAME_OV010_EVENT_POKE_STATUS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_poke_status.c, prototypes copied from their definitions. */

struct PokeListEventWork;
struct MoveSelectEventWork;
typedef struct PokeListEventWork PokeListEventWork;
typedef struct MoveSelectEventWork MoveSelectEventWork;

#include "../types.h"

void *EVENT_POKE_STATUS_CreatePokeSelectEvent(int gameSystem, u16 *retDecided, u16 *retSlot);
void *EVENT_POKE_STATUS_CreatePokeSelectMoveEvent(int gameSystem, int retDecided, int retSlot, int fieldIndex, unsigned short moveId);
void *EVENT_POKE_STATUS_CreatePokeSelectStatusEvent(int gameSystem, int retDecided, int retSlot);
int EVENT_POKE_STATUS_PokeSelectEvent(void *event, u32 *seq, PokeListEventWork *work);
int EVENT_POKE_STATUS_CreateMoveSelectEvent(int gameSystem, int fieldMap, int pos, int retDecided, int retMovePos, int mode, unsigned short newMove);
int EVENT_POKE_STATUS_MoveSelectEvent(void *event, u32 *seq, MoveSelectEventWork *work);
/* END mkheaders: generated region */

#endif
