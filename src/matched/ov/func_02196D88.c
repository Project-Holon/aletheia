/*
 * function: func_02196D88
 * address:  0x02196D88
 * packet:   pkt_02196D88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Untraced thunk: tail call on the word at +0x24 into the ARM9 image.
 *
 * symbols:
 *   func_02051C88  0x02051C88  arm

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Ctx;
extern s32 func_02051C88(struct Ctx *c);

void func_02196D88(u8 *p)
{
    func_02051C88((struct Ctx *)(*(u32 *)(p + 0x24)));
}
