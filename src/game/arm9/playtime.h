#ifndef GAME_ARM9_PLAYTIME_H
#define GAME_ARM9_PLAYTIME_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of playtime.c, prototypes copied from their definitions. */

struct PlayTime;
struct PlayTimeStamp;

#include "../types.h"

void *PLAYTIME_Create(u32 heap_id);
void PLAYTIME_Init(struct PlayTime *playtime);
void PLAYTIME_AddSeconds(struct PlayTime *playtime, u32 seconds_to_add);
void PLAYTIME_Copy(struct PlayTime *dest, const struct PlayTime *src);
u16 PLAYTIME_GetHours(const struct PlayTime *playtime);
u8 PLAYTIME_GetMinutes(const struct PlayTime *playtime);
u8 PLAYTIME_GetSeconds(const struct PlayTime *playtime);
void PLAYTIME_SetStampNow(struct PlayTime *playtime);
u32 PLAYTIME_GetStampYear(const struct PlayTime *playtime);
u32 PLAYTIME_GetStampMonth(const struct PlayTime *playtime);
u32 PLAYTIME_GetStampDay(const struct PlayTime *playtime);
u32 PLAYTIME_GetStampHour(const struct PlayTime *playtime);
u32 PLAYTIME_GetStampMinute(const struct PlayTime *playtime);
void PLAYTIME_GetStamp(const struct PlayTime *playtime, struct PlayTimeStamp *out);
void PLAYTIME_SetStamp(struct PlayTime *playtime, const struct PlayTimeStamp *in);
/* END mkheaders: generated region */

#endif
