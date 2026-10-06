/*
 * function: func_021BB0A4
 * address:  0x021BB0A4
 * packet:   pkt_021BB0A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   func_021BB11C  0x021BB11C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void func_021BB11C(u32 *p);
extern void func_020307B0(void *p);

void func_021BB0A4(u8 *p)
{
    func_021BB11C((u32 *)p);
    func_020307B0(p);
}
