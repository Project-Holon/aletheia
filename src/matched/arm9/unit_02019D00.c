/*
 * unit:     yes
 * address:  0x02019D00
 * packet:   pkt_02019388
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKE_TOOL_GetBoxParamIndex, POKE_TOOL_NormalizeForm
 *
 * Neither carries a label in the generated listing.  POKE_TOOL_GetBoxParamIndex
 * is a dense switch over 0x74..0x77 whose four arms each return a constant,
 * and the `subs r0, #0x74` in front of the `cmp`/`bhi` is the compiler's
 * normalisation of the range rather than anything the source wrote; see
 * docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *
 * The range stops at 0x02019D58.  The two unlabelled search loops after it,
 * at 0x02019D58 and 0x02019D84, reproduce every concrete byte but read
 * halfword tables at 0x0209E280 and 0x0209E42C, and each of those addresses
 * appears in exactly one literal pool in the whole image, the one under test,
 * so the literal class discards its only witness and no cut helps.
 *
 * symbols:
 *   POKE_TOOL_GetPersonalParam  0x02019C90  thumb
 */

typedef unsigned int   u32;
typedef signed int     s32;

extern u32 POKE_TOOL_GetPersonalParam(u32 a, u32 b, u32 k);

u32 POKE_TOOL_GetBoxParamIndex(u32 id)
{
    switch (id) {
    case 0x74:
        return 1;
    case 0x75:
        return 2;
    case 0x76:
        return 3;
    case 0x77:
        return 4;
    }
    return 0;
}

u32 POKE_TOOL_NormalizeForm(u32 a, u32 n)
{
    if (a != 0x28A) {
        if ((s32)n >= (s32)POKE_TOOL_GetPersonalParam(a, n, 0x20)) {
            n = 0;
        }
        return n;
    }
    if (n >= 2) {
        n = 0;
    }
    return n;
}
