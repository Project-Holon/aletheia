/*
 * function: func_0216C0D4
 * address:  0x0216C0D4
 * packet:   pkt_ov010_0216C0D4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045838  0x02045838  arm
 */

struct U16Vec;
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);

void func_0216C0D4(int *p, int a1)
{
    func_02045838((struct U16Vec *)a1, (struct U16Vec *)p[8]);
}
