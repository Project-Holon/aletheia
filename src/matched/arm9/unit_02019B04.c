/*
 * unit:     yes
 * address:  0x02019B04
 * packet:   pkt_02019388
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKE_TOOL_ApplyNatureModifier
 *
 * Scales b by a per (a, n) table entry of -1, 0 or 1; the multipliers are
 * 0x5A and 0x6E, which are 90 and 110 percent. Both arms are written out in
 * full and the compiler cross jumps their common muls/truncate/divide tail
 * into one block that the missing default branches past, which is
 * docs/idioms/switch-arms-tail-merge.md; hoisting the multiplication out of
 * the switch puts the default branch to that block instead of past it and
 * costs eight bytes.
 *
 * The table at 0x0209E324 is witnessed by the pool word of the neighbouring
 * leaf sub_02019B44.c (seeded via layout/function_starts.txt), and this
 * file's own pool word witnesses it for that one: the unit_02005DF8 /
 * unit_02005E30 pairwise treatment.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02019B04.c \
 *       --addr 0x02019B04 --thumb
 *
 * symbols:
 *   _s32_div_f           0x0209C0A4  arm
 *   func_02019B04_Table  0x0209E324  data
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;

extern const s8 func_02019B04_Table[][5];

u32 POKE_TOOL_ApplyNatureModifier(u32 a, u32 b, u32 n)
{
    s8 v;

    if (n >= 6) {
        return b;
    }
    v = func_02019B04_Table[a][n - 1];
    switch (v) {
    case 1:
        b = (u16)((u16)(b * 0x6E) / 100);
        break;
    case -1:
        b = (u16)((u16)(b * 0x5A) / 100);
        break;
    }
    return b;
}
