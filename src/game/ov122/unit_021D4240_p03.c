/*
 * file:     unit_021D4240_p03.c
 * unit:     yes
 * function: func_021D4BF4, func_021D4C50
 * address:  0x021D4BF4
 * region:   ov122
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B92C 0x0204B92C arm
 *   func_0204BA00 0x0204BA00 arm
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_021D4BDC 0x021D4BDC thumb ov122
 *   func_021D4BF0 0x021D4BF0 thumb ov122
 *   func_021D4244 0x021D4244 thumb ov122
 *   func_02158630 0x02158630 thumb ov010
 */
#include "../../matched/include/Obj22930.h"
#include "../../matched/include/Obj05359.h"
#include "../../matched/include/Obj22931.h"

struct Actor;
struct Obj;
struct Cmd;
struct Ctx;
typedef unsigned short u16;

typedef struct { u16 f00; char *f04; void (*f08)(void); } Params;

typedef unsigned int   u32;

extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204BA00(struct Actor *a, const struct Cmd *cmd);
extern void func_0204B9A0(struct Actor *a);
extern void func_021D4BDC(char *p);
extern void func_021D4BF0(void);
extern void func_021D4244(void *p, u32 a, int a2);
extern unsigned int func_02012138(const struct Ctx *p);
extern int func_02158630(int a);
extern void func_020061E4(u32 a);
void func_021D4BF4(char *p);
int func_021D4C50(int value, char *p);

void func_021D4BF4(char *p)
{
    int i;
    Params args;
    void **base;
    i = ((struct Obj22930 *)p)->f35C;
    args.f00 = 0;
    args.f04 = p;
    args.f08 = (void (*)(void))func_021D4BDC;
    if (i == 3) i = 0;
    else if (i == 4) i = 1;
    base = (void **)(p + 0x390);
    func_0204B92C(base[i], 1);
    func_0204BA00(base[i], (const struct Cmd *)(&args));
    func_0204B9A0(base[i]);
    func_021D4244(p, (u32)func_021D4BF0, 0x390);
}

int func_021D4C50(int value, char *p)
{
    void *obj;
    obj = (void *)func_02012138(((struct Obj05359 *)p)->f354);
    ((struct Obj05359 *)p)->f35C = value;
    switch (value) {
    case 0:
    case 3:
        ((struct Obj22931 *)(*(char * *)&((struct Obj05359 *)p)->f344))->f28 = func_02158630((int)obj);
        ((struct Obj05359 *)p)->f8 = 0;
        func_020061E4(0x73b);
        func_021D4244(p, (u32)func_021D4BF4, 0x3c4);
        break;
    case 1:
    case 4:
        ((struct Obj05359 *)p)->f8 = 1;
        func_020061E4(0x73b);
        func_021D4244(p, (u32)func_021D4BF4, 0x3cd);
        break;
    case 2:
        func_020061E4(0x73c);
        ((struct Obj05359 *)p)->f8 = 2;
        func_021D4244(p, (u32)func_021D4BF4, 0x3d3);
        break;
    }
    return 1;
}
