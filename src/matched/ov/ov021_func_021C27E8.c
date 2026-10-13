/*
 * function: FLD3D_CI_RestoreVisiblePlanes
 * address:  0x021C27E8
 * packet:   pkt_ov021_021C27E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: tail call on the word at +0x68.  (Not the ov099
 * function at the same address in src/matched/ov/FLD3D_CI_RestoreVisiblePlanes.c.)
 *
 * symbols:
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj20174.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void BG_SYS_SetMainVisiblePlanes(u32 a);

void FLD3D_CI_RestoreVisiblePlanes(u8 *p)
{
    BG_SYS_SetMainVisiblePlanes(((struct Obj20174 *)p)->f68);
}
