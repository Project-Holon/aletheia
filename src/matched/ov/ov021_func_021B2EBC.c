/*
 * function: func_021B2EBC
 * address:  0x021B2EBC
 * packet:   pkt_ov021_021B2EBC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188D30  0x02188D30  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_02189A1C  0x02189A1C  thumb  ov021
 *   func_021B2F18  0x021B2F18  thumb  ov021
 *   d_021DE14C     0x021DE14C  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_02188D30(int a);
extern u32 *func_02030734(u16, u32, u32, u8 *, u32);
extern void func_02030DA8(int, void (*)(), u32 *, u32);
extern void func_02189A1C(int a, int b);
extern void func_021B2F18(int p, int *q);
extern u8 d_021DE14C;

void func_021B2EBC(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    int h = func_02188D30(b);
    u32 *w = func_02030734(4, 0x18, 1, &d_021DE14C, 0x369);

    func_02030DA8(h, func_021B2F18, w, 0);
    func_02189A1C(b, 1);
    w[5] = 0;
    w[0] = a;
    w[1] = b;
    w[2] = d;
    w[3] = e;
    w[4] = c;
}
