/*
 * function: func_021A2AAC
 * address:  0x021A2AAC
 * packet:   pkt_021A2AAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned short u16;
typedef unsigned int u32;

void func_021A2AAC(char *p, u16 a, u16 b, u16 c, u32 d)
{
    *(u16 *)(p + 0xc) = a;
    *(u16 *)(p + 0xe) = b;
    *(u16 *)(p + 0x10) = c;
    *(u32 *)(p + 0x14) = d;
}
