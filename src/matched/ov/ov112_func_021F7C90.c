/*
 * function: func_021F7C90
 * address: 0x021F7C90
 * packet: pkt_ov112_021F7C90
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F5450 0x021F5450 thumb ov112
 *   func_021F5464 0x021F5464 thumb ov112
 *   VEC_Add 0x0207C9D0 arm
 *   func_021F4E8C 0x021F4E8C thumb ov112
 *   func_021F4E6C 0x021F4E6C thumb ov112
 *   func_021F4ED4 0x021F4ED4 thumb ov112
 *   func_021F4EB4 0x021F4EB4 thumb ov112
 */
#include "../include/Obj06410.h"
#include "../include/Obj08029.h"
#include "../include/Obj22563.h"
typedef struct { int x, y, z; } Vec;
typedef struct { short count, pad; int index, a, b; } Tail;
extern char *func_021F5450(char *, int);
extern char *func_021F5464(char *p);
extern void VEC_Add(Vec *, Vec *, Vec *);
extern void func_021F4E8C(int, int, Vec *);
typedef unsigned char  u8;
extern void func_021F4E6C(u8 *p, u8 *e, unsigned int value);
typedef signed short   s16;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_021F4ED4(u32 unused, u32 p, u16 v);
extern void func_021F4EB4(u32 unused, u32 p, s16 a, s16 b);
void func_021F7C90(char *p, char *q) {
    Tail *t = (Tail *)(q + 0xf0);
    char *r = func_021F5450(*(char * *)&((struct Obj06410 *)q)->f58, ((struct Obj06410 *)q)->fF4);
    Vec v;
    *(int *)(q + 0xcc + ((struct Obj06410 *)q)->fF4 * 4) = 0;
    if (((struct Obj06410 *)q)->f8 == 0 || ((struct Obj22563 *)r)->f0 == 0) {
        VEC_Add((Vec *)(q + 0x18), (Vec *)func_021F5464(*(char * *)&((struct Obj06410 *)q)->f58), &v);
        v.z -= 0x1c000;
        func_021F4E8C(((struct Obj08029 *)p)->f10, *(int *)(q + 0x84 + t->index * 4), &v);
    }
    func_021F4E6C((u8 *)(((struct Obj08029 *)p)->f10), (u8 *)(*(int *)(q + 0x84 + t->index * 4)), 1);
    func_021F4ED4(((struct Obj08029 *)p)->f10, *(int *)(q + 0x84 + t->index * 4), 0);
    func_021F4EB4(((struct Obj08029 *)p)->f10, *(int *)(q + 0x84 + t->index * 4), 1024, 1024);
}
