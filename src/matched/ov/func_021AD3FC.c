/*
 * function: func_021AD3FC
 * address:  0x021AD3FC
 * packet:   pkt_021AD3FC
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
 *   func_021AD530  0x021AD530  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void func_021AD530(void *p);
extern void func_020307B0(void *p);

void func_021AD3FC(u32 a, u8 *p)
{
    func_021AD530(p);
    func_020307B0(p);
}
