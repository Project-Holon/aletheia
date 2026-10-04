/*
 * function: func_021F3F7C
 * address:  0x021F3F7C
 * packet:   pkt_ov056_021F3F7C
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

void func_021F3F7C(void *a, void *b, u8 *c)
{
    if (*(u16 *)(c + 4) == 0) {
        func_02028B50(*(u8 **)(c + 0xc), 0x756);
    }
}
