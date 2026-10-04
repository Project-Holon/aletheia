/*
 * function: func_021BE148
 * address:  0x021BE148
 * packet:   pkt_021BE148
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call with a constant and the argument less 7.
 *
 * symbols:
 *   func_02048F4C  0x02048F4C  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02048F4C(void *dst, u32 archive_id, u32 member);

void func_021BE148(u32 a, int b)
{
    func_02048F4C((void *)a, 0xb3, b - 7);
}
