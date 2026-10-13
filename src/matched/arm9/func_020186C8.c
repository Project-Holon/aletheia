/*
 * function: POKE_TOOL_CreatePersonalRnd
 * address:  0x020186C8
 * packet:   pkt_0201862C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   POKE_TOOL_CheckShiny  0x02017ED8  thumb
 *   POKE_TOOL_GetGenderRatioClass  0x020185F8  thumb
 *   POKE_PERSONAL_IsPlaceholderAbility  0x0201AF6C  thumb
 *
 * Build a personality value for trainer id a0: a3 selects the gender
 * handling (2 = fully random), a5 the shininess (1 = force shiny through
 * the id key, 0 = force NOT shiny by flipping bit 28 when POKE_TOOL_CheckShiny
 * says shiny, 2 = leave), and bit 16 is forced to a4 (read as a word, so
 * a4 is int-sized).  Wave 11, 2026-09-23.
 *
 * The 8-byte shortfall of the r4-3/r4-6 lanes ("duplicated compare, shared
 * eors", judged a cross-jump no source can request) is the SOURCE shape:
 * case 1 carries its own bit-16 fix and `break`s, case 0 FALLS THROUGH into
 * case 2, which carries the other copy; the compiler tail-merges the two
 * `v ^= 0x10000` statements and nothing else.  Case bodies in the order
 * 1, 0, 2; the case-1 key written `hi(a0) ^ (u16)a0` first.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_020056EC(u32 range);
extern u32 POKE_TOOL_CheckShiny(u32 a0, u32 a1);
extern u32 POKE_TOOL_GetGenderRatioClass(int a0, int a1, int a2);
extern u32 POKE_PERSONAL_IsPlaceholderAbility(u32 v);

u32 POKE_TOOL_CreatePersonalRnd(u32 a0, int a1, int a2, int a3, int a4, int a5)
{
    u32 v;

    if (a3 == 2) {
        v = func_020056EC(0);
    } else {
        u32 t = func_020056EC(0) & ~0xFFu;

        v = POKE_TOOL_GetGenderRatioClass(a1, a2, (u8)a3);
        if (a3 == 0) {
            if (POKE_PERSONAL_IsPlaceholderAbility(v) == 0) {
                v = v + func_020056EC(0xFE - v);
                goto L;
            }
        }
        if (a3 == 1) {
            if (POKE_PERSONAL_IsPlaceholderAbility(v) == 0) {
                v = func_020056EC(v) + 1;
            }
        }
    L:
        v |= t;
    }
    switch (a5) {
    case 1:
        v = (u8)v | (((((a0 & 0xFFFF0000u) >> 16) ^ (u16)a0) ^ (u8)v) << 16);
        if ((v & 0x10000u) != ((u32)a4 << 16)) {
            v ^= 0x10000u;
        }
        break;
    case 0:
        if (POKE_TOOL_CheckShiny(a0, v) == 1) {
            v ^= 0x10000000u;
        }
    case 2:
        if ((v & 0x10000u) != ((u32)a4 << 16)) {
            v ^= 0x10000u;
        }
        break;
    }
    return v;
}
