/*
 * function: BTL_CALC_CombineTypeAffinity
 * address:  0x021D79E8
 * packet:   pkt_ov093_021D79E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     a plain switch with case 16 after case 8 (mwcc tables 0..8 and compares 16 in
 *           the default path); the u32 switch value gives the unsigned `bhi` range check.
 *
 * symbols:
 *   gBtlCalcAffinityScales  0x021F0427  data  ov093  a1
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 gBtlCalcAffinityScales[];

int BTL_CALC_CombineTypeAffinity(int x, int y)
{
    u32 m = gBtlCalcAffinityScales[x] * gBtlCalcAffinityScales[y] / 4;

    switch (m) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    case 4:
        return 3;
    case 8:
        return 4;
    case 16:
        return 5;
    }
    return 0;
}
