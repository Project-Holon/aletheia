/*
 * function: POKE_TOOL_CheckTmCompat
 * address:  0x020188AC
 * packet:   pkt_020188AC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Eight byte tail-call thunk to POKE_TOOL_CheckBoxTmCompat
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). Filed as the relocation
 * witness for ov021 func_021B62C8 (wave A1).
 *
 * symbols:
 *   POKE_TOOL_CheckBoxTmCompat  0x020188B4  thumb
 */

typedef unsigned int u32;

extern u32 POKE_TOOL_CheckBoxTmCompat(void *p, int v);

u32 POKE_TOOL_CheckTmCompat(void *p, int v)
{
    return POKE_TOOL_CheckBoxTmCompat(p, v);
}
