/*
 * function: POKE_TOOL_Create
 * address:  0x020173F0
 * packet:   pkt_020173F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_GetPartyParamSize  0x020173EC  thumb
 *   func_02030734  0x02030734  arm
 *   POKE_TOOL_SetupPartyParam  0x0201756C  thumb
 *   sPokeToolFile  0x020A72E4  data
 *
 * Allocate a record (0xA0 is the __LINE__ passed to func_02030734 with the
 * poke_tool.c __FILE__ anchor) and initialise it through POKE_TOOL_SetupPartyParam.
 * Wave 11, 2026-09-23.  The "one remaining codegen wall" of
 * docs/families/poke_tool.h section 11 was a declaration error: the id is a
 * single u64 in r2:r3, not two u32s.  A u64 parameter gets a memory home at
 * entry and is reloaded at the call, which is exactly the str/ldr pair the
 * earlier passes could not force.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long long u64;

extern u32   POKE_TOOL_GetPartyParamSize(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  POKE_TOOL_SetupPartyParam(void *v, u16 s, u16 l, u64 id);
extern u8    sPokeToolFile;

void *POKE_TOOL_Create(u16 species, u16 level, u64 id, u16 heap)
{
    void *v = func_02030734(heap, POKE_TOOL_GetPartyParamSize(), 1, (const char *)&sPokeToolFile, 0xa0);
    if (v != 0) {
        POKE_TOOL_SetupPartyParam(v, species, level, id);
    }
    return v;
}
