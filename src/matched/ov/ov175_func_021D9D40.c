/*
 * function: func_021D9D40
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
 *   func_021D99F4  0x021D99F4  thumb
 *
 * Clears the +0xec last-read length and tail-calls the +0x30 release path
 *     func_021D99F4, so nothing is saved.  Mirrors func_021D6954.
 */
#include "../include/Obj24319.h"

typedef unsigned long u32;

extern void func_021D99F4(char *obj);

void func_021D9D40(char *obj)
{
    ((struct Obj24319 *)obj)->fEC = 0;
    func_021D99F4(obj);
}

