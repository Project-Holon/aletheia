/*
 * function: func_021C24A8
 * address:  0x021C24A8
 * packet:   pkt_ov021_021C24A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * EXACT*: the 72-byte listing extent runs on into the unlabelled leaf
 * func_021C24BC (ov021_func_021C24BC.c), whose EXACT entry attests the
 * pool word 0x021C24BD as matched.
 * symbols:
 *   func_020515CC  0x020515CC  arm
 *   func_021C24BC  0x021C24BC  thumb  ov021
 */

void func_021C24BC(char *p);
int func_020515CC(int *p, int a, int b, int c);

void func_021C24A8(char *p, int k)
{
    func_020515CC((int *)(*(int *)(p + 0x58)), k, (int)func_021C24BC, 0);
}
