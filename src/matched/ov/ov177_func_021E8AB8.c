/*
 * function: func_021E8AB8
 * address:  0x021E8AB8
 * packet:   pkt_021E8AB8
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Field copy after func_021E8AB4: the word at +0xc is stored to +4.
 * Called from ov175 at 0x021D5550 and from the root func_021D7E18
 * (0x021D8858).
 */

typedef unsigned int u32;

void func_021E8AB8(u32 sys)
{
    *(u32 *)(sys + 4) = *(u32 *)(sys + 0xc);
}
