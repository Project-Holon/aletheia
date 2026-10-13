/*
 * function: INTRUDE_COMM_GetSessionWaitRemaining
 * address: 0x021758B4
 * packet: pkt_ov011_021758B4
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRUDE_COMM_GetSessionElapsed 0x02175894 thumb ov011
 */
#include "../include/Obj19191.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int INTRUDE_COMM_GetSessionElapsed(u8 *p);
int INTRUDE_COMM_GetSessionWaitRemaining(u8 *p)
{
    int limit = ((struct Obj19191 *)p)->fAA;
    int n = limit - INTRUDE_COMM_GetSessionElapsed(p);
    if (n < 0) n = 0;
    return n;
}
