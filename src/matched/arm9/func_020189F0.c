/*
 * function: POKE_TOOL_GetNatureStatModByNature
 * address:  0x020189F0
 * packet:   pkt_020189F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sNatureStatMods   0x0209E2A4  data  a1
 *
 * The nature table lookup: a signed byte out of the s8[25][5] table at
 * 0x0209E2A4 (row = nature, column = stat).  POKE_TOOL_GetBoxNatureStatMod is the one
 * caller, and it truncates the nature to u8 at the call.  Wave 11,
 * 2026-09-23.
 *
 * Closes the "one byte the language cannot express" of
 * docs/notes/POKE_TOOL_GetNatureStatModByNature.c.txt: earlier lanes read the SECOND argument as
 * a base pointer (`b[o + (u32)tbl]`), which makes the scaled index the
 * running operand of the final add.  It is an integer column index and the
 * natural two-dimensional subscript gives the image's `adds r0, r0, r2`
 * (table as accumulator) directly.
 */
typedef signed char   s8;
typedef unsigned char u8;
typedef unsigned int  u32;

extern const s8 sNatureStatMods[][5];

s8 POKE_TOOL_GetNatureStatModByNature(u8 nature, u32 stat)
{
    return sNatureStatMods[nature][stat];
}
