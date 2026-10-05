/*
 * function: func_021BBCF8
 * address:  0x021BBCF8
 * packet:   pkt_021BBCF8
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
 *   func_021BBD64  0x021BBD64  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void func_021BBD64(void *p);
extern void func_020307B0(void *p);

void func_021BBCF8(u32 a, u8 *p)
{
    func_021BBD64(p);
    func_020307B0(p);
}
