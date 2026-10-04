/*
 * function: func_021E1814
 * address: 0x021E1814
 * packet: pkt_ov137_021E1814
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj23810.h"
typedef unsigned short u16;
void func_021E1814(unsigned char *p,u16 *q)
{
    u16 *d=(u16 *)(p+108);
    unsigned n=8;
    do { *d++=*q++; } while(--n);
    ((struct Obj23810 *)p)->f40=1;
}
