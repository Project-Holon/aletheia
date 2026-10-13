/*
 * function: func_021F4894
 * address:  0x021F4894
 * packet:   pkt_021F4894
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_SetVramBanks  0x020433E0  arm  arm9
 *

 *
 * Tail-call thunk to BG_SYS_SetVramBanks.
 */

struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);

void func_021F4894(const struct DispVram *a0)
{
    BG_SYS_SetVramBanks(a0);
}
