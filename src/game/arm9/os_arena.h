#ifndef GAME_ARM9_OS_ARENA_H
#define GAME_ARM9_OS_ARENA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of os_arena.c, prototypes copied from their definitions. */

#include "../types.h"

void OS_InitArena(void);
void OS_InitArenaEx(void);
u32 OS_GetArenaHi(u32 arenaId);
u32 OS_GetArenaLo(u32 arenaId);
void *OS_GetInitArenaHi(int arenaId);
void *OS_GetInitArenaLo(int arenaId);
void OS_SetArenaHi(u32 arenaId, u32 newHi);
void OS_SetArenaLo(u32 arenaId, u32 newLo);
u32 OS_AllocFromArenaLo(int arenaId, u32 size, int alignment);
/* END mkheaders: generated region */

#endif
