/*
 * function: GAMESYSTEM_IsEventActive
 * address:  0x020120D8
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
#include "../include/Obj15623.h"

extern int GAME_EVENT_IsRunning(void *p);
int GAMESYSTEM_IsEventActive(char *p)
{
    if (GAME_EVENT_IsRunning(p))
        return 1;
    return ((struct Obj15623 *)p)->f31;
}
