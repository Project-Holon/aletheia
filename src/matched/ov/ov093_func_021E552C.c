/*
 * function: HAND_WAZA_WideGuardOnUncategorizedMoveNoTarget
 * address:  0x021E552C
 * packet:   pkt_ov093_021E552C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_MakeSlotKind2Index  0x021E8940  thumb  ov093
 *   BTL_MAIN_IsPokeIdInSecondPair  0x021B9A40  thumb  ov093
 *   HAND_WAZA_AddSideEffect  0x021E556C  thumb  ov093
 *   HAND_WAZA_ProtectIncrementStreak  0x021E3C5C  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { u32 v; } Word;

extern Word BTLV_CORE_MakeSlotKind2Index(int v);
extern unsigned char BTL_MAIN_IsPokeIdInSecondPair(unsigned int x);
extern void HAND_WAZA_AddSideEffect(int a, int b, int c, int d, u8 e, int f, Word g, u16 h);
extern void HAND_WAZA_ProtectIncrementStreak(void *a, int b, int c);

void HAND_WAZA_WideGuardOnUncategorizedMoveNoTarget(int a, int b, int c, int d)
{
    Word t;

    t = BTLV_CORE_MakeSlotKind2Index(1);
    HAND_WAZA_AddSideEffect(a, b, c, d, BTL_MAIN_IsPokeIdInSecondPair(c), 9, t, 0xa0);
    HAND_WAZA_ProtectIncrementStreak((void *)b, c, 1);
}
