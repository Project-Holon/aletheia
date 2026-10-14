/*
 * function: ZUKAN_DETAIL_AREA_DeletePrintQueues
 * address:  0x021C06EC
 * packet:   pkt_021C06EC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb  arm9
 *   (none)

 * Clears a word and releases two handles of each of four entries.
 */
#include "../include/Obj09204.h"


struct PrintSys;
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);

void ZUKAN_DETAIL_AREA_DeletePrintQueues(void *unused, char *p, void *a2)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        char *e = p + i * 4;
        ((struct Obj09204 *)e)->f24 = 0;
        PRINTSYS_QUE_Clear((struct PrintSys *)(((struct Obj09204 *)e)->f34));
        PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj09204 *)e)->f34));
    }
}

