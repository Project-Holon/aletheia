/*
 * function: B_BAG_MAIN_DeleteCursor
 * address:  0x0220D914
 * packet:   pkt_0220D914
 * region:   ov197
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CURSOR_MOVE_Delete  0x02025D14  thumb
 *
 * blocker: the ABS32 at +000C names 0x02025D14, an unlabelled arm9 leaf (no
 *   traced func_ label), so neither label nor sole-ref/code can attest it;
 *   byte-correct otherwise.  Not resolvable from this packet.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25122.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 CURSOR_MOVE_Delete(void *a0);

u32 B_BAG_MAIN_DeleteCursor(u8 *p)
{
    return CURSOR_MOVE_Delete((void *)(((struct Obj25122 *)p)->f144));
}

