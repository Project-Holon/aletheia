/*
 * function: func_021C2310
 * address:  0x021C2310
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C245C  0x021C245C  arm  ov114
 *
 *
 * Null-guarded release of the object at `a`.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021C245C(int);

void func_021C2310(int a)
{
    if (a == 0)
        return;
    func_021C245C(a);
}
