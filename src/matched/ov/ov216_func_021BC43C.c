/*
 * function: func_021BC43C
 * address:  0x021BC43C
 * packet:   pkt_ov216_021BC43C
 * region:   ov216
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * This address is also matched as func_021BC43C in ov099; the ov216 copy is a
 * distinct function and gets its own shard.
 *
 * symbols:
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *
 * Addresses are Black-image addresses.
 */

extern void func_0204AFD8(int);
extern void func_0204A8D4(int);
extern void func_0204ADA4(int);

void func_021BC43C(void *unused, char *p)
{
    func_0204AFD8(*(int *)(p + 8));
    func_0204A8D4(*(int *)(p + 4));
    func_0204ADA4(*(int *)(p));
}
