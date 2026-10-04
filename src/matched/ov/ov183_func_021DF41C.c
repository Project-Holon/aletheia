/*
 * function: func_021DF41C
 * address: 0x021DF41C
 * packet: pkt_ov183_021DF41C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FCDA8 0x021FCDA8 thumb ov186
 */
#include "../include/Obj24619.h"
typedef unsigned short u16;
extern int func_021FCDA8(char *);
int func_021DF41C(char *p)
{
    return func_021FCDA8(*(char * *)&((struct Obj24619 *)p)->f4);
}
