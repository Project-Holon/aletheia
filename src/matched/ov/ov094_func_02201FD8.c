/*
 * function: BTLV_CLACT_MoveTaskEnd
 * address:  0x02201FD8
 * packet:   pkt_ov094_02201FD8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TCBL_GetTaskUserData  0x02030EE8  arm  arm9
 */
#include "../include/Obj21735.h"
typedef unsigned int u32;
struct S02030EE8;
extern u32 TCBL_GetTaskUserData(struct S02030EE8 *p);

void BTLV_CLACT_MoveTaskEnd(void *h)
{
    int *q = (int *)TCBL_GetTaskUserData(h);
    char *p = (char *)q[0];
    ((struct Obj21735 *)p)->f78 &= (1 << q[4]) ^ -1;
}
