/*
 * function: BSUBWAY_RECORD_LIST_ChangePage
 * address: 0x021BA400
 * packet: pkt_ov069_021BA400
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of alignment padding follow.
 */
#include "../include/Obj00432.h"
int BSUBWAY_RECORD_LIST_ChangePage(char *p, int k)
{
    int result = 0;
    if (k == 0) {
        if (((struct Obj00432 *)p)->f160 != 0) {
            ((struct Obj00432 *)p)->f160 = ((struct Obj00432 *)p)->f160 - 1;
            result = 1;
        }
    } else if (k == 1) {
        if (((struct Obj00432 *)p)->f160 < ((struct Obj00432 *)p)->f162 - 1) {
            ((struct Obj00432 *)p)->f160 = ((struct Obj00432 *)p)->f160 + 1;
            result = 1;
        }
    }
    return result;
}
