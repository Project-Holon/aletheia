/*
 * function: func_021F7AEC
 * address: 0x021F7AEC
 * packet: pkt_ov112_021F7AEC
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero padding before 021F7BA8.
 * symbols:
 *   func_021F9DC0 0x021F9DC0 thumb ov132
 *   func_021F9EDC 0x021F9EDC thumb ov132
 *   func_021F9F74 0x021F9F74 thumb ov132
 *   func_021F5450 0x021F5450 thumb ov112
 *   func_021F5464 0x021F5464 thumb ov112
 *   func_0207C9D0 0x0207C9D0 arm
 *   func_021F4EA4 0x021F4EA4 thumb ov112
 */
#include "../../../matched/include/Obj08027.h"
#include "../../../matched/include/Obj13843.h"
#include "../../../matched/include/Obj22561.h"
typedef struct { int x, y, z; } Vec;
typedef struct { short count, pad; int index, a, b; } Tail;
typedef unsigned short u16;
extern void *func_021F9DC0(void *p);
typedef unsigned int   u32;
extern char *func_021F9EDC(char *p, u32 a);
extern void func_021F9F74(int, int, Vec *);
extern char *func_021F5450(char *, int);
extern char *func_021F5464(char *p);
extern void func_0207C9D0(Vec *, Vec *, Vec *);
extern void func_021F4EA4(u32 unused, u32 p, u32 q);
void func_021F7AEC(char *p, char *q) {
    Tail *t = (Tail *)(q + 0xf0);
    int a = (int)func_021F9DC0((void *)(((struct Obj13843 *)p)->f4));
    char *r = func_021F5450(*(char * *)&((struct Obj08027 *)q)->f58, ((struct Obj08027 *)q)->fF4);
    Vec v;
    t->a = (int)func_021F9EDC((char *)a, 0x35);
    if (((struct Obj08027 *)q)->f8 == 1 && ((struct Obj22561 *)r)->f0 == 1) {
        func_021F4EA4(((struct Obj13843 *)p)->f10, *(int *)(q + 0x84 + t->index * 4), (u32)(&v));
        v.x /= 16;
        v.y = (0xc0000 - v.y) / 16;
        v.z += 0x1000;
    } else {
        func_0207C9D0((Vec *)(q + 0x18), (Vec *)func_021F5464(*(char * *)&((struct Obj08027 *)q)->f58), &v);
        v.x /= 16;
        v.y = (0xc0000 - v.y) / 16;
        v.z -= 0x1c000;
    }
    func_021F9F74(t->a, 0, &v);
}
