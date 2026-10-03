/*
 * function: func_021D62BC
 * address:  0x021D62BC
 * packet:   pkt_021D62BC
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B878  0x0204B878  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);

void func_021D62BC(u8 *p, int i, u32 v)
{
    func_0204B878(*(void **)(p + i * 4 + 0x74), (u16)v);
}
