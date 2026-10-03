/*
 * function: func_021D7744
 * address:  0x021D7744
 * packet:   pkt_021D7474
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D7744   0x021D7744  arm
 *
 * ARM tail-call thunk into func_021D7750.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D7744.c \
 *       --func func_021D7744 --addr 0x021D7744 --region ov016 --cc dsi/1.1p1 --arm
 */

typedef unsigned int   u32;
struct StructR4;
extern void func_021D7750(u32 idx, struct StructR4 *r4);

void func_021D7744(unsigned int idx, void *r4)
{
    func_021D7750(idx, r4);
}
