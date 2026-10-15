/*
 * function: BEACON_VIEW_FreeGraphics
 * address:  0x021F2EDC
 * packet:   pkt_ov032_021F2EDC
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BEACON_VIEW_FreeGraphics 0x021F2EDC thumb
 *   func_020307B0 0x020307B0 arm
 *   BEACON_VIEW_FreeResSet 0x021F31A8 thumb ov032
 */
#include "../include/Obj00812.h"

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void BEACON_VIEW_FreeResSet(char *, char *);

void BEACON_VIEW_FreeGraphics(char *p)
{
    int i;

    for (i = 0; i < 12; i++) {
        func_020307B0((void *)(*(int *)(p + 0x2dc + i * 8)));
    }
    for (i = 0; i < 16; i++) {
        func_020307B0((void *)(*(int *)(p + 0x33c + i * 8)));
    }
    func_020307B0((void *)(((struct Obj00812 *)p)->f3CC));
    func_020307B0((void *)(((struct Obj00812 *)p)->f3C0));
    BEACON_VIEW_FreeResSet(p, p + 0x14c);
    BEACON_VIEW_FreeResSet(p, p + 0x164);
    BEACON_VIEW_FreeResSet(p, p + 0x134);
}
