/*
 * function: func_021C0AD8
 * address:  0x021C0AD8
 * packet:   pkt_ov217_021C0AD8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing.
 *
 * symbols:
 *   d_021C3F64  0x021C3F64  data
 *   d_021C3F9C  0x021C3F9C  data
 *   CLACT_InitSystem  0x0204A48C  arm  arm9
 *
 * closed: both data sites carried the contested ov217 token; dropping it lets
 * the function's own region (ov217) pick the objects and 0x021C3F9C resolves
 * as sole-ref/data.  All three relocations resolve, 24 bytes EXACT.
 * See docs/idioms/omitting-an-overlay-hint-can-attest-where-naming-it-cannot.md.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25984.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern u8 d_021C3F64[];
extern u8 d_021C3F9C[];
void func_021C0AD8(u32 a0)
{
    CLACT_InitSystem((const struct Cfg *)d_021C3F64, (u32)d_021C3F9C, ((struct Obj25984 *)((u8*)a0))->f0);
}

