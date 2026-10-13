/*
 * function: BTL_MAIN_GetSlotClientIdThunk
 * address:  0x021B8DE4
 * packet:   pkt_021B8DE4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetSlotClientId   0x021B8CFC  thumb ov093
 *   BTL_MAIN_GetSlotClientIdThunk   0x021B8DE4  thumb ov093
 *
 * tail-call thunk to BTL_MAIN_GetSlotClientId
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern unsigned char BTL_MAIN_GetSlotClientId(char *p, int i);

u8 BTL_MAIN_GetSlotClientIdThunk(char *p, int i)
{
    return BTL_MAIN_GetSlotClientId(p, i);
}
