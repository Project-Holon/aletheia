/*
 * function: func_021E949C
 * address:  0x021E949C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DD090  0x021DD090  thumb  ov170
 *
 * Forward, then store the third argument at 0x28.
 */



extern void func_021DD090(char *, int);
int func_021E949C(char *p, int a, int b)
{
    func_021DD090(p, a);
    *(int *)(p + 0x28) = b;
    return 8;
}
