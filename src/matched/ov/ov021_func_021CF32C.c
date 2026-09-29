/*
 * unit:     yes
 * function: func_021CF32C
 * function: func_021CF36C
 * address:  0x021CF32C
 * packet:   pkt_ov021_021CF32C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_021CF36C (unlabelled) is a tail-call stub into func_021CE70C.
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_021CE70C  0x021CE70C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020399A8(void);
extern void func_0203D3F8(u32, u32, u32, u32, u32, u32, u32, u32);
extern void func_021CE70C(u32, u32, u32);

void func_021CF32C(u32 flag)
{
    if (flag == 1)
        func_0203D3F8(func_020399A8(), 0xff, 0x2704, 0, 0, 0, 0, 0);
    else
        func_0203D3F8(func_020399A8(), 0, 0x2704, 0, 0, 0, 0, 0);
}

void func_021CF36C(u32 a, u32 b, u32 c, u32 d)
{
    func_021CE70C(d, b, c);
}
