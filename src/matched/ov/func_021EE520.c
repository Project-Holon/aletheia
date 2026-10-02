/*
 * function: func_021EE520
 * address:  0x021EE520
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202616C  0x0202616C  thumb
 *   func_021EEFA4  0x021EEFA4  thumb  ov170
 *
 * Hand the two tag bytes of the p+0x2c+0x70 object to the 0x54/0x10
 * emitter.
 */

extern void *func_0202616C(void **obj, unsigned idx);
extern void func_021EEFA4(int, int, int, int, int);
void func_021EE520(char *p, unsigned idx)
{
    unsigned char *q = func_0202616C(*(void ***)(*(char **)(p + 0x2c) + 0x70), idx);
    func_021EEFA4(*(int *)(p + 0x2c), 0x54, 0x10, q[0], q[1]);
}
