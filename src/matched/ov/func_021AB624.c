/*
 * function: func_021AB624
 * address:  0x021AB624
 * packet:   pkt_021AB624
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
 *   func_021AB650  0x021AB650  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void func_021AB650(void *p);
extern u32 func_020307B0(void *p);

void func_021AB624(u8 *p)
{
    func_021AB650(p);
    func_020307B0(p);
}
