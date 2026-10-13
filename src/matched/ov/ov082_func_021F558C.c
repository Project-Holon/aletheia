/*
 * function: FLD_FACEUP_ResumeLipSync
 * address: 0x021F558C
 * packet: pkt_ov082_021F558C
 * region: ov082
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   FIELDMAP_GetFaceUpWorkPtr 0x02189A60 thumb ov021
 */
#include "../include/Obj13225.h"
typedef unsigned char u8;
extern u8 **FIELDMAP_GetFaceUpWorkPtr(u8 *p);
void FLD_FACEUP_ResumeLipSync(u8 *p) { u8 *w = *FIELDMAP_GetFaceUpWorkPtr(p); ((struct Obj13225 *)w)->f1C=0; ((struct Obj13225 *)w)->f74=1; }
