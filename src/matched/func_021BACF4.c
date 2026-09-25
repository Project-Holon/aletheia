/*
 * function: func_021BACF4
 * address:  0x021BACF4
 * packet:   pkt_021BACF4
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02005C28  0x02005C28  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02005C28(u32 a);

void func_021BACF4(u8 *p, u32 a, u32 b)
{
    if (*(u32 *)(p + 4) == 3 || b == 1) {
        if (a == 0) {
            func_02005C28(1);
        } else {
            func_02005C28(0);
        }
    }
}
