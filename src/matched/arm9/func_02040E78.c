/*
 * function: BG_SYS_LoadPltt
 * address:  0x02040E78
 * packet:   pkt_02040DA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GX_LoadBGPltt  0x0207E3D0  arm
 *   DWCi_ScreenDC_FlushRange  0x020862F0  arm
 */

typedef unsigned int u32;

extern void DWCi_ScreenDC_FlushRange(void *, u32);
extern void GX_LoadBGPltt(void *, u32, u32);
extern void func_0207E468(void *, u32, u32);

void BG_SYS_LoadPltt(u32 r7, void *r6, u32 r5, u32 r4)
{
    DWCi_ScreenDC_FlushRange(r6, r5);
    if (r7 < 4) {
        GX_LoadBGPltt(r6, r4, r5);
    } else {
        func_0207E468(r6, r4, r5);
    }
}
