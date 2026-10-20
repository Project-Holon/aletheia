#ifndef GAME_ARM9_EVENT_ID_H
#define GAME_ARM9_EVENT_ID_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_id.c, prototypes copied from their definitions. */

struct SaveData;

#include "../types.h"

unsigned int PLACE_NAME_GetBank(unsigned int id);
unsigned int PLACE_NAME_GetIndex(unsigned int id);
u32 WAZA_TOOL_IsHmMove(void *unused, u16 value, u16 unused2);
int POKE_TOOL_HasNoHmMove(struct SaveData *save, int unused);
/* END mkheaders: generated region */

#endif
