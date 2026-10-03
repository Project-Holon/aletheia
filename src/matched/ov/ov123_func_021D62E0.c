/*
 * function: func_021D62E0
 * address:  0x021D62E0
 * packet:   pkt_021D62E0
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Obj;
extern void func_0204B3B4(struct Obj *p);

void func_021D62E0(u8 *p, int i)
{
    if (*(u32 *)(p + 0x74 + i * 4)) {
        func_0204B3B4(*(void **)(p + 0x74 + i * 4));
        *(u32 *)(p + 0x74 + i * 4) = 0;
    }
}
