/*
 * function: WIFIBATTLEMATCH_NET_TakeRegData
 * address:  0x021DC1E4
 * packet:   pkt_021DC1E4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * Take-and-clear: returns the word at +0x13c; when it is set, clears it and hands back the address of the +0x218 block through out.
 */
#include "../include/Obj14344.h"

typedef unsigned long u32;

u32 WIFIBATTLEMATCH_NET_TakeRegData(char *obj, char **out)
{
    u32 v = ((struct Obj14344 *)obj)->f13C;
    if (v != 0) {
        ((struct Obj14344 *)obj)->f13C = 0;
        *out = obj + 0x218;
    }
    return v;
}
