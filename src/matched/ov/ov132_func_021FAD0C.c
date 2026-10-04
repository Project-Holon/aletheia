/*
 * function: func_021FAD0C
 * address: 0x021FAD0C
 * packet: pkt_ov132_021FAD0C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FAC74 0x021FAC74 thumb ov132
 */
#include "../include/Obj10541.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_021FAC74(char *, void *, int);
char *func_021FAD0C(char *p, char *base, unsigned index, unsigned char flag)
{
    char *q = func_021FAC74(p, base + *(unsigned *)(base + index * 4), 0);
    *(char * *)&((struct Obj10541 *)q)->fC = base;
    ((struct Obj10541 *)q)->f16 |= 8;
    ((struct Obj10541 *)q)->f18 = flag;
    return q;
}
