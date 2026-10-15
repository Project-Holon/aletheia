/*
 * function: BOX2_UI_MoveCursorToHeld
 * address:  0x021EECB0
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_UI_UpdateCursor  0x021EE408  thumb  ov170
 *   CURSOR_MOVE_SetCurrent  0x020260E4  thumb  arm9
 *
 * Re-key the 0xA168 field unless the caller has a real selector.
 *   Two register facts pin it: the else-branch call must forward BOTH
 *   live argument registers (BOX2_UI_UpdateCursor(p, a) -- the one-argument
 *   form makes the range-check temp land in r1 where the image has r2),
 *   and the stored value is the reloaded 0xA168 word, not the call's
 *   result (the field is re-read after the 0x70 call).
 */
#include "../include/Obj07241.h"

typedef unsigned char  u8;
struct Sound;
extern void CURSOR_MOVE_SetCurrent(struct Sound *obj, u8 sel);
extern void BOX2_UI_UpdateCursor(char *, int);


void BOX2_UI_MoveCursorToHeld(char *p, int a)
{
    int v;
    if (a == 0 || (unsigned)(a - 5) <= 1) {
        CURSOR_MOVE_SetCurrent((struct Sound *)(*(int *)(((struct Obj07241 *)p)->f2C + 0x70)),
                      *(int *)(((struct Obj07241 *)p)->f2C + 0xA168) & 0xff);
        v = *(int *)(((struct Obj07241 *)p)->f2C + 0xA168);
    } else {
        BOX2_UI_UpdateCursor(p, a);
        v = a;
    }
    *(int *)(((struct Obj07241 *)p)->f2C + 0xA168) = v;
}

