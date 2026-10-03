/*
 * function: func_021D63D4
 * address:  0x021D63D4
 * packet:   pkt_021D63D4
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

void func_021D63D4(u8 *p)
{
    func_0204B878(*(void **)(p + 0xa8), 2);
}
