/*
 * function: GSYNC_DISP_VBlankTask
 * address: 0x021D60F8
 * packet: pkt_ov123_021D60F8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   GX_LoadBGPltt 0x0207E3D0 arm
 *   func_0207E468 0x0207E468 arm
 */
#include "../include/Obj06462.h"
#include "../include/Obj22948.h"
typedef unsigned char u8;
extern void CLACT_VBlankSystem(void);
extern void GX_LoadBGPltt(void *, unsigned int, unsigned int);
extern void func_0207E468(void *, unsigned int, unsigned int);
void GSYNC_DISP_VBlankTask(void *a, u8 *p)
{
    int n;
    u8 *base;
    int off;
    CLACT_VBlankSystem();
    n = ((struct Obj06462 *)p)->f4564 + 1;
    ((struct Obj06462 *)p)->f4564 = n;
    if (n % 10 == 1) {
        base = *(u8 * *)&((struct Obj22948 *)(*(u8 * *)&((struct Obj06462 *)p)->f18))->fC;
        off = (n / 10 + 2) * 32;
        GX_LoadBGPltt(base + off, 64, 32);
        func_0207E468(base + off, 64, 32);
    }
    if (((struct Obj06462 *)p)->f4564 >= 80) ((struct Obj06462 *)p)->f4564 = 0;
}
