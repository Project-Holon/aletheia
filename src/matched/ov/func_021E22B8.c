/*
 * function: func_021E22B8
 * address:  0x021E22B8
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E8F60  0x021E8F60  thumb  ov170
 *
 * candidate func_021E22B8: guard then dispatch
 */


extern int func_0201C6B4(int);
extern void func_021E8F60(int, int);
int func_021E22B8(int p)
{
    if (func_0201C6B4(*(int *)(*(int *)(p + 0x2c) + 0x8c)) == 0)
        return 0xc;
    func_021E8F60(p, *(int *)(*(int *)(p + 0x2c) + 0xA198));
}

