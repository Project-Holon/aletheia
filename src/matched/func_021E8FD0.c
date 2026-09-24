/*
 * function: func_021E8FD0
 * address:  0x021E8FD0
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DC9B8  0x021DC9B8  thumb  ov170
 *
 * Store the second argument, then re-seat the sub-object.
 */



extern void func_021DC9B8(char *);
int func_021E8FD0(char *p, int a)
{
    *(int *)(*(int *)(p + 0x2c) + 0x68) = a;
    func_021DC9B8(*(char **)(p + 0x2c));
    return 5;
}
