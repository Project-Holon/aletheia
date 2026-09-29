/*
 * function: func_021D794C
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
 *   d_021F047C  0x021F047C  data  ov093  a1
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 d_021F047C[17][17];

int func_021D794C(int a, int b)
{
    if (a == 0x11 || b == 0x11)
        return 3;
    switch (d_021F047C[a][b]) {
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
