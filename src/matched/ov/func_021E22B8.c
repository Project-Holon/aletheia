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


typedef unsigned int   u32;
struct PrintSys;
extern u32 func_0201C6B4(const struct PrintSys *p);
extern int func_021E8F60(void *p, int a);
int func_021E22B8(int p)
{
    if (func_0201C6B4((const struct PrintSys *)(*(int *)(*(int *)(p + 0x2c) + 0x8c))) == 0)
        return 0xc;
    func_021E8F60((void *)p, *(int *)(*(int *)(p + 0x2c) + 0xA198));
}

