/*
 * function: FLDMMDL_GetGridNowPos
 * address:  0x0216D828
 * packet:   pkt_ov010_0216D828
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as the sole blocker of ov018 INTRUDE_FIELD_TryStartOfferEvent: copies the three
 * s16 at +0x3C/+0x3E/+0x40 out to a caller's vector.
 */
#include "../include/Obj00113.h"

typedef unsigned char u8;
typedef short s16;

typedef struct { s16 x, y, z; } Vec3s;

void FLDMMDL_GetGridNowPos(u8 *p, Vec3s *out)
{
    out->x = ((struct Obj00113 *)p)->f3C;
    out->y = ((struct Obj00113 *)p)->f3E;
    out->z = ((struct Obj00113 *)p)->f40;
}
