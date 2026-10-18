/*
 * function: STA_ACT_LIGHT_SetActorAngle
 * address:  0x021F8068
 * packet:   pkt_ov112_021F8068
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   STA_ACT_LIGHT_SetActorAngle   0x021F8068  thumb  ov112
 *
 * note: unlabelled leaf in ov112 (the listing emits it as a .word run), filed
 * to witness the bl from src/pending/SCRIPT_COMMAND_TaskRotate.c.  The first
 * argument is ignored; the original moves r1 into r0, so the pointer is the
 * second parameter.
 */
#include "../include/Obj08033.h"

typedef unsigned short u16;
typedef unsigned int u32;

void STA_ACT_LIGHT_SetActorAngle(int self, char *p, u16 v)
{
    ((struct Obj08033 *)p)->f48 = v;
    if (((struct Obj08033 *)p)->f10 == 1)
        ((struct Obj08033 *)p)->f48 = 0;
    ((struct Obj08033 *)p)->f4 = 1;
}
