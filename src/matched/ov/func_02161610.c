/*
 * function: EVENT_FIELD_PROCLINK_ReturnEvolution
 * address:  0x02161610
 * packet:   pkt_02161610
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 */
#include "../include/Obj05854.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;

extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);

int EVENT_FIELD_PROCLINK_ReturnEvolution(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj05854 *)t4)->f18;
a0 = ((struct Obj05854 *)((char *)a0))->f0;
    GAMESYSTEM_GetGameData((const struct Ctx *)a0);
loc_0216161C:
a0 = ((struct Obj05854 *)t4)->f68;
    if (a0 != 3) goto loc_0216162A;
loc_02161622:
a0 = 2;
((struct Obj05854 *)t4)->fC = a0;
a0 = 4;
    return a0;
loc_0216162A:
    if (a0 != 4) goto loc_02161636;
loc_0216162E:
a0 = 0;
((struct Obj05854 *)t4)->fC = a0;
a0 = 4;
    return a0;
loc_02161636:
a0 = 0;
    return a0;}
