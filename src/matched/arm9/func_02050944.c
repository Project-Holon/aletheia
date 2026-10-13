/*
 * function: BILLBOARD_ACT_RunControlCommand
 * address:  0x02050944
 * packet:   pkt_02050340
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_RunControlCommand.c \
 *       --func BILLBOARD_ACT_RunControlCommand --addr 0x02050944 --cc 1.1p1 --arm
 *
 * symbols:
 *   BILLBOARD_ACT_GetControlHandler  0x02050984  arm
 */
#include "../include/Obj16163.h"

typedef unsigned short u16;

struct S14 {
    u16 f : 14;
};

extern int BILLBOARD_ACT_GetControlHandler(int a);

int BILLBOARD_ACT_RunControlCommand(void *p, struct S14 *q)
{
    int (*fn)(void *, struct S14 *);

    fn = (int (*)(void *, struct S14 *))BILLBOARD_ACT_GetControlHandler(q->f);
    ((struct Obj16163 *)p)->f1C = q->f;
    return fn(p, q);
}
