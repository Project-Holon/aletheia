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
 *   func_020173EC  0x020173EC  thumb
 *   func_02030734  0x02030734  arm
 *   func_02017588  0x02017588  thumb
 *   sPokeToolFile  0x020A72E4  data
 *
 * Allocate a record (line 0xBA) and initialise it through func_02017588,
 * forwarding the u64 id, the packed IVs `pow` and the u64 personality
 * `rnd`; the heap id (u16, `ldrh`) is the LAST parameter, after rnd.
 * Wave 11, 2026-09-23: closed by the u64 id/rnd declarations (see
 * func_020173F0.c).
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long long u64;

extern u32   func_020173EC(void);
struct Mon;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02017588(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern u8    sPokeToolFile;

void *POKE_TOOL_CreateEx(u16 species, u16 level, u64 id, u32 pow, u64 rnd, u16 heap)
{
    void *v = func_02030734(heap, func_020173EC(), 1, (const char *)&sPokeToolFile, 0xba);
    if (v != 0) {
        func_02017588(v, species, level, id, pow, rnd);
    }
    return v;
}
