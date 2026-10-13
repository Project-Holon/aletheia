/*
 * function: BILLBOARD_ACT_SetEntryCursor
 * address:  0x0205085C
 * packet:   pkt_02050340
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_SetEntryCursor.c \
 *       --func BILLBOARD_ACT_SetEntryCursor --addr 0x0205085C --cc 1.1p1 --arm
 *
 * symbols:
 *   BILLBOARD_ACT_ResetPlayback  0x020500A0  arm
 */
#include "../include/Obj02611.h"
#include "../include/Obj16158.h"

typedef unsigned short u16;
typedef unsigned int   u32;

extern void BILLBOARD_ACT_ResetPlayback(int p0);

void BILLBOARD_ACT_SetEntryCursor(void *p, int idx, u32 v)
{
    char *e = (char *)(((struct Obj16158 *)p)->f18 + idx * 40);

    BILLBOARD_ACT_ResetPlayback((int)e);
    ((struct Obj02611 *)e)->f10 = v;
}
