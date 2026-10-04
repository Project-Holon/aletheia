/*
 * function: func_021BBFA8
 * address:  0x021BBFA8
 * packet:   pkt_ov088_021BBFA8
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020286C4  0x020286C4  thumb
 *   func_0201CE30  0x0201CE30  thumb
 *   func_0203630C  0x0203630C  arm
 *   func_0201CE5C  0x0201CE5C  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_0201CE48  0x0201CE48  thumb
 */
#include "../include/Obj01887.h"

typedef unsigned int u32;

typedef signed int     s32;
struct Ctx;
struct Rec;
struct Rec3;
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern u32 func_0201CE30(void *p);
extern unsigned int func_0203630C(void);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern u32 func_020362DC(void);
extern void func_020061E4(u32);
extern void func_0201CE38(void *);
extern void func_0201CE48(struct Rec3 *p);

int func_021BBFA8(char *p)
{
    if (((struct Obj01887 *)p)->f6C == 0)
        return 0;
    func_020286C4(((struct Obj01887 *)p)->f74, ((struct Obj01887 *)p)->f6C, ((struct Obj01887 *)p)->fE8);
    switch (func_0201CE30(((struct Obj01887 *)p)->f6C)) {
    case 0:
        if (func_0203630C() & 3)
            func_0201CE5C(((struct Obj01887 *)p)->f6C, 0);
        ((struct Obj01887 *)p)->f78 = 0;
        break;
    case 1:
        if (((struct Obj01887 *)p)->f78 == 0) {
            if (func_020362DC() & 3) {
                func_020061E4(0x547);
                func_0201CE38(((struct Obj01887 *)p)->f6C);
                ((struct Obj01887 *)p)->f78 = 1;
            }
        }
        break;
    case 2:
        func_0201CE48(((struct Obj01887 *)p)->f6C);
        *(int *)&((struct Obj01887 *)p)->f6C = 0;
        ((struct Obj01887 *)p)->f78 = 0;
        return 0;
    }
    return 1;
}
