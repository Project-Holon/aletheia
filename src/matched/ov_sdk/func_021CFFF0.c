/*
 * function: func_021CFFF0
 * address:  0x021CFFF0
 * packet:   pkt_021CF440
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CFFF0   0x021CFFF0  arm
 *
 * Tail-call func_02073018 with the global object +0xa0 and two arguments.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CFFF0.c \
 *       --func func_021CFFF0 --addr 0x021CFFF0 --region ov016 --cc dsi/1.1p1 --arm
 */

typedef unsigned int   u32;
struct Obj;
extern void func_02073018(struct Obj *o, u32 v, u32 w);

void func_021CFFF0(unsigned int a, unsigned int b)
{
    func_02073018((struct Obj *)(*(char **)0x021DE648 + 0xa0), a, b);
}
