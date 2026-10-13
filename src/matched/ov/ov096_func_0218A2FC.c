/*
 * function: TR_AI_GetPoke
 * address:  0x0218A2FC
 * packet:   pkt_ov096_0218A2FC
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Resolved by the BTL_SIDE_GetPokeAtPos label in ov069 (thumb); cross-overlay target.
 *
 * symbols:
 *   BTL_SIDE_GetPokeAtPos  0x021B98AC  thumb  ov093
 */
#include "../include/Obj00067.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern u8 *BTL_SIDE_GetPokeAtPos(char *const *q, u8 b);
u8 *TR_AI_GetPoke(u8 *p, u8 i) { return BTL_SIDE_GetPokeAtPos(*(char *const * *)&((struct Obj00067 *)p)->fB8, i); }
