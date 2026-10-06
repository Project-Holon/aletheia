/*
 * function: func_021D0160
 * address:  0x021D0160
 * packet:   pkt_021D0160
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   func_021D01D8  0x021D01D8  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void func_021D01D8(u32 *p);
extern u32 func_020307B0(void *p);

void func_021D0160(u32 a, u8 *p)
{
    func_021D01D8((u32 *)p);
    func_020307B0(p);
}
