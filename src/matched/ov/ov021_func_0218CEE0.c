/*
 * function: FIELD_G3D_MAPPER_GetHeightEx
 * address:  0x0218CEE0
 * packet:   pkt_ov021_0218CEE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled 4-byte getter (ldr r0, [r0, #0x70]; bx lr), a leaf of
 * ov043 func_021F36C0.
 */
#include "../include/Obj19549.h"

typedef unsigned char u8;

void *FIELD_G3D_MAPPER_GetHeightEx(void *p)
{
    return ((struct Obj19549 *)p)->f70;
}
