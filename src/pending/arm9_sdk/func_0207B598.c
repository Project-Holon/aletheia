/*
 * function: func_0207B598
 * address:  0x0207B598
 * packet:   pkt_0207B598
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * SDK symbol: MTX_Identity43_ (TwlSDK libfx.TWL.HYB.a fx_mtx43.o)
 */

typedef unsigned long u32;

typedef struct MtxFx43
{
    u32 m[12];
} MtxFx43;

void func_0207B598(MtxFx43 *pDst)
{
    MtxFx43 t = {{0x1000, 0, 0, 0, 0x1000, 0, 0, 0, 0x1000, 0, 0, 0}};
    *pDst = t;
}
