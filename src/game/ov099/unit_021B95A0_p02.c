/*
 * file:     unit_021B95A0_p02.c
 * unit:     yes
 * function: func_021B9788, func_021B97CC, func_021B97F4, func_021B9800
 * address:  0x021B9788
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C49A4  0x021C49A4  thumb  ov127
 *   func_020362DC  0x020362DC  arm
 *   func_021B9CF8  0x021B9CF8  thumb  ov099
 *   func_021BA1FC  0x021BA1FC  thumb  ov099
 *   func_021C4AC4  0x021C4AC4  thumb  ov127
 *   func_021C4864  0x021C4864  thumb  ov127
 */
#include "../../matched/include/Obj13676.h"

typedef unsigned char u8;

typedef unsigned int u32_021B9788;

typedef unsigned short u16;

typedef unsigned long  u32_021B97CC;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef unsigned long  u32_021B97F4;

typedef struct {
    char pad[0x570];
    u8 *p;
} W;

typedef unsigned int u32_021B9800;

typedef struct {
    short x, y;
} Pos;

typedef struct {
    char pad[0x570];
    void **f570;
    char pad574[0x14];
    void *f588;
} Work;

extern int func_021C49A4(u8 *p, unsigned int i);
extern u32_021B9788 func_020362DC(void);
extern void *func_021B9CF8(char *p, u32_021B9788 *q, int c);
extern int func_021BA1FC(int *a);
extern Pos func_021C4AC4(void *v);
extern u32_021B9800 func_021C4864(u8 *p, u16 x, u16 y);
int func_021B9788(int a, int *b);
void func_021B97CC(char *p);
u8 func_021B97F4(W *w);
void func_021B9800(Work *w);


int func_021B9788(int a, int *b)
{
    int v;
    int c;
    int *r;

    c = func_021C49A4((u8 *)b[0], 6);
    if (func_020362DC() & 1) {
        r = func_021B9CF8((char *)a, (u32_021B9788 *)b, c);
        if (r != 0) {
            if (func_021BA1FC(r) == 1)
                v = func_021C49A4((u8 *)r[0], 4);
            else
                v = 0;
        } else
            v = 0;
        ((struct Obj13676 *)b)->fA = v;
    }
    return 1;
}


void func_021B97CC(char *p)
{
    int i;

    for (i = 0; i < 0x30; i++) {
        if (*(u32_021B97CC *)(p + i * 0x1C + 0x30) != 0) {
            func_021B9788((int)p, (int *)(p + 0x30 + i * 0x1C));
        }
    }
}


u8 func_021B97F4(W *w)
{
    return ((u8 *)w->p)[0xA];
}


void func_021B9800(Work *w)
{
    Pos b = func_021C4AC4(*w->f570);

    func_021C4864(w->f588, b.x / 16, b.y / 16);
}
