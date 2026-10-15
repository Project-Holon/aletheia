/*
 * function: SHORTCUT_MENU_ScrollStep
 * address:  0x021C59BC
 * packet:   pkt_ov021_021C59BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Scroll step: slides the BG by 0xC0/4 per frame and flags the end after 4.
 *
 * symbols:
 *   BG_SYS_FillScrollArea  0x02040618  arm  arm9
 */
#include "../include/Obj09688.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void BG_SYS_FillScrollArea(u32 layer, u32 a, u32 b);

void SHORTCUT_MENU_ScrollStep(void *a, u8 *p)
{
    u16 n = ((struct Obj09688 *)p)->f72;
    int v = n * 0xC0 / 4 - 0xC0;

    (((struct Obj09688 *)p)->f72)++;
    if (n >= 4) {
        v = 0;
        ((struct Obj09688 *)p)->f80 = 1;
    }
    BG_SYS_FillScrollArea(1, 3, v);
}
