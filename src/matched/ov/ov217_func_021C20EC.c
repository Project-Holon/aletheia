/*
 * function: func_021C20EC
 * address:  0x021C20EC
 * packet:   pkt_ov217_021C20EC
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C2118  0x021C2118  thumb  ov217
 *   func_021C211C  0x021C211C  thumb  ov217
 *   func_021C2188  0x021C2188  thumb  ov217
 */
#include "../include/Obj06717.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_021C2118(void *p);
extern void func_021C211C(void *p);
extern void func_021C2188(void *p);

void func_021C20EC(void *p)
{
    switch (((struct Obj06717 *)p)->f20) {
    case 0: func_021C2118(p); break;
    case 1: func_021C211C(p); break;
    case 2: func_021C2188(p); break;
    }
    (((struct Obj06717 *)p)->f24)++;
}
