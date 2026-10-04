/*
 * function: func_021B67B4
 * address:  0x021B67B4
 * packet:   pkt_021B67B4
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02050DB8  0x02050DB8  arm
 */

typedef unsigned char  u8;
extern void func_02050DB8(u8 *p);

void func_021B67B4(int *p)
{
    func_02050DB8((u8 *)(*(int *)((char *)p + 0x28)));
    *(int *)((char *)p + 0x28) = 0;
}
