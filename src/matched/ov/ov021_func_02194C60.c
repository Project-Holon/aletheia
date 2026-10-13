/*
 * function: TALKMSGWIN_UpdatePlainWindow
 * address:  0x02194C60
 * packet:   pkt_ov021_02194C60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TALKMSGWIN_DrawEntryFrame  0x02195E70  thumb  ov021
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 *   TALKMSGWIN_ReleaseEntry  0x02194B3C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01351.h"
#include "../include/Obj02377.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void TALKMSGWIN_DrawEntryFrame(u8 *p, u8 *e);
extern u32 PRINTSYS_PrintStream(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern void TALKMSGWIN_ReleaseEntry(u8 *p, u8 *e);

void TALKMSGWIN_UpdatePlainWindow(u8 *p, u8 *e)
{
    u32 t;

    switch (((struct Obj02377 *)e)->f0) {
    case 2:
        ((struct Obj02377 *)e)->f5E = 0;
        ((struct Obj02377 *)e)->f0 = 3;
    case 3:
        ((struct Obj02377 *)e)->f0 = 4;
        t = ((struct Obj02377 *)e)->f60;
        TALKMSGWIN_DrawEntryFrame(p, e);
        ((struct Obj02377 *)e)->f8 = PRINTSYS_PrintStream(((struct Obj02377 *)e)->fC, e[0x5C], e[0x5D], ((struct Obj02377 *)e)->f14,
                                        ((struct Obj01351 *)p)->f8, t, *(u32 *)&((struct Obj01351 *)p)->fC98, 0, ((struct Obj01351 *)p)->f0, 15);
        return;
    case 5:
        ((struct Obj02377 *)e)->f0 = 6;
        return;
    case 6:
        TALKMSGWIN_ReleaseEntry(p, e);
        return;
    }
}
