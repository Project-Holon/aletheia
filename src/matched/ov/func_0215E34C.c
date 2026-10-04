/*
 * function: func_0215E34C
 * address:  0x0215E34C
 * packet:   pkt_0215E34C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012A38  0x02012A38  thumb
 */
#include "../include/Obj17697.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct BigObj;
extern u32 func_02012A38(const struct BigObj *p);

int func_0215E34C(int a0)
{
    int a1;

    a0 = func_02012A38((const struct BigObj *)a0);
loc_0215E352:
a1 = 0;
((struct Obj17697 *)a0)->fC = a1;
    return a0;}
