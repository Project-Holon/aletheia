/*
 * function: RESEARCH_COMMON_DeleteClactUnit
 * address:  0x021C0BA8
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 32)) to CLACT_DeleteUnit.
 *
 * symbols:
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25986.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Bank;
extern u32 CLACT_DeleteUnit(struct Bank *bank);

void RESEARCH_COMMON_DeleteClactUnit(u8 *a0)
{
    CLACT_DeleteUnit((struct Bank *)((u32)(((struct Obj25986 *)a0)->f20)));
}

