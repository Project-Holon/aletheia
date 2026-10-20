#ifndef GAME_ARM9_RINGTONE_SYS_H
#define GAME_ARM9_RINGTONE_SYS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of ringtone_sys.c, prototypes copied from their definitions. */

struct Fader;

#include "../arm9/field_sound_system_shared_types.h"
#include "../types.h"

Ringtone *RINGTONE_SYS_Create(u32 heapId, struct Fader *volumeFader);
void RINGTONE_SYS_Delete(Ringtone *ringtone);
void RINGTONE_SYS_Update(Ringtone *ringtone);
void RINGTONE_SYS_Start(Ringtone *ringtone);
void RINGTONE_SYS_Stop(Ringtone *ringtone);
void RINGTONE_SYS_RegisterSleepCallbacks(void);
int RINGTONE_SYS_TickRing(Ringtone *ringtone);
void RINGTONE_SYS_OnSleep(void);
void RINGTONE_SYS_OnWake(void);
void RINGTONE_SYS_StartRing(Ringtone *ringtone);
void RINGTONE_SYS_StopRing(Ringtone *ringtone);
void RINGTONE_SYS_SetBgmMuted(Ringtone *ringtone, u32 muted);
void RINGTONE_SYS_PostEvent(Ringtone *ringtone, int event);
void RINGTONE_SYS_HandleRingTimeout(Ringtone *ringtone);
/* END mkheaders: generated region */

#endif
