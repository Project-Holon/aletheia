/*
 * function: func_021F3738
 * address:  0x021F3738
 * packet:   pkt_ov062_021F3738
 * region:   ov062
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE418  0x021BE418  thumb  ov021
 */

extern int func_02188D2C(int *p);
extern void func_021BE418(unsigned char *p, unsigned short i);

void func_021F3738(void *p)
{
    func_021BE418((unsigned char *)func_02188D2C(p), 0);
}
