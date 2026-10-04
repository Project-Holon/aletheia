/*
 * function: func_02210F98
 * address: 0x02210F98
 * packet: pkt_ov198_02210F98
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_022110B8 0x022110B8 thumb ov198
 */
#include "../include/Obj10852.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_022110D4(u8 *, int);
extern unsigned func_022110B8(u8 **, unsigned);
unsigned func_02210F98(u8 *p, int index)
{
    unsigned selected = func_022110D4(p, index);
    u8 *q = *(u8 * *)&((struct Obj10852 *)p)->f0;
    if (q[0x22] != 1) {
        if (selected == q[0x1d] || selected == q[0x1e]) return 1;
        return func_022110B8((u8 **)p, selected);
    }
    return 0;
}
