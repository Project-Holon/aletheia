/*
 * function: func_021C0C50
 * address:  0x021C0C50
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 40)) to func_02021540.
 *
 * MATCH: the pool word has no witness outside the compared range:
 *   func_02021540 (thumb, arm9) has no witness: it is an ARM9 address that no
 *   ARM9 shard pins, and matching it is another lane's range.
 *
 * symbols:
 *   func_02021540  0x02021540  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_02021540(u32);

void func_021C0C50(u8 *a0)
{
    func_02021540((u32)(*(u32*)(a0 + 40)));
}

