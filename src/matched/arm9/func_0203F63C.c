/*
 * function: func_0203F63C
 * address:  0x0203F63C
 * packet:   pkt_0203F63C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Twin of func_0203F5FC at table index 2 * i + 1 (cosine entry); angles of 360 or more return 0.
 *
 * symbols:
 *   FX_SinCosTable_   0x020A1B38  data
 */

typedef short s16;
typedef int   s32;
typedef unsigned int u32;

extern s16 FX_SinCosTable_[];

s16 func_0203F63C(u32 x)
{
    if (x >= 360) {
        return 0;
    }
    return FX_SinCosTable_[2 * ((((s32)x * 0xFFFF) / 360) >> 4) + 1];
}
