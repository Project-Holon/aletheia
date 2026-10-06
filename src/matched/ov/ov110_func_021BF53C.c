/*
 * function: func_021BF53C
 * address: 0x021BF53C
 * packet: pkt_ov110_021BF53C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9C74 0x021B9C74 thumb ov110
 *   func_021BF680 0x021BF680 thumb ov110
 *   func_021BF6CC 0x021BF6CC thumb ov110
 *   func_021B9BEC 0x021B9BEC thumb ov110
 *   func_021BAC0C 0x021BAC0C thumb ov110
 *   func_020245AC 0x020245AC thumb
 *   func_020241E0 0x020241E0 thumb
 *   func_021BD7A0 0x021BD7A0 thumb ov110
 *   func_021BF4C4 0x021BF4C4 thumb ov110
 *   func_021BF500 0x021BF500 thumb ov110
 */
#include "../include/Obj00012.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int (*Handler)(u8 *, void *);
struct T245;
struct T241;
extern int func_021B9C74(unsigned int a);
extern int func_021BF680(u8 *);
extern void func_021BF6CC(u8 *, u8, u8);
extern void func_021B9BEC(u8 *, int);
extern int func_021BAC0C(u8 *p);
struct T;
extern void func_020245AC(struct T *p, u32 a1);
extern void func_020241E0(struct T *p, u16 *a1, u16 *a2);
extern void func_021BD7A0(u8 *, Handler);
extern int func_021BF4C4(u8 *p, int *q);
extern void func_021BF500(u8 *);
void func_021BF53C(u8 *p, u32 *q)
{
    switch (*q) {
    case 0:
        if (func_021B9C74((unsigned int)(((struct Obj00012 *)p)->f14))) {
            if (func_021BF680(p)) {
                func_021BF6CC(p + 107, 1, 0);
                ((struct Obj00012 *)p)->f48 = 0;
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14, 21);
                *q = 1;
            } else *q = 3;
        }
        break;
    case 1:
        switch (func_021BAC0C(((struct Obj00012 *)p)->f14)) {
        case 0:
            func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14, 23);
            *q = 3;
            break;
        case 1:
            if (((struct Obj00012 *)p)->f4 == 2) func_020245AC((struct T *)(p + 8), 42);
            func_020241E0((struct T *)(*(struct T241 * *)&((struct Obj00012 *)p)->f0), (u16 *)(p + 16), (u16 *)(p + 8));
            func_021BD7A0(p, (Handler)func_021BF4C4);
            *q = 3;
            break;
        }
        break;
    case 2:
        if (((struct Obj00012 *)p)->f34 & 243) *q = 3;
        break;
    case 3:
        if (func_021B9C74((unsigned int)(((struct Obj00012 *)p)->f14))) func_021BF500(p);
        break;
    }
}
