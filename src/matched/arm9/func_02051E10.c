/*
 * function: BUTTON_MAN_SlotHandlerPressed
 * address:  0x02051E10
 * packet:   pkt_02051E10
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   BUTTON_MAN_SlotSetKind   0x02051E64  arm
 *
 * State-machine step over a small ARM struct: if the flag byte at +1 is set,
 * bump the halfword at +2 while it is below 0xFFFF and report state 2;
 * otherwise it clears the second argument's slot through BUTTON_MAN_SlotSetKind and
 * reports 1 or 3 depending on whether the incoming second argument was zero.
 * The shared `mov r1, #0` before the compare is the constant both arms pass.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_SlotHandlerPressed.c \
 *       --func BUTTON_MAN_SlotHandlerPressed --addr 0x02051E10 --cc 1.1p1 --arm
 */
#include "../include/Obj04767.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void BUTTON_MAN_SlotSetKind(void *p, int a);

int BUTTON_MAN_SlotHandlerPressed(char *p, u32 x)
{
    if (((struct Obj04767 *)p)->f1 != 0) {
        u16 v = ((struct Obj04767 *)p)->f2;

        if (v < 0xFFFF)
            ((struct Obj04767 *)p)->f2 = (u16)(v + 1);
        return 2;
    }
    if (x != 0) {
        BUTTON_MAN_SlotSetKind(p, 0);
        return 3;
    }
    BUTTON_MAN_SlotSetKind(p, 0);
    return 1;
}
