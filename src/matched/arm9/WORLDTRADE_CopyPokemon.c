/*
 * function: WORLDTRADE_CopyPokemon
 * address:  0x0200AD9C
 * packet:   pkt_0200AD9C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   MI_CpuCopy8 0x02082D44 arm
 */

typedef unsigned int   u32;
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern void MI_CpuCopy8(void *thread, void *arg1, void *res);

void WORLDTRADE_CopyPokemon(void *thread, void *arg1)
{
    void *res = (void *)POKE_TOOL_GetPartyParamSize();
    MI_CpuCopy8(thread, arg1, res);
}
