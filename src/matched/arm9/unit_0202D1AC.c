/*
 * unit:     yes
 * function: POKEGRA_GetMAnmArcIndex
 * address:  0x0202D1AC
 * packet:   pkt_0202D1AC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKEGRA_CalcArcIndex  0x0202D4A8  thumb
 *
 * The two consecutive wrappers around the 13-argument text/window
 * measurement routine at 0x0202D4A8, folded into one translation unit.
 * Each forwards its three stack arguments, hands the callee two
 * out-pointers and returns their sum plus a per-function constant
 * (7, 8).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202D1AC.c \
 *       --addr 0x0202D1AC --cc 1.1p1 --thumb
 */

typedef unsigned int u32;
typedef int s32;

extern void POKEGRA_CalcArcIndex(void *narc, u32 species, s32 form, s32 mode, u32 base, u32 shiny, u32 egg, u32 *out_index, u32 *out_pal, u32 *out_mode, u32 *out_base, u32 **out_ptr, u32 female);

s32 POKEGRA_GetMAnmArcIndex(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7)
{
    s32 b;
    s32 a;

    POKEGRA_CalcArcIndex((void *)a0, a1, a2, a3, s5, s6, s7, (u32 *)(&b), (u32 *)(&a), 0, 0, 0, 0);
    return b + a + 7;
}

s32 POKEGRA_GetNcecArcIndex(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7)
{
    s32 b;
    s32 a;

    POKEGRA_CalcArcIndex((void *)a0, a1, a2, a3, s5, s6, s7, (u32 *)(&b), (u32 *)(&a), 0, 0, 0, 0);
    return b + a + 8;
}

