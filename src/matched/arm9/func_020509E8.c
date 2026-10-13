/*
 * function: BILLBOARD_ACT_CmdSetList
 * address:  0x020509E8
 * packet:   pkt_02050340
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_CmdSetList.c \
 *       --func BILLBOARD_ACT_CmdSetList --addr 0x020509E8 --cc 1.1p1 --arm
 *
 * symbols:
 *   BILLBOARD_ACT_ResetPlayback  0x020500A0  arm
 */
#include "../include/Obj02611.h"
#include "../include/Obj16164.h"

typedef unsigned short u16;

extern void BILLBOARD_ACT_ResetPlayback(int p0);

int BILLBOARD_ACT_CmdSetList(void *p, void *q)
{
    ((struct Obj02611 *)p)->fE = ((struct Obj16164 *)q)->f2;
    BILLBOARD_ACT_ResetPlayback((int)p);
    return 0;
}
