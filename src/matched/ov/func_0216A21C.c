/*
 * function: func_0216A21C
 * address:  0x0216A21C
 * packet:   pkt_0216A21C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3208  0x021A3208  thumb
 *   func_021A2F54  0x021A2F54  thumb
 */
#include "../include/Obj17753.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02188CB4(unsigned char *p);
extern int func_021A3208();
extern int func_021A2F54();

int func_0216A21C(int a0)
{    void *v0;

a0 = ((struct Obj17753 *)a0)->f8;
    v0 = func_02188CB4((void *)a0);
loc_0216A224:
    a0 = func_021A3208(v0);
loc_0216A22A:
    if (a0 != 0) goto loc_0216A232;
loc_0216A22E:
a0 = 1;
    return a0;
loc_0216A232:
    a0 = func_021A2F54(v0);
loc_0216A238:
    if (a0 != 1) goto loc_0216A240;
loc_0216A23C:
a0 = 1;
    return a0;
loc_0216A240:
a0 = 0;
    return a0;}
