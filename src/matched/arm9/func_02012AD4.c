/*
 * function: func_02012AD4
 * address:  0x02012AD4
 * packet:   pkt_02012AD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   data_0209DFA8  0x0209DFA8  data  a2
 */
#include "../include/Obj15629.h"

typedef unsigned char  u8;
typedef unsigned short u16;

extern const u16 data_0209DFA8[];

void func_02012AD4(u8 *p, int i)
{
    ((struct Obj15629 *)p)->f18 = data_0209DFA8[i];
}
