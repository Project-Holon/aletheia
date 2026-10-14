/*
 * function: BTLV_MCSS_RotationTaskEnd
 * address:  0x02201700
 * packet:   pkt_ov094_02201700
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TCBL_GetTaskUserData  0x02030EE8  arm  arm9
 */
#include "../include/Obj21729.h"
typedef unsigned int u32;
struct S02030EE8;
extern u32 TCBL_GetTaskUserData(struct S02030EE8 *p);

void BTLV_MCSS_RotationTaskEnd(void *h)
{
    char *p = *((char **)TCBL_GetTaskUserData(h));
    ((struct Obj21729 *)p)->f510 &= ~4;
}
