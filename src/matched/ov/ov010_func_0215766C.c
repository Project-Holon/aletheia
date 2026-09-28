/*
 * function: func_0215766C
 * address:  0x0215766C
 * packet:   pkt_ov010_0215766C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

u8 *func_0215766C(u8 *p)
{
    int v = *(int *)(p + 0x31B4);
    int rem = v % 0x12;
    u32 q = v / 0x12;

    if (q >= *(u32 *)(p + 0x78)) {
        q = 0;
        *(int *)(p + 0x31B4) = 0;
    }
    return p + 0x7C + q * 0x708 + rem * 100;
}
