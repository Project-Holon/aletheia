/*
 * function: TALKMSGWIN_UpdateBalloon
 * address:  0x02194B84
 * packet:   pkt_ov021_02194B84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TALKMSGWIN_UpdateShape  0x02195338  thumb  ov021
 *   TALKMSGWIN_RedrawEntryFrame  0x02195E80  thumb  ov021
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 *   TALKMSGWIN_ReleaseEntry  0x02194B3C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01351.h"
#include "../include/Obj01493.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 TALKMSGWIN_UpdateShape(u8 *p, u8 *e);
extern int TALKMSGWIN_RedrawEntryFrame(u32 a, u32 b);
extern u32 PRINTSYS_PrintStream(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern void TALKMSGWIN_ReleaseEntry(u8 *p, u8 *e);

void TALKMSGWIN_UpdateBalloon(u8 *p, u8 *e)
{
    u32 t;

    switch (((struct Obj01493 *)e)->f0) {
    case 0:
    case 1:
        break;
    case 2:
        TALKMSGWIN_UpdateShape(p, e);
        ((struct Obj01493 *)e)->f5E = 0;
        ((struct Obj01493 *)e)->f0 = 3;
        return;
    case 3:
        TALKMSGWIN_UpdateShape(p, e);
        if (((struct Obj01493 *)e)->f5E < 8) {
            ((struct Obj01493 *)e)->f5E += 1;
            return;
        }
        ((struct Obj01493 *)e)->f0 = 4;
        t = ((struct Obj01493 *)e)->f60;
        TALKMSGWIN_RedrawEntryFrame((u32)p, (u32)e);
        ((struct Obj01493 *)e)->f8 = PRINTSYS_PrintStream(((struct Obj01493 *)e)->fC, e[0x5C], e[0x5D], ((struct Obj01493 *)e)->f14,
                                        ((struct Obj01351 *)p)->f8, t, *(u32 *)&((struct Obj01351 *)p)->fC98, 0, ((struct Obj01351 *)p)->f0, 15);
        return;
    case 4:
        if (TALKMSGWIN_UpdateShape(p, e) == 1) {
            TALKMSGWIN_RedrawEntryFrame((u32)p, (u32)e);
        }
        return;
    case 5:
        if (((struct Obj01493 *)e)->f5E != 0) {
            ((struct Obj01493 *)e)->f5E -= 1;
            return;
        }
        ((struct Obj01493 *)e)->f0 = 6;
        return;
    case 6:
        TALKMSGWIN_ReleaseEntry(p, e);
        return;
    }
}
