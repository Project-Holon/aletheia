/*
 * unit: yes
 * function: STAFF_ROLL_CmdShowEntry, STAFF_ROLL_CmdSetEntryMode, STAFF_ROLL_CmdStartScroll, STAFF_ROLL_CmdStopScroll, STAFF_ROLL_CmdEnd, STAFF_ROLL_CmdNop
 * address: 0x021BAA54
 * packet: pkt_ov181_021BAA54
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STAFF_ROLL_PrintEntry 0x021BA594 thumb ov181
 */
#include "../include/Obj10725.h"
#include "../include/Obj14414.h"
#include "../include/Obj24511.h"
#include "../include/Obj24512.h"
#include "../include/Obj24513.h"
extern void STAFF_ROLL_PrintEntry(char *, unsigned char *);
int STAFF_ROLL_CmdShowEntry(char *p, unsigned char *q)
{
    if (((struct Obj10725 *)p)->f2EC == 0) {
        ((struct Obj10725 *)p)->f2CD = q[7];
        ((struct Obj10725 *)p)->f2EC = 2;
    }
    STAFF_ROLL_PrintEntry(p, q);
    if (q[0x16] != 1)
        return 1;
    return 0;
}
int STAFF_ROLL_CmdSetEntryMode(char *p, unsigned char *q)
{
    ((struct Obj14414 *)p)->f2CD = q[7];
    ((struct Obj14414 *)p)->f2EC = 3;
    return 1;
}
int STAFF_ROLL_CmdStartScroll(char *p)
{
    ((struct Obj24511 *)p)->f2E0 = 1;
    return 0;
}
int STAFF_ROLL_CmdStopScroll(char *p)
{
    ((struct Obj24512 *)p)->f2E0 = 0;
    return 0;
}
int STAFF_ROLL_CmdEnd(char *p)
{
    ((struct Obj24513 *)p)->f2EC = 5;
    return 1;
}
int STAFF_ROLL_CmdNop(void)
{
    return 1;
}
