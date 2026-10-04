/*
 * function: func_021E10DC
 * address:  0x021E10DC
 * packet:   pkt_021E10DC
 * region:   ov183
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049238  0x02049238  arm
 */
#include "../include/Obj24626.h"

typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02049238(void *arc);

void func_021E10DC(char *p)
{
    func_02049238(func_020490F4(0x17, ((struct Obj24626 *)p)->f34C));
}
