/*
 * function: FISHING_StartRodEffect
 * address:  0x021C602C
 * packet:   pkt_ov021_021C602C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FLDEFF_FISHING_Start  0x021ADF94  thumb  ov021
 */
#include "../include/Obj06081.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern u32 FIELDMAP_GetEffect(u8 *p);
extern u32 FLDEFF_FISHING_Start(u32 a, void *b, u32 c, int d);
void FISHING_StartRodEffect(u8 *p)
{
    ((struct Obj06081 *)p)->f30 = FLDEFF_FISHING_Start(FIELDMAP_GetEffect((u8 *)(((struct Obj06081 *)p)->f8)), p + 0x40, ((struct Obj06081 *)p)->f58, ((struct Obj06081 *)p)->f44 == ((struct Obj06081 *)p)->f38);
}
