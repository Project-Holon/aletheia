/*
 * function: func_021B681C
 * address:  0x021B681C
 * packet:   pkt_021B681C
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

void func_021B681C(int *p)
{
    func_02050DB8((u8 *)(*(int *)((char *)p + 0x2c)));
    *(int *)((char *)p + 0x2c) = 0;
}
