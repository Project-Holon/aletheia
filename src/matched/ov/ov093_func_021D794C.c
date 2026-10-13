/*
 * function: BTL_CALC_GetTypeAffinity
 * address:  0x021D794C
 * packet:   pkt_ov093_021D794C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlCalcTypeAffinityTable  0x021F047C  data  ov093  a1
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 gBtlCalcTypeAffinityTable[17][17];

int BTL_CALC_GetTypeAffinity(int a, int b)
{
    if (a == 0x11 || b == 0x11)
        return 3;
    switch (gBtlCalcTypeAffinityTable[a][b]) {
    case 0:
        return 0;
    case 2:
        return 2;
    case 4:
        return 3;
    case 8:
        return 4;
    default:
        return 0;
    }
}
