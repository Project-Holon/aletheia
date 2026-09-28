/*
 * function: func_021D7118
 * address:  0x021D7118
 * packet:   pkt_ov118_021D7118
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021E3208  0x021E3208  thumb  ov119
 *   func_021D7130  0x021D7130  thumb  ov118
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

extern void func_021D8E84(void *p, int next);
extern void func_021E3208(void *p, int a);
extern void func_021D7130(u8 *p);

void func_021D7118(u8 *p)
{
    func_021E3208(p, 3);
    func_021D8E84(p, (int)func_021D7130);
}
