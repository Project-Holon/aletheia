/*
 * unit:     yes
 * function: INTRUDE_COMM_SetSessionEntrySendFlag, INTRUDE_COMM_SetSessionRequestSendFlag, INTRUDE_COMM_SetSessionResultSendFlag
 * address:  0x02175914
 * packet:   pkt_02175914
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Three one-byte flag setters at fixed offsets.
 */
#include "../include/Obj12430.h"
#include "../include/Obj12431.h"

void INTRUDE_COMM_SetSessionEntrySendFlag(int a, int b)
{
    *(unsigned char *)(a + b + 0x194) = 1;
}

void INTRUDE_COMM_SetSessionRequestSendFlag(int a)
{
    ((struct Obj12430 *)a)->f19A = 1;
}

void INTRUDE_COMM_SetSessionResultSendFlag(int a)
{
    ((struct Obj12431 *)a)->f19B = 1;
}
