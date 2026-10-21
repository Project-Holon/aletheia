#ifndef GAME_ARM9_CONSOLE_STAMP_H
#define GAME_ARM9_CONSOLE_STAMP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of console_stamp.c, prototypes copied from their definitions. */

struct ConsoleStamp;
struct SaveControl;
struct DailyClock;

#include "../types.h"

u32 CONSOLE_STAMP_GetSize(void);
void CONSOLE_STAMP_Init(struct ConsoleStamp *stamp);
struct ConsoleStamp *CONSOLE_STAMP_GetFromSave(struct SaveControl *control);
struct DailyClock *CONSOLE_STAMP_GetDailyClock(struct SaveControl *control);
void CONSOLE_STAMP_SetIdentity(struct ConsoleStamp *stamp);
int CONSOLE_STAMP_IsThisConsole(const struct ConsoleStamp *stamp);
int CONSOLE_STAMP_IsRtcOffsetCurrent(const struct ConsoleStamp *stamp);
u8 CONSOLE_STAMP_GetBirthdayMonth(const struct ConsoleStamp *stamp);
u8 CONSOLE_STAMP_GetBirthdayDay(const struct ConsoleStamp *stamp);
void DAILY_CLOCK_Init(struct DailyClock *clock);
int DAILY_CLOCK_HasAllowance(const struct DailyClock *clock);
void DAILY_CLOCK_Spend(struct DailyClock *clock, u32 minutes);
void DAILY_CLOCK_Refill(struct DailyClock *clock);
/* END mkheaders: generated region */

#endif
