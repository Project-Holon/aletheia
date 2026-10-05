/*
 * function: func_021ACA5C
 * address:  0x021ACA5C
 * packet:   pkt_021ACA5C
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
 *   func_021ACB0C  0x021ACB0C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void func_021ACB0C(void *p);
extern void func_020307B0(void *p);

void func_021ACA5C(u32 a, u8 *p)
{
    func_021ACB0C(p);
    func_020307B0(p);
}
