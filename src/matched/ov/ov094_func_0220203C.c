/*
 * function: func_0220203C
 * address:  0x0220203C
 * packet:   pkt_ov094_0220203C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TCBL_GetTaskUserData  0x02030EE8  arm  arm9
 */
#include "../include/Obj21736.h"
typedef unsigned int u32;
struct S02030EE8;
extern u32 TCBL_GetTaskUserData(struct S02030EE8 *p);

void func_0220203C(void *h)
{
    int *q = (int *)TCBL_GetTaskUserData(h);
    char *p = (char *)q[0];
    ((struct Obj21736 *)p)->f7C &= (1 << q[4]) ^ -1;
}
