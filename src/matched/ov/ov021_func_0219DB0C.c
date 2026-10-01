/*
 * function: func_0219DB0C
 * address:  0x0219DB0C
 * packet:   pkt_ov021_0219DB0C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D98C  0x0216D98C  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_0219DC08  0x0219DC08  thumb  ov021
 *   func_021AC2C0  0x021AC2C0  thumb  ov021
 *   func_0216D568  0x0216D568  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern u32 func_0216D67C(u32);
extern int func_0216D98C(u32);
extern int func_0216D57C(u32, u32);
extern u32 func_0219DC08(u32);
extern void func_021AC2C0(u32, u32);
extern void func_0216D568(u32, u32);

void func_0219DB0C(u32 a)
{
    if (func_0216D98C(func_0216D67C(a)) != 0) {
        if (func_0216D57C(a, 0x4000) == 0) {
            func_021AC2C0(a, func_0219DC08(a));
            func_0216D568(a, 0x4000);
        }
    }
}
