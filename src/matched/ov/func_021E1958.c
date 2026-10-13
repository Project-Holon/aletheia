/*
 * function: HAND_WAZA_CounterOnCalcFixedDamage
 * address:  0x021E1958
 * packet:   pkt_021DFA3C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HAND_WAZA_CounterOnCalcFixedDamage   0x021E1958  thumb  ov093
 *   HAND_WAZA_RetaliateOnCalcFixedDamage   0x021E1AA4  thumb  ov093
 * Wrapper family member; the body is the hand-checked shape of the family's first instance with only the member's constants substituted, per the family uniformity assertion in o36/report.md.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

typedef struct { u32 f0; u8 pad[60]; } E64;

void HAND_WAZA_CounterOnCalcFixedDamage(int a, int b, int c, int d) { HAND_WAZA_RetaliateOnCalcFixedDamage(b, c, d, 1, 2 << 12); }

