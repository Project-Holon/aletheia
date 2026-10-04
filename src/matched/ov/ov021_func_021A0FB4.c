/*
 * function: func_021A0FB4
 * address:  0x021A0FB4
 * packet:   pkt_ov021_021A0FB4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188E30  0x02188E30  thumb  ov021
 *   func_021D3270  0x021D3270  thumb  ov021
 *   func_02193060  0x02193060  thumb  ov021
 *   func_020414EC  0x020414EC  arm
 *   func_021902A4  0x021902A4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern u32 func_02188E30(u8 *p);
extern void func_021D3270(u32, u32, u32, u32, u32, u32);
extern void func_02193060(u32);
extern void func_020414EC(u32 i);
extern void func_021902A4(u32, u32);

void func_021A0FB4(u32 *p, u32 a)
{
    func_021D3270(func_02188E30((u8 *)p[5]), 1, 0, 0, 0, 0);
    func_02193060(0);
    func_020414EC(1);
    func_021902A4(1, a);
}
