/*
 * function: func_02192BC0
 * address:  0x02192BC0
 * packet:   pkt_02192BC0
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
 *   func_02192B64  0x02192B64  thumb  ov021
 *   func_020452E8  0x020452E8  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void func_02192B64(u32 a);
extern void func_020452E8(void *p);

void func_02192BC0(u8 *p)
{
    func_02192B64((u32)p);
    func_020452E8(p);
}
