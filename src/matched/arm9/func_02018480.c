/*
 * function: POKE_TOOL_IsOwnedByPlayer
 * address:  0x02018480
 * packet:   pkt_02018480
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Eight byte thunk (pool word and bx) that forwards both arguments to
 * POKE_TOOL_IsBoxOwnedByPlayer. Witness for the ov093 caller func_021BCFAC.
 *
 * symbols:
 *   POKE_TOOL_IsOwnedByPlayer  0x02018480  thumb
 *   POKE_TOOL_IsBoxOwnedByPlayer  0x02018488  thumb
 */

typedef unsigned int   u32;
extern u32 POKE_TOOL_IsBoxOwnedByPlayer(void *p, void *mail);

int POKE_TOOL_IsOwnedByPlayer(void *p, int q)
{
    return POKE_TOOL_IsBoxOwnedByPlayer(p, (void *)q);
}
