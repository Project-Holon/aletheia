/*
 * function: GAMESYSTEM_UpdateEventActiveFlag
 * address:  0x020120A4
 * packet:   pkt_02011F28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_EVENT_IsRunning  0x020123C4  thumb
 */
#include "../include/Obj15622.h"

extern int GAME_EVENT_IsRunning(void *p);
void GAMESYSTEM_UpdateEventActiveFlag(char *p)
{
    ((struct Obj15622 *)p)->f31 = (unsigned char)GAME_EVENT_IsRunning(p);
}
