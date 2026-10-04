/*
 * function: func_0216A1F8
 * address:  0x0216A1F8
 * packet:   pkt_0216A1F8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3208  0x021A3208  thumb
 *   func_021A2F48  0x021A2F48  thumb
 *   func_021A2F54  0x021A2F54  thumb
 */
#include "../include/Obj17752.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02188CB4(unsigned char *p);
extern int func_021A3208();
extern int func_021A2F48();
extern int func_021A2F54();

void func_0216A1F8(int a0)
{
    int a1;
    void *v0;

a0 = ((struct Obj17752 *)a0)->f8;
    v0 = func_02188CB4((void *)a0);
loc_0216A200:
    a0 = func_021A3208(v0);
loc_0216A206:
    if (a0 != 1) goto loc_0216A218;
loc_0216A20A:
a1 = 8;
    a0 = func_021A2F48(v0, a1);
loc_0216A212:
    a0 = func_021A2F54(v0);
loc_0216A218:
    return;}
