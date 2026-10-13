/*
 * function: TALKMSGWIN_Reprint
 * address:  0x0219499C
 * packet:   pkt_ov021_0219499C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201CE48  0x0201CE48  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02376.h"
#include "../include/Obj09486.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec3;
extern void func_0201CE48(struct Rec3 *p);
extern u32 PRINTSYS_PrintStream(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);

void TALKMSGWIN_Reprint(u8 *p, int i, u32 b, u32 c)
{
    u8 *e;

    e = p + 0x18 + i * 100;
    if (((struct Obj02376 *)e)->f8 != 0) {
        func_0201CE48((struct Rec3 *)(((struct Obj02376 *)e)->f8));
        ((struct Obj02376 *)e)->f8 = 0;
    }
    if (b != 0) {
        ((struct Obj02376 *)e)->f60 = c;
        ((struct Obj02376 *)e)->f14 = b;
        ((struct Obj02376 *)e)->f8 = PRINTSYS_PrintStream(((struct Obj02376 *)e)->fC, e[0x5C], e[0x5D], ((struct Obj02376 *)e)->f14,
                                        ((struct Obj09486 *)p)->f8, c, ((struct Obj09486 *)p)->fC98, 0, ((struct Obj09486 *)p)->f0, 15);
        ((struct Obj02376 *)e)->f0 = 4;
    }
}
