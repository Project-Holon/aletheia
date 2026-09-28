/*
 * function: func_021D4520
 * address:  0x021D4520
 * packet:   pkt_ov118_021D4520
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021D4544  0x021D4544  thumb  ov118
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern u32 func_020399A8(void);
extern u32 func_02039CB4(u32 h, u32 a, u32 b);
extern void func_021D8E84(void *p, int next);
extern void func_021D4544(u8 *p);

void func_021D4520(u8 *p)
{
    if (func_02039CB4(func_020399A8(), 0x11, 8) != 0) {
        func_021D8E84(p, (int)func_021D4544);
    }
}
