/*
 * function: func_0219DC88
 * address:  0x0219DC88
 * packet:   pkt_ov021_0219DC88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219E370  0x0219E370  thumb  ov021
 *   func_0219E6C8  0x0219E6C8  thumb  ov021
 *   func_0216D60C  0x0216D60C  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void func_0219E370(u32, u16, u32);
extern void func_0219E6C8(u32, u16);
extern void func_0216D60C(u32, u16);
extern void func_0216D674(u32, u32);
extern void func_0216D568(void *p, u32 v);
extern void func_0216D7CC(u8 *p);

void func_0219DC88(u32 a, u32 b, u32 c, u32 d)
{
    func_0219E370(a, b, c);
    func_0219E6C8(a, b);
    func_0216D60C(a, b);
    func_0216D674(a, d);
    func_0216D568((void *)a, 0x20);
    func_0216D7CC((u8 *)a);
}
