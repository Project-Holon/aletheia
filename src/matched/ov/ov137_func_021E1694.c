/*
 * function: func_021E1694
 * address: 0x021E1694
 * packet: pkt_ov137_021E1694
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:

 */
#include "../include/Obj23802.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int a, b, c, d, e; } Record;
void func_021E1694(char *p, const Record *q)
{
    ((struct Obj23802 *)p)->f3C = 1;
    *(Record *)(p + 0x58) = *q;
}
