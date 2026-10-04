/*
 * function: func_02189F58
 * address: 0x02189F58
 * packet: pkt_ov096_02189F58
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02189F98 0x02189F98 thumb ov096
 */
#include "../include/Obj21979.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02189F98(unsigned char *a, unsigned char *b, int c);
int func_02189F58(u8 *a, u8 *b)
{
    func_02189F98(a,b,0); return ((struct Obj21979 *)b)->fC4;
}
