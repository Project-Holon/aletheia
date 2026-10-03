/*
 * function: func_021BABF4
 * address:  0x021BABF4
 * packet:   pkt_ov093_021BABF4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub (leaf of func_021BAC04): forwards its first
 * argument to func_021BABEC with the function pointer 0x021BACAD in r1.
 *
 * symbols:
 *   func_021BABEC  0x021BABEC  thumb  ov093
 *   func_021BACAC  0x021BACAC  thumb  ov093
 */

typedef unsigned char  u8;
extern void func_021BABEC(int *p, void *f);
extern int func_021BACAC(u8 *p, int *s);

void func_021BABF4(void *p)
{
    func_021BABEC(p, (void *)func_021BACAC);
}
