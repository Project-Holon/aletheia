/*
 * function: INTRUDE_SUBDISP_VBlankTask
 * address:  0x0217D5AC
 * packet:   pkt_ov018_0217D5AC
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DC_FlushRange  0x020862F0  arm
 *   func_0207E5D0  0x0207E5D0  arm
 *   func_0207E804  0x0207E804  arm
 */
#include "../include/Obj03091.h"

typedef unsigned char u8;

extern void DC_FlushRange();
extern void func_0207E5D0();
extern void func_0207E804();

void INTRUDE_SUBDISP_VBlankTask(int a0, u8 *p)
{
    p[0x11D] ^= 1;
    if (p[0x11D] != 0) {
        if (p[0x11C] != 0) {
            DC_FlushRange(p + 0x130, 8);
            func_0207E5D0(p + 0x130, 0x102, 8);
            p[0x11C] = 0;
        }
        if (p[0x10F] != 0) {
            DC_FlushRange(((struct Obj03091 *)p)->fD0, 0x200);
            func_0207E804(((struct Obj03091 *)p)->fD0, ((struct Obj03091 *)p)->fD4, 0x200);
            p[0x10F] = 0;
        }
    }
}
