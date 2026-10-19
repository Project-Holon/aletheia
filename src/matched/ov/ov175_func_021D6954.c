/*
 * function: WIFIBATTLEMATCH_NET_ClearError
 * address:  0x021D6954
 * packet:   pkt_021D6954
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFIBATTLEMATCH_NET_DeleteChoiceMenu  0x021D65C8  thumb
 *
 * Clears the word at +0xe4 (the last-read length) and then tail-calls the
 *     +0x28 release path WIFIBATTLEMATCH_NET_DeleteChoiceMenu, which is why nothing is saved.
 */
#include "../include/Obj24232.h"

typedef unsigned long u32;

extern void WIFIBATTLEMATCH_NET_DeleteChoiceMenu(char *obj);

void WIFIBATTLEMATCH_NET_ClearError(char *obj)
{
    ((struct Obj24232 *)obj)->fE4 = 0;
    WIFIBATTLEMATCH_NET_DeleteChoiceMenu(obj);
}

