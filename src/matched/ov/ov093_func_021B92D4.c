/*
 * function: func_021B92D4
 * address:  0x021B92D4
 * packet:   pkt_ov093_021B92D4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B9940  0x021B9940  thumb  ov093
 *   func_021D5844  0x021D5844  thumb  ov093
 *   func_021B8714  0x021B8714  thumb  ov093
 *   func_0201B7A0  0x0201B7A0  thumb
 */
#include "../include/Obj07746.h"
#include "../include/Obj13277.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 func_021D5440(u8 *p);
extern u8 *func_021B9940(char *p, u8 i);
extern void *func_021D5844(void *m);
extern char *func_021B8714(char **p);
extern void func_0201B7A0(void *a0, int a1, int a2, u16 a3);

void func_021B92D4(char *p, void *m, int c)
{
    u8 i;
    void *x;
    void *y;
    char *e;

    i = func_021D5440(m);
    x = func_021B9940(p + 0x1b0, i);
    y = func_021B9940(p + 0xc8, i);
    x = func_021D5844(x);
    y = func_021D5844(y);
    e = func_021B8714((char **)p);
    func_0201B7A0(x, c, ((struct Obj13277 *)e)->fA, (((struct Obj07746 *)p)->f468 & 0x7fff) | 0x8000);
    func_0201B7A0(y, c, ((struct Obj13277 *)e)->fA, (((struct Obj07746 *)p)->f468 & 0x7fff) | 0x8000);
}
