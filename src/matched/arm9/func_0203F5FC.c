/*
 * function: func_0203F5FC
 * address:  0x0203F5FC
 * packet:   pkt_0203F5FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Fixed-point sine lookup without the mod: angles of 360 or more return 0; otherwise the same table index as func_0203F684 (4096-entry table at 0x020A1B38, even halfword).
 *
 * symbols:
 *   FX_SinCosTable_   0x020A1B38  data
 */

typedef short s16;
typedef int   s32;
typedef unsigned int u32;

extern s16 FX_SinCosTable_[];

int func_0203F5FC(u32 x)
{
    if (x >= 360) {
        return 0;
    }
    return FX_SinCosTable_[2 * ((((s32)x * 0xFFFF) / 360) >> 4)];
}
