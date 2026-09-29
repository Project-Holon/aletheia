/*
 * function: func_021C6B18
 * address:  0x021C6B18
 * packet:   pkt_ov021_021C6B18
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188D30  0x02188D30  thumb  ov021
 *   func_0218ED54  0x0218ED54  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_021C6B8C  0x021C6B8C  thumb  ov021
 *   d_021DE4B8     0x021DE4B8  data  ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02188C84(u32 a);
extern u32 func_02188C58(u32 a);
extern u32 func_02188D30(u32 a);
extern u32 func_0218ED54(u32 a);
extern void *func_02030734(int, int, int, void *, int);
extern void func_02030DA8(u32 a, void *cb, void *arg, int z);
extern void func_021C6B8C(void);
extern int d_021DE4B8;

void func_021C6B18(u32 a, u16 b, u32 c)
{
    u32 h = func_02188C84(a);
    u32 x = func_02188C58(a);
    u32 y = func_02188D30(a);
    u32 *e;

    e = (u32 *)func_02030734((u16)((h & 0x7FFF) | 0x8000), 0x10, 0, &d_021DE4B8, 0x5F);
    *(u16 *)((u8 *)e + 4) = 0;
    *(u16 *)((u8 *)e + 6) = b;
    e[2] = func_0218ED54(x);
    e[3] = c + func_0218ED54(x);
    e[0] = a;
    func_02030DA8(y, (void *)func_021C6B8C, e, 0);
}
