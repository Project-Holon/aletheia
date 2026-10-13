/*
 * function: BTL_MAIN_PokeIdToClientIdThunk
 * address:  0x021B8DDC
 * packet:   pkt_021B8DDC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_PokeIdToClientId   0x021B8D08  thumb ov093
 *   BTL_MAIN_PokeIdToClientIdThunk   0x021B8DDC  thumb ov093
 *
 * tail-call thunk to BTL_MAIN_PokeIdToClientId
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern u8 BTL_MAIN_PokeIdToClientId(u32 x);

u8 BTL_MAIN_PokeIdToClientIdThunk(u32 x)
{
    return BTL_MAIN_PokeIdToClientId(x);
}
