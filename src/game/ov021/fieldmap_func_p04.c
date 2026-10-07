/*
 * file:     fieldmap_func_p04.c
 * unit:     yes
 * function: func_021BB960, func_021BB978, func_021BB990
 * address:  0x021BB960
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
 *   func_02034AC4  0x02034AC4  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_02030734  0x02030734  arm
 *   d_021DE2F8     0x021DE2F8  data  a4
 */
#include "../../matched/include/Obj07223.h"
#include "../../matched/include/Obj07224.h"
#include "../../matched/include/Obj06051.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef signed int     s32;

int func_02034AC4(s32 handle);
int func_02030DA8(int a, void *fn, int *b, int c);
void *func_02030734(u32 a, u32 b, int c, const char *d, u16 e);
void func_021BB960(u32 a, u32 b, u32 c, u32 d);
void func_021BB978(u32 a, u32 b, u32 c, u32 d);
int *func_021BB990(int a, int *d, const int *c);
extern int d_021DE2F8;


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
void func_021BB960(u32 a, u32 b, u32 c, u32 d)
{
if (*(u32 *)((u8 *)(((struct Obj07223 *)((u8 *)(b)))->fC) + 16) != 0) {
    ((void (*)(u32, u32, u32, u32))*(u32 *)((u8 *)(*(u32 *)((u8 *)(b) + 12)) + 16))(b, *(u32 *)((u8 *)(((struct Obj07223 *)((u8 *)(b)))->f0)), ((struct Obj07223 *)((u8 *)(b)))->f10, *(u32 *)((u8 *)(((struct Obj07223 *)((u8 *)(b)))->fC) + 16));
}
}


void func_021BB978(u32 a, u32 b, u32 c, u32 d)
{
if (*(u32 *)((u8 *)(((struct Obj07224 *)((u8 *)(b)))->fC) + 20) != 0) {
    ((void (*)(u32, u32, u32, u32))*(u32 *)((u8 *)(*(u32 *)((u8 *)(b) + 12)) + 20))(b, *(u32 *)((u8 *)(((struct Obj07224 *)((u8 *)(b)))->f0)), ((struct Obj07224 *)((u8 *)(b)))->f10, *(u32 *)((u8 *)(((struct Obj07224 *)((u8 *)(b)))->fC) + 20));
}
}


int *func_021BB990(int a, int *d, const int *c)
{
    int *p = (int *)d[3];
    int i;

    for (i = 0; i < d[2]; i++, p += 6) {
        if (p[1] != 0) {
            continue;
        }
        if (a != -1) {
            func_02034AC4(a);
        }
        p[5] = a;
        p[1] = func_02030DA8(d[4], func_021BB960, p, c[0]);
        p[2] = func_02030DA8(d[5], func_021BB978, p, c[0]);
        p[0] = (int)d;
        p[3] = (int)c;
        if (((struct Obj06051 *)c)->f4 != 0) {
            p[4] = (int)func_02030734((u16)d[1], ((struct Obj06051 *)c)->f4, 1, (const char *)&d_021DE2F8, 0xc3);
        }
        if (c[2] != 0) {
            ((void (*)(int *, int, int))c[2])(p, d[0], p[4]);
        }
        return p;
    }
    return 0;
}
