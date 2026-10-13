/*
 * unit:     yes
 * function: POKEGRA_GetCgrArcIndex
 * address:  0x0202D064
 * packet:   pkt_0202D064
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
 * The two consecutive three-out-pointer wrappers around the 13-argument
 * text/window measurement routine at 0x0202D4A8, folded into one
 * translation unit. The first sets the trailing flag to one and returns the
 * plain sum of the three accumulators; the second leaves every flag zero
 * and adds two.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202D064.c \
 *       --addr 0x0202D064 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;
typedef int s32;

extern void POKEGRA_CalcArcIndex(void *narc, u32 species, s32 form, s32 mode, u32 base, u32 shiny, u32 egg, u32 *out_index, u32 *out_pal, u32 *out_mode, u32 *out_base, u32 **out_ptr, u32 female);

s32 POKEGRA_GetCgrArcIndex(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7)
{
    s32 b;
    s32 a;
    s32 c;

    POKEGRA_CalcArcIndex((void *)a0, a1, a2, a3, s5, s6, s7, (u32 *)(&b), (u32 *)(&a), (u32 *)(&c), 0, 0, 1);
    return c + (b + a);
}

s32 POKEGRA_GetCbrArcIndex(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7)
{
    s32 b;
    s32 a;
    s32 c;

    POKEGRA_CalcArcIndex((void *)a0, a1, a2, a3, s5, s6, s7, (u32 *)(&b), (u32 *)(&a), (u32 *)(&c), 0, 0, 0);
    return c + (b + a + 2);
}
