/*
 * function: func_020394C0
 * address:  0x020394C0
 * packet:   pkt_020394C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469D0     0x021469D0  data
 *   func_020366A8  0x020366A8  arm
 *
 * Leaf that saves no lr: tail-calls func_020366A8 on the 0xCC queue of the
 * net_system record (docs/families/net_system.h, fCC).  Reached only through
 * the long-branch veneer at 0x0203D56C.
 */

typedef unsigned char u8;

struct Conn;
extern int func_020366A8(struct Conn *p);
extern u8 *g_021469D0;

int func_020394C0(void)
{
    return func_020366A8((struct Conn *)(g_021469D0 + 0xCC));
}
