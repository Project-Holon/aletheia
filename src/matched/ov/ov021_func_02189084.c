/*
 * function: FIELDMAP_DrawStart
 * address:  0x02189084
 * packet:   pkt_ov021_02189084
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_DrawStart  0x02047964  arm
 *   G3D_SYSTEM_ApplyLookAt  0x020479D8  arm
 *   sDrawStartFuncs     0x021D35D8  data  a4
 */
#include "../include/Obj19495.h"

typedef void (*Fn)(unsigned char *p);

extern Fn sDrawStartFuncs[];
void G3D_SYSTEM_DrawStart(void);
void G3D_SYSTEM_ApplyLookAt(void);

void FIELDMAP_DrawStart(unsigned char *p)
{
    Fn fn;
    G3D_SYSTEM_DrawStart();
    G3D_SYSTEM_ApplyLookAt();
    fn = sDrawStartFuncs[((struct Obj19495 *)p)->f12C];
    if (fn != 0)
        fn(p);
}
