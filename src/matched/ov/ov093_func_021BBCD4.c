/*
 * function: func_021BBCD4
 * address:  0x021BBCD4
 * packet:   pkt_ov093_021BBCD4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD2B4  0x021BD2B4  thumb  ov093
 *   func_021BD34C  0x021BD34C  thumb  ov093
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021C6110  0x021C6110  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021BD2B4(u8 *it, u8 **q);
extern int func_021BD34C(u8 *it, u8 **q, u8 **x);
extern int func_021D5BDC(void *p, u32 n);
extern void func_021C6110(u8 *p, u8 *a, u32 n);

void func_021BBCD4(u8 *p)
{
    u32 it;
    u8 *x;
    u32 n;

    func_021BD2B4((u8 *)&it, (u8 **)p);
    if (func_021BD34C((u8 *)&it, (u8 **)p, &x) != 0) {
        n = 12;
        do {
            if (func_021D5BDC(x, n) != 0)
                func_021C6110(p, x, n);
        } while (func_021BD34C((u8 *)&it, (u8 **)p, &x) != 0);
    }
}
