/*
 * function: func_021C7420
 * address:  0x021C7420
 * packet:   pkt_ov136_021C7420
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200902C 0x0200902C thumb
 */

typedef unsigned char u8;
typedef unsigned int   u32;
struct Sub02008F80Obj;
extern void func_0200902C(struct Sub02008F80Obj *arr, u32 unused, int i);
void func_021C7420(u8 *p)
{
    func_0200902C(*(void **)p, 0, p[0x1F]);
}
