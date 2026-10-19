#ifndef GAME_ARM9_OS_TICK_H
#define GAME_ARM9_OS_TICK_H

/* Public functions of os_tick.c, prototypes copied from their definitions. */

void OS_InitTick(void);
BOOL OS_IsTickAvailable(void);
void OSi_CountUpTick(void);
OSTick OS_GetTick(void);
unsigned short OS_GetTickLo(void);

#endif
