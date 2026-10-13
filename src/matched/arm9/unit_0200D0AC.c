/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * unit:     yes
 * address:  0x0200D0AC
 * packet:   pkt_0200CA98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: ZUKAN_SAVE_CountSeen, ZUKAN_SAVE_CountSeenNational, ZUKAN_SAVE_CountSeenRegional
 *
 * 152 bytes, 0x0200D0AC..0x0200D144, 3 functions, all labelled.
 *
 * The "seen" counterpart of src/matched/unit_0200CED4.c: the same three
 * functions over ZUKAN_SAVE_IsSeen's four-bitmap test instead of ZUKAN_SAVE_IsCaught's
 * single one.  0x289 is 649, one past the last species id this block tracks,
 * and 0x3E7 is the 999 the id-to-index table uses for "no entry".
 *
 * Near miss, and the reason this range starts at 0x0200D0AC: ZUKAN_SAVE_IsSeen,
 * 72 bytes, the four-bitmap test itself.  Every instruction reproduces bar the
 * placement of one `adds`: the original recomputes `p + i * 0x54 + (id >> 3)`
 * inside the loop, and mwccarm hoists the loop-invariant `p + (id >> 3)` into
 * the preheader instead, which leaves the same instruction count and the same
 * 72 bytes with 30 concrete bytes differing in register numbers.  Eighty
 * source shapes were compiled and ranked: the loop counter as `u16`, `u32` and
 * `s32`, the index with and without a `(u16)` cast, the bit mask and the byte
 * index as locals and inline, `for` against `do`/`while`, `goto` against
 * `return`, and the row as a pointer local, a dereferenced sum and a flat
 * index.  Only the `(u16)` cast on the index and the mask in a local reach the
 * right size at all, and past that the ranking is flat at 30, so the hoist is
 * not reachable from the source shape.  Same class as the near misses at
 * 0x0200B2A4 and 0x0200B37C.
 *
 * symbols:
 *   POKE_PERSONAL_LoadFormTable  0x0201AF80  thumb
 *   ZUKAN_SAVE_IsInvalidSpecies  0x0200C720  thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled  0x0200CA38  thumb
 *   ZUKAN_SAVE_IsSeen  0x0200D064  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Blk37 {
    u32 unk00;
    u32 f0  : 1;
    u32 f1  : 10;
    u32 f11 : 1;
    u32 f12 : 10;
    u32 f22 : 10;
    u8  unk008[0x54];
    u8  unk05C[4][0x54];
    u8  unk1AC[4][0x54];
    u8  unk2FC[4][9];
    u8  unk320[0x1B0];
    u32 unk4D0;
};

extern u32 ZUKAN_SAVE_IsInvalidSpecies(u32 v);
extern u32   ZUKAN_SAVE_IsNationalDexEnabled(struct Blk37 *p);
extern u16 *POKE_PERSONAL_LoadFormTable(u32 heap, u16 *countOut);
extern u32 func_020307B0(void *p);

u32 ZUKAN_SAVE_IsSeen(struct Blk37 *p, u16 id);
u16 ZUKAN_SAVE_CountSeenNational(struct Blk37 *p);
u16 ZUKAN_SAVE_CountSeenRegional(struct Blk37 *p, u32 heap);

u32 ZUKAN_SAVE_CountSeen(struct Blk37 *p, u32 heap)
{
    if (ZUKAN_SAVE_IsNationalDexEnabled(p) != 0) {
        return ZUKAN_SAVE_CountSeenNational(p);
    }
    return ZUKAN_SAVE_CountSeenRegional(p, heap);
}

u16 ZUKAN_SAVE_CountSeenNational(struct Blk37 *p)
{
    s32 n;
    s32 i;

    n = 0;
    for (i = 1; i <= 0x289; i++) {
        if (ZUKAN_SAVE_IsSeen(p, (u16)i) == 1) {
            n++;
        }
    }
    return (u16)n;
}

u16 ZUKAN_SAVE_CountSeenRegional(struct Blk37 *p, u32 heap)
{
    u16 i;
    u16 n;
    u16 *t;

    n = 0;
    t = POKE_PERSONAL_LoadFormTable(heap, 0);
    for (i = 1; i <= 0x289; i++) {
        if (ZUKAN_SAVE_IsSeen(p, i) == 1 && t[i] != 0x3E7) {
            n = (u16)(n + 1);
        }
    }
    func_020307B0(t);
    return n;
}
