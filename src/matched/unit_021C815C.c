/*
 * unit:     yes
 * function: func_021C815C, func_021C8168
 * address:  0x021C815C
 * packet:   pkt_021C815C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two tail thunks forwarding p->field4 to distinct callees.
 *
 * symbols:
 *   func_021B8588  0x021B8588  thumb  ov093
 *   func_021B86B8  0x021B86B8  thumb  ov093
 */

extern void func_021B8588(int);
extern void func_021B86B8(int);

void func_021C815C(int *p)
{
    func_021B8588(*(int *)((char *)p + 4));
}

void func_021C8168(int *p)
{
    func_021B86B8(*(int *)((char *)p + 4));
}
