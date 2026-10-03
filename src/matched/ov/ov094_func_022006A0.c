/*
 * function: func_022006A0
 * address:  0x022006A0
 * packet:   pkt_ov094_022006A0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call stub: forwards (p, out) and passes !(flags & 1) as the third
 * argument of func_02017214.
 *
 * symbols:
 *   func_02017214  0x02017214  thumb
 */
struct Stats;
extern void func_02017214(void *p, struct Stats *out, void *q);

void func_022006A0(void *p, void *out, int flags)
{
    func_02017214(p, out, (void *)((flags & 1) == 0));
}
