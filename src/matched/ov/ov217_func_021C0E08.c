/*
 * function: func_021C0E08
 * address:  0x021C0E08
 * packet:   pkt_ov217_021C0E08
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021C4050  0x021C4050  data  a4
 *   func_02030734  0x02030734  arm
 *   func_021C0E6C  0x021C0E6C  thumb  ov217
 *   func_021C0E78  0x021C0E78  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

extern const int d_021C4050[];
extern void *func_02030734(unsigned int heap, unsigned int size, int clear, const char *site, unsigned short tag);
extern void func_021C0E6C(int h);
typedef unsigned int   u32;
extern void func_021C0E78(u32 a0, u32 a1, u32 a2);

int func_021C0E08(int a0, int a1)
{
    int h;
    h = (int)func_02030734(a1, 0x10, 0, (const char *)d_021C4050, 0x3C);
    func_021C0E6C(h);
    func_021C0E78(h, a0, a1);
    return h;
}
