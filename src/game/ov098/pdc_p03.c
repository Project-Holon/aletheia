/*
 * file:     pdc_p03.c
 * unit:     yes
 * function: func_021B6504, func_021B6578, func_021B6750, func_021B67A4
 * address:  0x021B6504
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B694C  0x021B694C  thumb  ov098
 *   func_021B6A3C  0x021B6A3C  thumb  ov098
 *   func_0220270C  0x0220270C  thumb  ov094
 *   func_02202DC4  0x02202DC4  thumb  ov094
 *   func_021B6364  0x021B6364  thumb  ov098
 *   d_021B6D98     0x021B6D98  data   ov098  a4
 *   d_021B6DC0     0x021B6DC0  data   ov098  a4
 *   ov196_id 0x000000C4 data
 *   ov197_id 0x000000C5 data
 *   func_021B614C 0x021B614C thumb ov098
 *   func_021B6140 0x021B6140 thumb ov098
 *   func_021B6988 0x021B6988 thumb ov098
 *   func_021B69C4 0x021B69C4 thumb ov098
 *   func_021B6B74 0x021B6B74 thumb ov098
 *   func_022025D8 0x022025D8 thumb ov094
 *   func_022026FC 0x022026FC thumb ov094
 *   func_0220266C 0x0220266C thumb ov094
 *   func_0220C834 0x0220C834 thumb ov197
 *   func_021F7CFC 0x021F7CFC thumb ov094
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 *   func_021F7C0C 0x021F7C0C thumb ov094
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_02007F1C 0x02007F1C thumb
 *   func_02005D90 0x02005D90 thumb
 *   func_02005F38 0x02005F38 thumb
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_0202142C 0x0202142C thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_021B6A00  0x021B6A00  thumb  ov098
 *   func_02005E30  0x02005E30  thumb
 *   func_0207D55C 0x0207D55C arm
 */
#include "../../matched/include/Obj00381.h"
#include "../../matched/include/Obj03730.h"

struct P;
struct Obj;
struct W;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

struct P {
    void *parent; u32 pad04; void *w08; u32 pad0c; char *window; u8 *object; u32 pad18;
    u32 b1c; void *w20; u32 w24; u16 h28; u8 pad2a[6]; u8 b30, b31; u16 h32;
    u8 pad34, b35; u8 pad36[2]; void *w38; u32 w3c; u8 pad40[8]; u8 *w48;
    u8 pad4c[16]; u32 w5c, state; int timer; u32 pad68; u16 heap; u16 pad6e;
    void *w70; u8 workspace[1];
};

typedef signed int     s32;

extern void func_021B694C(u8 *p, u8 *q);
extern int func_021B6A3C(u8 *p);
extern void func_0220270C(char *s, int mode, void *arg);
extern int func_02202DC4(int a, char *b, char *c);
extern void func_021B6364(u8 *p, u32 v);
extern int func_021B614C(int *p);
extern int func_021B6140(void *);
extern void func_021B6988(int, int);
extern void func_021B69C4(int, int);
extern int func_021B6B74(u8 *);
extern void func_022025D8(char *, int);
extern int func_022026FC(struct W *p);
extern void func_0220266C(struct Obj *p);
extern void func_0220C834(u8 *);
extern void func_021F7CFC(u32, u16, u8, int, int);
extern int func_021F7EB4(void);
extern void func_021F7C0C(void);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
extern u32 func_02007F1C(u8 *, u16, u16, u16);
extern void func_02005D90(u32, u16);
extern int func_02005F38(void);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_0204E720(u32, int, int, int);
extern int func_0204E804(void);
extern unsigned short func_0202142C(int a0);
extern void func_02017E40(void *, u32, u32);
extern void func_021B6A00(u8 *p, u8 *q);
extern void func_02005E30(u32 a);
extern int func_0207D55C(volatile u16 *reg);
int func_021B6504(char *p);
int func_021B6578(struct P *p);
int func_021B6750(char *p);
void func_021B67A4(int a);
extern char d_021B6D98[];
extern char d_021B6DC0[];
extern char ov196_id[], ov197_id[];


