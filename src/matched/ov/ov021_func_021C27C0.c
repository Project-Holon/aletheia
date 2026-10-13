/*
 * function: FLD3D_CI_SaveVisiblePlanes
 * address:  0x021C27C0
 * packet:   pkt_021C27C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   BG_SYS_GetMainVisiblePlanes  0x02043658  arm
 */
#include "../include/Obj20172.h"

typedef unsigned int u32;

u32 BG_SYS_GetMainVisiblePlanes(void);

void FLD3D_CI_SaveVisiblePlanes(char *p)
{
    ((struct Obj20172 *)p)->f68 = BG_SYS_GetMainVisiblePlanes();
}
