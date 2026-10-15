/*
 * function: DIGITALCARDCHECK_UpdateMenu
 * address:  0x0217CFE8
 * packet:   pkt_ov176_0217CFE8
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_PrintMessage  0x021E8738  thumb  ov177
 */
#include "../include/Obj14364.h"

extern void WIFIBATTLEMATCH_UTIL_PrintMessage(int *p, int a, int b, int c);

void DIGITALCARDCHECK_UpdateMenu(void *obj, int a, int b)
{
    WIFIBATTLEMATCH_UTIL_PrintMessage((int *)(((struct Obj14364 *)obj)->f1A4), ((struct Obj14364 *)obj)->f20, a, b);
}

