/*
 * function: func_02159DEC
 * address:  0x02159DEC
 * packet:   pkt_02159DEC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02049238  0x02049238  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj17652.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02049238(void *arc);
extern int func_020307B0();

int func_02159DEC(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj17652 *)t4)->f4;
    func_02049238((void *)a0);
loc_02159DF6:
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_02159DFC:
    return a0;}
