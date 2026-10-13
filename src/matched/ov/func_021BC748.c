/*
 * function: FIELD_PLACE_NAME_DeleteClactRenderer
 * address:  0x021BC748
 * packet:   pkt_021BC748
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   CLACT_DeleteRenderer  0x0204B084  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00575.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void CLACT_DeleteRenderer(u32 v);

void FIELD_PLACE_NAME_DeleteClactRenderer(u8 *p)
{
    u32 v = ((struct Obj00575 *)p)->f38;
    if (v != 0) {
        CLACT_DeleteRenderer(v);
        ((struct Obj00575 *)p)->f38 = 0;
    }
}
