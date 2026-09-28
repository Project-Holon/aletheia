/*
 * function: func_021E8AB4
 * address:  0x021E8AB4
 * packet:   pkt_021E8AB4
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter after func_021E8AA8's pool: stores the second argument at
 * +0xc. Called from the ov175 root func_021D7E18 (0x021D7EF6, 0x021D8060,
 * 0x021D8550).
 */

typedef unsigned int u32;

void func_021E8AB4(u32 sys, u32 v)
{
    *(u32 *)(sys + 0xc) = v;
}
