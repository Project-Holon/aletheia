/*
 * function: func_021BC688
 * address: 0x021BC688
 * packet: pkt_ov217_021BC688
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent ends in two zero alignment bytes at 021BC6CE.
 * 021BC3AC is void in its source but forwards to 02040804. Original reads
 * r0 as a signed coordinate, so declare int and preserve its visible input.
 * symbols:
 *   func_021BC3AC 0x021BC3AC thumb ov217
 *   ListViewState_SetScrollY 0x021C0E04 thumb ov217
 *   ListViewState_SetScrollX 0x021C0E00 thumb ov217
 *   ListViewState_SetMode 0x021C0DFC thumb ov217
 */
#include "../include/Obj04639.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021BC3AC(void);
extern void ListViewState_SetScrollY(void *, u32);
extern void ListViewState_SetScrollX(void *, u32);
extern void ListViewState_SetMode(void *, u8);
void func_021BC688(char *p)
{
    int y;
    if (*(u32 *)&((struct Obj04639 *)p)->f4 != 0) {
        y = func_021BC3AC();
        if (y < -24) y = -24;
        if (y > 72) y = 72;
        ListViewState_SetScrollY(((struct Obj04639 *)p)->f4, y);
        y = ((struct Obj04639 *)p)->f34;
        if (y < 0) y = 0;
        if (y > 240) y = 240;
        ListViewState_SetScrollX(((struct Obj04639 *)p)->f4, y);
        ListViewState_SetMode(((struct Obj04639 *)p)->f4, ((struct Obj04639 *)p)->f32);
    }
}
