/*
 * function: func_021A3C24
 * address:  0x021A3C24
 * packet:   pkt_ov021_021A3C24
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3C3C  0x021A3C3C  thumb  ov021
 *   func_021A3C54  0x021A3C54  thumb  ov021
 */
#include "../include/Obj12731.h"

typedef unsigned char  u8;
typedef unsigned short u16;

typedef unsigned int   u32;
int func_021A3C3C(u32 keys);
int func_021A3C54(u32 keys);

void func_021A3C24(u8 *p, int a)
{
    ((struct Obj12731 *)p)->f20 = func_021A3C3C(a);
    ((struct Obj12731 *)p)->f22 = func_021A3C54(a);
}
