/*
 * function: func_021C211C
 * address:  0x021C211C
 * packet:   pkt_ov217_021C211C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C21C4  0x021C21C4  thumb  ov217
 *   func_021C2250  0x021C2250  thumb  ov217
 *   func_021C2194  0x021C2194  thumb  ov217
 *   func_021C218C  0x021C218C  thumb  ov217
 */
#include "../include/Obj06717.h"
#include "../include/Obj06718.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_021C21C4(u8 *p, int index);
extern void func_021C2250(u32 a0, u32 a1);
extern u32 func_021C2194(void *p);
extern void func_021C218C(void *p, u32 v);

void func_021C211C(void *p)
{
    s32 i;
    for (i = 0; i < ((struct Obj06717 *)p)->f298; i++) {
        char *e = (char *)p + i * 0x18;
        if (((struct Obj06718 *)e)->f28 == 0 && ((struct Obj06718 *)e)->f2C <= ((struct Obj06717 *)p)->f24)
            func_021C21C4(p, (u8)i);
        if (((struct Obj06718 *)e)->f28 == 1 && ((struct Obj06718 *)e)->f30 == 1 && ((struct Obj06718 *)e)->f34 <= ((struct Obj06717 *)p)->f24)
            func_021C2250((u32)p, (u8)i);
    }
    if (func_021C2194(p))
        func_021C218C(p, 2);
}
