/*
 * function: BILLBOARD_ACT_SetEntryCommands
 * address:  0x02050804
 * packet:   pkt_02050340
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_SetEntryCommands.c \
 *       --func BILLBOARD_ACT_SetEntryCommands --addr 0x02050804 --cc 1.1p1 --arm
 *
 * symbols:
 *   BILLBOARD_ACT_ResetPlayback  0x020500A0  arm
 */
#include "../include/Obj02611.h"
#include "../include/Obj16156.h"

typedef unsigned short u16;
typedef unsigned int   u32;

extern void BILLBOARD_ACT_ResetPlayback(int p0);

void BILLBOARD_ACT_SetEntryCommands(void *p, int idx, u32 v, u16 h)
{
    char *e = (char *)(((struct Obj16156 *)p)->f18 + idx * 40);

    ((struct Obj02611 *)e)->f8 = v;
    ((struct Obj02611 *)e)->fC = h;
    ((struct Obj02611 *)e)->fE = 0;
    BILLBOARD_ACT_ResetPlayback((int)e);
}
