/*
 * function: func_02173568
 * address:  0x02173568
 * packet:   pkt_ov011_02173568
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0217963C  0x0217963C  thumb  ov014
 *   func_02173368  0x02173368  thumb  ov011
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_0217963C(u32 v);
struct Obj;
extern void func_02173368(void *a0, struct Obj *s);

void func_02173568(u8 *w)
{
    w[0x8fd] = 2;
    func_0217963C((u32)func_02173368);
}
