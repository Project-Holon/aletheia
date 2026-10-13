/*
 * function: HAND_TOKUSEI_SandVeilBlockSandDamage
 * address:  0x021D8A8C
 * packet:   pkt_021D8A8C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HAND_TOKUSEI_SandVeilBlockSandDamage   0x021D8A8C  thumb
 *   HAND_TOKUSEI_BlockWeatherDamage   0x021D8AEC  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #4; str r4, [sp]; bl HAND_TOKUSEI_BlockWeatherDamage; add sp, #4; pop {r3, r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D8A8C  stack-arg wrapper: HAND_TOKUSEI_BlockWeatherDamage(a, b, c, d, 0x4) */
void HAND_TOKUSEI_SandVeilBlockSandDamage(int a, int b, int c, int d) { HAND_TOKUSEI_BlockWeatherDamage(a, b, c, d, 0x4); }

