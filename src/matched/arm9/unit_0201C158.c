/*
 * unit:     yes
 * address:  0x0201C158
 * packet:   pkt_0201BD28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: WAZA_TOOL_GetMaxPP, WAZA_TOOL_GetWeather, WAZA_TOOL_GetCategory
 *
 * waza_tool.c: the effective PP calculation, a four-entry id translation and
 * one more named field read.
 *
 * WAZA_TOOL_GetMaxPP is the function src/pending/POKE_TOOL_GetBoxValueRaw.c's field map calls
 * for ids 0x42 to 0x45: base PP (field 5 of the move record, through
 * src/matched/unit_0201BD28.c) plus base * 20 * ppUp / 100, with ppUp clamped
 * to 3 and every intermediate truncated to u8.  The two `muls` are one
 * expression and their order is the source's: the clamped count multiplies
 * the already-scaled base, not the other way round
 * (docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md).
 *
 * The clamp compares unsigned (`bls`) while the division calls _s32_div_f,
 * so the count is an unsigned parameter and the product is cast to `int`
 * before the divide; written unsigned throughout, every concrete byte is
 * still right and the call goes to _u32_div_f instead, which is a different
 * address and a DIFF.
 *
 * WAZA_TOOL_GetWeather is a sparse four-case switch, which this front end lowers as a
 * binary search rather than a table: `> 0xF1`, then `< 0xF0`, then the two
 * equality tests.  The bodies are still emitted in source order, so the arms
 * are written 0xF0, 0xF1, 0xC9, 0x102 even though the comparisons are in
 * value order, and the value is signed: the two range tests are `bgt`/`blt`,
 * so the parameter is `int` and not `u32`.  0x102 arrives from a pool word because it is past the 255 a
 * `movs` immediate reaches.
 *
 * VERSION SENSITIVITY: 0xF0, 0xF1, 0xC9 and 0x102 are content ids (moves or
 * items), not offsets.  They are expected to be the same in Pokemon White,
 * which shares Black's numbering, but they are the constants to re-read first
 * if a White build diverges here.
 *
 * WAZA_TOOL_GetCategory is an unlabelled tail call, three instructions and two pool
 * words (docs/idioms/tail-call-is-a-pool-word-and-bx.md), reading field 1.
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C158.c \
 *       --addr 0x0201C158 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 sub_0201BD28(u16 id, u32 field);

u8 WAZA_TOOL_GetMaxPP(u16 move, u32 ppUp)
{
    u8 base;

    if (ppUp > 3) {
        ppUp = 3;
    }
    base = (u8)sub_0201BD28(move, 5);
    return (u8)(base + (u8)((int)(ppUp * (base * 20)) / 100));
}

u32 WAZA_TOOL_GetWeather(int id)
{
    switch (id) {
    case 0xF0:  return 2;
    case 0xF1:  return 1;
    case 0xC9:  return 4;
    case 0x102: return 3;
    }
    return 0;
}

u32 WAZA_TOOL_GetCategory(u16 move)
{
    return sub_0201BD28(move, 1);
}
