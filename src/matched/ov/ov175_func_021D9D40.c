/*
 * function: WIFIBATTLEMATCH_NET_CompClearError
 * address:  0x021D9D40
 * packet:   pkt_021D9D40
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu  0x021D99F4  thumb
 *
 * Clears the +0xec last-read length and tail-calls the +0x30 release path
 *     WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu, so nothing is saved.  Mirrors WIFIBATTLEMATCH_NET_ClearError.
 */
#include "../include/Obj24319.h"

typedef unsigned long u32;

extern void WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(char *obj);

void WIFIBATTLEMATCH_NET_CompClearError(char *obj)
{
    ((struct Obj24319 *)obj)->fEC = 0;
    WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(obj);
}

