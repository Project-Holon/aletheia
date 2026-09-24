/*
 * function: func_021E8FC0
 * address:  0x021E8FC0
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DC9A0  0x021DC9A0  thumb  ov170
 *
 * Store the third argument, then reset the sub-object.
 */



extern void func_021DC9A0(char *, int);
int func_021E8FC0(char *p, int a, int b)
{
    *(int *)(*(int *)(p + 0x2c) + 0x68) = b;
    func_021DC9A0(*(char **)(p + 0x2c), a);
    return 5;
}
