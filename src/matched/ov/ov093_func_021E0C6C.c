/*
 * function: func_021E0C6C
 * address:  0x021E0C6C
 * packet:   pkt_ov093_021E0C6C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   func_021E03F8  0x021E03F8  thumb  ov093
 */

typedef unsigned short u16;
struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void func_021E03F8(int a, int b);

void func_021E0C6C(void *a, int b, int c)
{
    func_021E03F8(c, BTL_EVENT_GetFactorKey(a));
}
