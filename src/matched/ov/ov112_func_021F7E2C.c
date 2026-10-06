/*
 * function: func_021F7E2C
 * address: 0x021F7E2C
 * packet: pkt_ov112_021F7E2C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F5450 0x021F5450 thumb ov112
 *   func_021F5464 0x021F5464 thumb ov112
 *   func_0207C9D0 0x0207C9D0 arm
 *   func_021F4E8C 0x021F4E8C thumb ov112
 *   func_021F4E6C 0x021F4E6C thumb ov112
 *   func_021F4ED4 0x021F4ED4 thumb ov112
 *   func_021F4EB4 0x021F4EB4 thumb ov112
 */
#include "../include/Obj06411.h"
#include "../include/Obj08031.h"
#include "../include/Obj22564.h"
typedef struct { int x, y, z; } Vec;
typedef struct { short count, pad; int index, a, b; } Tail;
extern char *func_021F5450(char *, int);
extern char *func_021F5464(char *p);
extern void func_0207C9D0(Vec *, Vec *, Vec *);
extern void func_021F4E8C(int, int, Vec *);
extern void func_021F4E6C(int, int, int);
typedef signed short   s16;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_021F4ED4(u32 unused, u32 p, u16 v);
extern void func_021F4EB4(u32 unused, u32 p, s16 a, s16 b);
void func_021F7E2C(char *p, char *q) {
    Tail *t = (Tail *)(q + 0xf0);
    char *r = func_021F5450(*(char * *)&((struct Obj06411 *)q)->f58, ((struct Obj06411 *)q)->fF4);
    Vec v;
    *(int *)(q + 0xcc + ((struct Obj06411 *)q)->fF4 * 4) = 0;
    if (((struct Obj06411 *)q)->f8 == 0 || ((struct Obj22564 *)r)->f0 == 0) {
        func_0207C9D0((Vec *)(q + 0x18), (Vec *)func_021F5464(*(char * *)&((struct Obj06411 *)q)->f58), &v);
        func_021F4E8C(((struct Obj08031 *)p)->f10, *(int *)(q + 0x84 + t->index * 4), &v);
    }
    t->b = -0x3000;
    func_021F4E6C(((struct Obj08031 *)p)->f10, *(int *)(q + 0x84 + t->index * 4), 1);
    func_021F4ED4(((struct Obj08031 *)p)->f10, *(int *)(q + 0x84 + t->index * 4), 0);
    func_021F4EB4(((struct Obj08031 *)p)->f10, *(int *)(q + 0x84 + t->index * 4), 1024, 1024);
}
