/*
 * function: FIELD_G3D_MAP_SetAltTextureRes
 * address:  0x021693B4
 * packet:   pkt_ov010_021693B4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from ov021 FIELD_G3D_MAPPER_Setup.
 */
#include "../include/Obj19037.h"

void FIELD_G3D_MAP_SetAltTextureRes(char *p, int v)
{
    ((struct Obj19037 *)p)->f94 = v;
}
