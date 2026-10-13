/*
 * function: POKE_TOOL_SetupBoxParam
 * address:  0x02017600
 * packet:   pkt_0201756C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_SetupBoxParamEx  0x0201761C  thumb
 *
 * Forwarder: POKE_TOOL_SetupBoxParamEx(obj, species, level, id, 0xFFFFFFFF,
 * 0xFFFFFFFF00000000).  Twin of POKE_TOOL_SetupPartyParam; wave 11, 2026-09-23, closed
 * by the u64 `id` parameter.
 */
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long long u64;

extern void POKE_TOOL_SetupBoxParamEx(void *obj, u16 species, u16 level, u64 id, u32 pow, u64 rnd);

void POKE_TOOL_SetupBoxParam(void *obj, u16 species, u16 level, u64 id)
{
    POKE_TOOL_SetupBoxParamEx(obj, species, level, id, 0xFFFFFFFF, 0xFFFFFFFF00000000ULL);
}
