/*
 * function: BTL_SIDE_GetPokeAtPosThunk
 * address:  0x021B98A4
 * packet:   pkt_021B98A4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SIDE_GetPokeAtPos   0x021B98AC  thumb ov093
 *   BTL_SIDE_GetPokeAtPosThunk   0x021B98A4  thumb ov093
 *
 * tail-call thunk to BTL_SIDE_GetPokeAtPos
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern u8 *BTL_SIDE_GetPokeAtPos(char *const *q, u8 b);

u8 *BTL_SIDE_GetPokeAtPosThunk(char *const *q, u8 b)
{
    return BTL_SIDE_GetPokeAtPos(q, b);
}
