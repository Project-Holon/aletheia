/*
 * function: OEKAKI_CloseMenuIfOpen
 * address: 0x02186480
 * packet: pkt_ov023_02186480
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   OEKAKI_CloseYesNoMenu 0x02186694 thumb ov023
 */
#include "../include/Obj00336.h"
extern void OEKAKI_CloseYesNoMenu(char *);
void OEKAKI_CloseMenuIfOpen(char *p)
{
    if (((struct Obj00336 *)p)->f9E70 != 0) {
        if (((struct Obj00336 *)p)->f178 != 0)
            OEKAKI_CloseYesNoMenu(p);
        ((struct Obj00336 *)p)->f9E70 = 0;
    }
}
