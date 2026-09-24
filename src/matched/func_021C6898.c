/*
 * function: func_021C6898
 * address:  0x021C6898
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Queues a 0x21/5 record against the 0x021CF464 block.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02084F80(int, int, void *, int, int);

void func_021C6898(int a)
{
    func_02084F80(a, 0x21, (void *)0x021CF464, 5, 3);
}
