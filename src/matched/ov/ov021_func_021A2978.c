/*
 * function: func_021A2978
 * address:  0x021A2978
 * packet:   pkt_ov021_021A2978
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_020490F4(u16 a, int b);

void func_021A2978(u8 *p, u16 *q, int c)
{
    if (q[1] != 0 || q[2] != 0)
        *(u32 *)(p + 0x10) = func_020490F4(q[0], c);
}
