/*
 * function: func_021C25C4
 * address:  0x021C25C4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 4)) to func_0204B1CC.
 *
 * symbols:
 *   func_0204B1CC  0x0204B1CC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Bank;
extern void func_0204B1CC(struct Bank *bank);

void func_021C25C4(u8 *a0)
{
    func_0204B1CC((struct Bank *)((u32)(*(u32*)(a0 + 4))));
}

