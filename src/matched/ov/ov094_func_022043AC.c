/*
 * function: func_022043AC
 * address:  0x022043AC
 * packet:   pkt_ov094_022043AC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TCBL_IsDeletePending  0x02030EE8  arm  arm9
 */
#include "../include/Obj21763.h"
typedef unsigned int u32;
struct S02030EE8;
extern u32 TCBL_IsDeletePending(struct S02030EE8 *p);

void func_022043AC(void *h)
{
    char *p = *((char **)TCBL_IsDeletePending(h));
    ((struct Obj21763 *)p)->f68 &= ~1;
}
