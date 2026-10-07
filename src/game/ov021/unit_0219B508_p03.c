/*
 * file:     unit_0219B508_p03.c
 * unit:     yes
 * function: func_0219BA0C, func_0219BA2C, func_0219BA6C
 * address:  0x0219BA0C
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
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216DEE0  0x0216DEE0  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D7C4  0x0216D7C4  thumb  ov010
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 *   func_021642B4  0x021642B4  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 */
#include "../../matched/include/Obj05998.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern void *func_0216D67C(void *a0);
extern void *func_0216DEE0(void *a0);
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
extern u16 func_0216D7C4(u8 *p);
extern int func_0216D804(void *p);
extern int func_0216D81C(void *p);
extern u16 func_021642B4(int x0, int y0, int x1, int y1);
extern int func_02197E7C(int a, int b);
extern void func_0216D438(char *a0, int a1);
void func_0219BA0C(u32 a, u8 *s);
int func_0219BA2C(int a);
int func_0219BA6C(char *a);


void func_0219BA0C(u32 a, u8 *s)
{
    u32 o = (u32)func_0216DEE0(func_0216D67C((void *)a));
    ((struct Obj05998 *)s)->f2 = func_0216D83C((void *)o);
    ((struct Obj05998 *)s)->f4 = func_0216D86C((void *)o);
}


int func_0219BA2C(int a)
{
    int v;

    func_0216DEE0(func_0216D67C((void *)a));
    v = func_0216D7C4((u8 *)a);
    switch (v) {
    case 0x58:
        return 0x10;
    case 0x59:
        return 0x11;
    case 0x5a:
        return 0x12;
    case 0x5b:
        return 0x13;
    }
    return v;
}


int func_0219BA6C(char *a)
{
    int o;
    int x;
    int y;
    int tx;
    int ty;
    int k;

    o = (int)func_0216DEE0(func_0216D67C((void *)a));
    x = func_0216D83C((void *)a);
    y = func_0216D86C((void *)a);
    tx = func_0216D804((void *)o);
    ty = func_0216D81C((void *)o);
    if (x != tx || y != ty) {
        k = func_0219BA2C((int)a);
        func_0216D438(a, (u16)((u32)func_02197E7C((u16)((int)func_021642B4(x, y, tx, ty)), (u16)k)));
        return 1;
    }
    return 0;
}
