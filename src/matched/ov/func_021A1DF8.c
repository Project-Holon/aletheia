/*
 * function: func_021A1DF8
 * address:  0x021A1DF8
 * packet:   pkt_021A1DF8
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
 *   func_021A20C8  0x021A20C8  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
struct O;
extern void func_021A20C8(struct O *p);
extern u32 func_020307B0(void *p);

void func_021A1DF8(u8 *p)
{
    func_021A20C8((struct O *)p);
    func_020307B0(p);
}
