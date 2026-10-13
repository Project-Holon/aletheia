/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200C7C0
 * packet:   pkt_0200C52C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: ZUKAN_SAVE_GetFormBitBase, ZUKAN_SAVE_GetFormTableIndex
 *
 * 88 bytes, 0x0200C7C0..0x0200C818, 2 functions, neither of which carries a
 * label in the generated listing.
 *
 * alias: inside "musical_dist_save.c"; see src/matched/unit_0200C6D8.c for
 * how the name is attested.
 *
 * Two searches of the same zero-terminated table of `{u16 id, u16 count}`
 * pairs at 0x0209DE4C: the first returns the running sum of the counts in
 * front of the match, which is a base index into a flat array, and the second
 * returns the entry's own index.  Both return ~0 when the id is not listed,
 * spelled `movs r0, #0` / `mvns r0, r0` rather than a pool word.
 *
 * Both are `do`/`while` loops and not `while` loops: the key of entry zero is
 * never tested before the first body, so the table is known to be non-empty
 * by construction.  A `while (tbl[i].key != 0)` adds the entry test in front
 * of the loop and moves every instruction after it.
 *
 * The declaration order of the two locals in ZUKAN_SAVE_GetFormBitBase is load bearing
 * and is the only thing the bytes say about it: the running sum is declared
 * first and lands in r2, the index second and lands in r3.  Declared the
 * other way round the two swap registers and five bytes differ with nothing
 * else moving.
 *
 * The pool word holding 0x0209DE4C is attested as `literal`: three literal
 * pools in the image hold that address, so even with both of these functions
 * in one range a witness survives outside it.
 *
 * The two neighbours immediately before this range, ZUKAN_SAVE_IsCountedForNationalCompletion and
 * ZUKAN_SAVE_IsCountedForRegionalCompletion, reproduce every concrete byte and stay at MATCH.  Each is a
 * linear scan of a `u16` table, at 0x0209DE2C with fifteen entries and at
 * 0x0209DE20 with six, and each table's address appears in exactly one
 * literal pool in the whole image: its own.  The `literal` class discards
 * that witness under the honesty rule and no cut helps, because shrinking the
 * range to one function keeps its own pool word in it.  Evidence class:
 * `literal`, no outside witness; the C is not in question.
 *
 * symbols:
 *   sZukanFormTable  0x0209DE4C  data
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct DistEnt {
    u16 id;
    u16 count;
};

extern const struct DistEnt sZukanFormTable[];

u32 ZUKAN_SAVE_GetFormBitBase(u16 id)
{
    u32 base = 0, i = 0;

    do {
        if (id == sZukanFormTable[i].id) {
            return base;
        }
        base += sZukanFormTable[i].count;
        i++;
    } while (sZukanFormTable[i].id != 0);
    return (u32)-1;
}

u32 ZUKAN_SAVE_GetFormTableIndex(u32 id)
{
    u32 i = 0;

    do {
        if (id == sZukanFormTable[i].id) {
            return i;
        }
        i++;
    } while (sZukanFormTable[i].id != 0);
    return (u32)-1;
}
