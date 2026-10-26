#ifndef GAME_OV112_MUSICAL_SYSTEM_H
#define GAME_OV112_MUSICAL_SYSTEM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of musical_system.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov010/musical_event_shared_types.h"

char *MUSICAL_MCSS_CreateMon(void *a,u16 heap);
char *MUSICAL_MCSS_AllocMon(u16 a,u8 b,u8 c,u8 d,u32 e,u16 heap);
MusicalSystemHead *MUSICAL_MCSS_AllocDistSave(u32 heap);
void MUSICAL_MCSS_FreeDistSave(MusicalSystemHead *p);
void MUSICAL_MCSS_LoadDistSave(MusicalSystemHead *m, void *unused, void *sys, u8 kind, u16 heap);
/* END mkheaders: generated region */

#endif
