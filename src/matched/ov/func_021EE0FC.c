/*
 * function: func_021EE0FC
 * address:  0x021EE0FC
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EC000  0x021EC000  thumb  ov170
 *
 * Release slots 6, 7 and 8 of the 0x9E74 array.
 */


extern void func_021EC000(char *p, int i, int v);
void func_021EE0FC(char *p)
{
    func_021EC000((char *)(*(int *)(p + 0x2c)), 6, 0);
    func_021EC000((char *)(*(int *)(p + 0x2c)), 7, 0);
    func_021EC000((char *)(*(int *)(p + 0x2c)), 8, 0);
}
