/*
 * file:     shinka_demo_p07.c
 * unit:     yes
 * function: func_022054E8, func_02205530
 * address:  0x022054E8
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201F73C  0x0201F73C  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02045B38 0x02045B38 arm
 *   func_02205A28 0x02205A28 thumb ov195
 *   func_021B6DC0 0x021B6DC0 thumb ov067
 */
#include "../../matched/include/Obj03344.h"

struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
typedef unsigned char  u8;

typedef unsigned int   u32;

typedef unsigned short u16;

extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern int func_02205A28(char *a);
extern u32 func_021B6DC0(u16, int, int, int, int, u32, u32, u32, int);
void func_022054E8(int a, int *p, int flag);
void func_02205530(int a, char *b);


/*
 * Leaf of the func_022040E0 dependency tree: either build the +0x6c render
 * node from the +0x74 id (and flush the +0x104/+0x108 stage), or arm the
 * +0x88 transition word with 2.
 */
void func_022054E8(int a, int *p, int flag)
{
    if (flag != 0) {
        int *q;

        func_0201F73C((void *)p[0x1b], 0, (unsigned short)p[0x1d], 2);
        func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)p[0x1b])), 0xf);
        q = (int *)p[0x1b];
        func_02045334((struct Descriptor *)q);
        func_02045374((struct Cfg *)((int)q));
        func_020409B4(func_02045730((struct Descriptor *)((int)q)));
    } else {
        p[0x22] = 2;
    }
}


void func_02205530(int a, char *b)
{
    ((struct Obj03344 *)b)->f90 = (u32)func_02045B38(0, 2, 0xe9, ((struct Obj03344 *)b)->f2);
    ((struct Obj03344 *)b)->f9C = func_021B6DC0(((struct Obj03344 *)b)->f2, 5, 0, 1, 0, func_02205A28((char *)(((struct Obj03344 *)b)->f4)),
                                       ((struct Obj03344 *)b)->f8, ((struct Obj03344 *)b)->fC, 0);
    ((struct Obj03344 *)b)->f94 = 0;
    ((struct Obj03344 *)b)->f98 = 0;
}
