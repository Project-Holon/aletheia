/*
 * function: BTL_SICKCONT_MakeNone
 * address:  0x021E8918
 * packet:   pkt_021EA478
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SICKCONT_MakeNone   0x021E8918  thumb  ov093

 * Returns 0 with a 4-byte frame that nothing ever stores to.  Taking the address of a local array forces the slot, and the optimizer then removes both the store and the reload (nothing outside can alias it), so the frame and the register-resident value both survive.  A scalar `u32 v = 0; v &= ~7u;` folds to 4 bytes, which is why O28's residue could not reach this; the address-taken local is the missing form.
 */
#include "../include/Obj12160.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

u32 BTL_SICKCONT_MakeNone(void) { u8 b[4]; ((struct Obj12160 *)b)->f0 = 0; return ((struct Obj12160 *)b)->f0 & ~7u; }

