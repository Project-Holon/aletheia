/*
 * function: POKETRADE_NEGO_ReleaseIconResources
 * address:  0x021DD588
 * packet:   pkt_ov119_021DD588
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 */
#include "../include/Obj00001.h"

typedef unsigned int   u32;
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);

void POKETRADE_NEGO_ReleaseIconResources(char *p)
{
    if (((struct Obj00001 *)p)->f890 != 0) {
        CLACT_ReleasePalette((u32)(((struct Obj00001 *)p)->f890));
        ((struct Obj00001 *)p)->f890 = 0;
    }
    if (((struct Obj00001 *)p)->f8C0 != 0) {
        CLACT_ReleaseCellAnim((u32)(((struct Obj00001 *)p)->f8C0));
        ((struct Obj00001 *)p)->f8C0 = 0;
    }
}
