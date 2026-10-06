/*
 * function: func_021D5930
 * address:  0x021D5930
 * packet:   pkt_ov118_021D5930
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D58F0  0x021D58F0  thumb  ov118
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
extern u32 func_02051774(void);
extern void func_02051A2C(void *p, int v);
extern void func_02051A24(void *p, int v);
extern void func_021D58F0(void *obj, int on);

void func_021D5930(void *p)
{
    func_02051A2C(p, func_02051774());
    func_02051A24(p, (int)func_021D58F0);
}
