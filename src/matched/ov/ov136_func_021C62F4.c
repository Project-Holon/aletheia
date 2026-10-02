/*
 * function: func_021C62F4
 * address:  0x021C62F4
 * packet:   pkt_ov136_021C62F4
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201F7A8    0x0201F7A8  thumb
 *   func_02041B6C    0x02041B6C  arm
 */

typedef unsigned char u8;
extern void func_0201F7A8(void *, int);
extern void func_02041B6C(int);
void func_021C62F4(u8 *p)
{
    func_0201F7A8(*(void **)(*(u8 **)(p + 8) + 0xA8), 2);
    func_02041B6C(0);
}
