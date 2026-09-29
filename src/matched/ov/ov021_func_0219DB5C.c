/*
 * function: func_0219DB5C
 * address:  0x0219DB5C
 * packet:   pkt_ov021_0219DB5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216DC34  0x0216DC34  thumb  ov010
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_02163F40  0x02163F40  thumb  ov010
 *   func_0219DC08  0x0219DC08  thumb  ov021
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216DC18  0x0216DC18  thumb  ov010
 *   func_021BBFB8  0x021BBFB8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_0216DC34(u32);
extern u32 func_021AB0F8(u32);
extern u32 func_02163F40(u32, u32);
extern u32 func_0219DC08(u32);
extern u32 func_0216D67C(u32);
extern void func_0216DC18(u32, u32);
extern void func_021BBFB8(u32, u32, u32, u32);

void func_0219DB5C(u32 a, u32 b, u32 c, u8 *d)
{
    u32 m;
    u32 e;
    u32 f;
    if (d[6] != 0 && func_0216DC34(a) == 0) {
        m = -1;
        if (b != -1) {
            if (func_021AB0F8(b) & 0x40) {
                m = b;
            } else {
                b = func_02163F40(a, 1);
                if (func_021AB0F8(b) & 0x40) {
                    m = b;
                }
            }
            if (m != -1) {
                e = func_0219DC08(a);
                f = func_0216D67C(a);
                func_0216DC18(a, 1);
                func_021BBFB8(f, a, e, 1);
            }
        }
    }
}
