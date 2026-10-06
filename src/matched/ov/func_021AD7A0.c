/*
 * function: func_021AD7A0
 * address:  0x021AD7A0
 * packet:   pkt_021AD7A0
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
 *   func_021ADA1C  0x021ADA1C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
struct Q;
extern void func_021ADA1C(struct Q *a);
extern void func_020307B0(void *p);

void func_021AD7A0(u32 a, u8 *p)
{
    func_021ADA1C((struct Q *)p);
    func_020307B0(p);
}
