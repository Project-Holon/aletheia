/*
 * function: BUTTON_MAN_SlotHandlerIdle
 * address:  0x02051DE8
 * packet:   pkt_02051C6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The conjunction shares one exit; `*(u8 *)(p+1)` is the armed flag the
 * 0x02051E10 sibling also tests.
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_SlotHandlerIdle.c \
 *       --func BUTTON_MAN_SlotHandlerIdle --addr 0x02051DE8 --cc 1.1p1 --arm
 *
 * symbols:
 *   BUTTON_MAN_SlotSetKind  0x02051E64  arm
 */
#include "../include/Obj04767.h"

extern void BUTTON_MAN_SlotSetKind(void *p, int a);

int BUTTON_MAN_SlotHandlerIdle(void *p, int a, int b)
{
    if (((struct Obj04767 *)p)->f1 == 0 || b == 0)
        return -1;
    BUTTON_MAN_SlotSetKind(p, 1);
    return 0;
}
