/*
 * function: BTL_CALC_StallMoveLast
 * address:  0x021D88B8
 * packet:   pkt_021D8684
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_CALC_StallMoveLast   0x021D88B8  thumb
 *   BTL_EVENT_OverwriteVar   0x021D76BC  thumb
 *   BTL_EVENT_GetVar   0x021D775C  thumb
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #2; adds r4, r2, #0; bl BTL_EVENT_GetVar; cmp r4, r0; bne loc_021D88CE; movs r0, #0x11; movs r1, #0; bl BTL_EVENT_OverwriteVar; pop {r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D88B8  shape F1: gate on BTL_EVENT_GetVar(2) */
void BTL_CALC_StallMoveLast(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(2))
        BTL_EVENT_OverwriteVar(0x11, 0);
}

