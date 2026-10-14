/*
 * function: MB_SEQ_DrawActors
 * address:  0x021C6594
 * packet:   pkt_ov136_021C6594
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_DrawSystem  0x0204A600  arm
 */
#include "../include/Obj23592.h"

typedef unsigned char u8;
extern void CLACT_DrawSystem(void *);
void MB_SEQ_DrawActors(u8 *p)
{
    void *q = ((struct Obj23592 *)p)->f1EC;
    if (q != 0) {
        CLACT_DrawSystem(q);
    }
}
