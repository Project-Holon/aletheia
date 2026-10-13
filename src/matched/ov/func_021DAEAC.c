/*
 * function: HAND_TOKUSEI_DampRemoveSkipCheckForOwner
 * address:  0x021DAEAC
 * packet:   pkt_021D8684
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HAND_TOKUSEI_DampRemoveSkipCheckForOwner   0x021DAEAC  thumb
 *   BTL_EVENT_ClearFactorSkipCheck   0x021D7324  thumb
 *   BTL_EVENT_GetVar   0x021D775C  thumb
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r3, r4, r5, lr}; adds r5, r0, #0; movs r0, #2; adds r4, r2, #0; bl BTL_EVENT_GetVar; cmp r4, r0; bne loc_021DAEC2; adds r0, r5, #0; bl BTL_EVENT_ClearFactorSkipCheck; pop {r3, r4, r5, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021DAEAC  shape F3: gate on BTL_EVENT_GetVar(2) then BTL_EVENT_ClearFactorSkipCheck */
void HAND_TOKUSEI_DampRemoveSkipCheckForOwner(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(2))
        BTL_EVENT_ClearFactorSkipCheck(a);
}

