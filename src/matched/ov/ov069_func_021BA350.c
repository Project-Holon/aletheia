/*
 * function: BSUBWAY_RECORD_LIST_InitPageCount
 * address: 0x021BA350
 * packet: pkt_ov069_021BA350
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj06173.h"
void BSUBWAY_RECORD_LIST_InitPageCount(char *p)
{
    ((struct Obj06173 *)p)->f160 = 0;
    ((struct Obj06173 *)p)->f162 = ((struct Obj06173 *)p)->f164 / 10;
    if (((struct Obj06173 *)p)->f164 % 10 != 0)
        (((struct Obj06173 *)p)->f162)++;
}
