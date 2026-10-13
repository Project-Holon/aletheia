/*
 * function: POKE_TOOL_GetNatureStatMod
 * address:  0x020189D0
 * packet:   pkt_020189D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   POKE_TOOL_GetBoxNatureStatMod  0x020189D8  thumb
 */

typedef unsigned int u32;

typedef signed char    s8;
extern s8 POKE_TOOL_GetBoxNatureStatMod(void *m, u32 a1);

int POKE_TOOL_GetNatureStatMod(void *m, int b)
{
    return POKE_TOOL_GetBoxNatureStatMod(m, b);
}
