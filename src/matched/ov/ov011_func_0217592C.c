/*
 * function: INTRUDE_COMM_SetSessionResultSendFlag
 * address:  0x0217592C
 * packet:   pkt_0217592C
 * region:   ov011
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets the byte field at +0x19B of the object to 1.
 */
#include "../include/Obj12431.h"

void INTRUDE_COMM_SetSessionResultSendFlag(void *p)
{
    *(char *)&((struct Obj12431 *)p)->f19B = 1;
}
