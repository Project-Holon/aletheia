/*
 * function: CDEMO_SCENE_LoadScreenBlock
 * address:  0x021B669C
 * packet:   pkt_ov179_021B669C
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ARC_UTIL_LoadHandleMember  0x0204A380  arm
 *   DWCi_ScreenDC_FlushRange  0x020862F0  arm
 *   GX_LoadBG2Scr  0x0207EB78  arm
 *   func_0207ECF0  0x0207ECF0  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;
extern void *ARC_UTIL_LoadHandleMember(void *a0, u32 a1, u32 a2, u32 a3);
extern void DWCi_ScreenDC_FlushRange(int, int);
extern void GX_LoadBG2Scr(int, int, int);
extern void func_0207ECF0(int, int, int);
extern u32 func_020307B0(void *p);

void CDEMO_SCENE_LoadScreenBlock(int a, int b, int c, int d, int e)
{
    int t = (int)ARC_UTIL_LoadHandleMember((void *)a, b, 1, 0x807f);

    DWCi_ScreenDC_FlushRange(t, d);
    if (e == 0) {
        GX_LoadBG2Scr(t, c, d);
    } else {
        func_0207ECF0(t, c, d);
    }
    func_020307B0((void *)t);
}