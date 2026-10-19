/*
 * function: HAND_WAZA_ReflectOnUncategorizedMoveNoTarget
 * address:  0x021E52D4
 * packet:   pkt_ov093_021E52D4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The callee's word result is a one-word struct (see
 * docs/idioms/a-one-word-struct-result-passed-by-value-costs-a-second-frame-word.md).
 *
 * symbols:
 *   BTL_SICKCONT_MakeKind2Index  0x021E8940  thumb  ov093
 *   BTL_MAIN_IsPokeIdInSecondPair  0x021B9A40  thumb  ov093
 *   HAND_WAZA_AddSideEffect  0x021E556C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef struct Word { u32 v; } Word;

extern Word BTL_SICKCONT_MakeKind2Index(int k);
extern unsigned char BTL_MAIN_IsPokeIdInSecondPair(unsigned int x);
extern void HAND_WAZA_AddSideEffect(int a, int b, int c, int d, int e, int f, Word g, int h);

void HAND_WAZA_ReflectOnUncategorizedMoveNoTarget(int a, int b, int c, int d)
{
    Word t = BTL_SICKCONT_MakeKind2Index(5);
    int e = BTL_MAIN_IsPokeIdInSecondPair(c);
    HAND_WAZA_AddSideEffect(a, b, c, d, e, 0, t, 0x7c);
}
