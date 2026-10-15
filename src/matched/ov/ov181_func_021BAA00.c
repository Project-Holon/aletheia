/*
 * function: STAFF_ROLL_CmdPrintEntry
 * address: 0x021BAA00
 * packet: pkt_ov181_021BAA00
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STAFF_ROLL_PrintRowText 0x021BA558 thumb ov181
 */
#include "../include/Obj06591.h"
#include "../include/Obj06592.h"
extern void STAFF_ROLL_PrintRowText(char *, unsigned char *);
int STAFF_ROLL_CmdPrintEntry(char *p, unsigned char *q)
{
    if (((struct Obj06592 *)q)->f0 == 0xffff) {
        ((struct Obj06591 *)p)->f2DA = ((struct Obj06592 *)q)->f4;
        ((struct Obj06591 *)p)->f2EC = 1;
        return 1;
    }
    if (((struct Obj06591 *)p)->f2DA == 0)
        ((struct Obj06591 *)p)->f2DA = ((struct Obj06592 *)q)->f4;
    STAFF_ROLL_PrintRowText(p, q);
    if (q[0x16] != 0 || ((struct Obj06592 *)q)->f14 != 0) {
        ((struct Obj06591 *)p)->f2EC = 1;
        return 1;
    }
    return 0;
}
