/*
 * function: func_021EBF50
 * address:  0x021EBF50
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EBF34  0x021EBF34  thumb  ov170
 *
 * Release all 0x60 slots of the 0x9E70 pool, then release the pool
 *   head itself.
 */


extern void func_021EBF34(char *, int);
struct Bank;
extern void func_0204B1CC(struct Bank *bank);
void func_021EBF50(char *p)
{
    unsigned i;
    for (i = 0; i < 0x60; i++)
        func_021EBF34(p, i);
    func_0204B1CC((struct Bank *)(*(int *)(p + 0x9E70)));
}
