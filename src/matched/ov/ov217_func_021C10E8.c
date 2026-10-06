/*
 * function: func_021C10E8
 * address:  0x021C10E8
 * packet:   pkt_ov217_021C10E8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C1704  0x021C1704  thumb  ov217
 *   func_021C1720  0x021C1720  thumb  ov217
 *   func_021C17C4  0x021C17C4  thumb  ov217
 *   func_021C1850  0x021C1850  thumb  ov217
 *   func_021C18C4  0x021C18C4  thumb  ov217
 *   func_021C18F8  0x021C18F8  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

typedef unsigned int   u32;
extern u32 func_021C1704(void *a0);
extern void func_021C1720(u8 *p, u8 *e);
extern void func_021C17C4(u8 *p);
extern void func_021C1850(u8 *p);
extern void func_021C18C4(u8 *p);
extern void func_021C18F8(u8 *p);

void func_021C10E8(u8 *p, u8 *tab, int n)
{
    int i;
    func_021C1704((void *)p);
    for (i = 0; i < n; i++)
        func_021C1720(p, tab + i * 16);
    func_021C17C4(p);
    func_021C1850(p);
    func_021C18C4(p);
    func_021C18F8(p);
}
