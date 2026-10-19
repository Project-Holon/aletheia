#ifndef GAME_ARM9_OS_EMULATOR_H
#define GAME_ARM9_OS_EMULATOR_H

/* Public functions of os_emulator.c, prototypes copied from their definitions. */

u32 OS_GetConsoleType(void);
int OS_IsRunOnEmulator(void);
int OS_IsRunOnTwl(void);
int OSi_IsRunOnTwl(void);

#endif
