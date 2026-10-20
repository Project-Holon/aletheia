#ifndef GAME_ARM9_ISS_ZONE_SYS_H
#define GAME_ARM9_ISS_ZONE_SYS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of iss_zone_sys.c, prototypes copied from their definitions. */

struct IssZone;

#include "../types.h"

struct IssZone *ISS_ZONE_SYS_Create(u32 heapId);
void ISS_ZONE_SYS_Delete(struct IssZone *zone);
void ISS_ZONE_SYS_Update(struct IssZone *zone);
void ISS_ZONE_SYS_SwitchZone(struct IssZone *zone, u32 key);
void ISS_ZONE_SYS_Start(struct IssZone *zone, u16 key);
void ISS_ZONE_SYS_Stop(struct IssZone *zone);
void ISS_ZONE_SYS_LoadRecords(struct IssZone *zone, u32 heapId);
void ISS_ZONE_SYS_SelectRecord(struct IssZone *zone, u16 key);
void ISS_ZONE_SYS_ClearActive(u32 *active);
void ISS_ZONE_SYS_BeginFade(struct IssZone *zone, u32 key);
u32 ISS_ZONE_SYS_FindRecord(const struct IssZone *zone, u32 key);
void ISS_ZONE_SYS_StepFade(struct IssZone *zone);
/* END mkheaders: generated region */

#endif
