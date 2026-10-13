/*
 * function: SHORTCUT_MENU_Start
 * address:  0x021C5348
 * packet:   pkt_ov021_021C5348
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Starts the fade sequence once (state 0 to 1).
 */
#include "../include/Obj07562.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02040588(unsigned char which, unsigned char enable);

void SHORTCUT_MENU_Start(u8 *p)
{
    if (((struct Obj07562 *)p)->f70 == 0) {
        ((struct Obj07562 *)p)->f74 = 0;
        ((struct Obj07562 *)p)->f78 = 0x19;
        func_02040588(1, 1);
        ((struct Obj07562 *)p)->f70 = 1;
    }
}
