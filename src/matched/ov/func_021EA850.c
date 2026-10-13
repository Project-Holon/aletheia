/*
 * function: BTLV_CORE_WaitSlotEffect25F
 * address:  0x021EA850
 * packet:   pkt_021E9884
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_WaitSlotEffect25F   0x021EA850  thumb  ov093
 *   BTLV_SCU_IsPosCueEffectDone   0x021ED57C  thumb  ov093
 *   BTL_MAIN_GetViewPosOfSlot   0x021B8E70  thumb  ov093
 * Wrapper family member; the body is the hand-checked shape of the family's first instance with only the member's constants substituted, per the family uniformity assertion in o36/report.md.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

typedef struct { u32 f0; u8 pad[60]; } E64;

extern u8 BTL_MAIN_GetViewPosOfSlot(u8 *p, u32 k);
extern int BTLV_SCU_IsPosCueEffectDone(int a, int b);

int BTLV_CORE_WaitSlotEffect25F(u32 *p, u32 k) { return BTLV_SCU_IsPosCueEffectDone(p[0x5f], BTL_MAIN_GetViewPosOfSlot((u8 *)p[0], k)); }

