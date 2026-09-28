/*
 * function: func_021D4C20
 * address:  0x021D4C20
 * packet:   pkt_ov118_021D4C20
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021E3230  0x021E3230  thumb  ov119
 *   func_021E3208  0x021E3208  thumb  ov119
 *   func_021D4C40  0x021D4C40  thumb  ov118
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

extern void func_021D8E84(void *p, int next);
extern void func_021E3230(void *p);
extern void func_021E3208(void *p, int a);
extern void func_021D4C40(u8 *p);

void func_021D4C20(u8 *p)
{
    func_021E3230(p);
    func_021E3208(p, 3);
    func_021D8E84(p, (int)func_021D4C40);
}
