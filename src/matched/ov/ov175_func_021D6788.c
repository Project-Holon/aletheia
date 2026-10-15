/*
 * function: WIFIBATTLEMATCH_NET_SetWaitCallback
 * address:  0x021D6788
 * packet:   pkt_021D6788
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E7710   0x021E7710  thumb
 *   func_021E8AA0   0x021E8AA0  thumb
 *   func_021E8A80   0x021E8A80  thumb
 *   func_021E8A90   0x021E8A90  thumb
 *   func_021E64C8   0x021E64C8  thumb
 *   func_021E8AA8   0x021E8AA8  thumb
 *
 * Closes the +0x38 stream handle through 0x021E8AA0 and parks the +0x3c
 *     result word at its "no data" sentinel 0xFFFF.
 */
#include "../include/Obj01562.h"

typedef unsigned long u32;

extern void func_021E8AA0(u32 sys, void *fn);

void WIFIBATTLEMATCH_NET_SetWaitCallback(char *obj, void *fn)
{
    func_021E8AA0(((struct Obj01562 *)obj)->f38, fn);
    ((struct Obj01562 *)obj)->f3C = 0xFFFF;
}

