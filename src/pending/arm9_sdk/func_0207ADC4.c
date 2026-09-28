/*
 * function: func_0207ADC4
 * address:  0x0207ADC4
 * packet:   pkt_0207ADC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * SDK symbol: MTX_Identity33_ (TwlSDK libfx.TWL.HYB.a fx_mtx33.o)
 */

typedef unsigned long u32;

typedef struct MtxFx33
{
    u32 m[9];
} MtxFx33;

void func_0207ADC4(MtxFx33 *pDst)
{
    MtxFx33 t = {{0x1000, 0, 0, 0, 0x1000, 0, 0, 0, 0x1000}};
    *pDst = t;
}
