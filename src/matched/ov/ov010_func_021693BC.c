/*
 * function: FIELD_G3D_MAP_ClearAltTextureRes
 * address:  0x021693BC
 * packet:   pkt_ov010_021693BC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from ov021 FIELD_G3D_MAPPER_ReleaseBlocks.
 */
#include "../include/Obj19038.h"

void FIELD_G3D_MAP_ClearAltTextureRes(char *p)
{
    ((struct Obj19038 *)p)->f94 = 0;
}
