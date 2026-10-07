/*
 * file:     unit_021E9B14_p02.c
 * unit:     yes
 * function: func_021E9CE0, func_021E9D04
 * address:  0x021E9CE0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E9984  0x021E9984  thumb  ov093
 *   func_021B90E8 0x021B90E8 thumb ov093
 *   func_021B90F0 0x021B90F0 thumb ov093
 *   func_021E9E60 0x021E9E60 thumb ov093
 *   func_021BA1E4 0x021BA1E4 thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021BA1A8 0x021BA1A8 thumb ov093
 *   func_021B9B04 0x021B9B04 thumb ov093
 *   func_021D3D7C 0x021D3D7C thumb ov093
 *   func_021B9B94 0x021B9B94 thumb ov093
 *   func_021B9C00 0x021B9C00 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 */
#include "../../matched/include/Obj00056.h"

struct Q1;
struct S2;
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_021E9984(u8 *p, u8 *q, int mode, u8 x, int y);
extern u32 func_021B90E8(void **p);
extern u32 func_021B90F0(void **p);
extern int func_021E9E60(void *);
extern char *func_021BA1E4(char **);
extern void *func_021B86B8(void ***);
extern int func_021BA1A8(char **p, int m);
extern unsigned char func_021B9B04(int a, int b);
extern u32 func_021D3D7C(u8 *p);
extern u8 func_021B9B94(struct Q1 *p);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
void func_021E9CE0(u8 *p, u8 a, u8 b);
void func_021E9D04(u8 *p, int x, u8 a, u8 b, u8 c, u8 d);


void func_021E9CE0(u8 *p, u8 a, u8 b)
{
    func_021E9984(p, p + 0x10c, 5, a, 0);
    p[0x157] = b;
    p[0x174] = 0;
}


void func_021E9D04(u8 *p, int x, u8 a, u8 b, u8 c, u8 d)
{
    u32 i;
    u32 n;
    void *list;
    int flag;
    if (p[0x174]) return;
    ((struct Obj00056 *)p)->fC8 = (void *)func_021B90E8(((struct Obj00056 *)p)->f0);
    ((struct Obj00056 *)p)->fE4 = (void *)func_021B90F0(((struct Obj00056 *)p)->f0);
    ((struct Obj00056 *)p)->fD0 = x;
    ((struct Obj00056 *)p)->fCC = ((struct Obj00056 *)p)->fB0;
    ((struct Obj00056 *)p)->fD4 = ((struct Obj00056 *)p)->f184;
    p[0xdc] = a;
    p[0xdd] = b;
    ((struct Obj00056 *)p)->fDE = 0;
    ((struct Obj00056 *)p)->fF4 = func_021E9E60(((struct Obj00056 *)p)->f180);
    ((struct Obj00056 *)p)->fE8 = 0;
    *(char * *)&((struct Obj00056 *)p)->fD8 = func_021BA1E4(*(char ** *)&((struct Obj00056 *)p)->f0);
    flag = 0;
    if ((int)func_021B86B8(*(void *** *)&((struct Obj00056 *)p)->f0) != 3) flag = 1;
    ((struct Obj00056 *)p)->f108 = flag;
    ((struct Obj00056 *)p)->fEC = 0;
    flag = 0;
    if (func_021B86B8(*(void *** *)&((struct Obj00056 *)p)->f0) == 0) flag = 1;
    p[0xf1] = flag;
    p[0xe1] = 0;
    flag = 0;
    if (c == 0) flag = 3;
    else if (func_021BA1A8(((struct Obj00056 *)p)->f0, 0x40)) flag = 1;
    else if (func_021B86B8(*(void *** *)&((struct Obj00056 *)p)->f0) == 0) {
        if (func_021B9B04(((struct Obj00056 *)p)->f8, 1) > 1) flag = 2;
        else if (d) flag = 4;
    }
    p[0xf0] = flag;
    func_021E9984(p, p + 0x10c, 3, 0, 0);
    list = (void *)func_021D3D7C(((struct Obj00056 *)p)->f4);
    n = func_021B9B94(list);
    for (i = 0; i < n; i++)
        p[0x144 + i] = func_021D62C4((struct Unk021D62A8 *)func_021B9C00(list, (u8)i), 0x13);
    for (; i < 6; i++) p[0x144 + i] = 0;
    p[0x174] = 1;
}
