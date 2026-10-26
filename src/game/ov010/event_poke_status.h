#ifndef GAME_OV010_EVENT_POKE_STATUS_H
#define GAME_OV010_EVENT_POKE_STATUS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_poke_status.c, prototypes copied from their definitions. */

struct GameSystem;
struct PokeListEventWork;
struct FieldMap;
struct MoveSelectEventWork;
typedef struct PokeListEventWork PokeListEventWork;
typedef struct MoveSelectEventWork MoveSelectEventWork;

#include "../types.h"

void *EVENT_POKE_STATUS_CreatePokeSelectEvent(struct GameSystem *gameSystem, u16 *retDecided, u16 *retSlot);
void *EVENT_POKE_STATUS_CreatePokeSelectMoveEvent(struct GameSystem *gameSystem, u16 *retDecided, u16 *retSlot, int fieldIndex, unsigned short moveId);
void *EVENT_POKE_STATUS_CreatePokeSelectStatusEvent(struct GameSystem *gameSystem, u16 *retDecided, u16 *retSlot);
int EVENT_POKE_STATUS_PokeSelectEvent(struct GameEvent *event, int *seq, void *work);
void *EVENT_POKE_STATUS_CreateMoveSelectEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int pos, u16 *retDecided, u16 *retMovePos, int mode, unsigned short newMove);
int EVENT_POKE_STATUS_MoveSelectEvent(struct GameEvent *event, int *seq, void *work);
/* END mkheaders: generated region */

#endif
