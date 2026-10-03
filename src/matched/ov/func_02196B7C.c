/*
 * function: func_02196B7C
 * address:  0x02196B7C
 * packet:   pkt_02196B7C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Untraced thunk: registers the record at 0x021966F0.
 *
 * symbols:
 *   func_021966F0  0x021966F0  thumb  ov021
 *   func_02196034  0x02196034  thumb  ov021

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_02196034(u8 *p, void *fn, u32 n);
extern void func_021966F0(u8 *p);

void func_02196B7C(u8 *p)
{
    func_02196034(p, func_021966F0, 0x47A);
}
