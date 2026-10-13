/*
 * function: SODATEYA_PrepareDeposit
 * address:  0x021C3248
 * packet:   pkt_021C31FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to POKE_TOOL_HealFull with no argument change.
 *
 * symbols:
 *   POKE_TOOL_HealFull  0x0201B9F0  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void POKE_TOOL_HealFull(void *mon);

void SODATEYA_PrepareDeposit(void *a0)
{
    POKE_TOOL_HealFull(a0);
}
