/*
 * function: HAND_WAZA_StealthRockOnUncategorizedMoveNoTarget
 * address:  0x021E54EC
 * packet:   pkt_ov093_021E54EC
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
 *   BTL_SICKCONT_MakeKind1Empty  0x021E89C0  thumb  ov093
 *   BTL_MAIN_IsPokeIdInFirstPair  0x021B9A50  thumb  ov093
 *   HAND_WAZA_AddSideEffect  0x021E556C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef struct Word { u32 v; } Word;

extern Word BTL_SICKCONT_MakeKind1Empty(void);
extern unsigned char BTL_MAIN_IsPokeIdInFirstPair(unsigned int x);
extern void HAND_WAZA_AddSideEffect(int a, int b, int c, int d, int e, int f, Word g, int h);

void HAND_WAZA_StealthRockOnUncategorizedMoveNoTarget(int a, int b, int c, int d)
{
    Word t = BTL_SICKCONT_MakeKind1Empty();
    int e = BTL_MAIN_IsPokeIdInFirstPair(c);
    HAND_WAZA_AddSideEffect(a, b, c, d, e, 8, t, 0x9c);
}
