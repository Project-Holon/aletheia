#ifndef GAME_OV010_MUSICAL_DRESSUP_SYS_H
#define GAME_OV010_MUSICAL_DRESSUP_SYS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of musical_dressup_sys.c, prototypes copied from their definitions. */

struct MusicalDressupWork;
typedef struct MusicalDressupWork MusicalDressupWork;

#include "../types.h"
#include "../ov010/musical_event_shared_types.h"

int MUSICAL_DRESSUP_SYS_Init(void *proc, u32 *state, MusicalDressupParam *param);
int MUSICAL_DRESSUP_SYS_Exit(void *proc, int unused1, int unused2, MusicalDressupWork *work);
int MUSICAL_DRESSUP_SYS_Main(void *proc, int *state, int unused, MusicalDressupWork *work);
MusicalDressupParam *MUSICAL_DRESSUP_SYS_Create(int heapId, MusicalPerformer *performer, void *saveControl);
void MUSICAL_DRESSUP_SYS_Delete(MusicalDressupParam *param);
/* END mkheaders: generated region */

#endif
