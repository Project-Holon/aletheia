/*
 * function: func_0220203C
 * address:  0x0220203C
 * packet:   pkt_ov094_0220203C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj21736.h"
typedef unsigned int u32;
struct S02030EE8;
extern u32 func_02030EE8(struct S02030EE8 *p);

void func_0220203C(void *h)
{
    int *q = (int *)func_02030EE8(h);
    char *p = (char *)q[0];
    ((struct Obj21736 *)p)->f7C &= (1 << q[4]) ^ -1;
}
