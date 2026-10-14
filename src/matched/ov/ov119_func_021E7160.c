/*
 * function: POKETRADE_2D_FadePaletteCopy
 * address:  0x021E7160
 * packet:   pkt_021D8B54
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 *   DWCi_ScreenDC_FlushRange  0x020862F0  arm
 *   func_0207E468  0x0207E468  arm
 *   func_0207E5D0  0x0207E5D0  arm
 *   POKETRADE_2D_FadePaletteBank  0x021E7098  thumb  ov119
 */
#include "../include/Obj05339.h"

typedef unsigned int u32;

extern void MI_CpuCopy8(void *dst, void *src, int n);
extern void DWCi_ScreenDC_FlushRange(void *a, u32 b);
extern void func_0207E468(void *a, u32 b, u32 c);
extern void func_0207E5D0(void *a, u32 b, u32 c);
extern void POKETRADE_2D_FadePaletteBank(char *p, int bank, int mask);

void POKETRADE_2D_FadePaletteCopy(void *p, int a1, int a2, int a3)
{
    if (a1 != 0) {
        if (a2 == 3)
            MI_CpuCopy8((void *)0x05000600, ((struct Obj05339 *)p)->f10A4,
                          0x200);
        else if (a2 == 1)
            MI_CpuCopy8((void *)0x05000400, ((struct Obj05339 *)p)->f10A8,
                          0x200);
        POKETRADE_2D_FadePaletteBank(p, a2, a3);
        return;
    }
    if (a2 == 3) {
        DWCi_ScreenDC_FlushRange(((struct Obj05339 *)p)->f10A4, 0x200);
        func_0207E5D0(((struct Obj05339 *)p)->f10A4, 0, 0x200);
        return;
    }
    if (a2 == 1) {
        DWCi_ScreenDC_FlushRange(((struct Obj05339 *)p)->f10A8, 0x200);
        func_0207E468(((struct Obj05339 *)p)->f10A8, 0, 0x200);
    }
}
