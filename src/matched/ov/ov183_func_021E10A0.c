/*
 * function: BR_CODEIN_ProfileCreateOam
 * address:  0x021E10A0
 * packet:   pkt_021E10A0
 * region:   ov183
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_OAM_CreateSys  0x02025538  thumb
 */
#include "../include/Obj00143.h"

extern void *BMP_OAM_CreateSys(unsigned int a0, void *a1);

void BR_CODEIN_ProfileCreateOam(char *p)
{
    ((struct Obj00143 *)p)->f300 =
        BMP_OAM_CreateSys(((struct Obj00143 *)p)->f34C, ((struct Obj00143 *)p)->f25C);
}
