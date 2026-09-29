/*
 * function: func_02191504
 * address:  0x02191504
 * packet:   pkt_ov021_02191504
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02193170  0x02193170  thumb  ov021
 *   func_02193044  0x02193044  thumb  ov021
 *   func_02194A00  0x02194A00  thumb  ov021
 *   func_021927C0  0x021927C0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02193170(u32);
extern void func_02193044(u32);
extern u32 func_02194A00(u32, u8, u8, u8, u8, u32);
extern void func_021927C0(u32 *, u16 *);

void func_02191504(u16 *a, u32 *b, u32 c, u32 d, u16 e, u16 f, u32 g)
{
    a[3] = 11;
    b[4] = *(u32 *)((u8 *)a + 0x15C);
    func_02193170(a[0]);
    func_02193044(0);
    b[6] = func_02194A00(b[4], c, d, e, f, g);
    func_021927C0(b, a);
}
