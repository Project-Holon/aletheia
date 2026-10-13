/*
 * function: BTL_TOKUSEI_ParalysisGuard_CheckAdd
 * address:  0x021D93D8
 * packet:   pkt_021D8684
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_TOKUSEI_ParalysisGuard_CheckAdd   0x021D93D8  thumb
 *   BTL_TOKUSEI_BlockSickIfTargeted   0x021D9648  thumb
 * Leaf with no calls and no pool; 8 instructions, 18 bytes: push {r4, lr}; adds r0, r1, #0; adds r1, r2, #0; movs r2, #1; adds r4, r3, #0; bl BTL_TOKUSEI_BlockSickIfTargeted; str r0, [r4]; pop {r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D93D8  shape F5: out-param store of BTL_TOKUSEI_BlockSickIfTargeted(..., 1) */
void BTL_TOKUSEI_ParalysisGuard_CheckAdd(int a, int b, int c, u32 *out)
{
    *out = BTL_TOKUSEI_BlockSickIfTargeted(b, c, 1);
}

