/*
 * function: RESEARCH_COMMON_CreateClactUnit
 * address:  0x021C0B94
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reconstructed from the listing.
 *
 * symbols:
 *   RESEARCH_COMMON_CreateClactUnit  0x021C0B94  thumb  ov217
 *   CLACT_CreateUnit  0x0204B100  arm  arm9
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00791.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
void RESEARCH_COMMON_CreateClactUnit(u32 a0)
{
    ((struct Obj00791 *)(((u8*)a0 + 0)))->f20 = (u32)CLACT_CreateUnit(1, 2, ((struct Obj00791 *)((u8*)a0))->f0);
}

