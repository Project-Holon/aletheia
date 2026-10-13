/*
 * function: POKE_TOOL_CreateEx
 * address:  0x02017430
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
 *   POKE_TOOL_SetupPartyParamEx  0x02017588  thumb
 *   sPokeToolFile  0x020A72E4  data
 *
 * Allocate a record (line 0xBA) and initialise it through POKE_TOOL_SetupPartyParamEx,
 * forwarding the u64 id, the packed IVs `pow` and the u64 personality
 * `rnd`; the heap id (u16, `ldrh`) is the LAST parameter, after rnd.
 * Wave 11, 2026-09-23: closed by the u64 id/rnd declarations (see
 * POKE_TOOL_Create.c).
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long long u64;

extern u32   POKE_TOOL_GetPartyParamSize(void);
struct Mon;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void POKE_TOOL_SetupPartyParamEx(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern u8    sPokeToolFile;

void *POKE_TOOL_CreateEx(u16 species, u16 level, u64 id, u32 pow, u64 rnd, u16 heap)
{
    void *v = func_02030734(heap, POKE_TOOL_GetPartyParamSize(), 1, (const char *)&sPokeToolFile, 0xba);
    if (v != 0) {
        POKE_TOOL_SetupPartyParamEx(v, species, level, id, pow, rnd);
    }
    return v;
}
