/*
 * function: func_021BD4CC
 * address:  0x021BD4CC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   func_02021540  0x02021540  thumb
 *   func_021BD4CC  0x021BD4CC  thumb  ov217
 *
 *
 * BLOCKED at MATCH: the relocation site(s) below have no independent witness.
 *   +001E THM_CALL func_02021540       -> unresolved: 02021540 (arm, from name) has no witness outside 021BD4CC..021BD4F0
 * Promote automatically when the target is matched.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10958.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_02021540(void *a0);
struct PalAnmSlot;
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
u32 func_021BD4CC(u32 a0)
{
    func_020215A0((struct PalAnmSlot *)(((struct Obj10958 *)((u8*)a0))->f98), 0);
    func_020215A0((struct PalAnmSlot *)(((struct Obj10958 *)((u8*)a0))->f98), 2);
    return func_02021540((void *)(((struct Obj10958 *)((u8*)a0))->f98));
}

