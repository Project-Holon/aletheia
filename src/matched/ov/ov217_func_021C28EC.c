/*
 * function: func_021C28EC
 * address:  0x021C28EC
 * packet:   pkt_ov217_021C28EC
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_021C28EC(const u32 *p, u16 *a, u16 *b)
{
    *a = p[1] + 0xA;
    *b = p[2] - 8;
}
