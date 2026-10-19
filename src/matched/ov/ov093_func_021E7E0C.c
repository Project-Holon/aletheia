/*
 * function: HAND_WAZA_QuickGuardOnUncategorizedMoveNoTarget
 * address:  0x021E7E0C
 * packet:   pkt_ov093_021E7E0C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SICKCONT_MakeKind2Index  0x021E8940  thumb  ov093
 *   BTL_MAIN_IsPokeIdInSecondPair  0x021B9A40  thumb  ov093
 *   HAND_WAZA_AddSideEffect  0x021E556C  thumb  ov093
 *   HAND_WAZA_ProtectIncrementStreak  0x021E3C5C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef struct Word { u32 v; } Word;

extern Word BTL_SICKCONT_MakeKind2Index(int v);
extern unsigned char BTL_MAIN_IsPokeIdInSecondPair(unsigned int x);
extern void HAND_WAZA_AddSideEffect(int a, int b, int c, int d, int e, int f, Word g, int h);
extern void HAND_WAZA_ProtectIncrementStreak(void *a, int b, int c);

void HAND_WAZA_QuickGuardOnUncategorizedMoveNoTarget(int a, int b, int c, int d)
{
    Word t = BTL_SICKCONT_MakeKind2Index(1);
    int e = BTL_MAIN_IsPokeIdInSecondPair(c);
    HAND_WAZA_AddSideEffect(a, b, c, d, e, 10, t, 0xa2);
    HAND_WAZA_ProtectIncrementStreak((void *)b, c, 1);
}
