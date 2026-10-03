/*
 * function: func_02156730
 * address:  0x02156730
 * packet:   pkt_ov009_02156730
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009  a4
 *   func_02155374  0x02155374  thumb  ov009
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *g_021A8264;
extern void func_02155374(int v);

int func_02156730(void)
{
    u32 s = *(u32 *)(g_021A8264 + 0x754);
    if (s == 0x13 || s == 0x14 || s == 0x10 || s == 6) {
        u32 v = 6;
        func_02155374(v);
        *(u32 *)(g_021A8264 + 0x758) = 0x3ef;
        *(u32 *)(g_021A8264 + 0x774) = v - 7;
        return 1;
    }
    return 0;
}