int func_021B6504(char *p)
{
    int r;

    switch (((struct Obj00381 *)p)->f60) {
    case 0:
        func_021B694C((u8 *)(((struct Obj00381 *)p)->f14), (u8 *)(*(int *)&((struct Obj00381 *)p)->f0));
        ((struct Obj00381 *)p)->f60 = ((struct Obj00381 *)p)->f60 + 1;
        break;
    case 1:
        if (func_021B6A3C((u8 *)(((struct Obj00381 *)p)->f14)) != 0) {
            func_0220270C((char *)(((struct Obj00381 *)p)->f10), 7, 0);
            ((struct Obj00381 *)p)->f60 = ((struct Obj00381 *)p)->f60 + 1;
        }
        break;
    case 2:
        r = func_02202DC4(((struct Obj00381 *)p)->f10, d_021B6D98, d_021B6DC0);
        if (r != -1) {
            if (r != 0)
                func_021B6364((u8 *)p, (u32)func_021B6750);
            else
                func_021B6364((u8 *)p, (u32)func_021B6578);
        }
        break;
    }
    return 0;
}

int func_021B6578(struct P *p)
{
    u32 t;
    switch (p->state) {
    case 0:
        p->b1c = func_021B614C(p->parent);
        p->w38 = p->w70;
        p->w24 = 3;
        p->w20 = p->w08;
        p->h28 = p->heap;
        p->h32 = 0;
        p->w3c = 0;
        p->b30 = 0; p->b31 = 0; p->b35 = 0;
        p->w48 = p->workspace;
        p->w5c = 1;
        func_022025D8(p->window, 1);
        func_02034AC4((s32)ov196_id);
        (p->state)++;
        break;
    case 1:
        if (!func_022026FC((struct W *)p->window)) {
            func_02034AC4((s32)ov197_id);
            func_0220C834((u8 *)&p->b1c);
            (p->state)++;
        }
        break;
    case 2:
        if (p->b35) {
            func_02034A5C((s32)ov196_id); func_02034A5C((s32)ov197_id);
            func_0220266C((struct Obj *)p->window);
            if (p->h32 == 0) p->state = 3;
            else {
                func_02007F1C((u8 *)func_021B614C(p->parent), p->h32, 1, p->heap);
                p->state = 4;
            }
        }
        break;
    case 3:
        if (!func_022026FC((struct W *)p->window)) func_021B6364((u8 *)p, (u32)func_021B6504);
        break;
    case 4:
        if (!func_022026FC((struct W *)p->window)) {
            func_021B6988((int)p->object, (int)p->parent);
            (p->state)++;
        }
        break;
    case 5:
        if (func_021B6A3C(p->object)) {
            func_021F7CFC(1, p->h32, 4, 1, 0);
            (p->state)++;
        }
        break;
    case 6:
        if (!func_021F7EB4()) {
            func_021B69C4((int)p->object, (int)p->parent);
            (p->state)++;
        }
        break;
    case 7:
        if (func_021B6B74(p->object)) func_02005D90(0x518, 0xffff);
        if (func_021B6A3C(p->object)) (p->state)++;
        break;
    case 8:
        if (!func_02005F38()) {
            func_021F7C0C(); func_02005D90(0x47c, 0xffff);
            (p->state)++;
        }
        break;
    case 9:
        if (!func_021F7EB4()) {
            p->timer = 80;
            (p->state)++;
        }
        break;
    case 10:
        if (((u32)func_020362DC() & 3) || func_02035C60() || --p->timer == 0) {
            func_0204E720(3, 0, 16, 2);
            (p->state)++;
        }
        break;
    case 11:
        if (!func_0204E804()) {
            t = func_0202142C(p->h32);
            func_02017E40((void *)func_021B6140(p->parent), 152, t);
            return 1;
        }
        break;
    }
    return 0;
}


int func_021B6750(char *p)
{
    switch (((struct Obj03730 *)p)->f60) {
    case 0:
        func_021B6A00((u8 *)(((struct Obj03730 *)p)->f14), (u8 *)(((struct Obj03730 *)p)->f0));
        ((struct Obj03730 *)p)->f60 = ((struct Obj03730 *)p)->f60 + 1;
        break;
    case 1:
        if (func_021B6A3C((u8 *)(((struct Obj03730 *)p)->f14)) != 0) {
            func_0204E720(3, 0, 0x10, 2);
            func_02005E30(8);
            ((struct Obj03730 *)p)->f60 = ((struct Obj03730 *)p)->f60 + 1;
        }
        break;
    case 2:
        if (func_0204E804() == 0)
            return 2;
        break;
    }
    return 0;
}

void func_021B67A4(int a) { if (func_0207D55C((unsigned short *)0x0400006c) <= 0) func_0204E720(3,16,0,a); else func_0204E720(12,16,0,a); }
