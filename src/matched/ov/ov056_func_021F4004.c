/*
 * function: func_021F4004
 * address:  0x021F4004
 * packet:   pkt_ov056_021F4004
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02028B50  0x02028B50  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02028B50(u8 *p, int a0);

void func_021F4004(void *a, void *b, u8 *c)
{
    if (*(u16 *)(c + 4) == 0) {
        func_02028B50(*(u8 **)(c + 0xc), 0x7ef);
    }
}
