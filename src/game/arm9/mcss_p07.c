/*
 * file:     mcss_p07.c
 * unit:     yes
 * function: func_020173D0, func_020173E8, func_020173EC, func_020173F0, func_02017430
 * address:  0x020173D0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02146270      0x02146270  data
 *   func_02030734  0x02030734  arm
 *   func_0201756C  0x0201756C  thumb
 *   sPokeToolFile  0x020A72E4  data
 *   func_02017588  0x02017588  thumb
 */
struct Mon;
typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long long u64;

extern void func_0201AD88(u32 heap);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  func_0201756C(void *v, u16 s, u16 l, u64 id);
extern void func_02017588(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
void func_020173D0(u32 heap);
u32 func_020173E8(void);
u32 func_020173EC(void);
void *func_020173F0(u16 species, u16 level, u64 id, u16 heap);
void *func_02017430(u16 species, u16 level, u64 id, u32 pow, u64 rnd, u16 heap);
extern unsigned char g_02146270[];
extern u8    sPokeToolFile;


void func_020173D0(u32 heap)
{
    func_0201AD88(heap);
    *(unsigned short *)(g_02146270 + 2) = 0x28b;
}



/*
 * The two record sizes this region's files open with, `movs r0, #imm; bx lr`,
 * neither of them labelled in the generated listing because neither saves lr.
 * 0xDC is exactly what func_02017528 in src/matched/unit_02017528.c clears and
 * 0x88 exactly what func_02017550 clears, so the two constants and the struct
 * declaration check each other.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * The three functions in front of them are parked in
 * src/pending/unit_020173B4.c.
 *
 * The original file name of the two constructors after them is recoverable
 * even though neither is matched yet: func_020173F0 and func_02017430 both
 * pass 0x020A72E4 to the debug allocator at 0x02030734, and the bytes there
 * spell "poke_tool.c".  Its left neighbours in the packed string area are
 * "d_status.c" at 0x020A72C0 and "mcss.c" at 0x020A72CC, and between "mcss.c"
 * and it sit four pointer words at 0x020A72D4, so the `string` class cannot
 * reach it (docs/idioms/a-string-after-a-data-table-has-no-witness.md).  The
 * `literal` class can: two pool words name it, 0x0201742C and 0x02017478, so
 * a range holding exactly one of the two constructors attests it.  Neither is
 * matched here because each is in turn the only caller of its worker.
 */
u32 func_020173E8(void)
{
    return 0x88;
}



u32 func_020173EC(void)
{
    return 0xDC;
}



/*
 * Allocate a record (0xA0 is the __LINE__ passed to func_02030734 with the
 * poke_tool.c __FILE__ anchor) and initialise it through func_0201756C.
 * Wave 11, 2026-09-23.  The "one remaining codegen wall" of
 * docs/families/poke_tool.h section 11 was a declaration error: the id is a
 * single u64 in r2:r3, not two u32s.  A u64 parameter gets a memory home at
 * entry and is reloaded at the call, which is exactly the str/ldr pair the
 * earlier passes could not force.
 */
void *func_020173F0(u16 species, u16 level, u64 id, u16 heap)
{
    void *v = func_02030734(heap, func_020173EC(), 1, (const char *)&sPokeToolFile, 0xa0);
    if (v != 0) {
        func_0201756C(v, species, level, id);
    }
    return v;
}



/*
 * Allocate a record (line 0xBA) and initialise it through func_02017588,
 * forwarding the u64 id, the packed IVs `pow` and the u64 personality
 * `rnd`; the heap id (u16, `ldrh`) is the LAST parameter, after rnd.
 * Wave 11, 2026-09-23: closed by the u64 id/rnd declarations (see
 * func_020173F0.c).
 */
void *func_02017430(u16 species, u16 level, u64 id, u32 pow, u64 rnd, u16 heap)
{
    void *v = func_02030734(heap, func_020173EC(), 1, (const char *)&sPokeToolFile, 0xba);
    if (v != 0) {
        func_02017588(v, species, level, id, pow, rnd);
    }
    return v;
}
