/*
 * file:     weather_task_p45.c
 * unit:     yes
 * function: func_021A4140, func_021A41A8
 * address:  0x021A4140
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021DDECC     0x021DDECC  data  ov021  a4
 *   func_021A395C  0x021A395C  thumb  ov021
 *   func_021A5354  0x021A5354  thumb  ov021
 *   func_021A3974  0x021A3974  thumb  ov021
 *   func_021A3CB0  0x021A3CB0  thumb  ov021
 *   func_021A3CE8  0x021A3CE8  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj03586.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_021A395C(u8 *p);
extern void func_021A5354(u32 a);
extern u32 func_021A3974(u8 *p);
extern int func_021A3CB0(u32, u32);
extern void func_021A3CE8(u32);
extern u32 func_020307B0(void *p);
u32 *func_021A4140(u32 a, u32 b);
void func_021A41A8(void *a0);
extern u8 d_021DDECC[];


/*
 * Addresses are Black-image addresses.
 */
u32 *func_021A4140(u32 a, u32 b)
{
    u32 *o;
    int k;

    o = func_02030734(b, 0x20, 1, (const char *)d_021DDECC, 0x17D);
    o[3] = a;
    o[4] = func_021A395C((u8 *)a);
    ((struct Obj03586 *)o)->f18 = 0x546;
    func_021A5354((u32)o);
    k = func_021A3974((u8 *)o[3]);
    switch (k) {
    case 2:
        func_021A3CB0(o[3], 4);
        func_021A3CE8(o[3]);
        break;
    case 3:
        func_021A3CB0(o[3], 0x100);
        func_021A3CE8(o[3]);
        break;
    }
    return o;
}


/*
 * Tail-call thunk: forwards to func_020307B0 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021A41A8(void *a0)
{
    func_020307B0(a0);
}
