/*
 * function: BUTTON_MAN_SlotSetKind
 * address:  0x02051E64
 * packet:   pkt_02051C6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_SlotSetKind.c \
 *       --func BUTTON_MAN_SlotSetKind --addr 0x02051E64 --cc 1.1p1 --arm
 */
#include "../include/Obj04767.h"

typedef unsigned short u16;

void BUTTON_MAN_SlotSetKind(void *p, int a)
{
    ((struct Obj04767 *)p)->f0 = (unsigned char)a;
    ((struct Obj04767 *)p)->f2 = 0;
}
