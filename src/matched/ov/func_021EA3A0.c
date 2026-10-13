/*
 * function: BTLV_CORE_WaitMonSpriteUpdate
 * address:  0x021EA3A0
 * packet:   pkt_021E9884
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_WaitMonSpriteUpdate   0x021EA3A0  thumb  ov093
 *   BTLV_SCU_IsHpGaugeIdle   0x021ED4D0  thumb  ov093
 * Wrapper family member; the body is the hand-checked shape of the family's first instance with only the member's constants substituted, per the family uniformity assertion in o36/report.md.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

typedef struct { u32 f0; u8 pad[60]; } E64;

int BTLV_CORE_WaitMonSpriteUpdate(u32 *p) { return BTLV_SCU_IsHpGaugeIdle(p[0x5f]) != 0; }

