/*
 * file:     field_msgbg_p75.c
 * unit:     yes
 * function: func_02191978, func_021919AC, func_021919C8, func_02191A04, func_02191A10, func_02191B14, func_02191BE8
 * address:  0x02191978
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
 *   func_0219194C  0x0219194C  thumb  ov021
 *   func_0201CE30  0x0201CE30  thumb  arm9
 *   func_020362DC  0x020362DC  arm  arm9
 *   func_0203630C  0x0203630C  arm  arm9
 *   func_02194974  0x02194974  thumb  ov021
 *   func_02194984  0x02194984  thumb  ov021
 *   d_021DDA50     0x021DDA50  data  a4
 *   func_02030734  0x02030734  arm
 *   func_02040618  0x02040618  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02043678  0x02043678  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045374  0x02045374  arm
 *   func_02045334  0x02045334  arm
 *   func_02191D88  0x02191D88  thumb  ov021
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_02045738  0x02045738  arm
 *   func_02045740  0x02045740  arm
 *   func_02191DC8  0x02191DC8  thumb  ov021
 *   func_020409B4  0x020409B4  arm
 *   func_021927C0  0x021927C0  thumb  ov021
 *   func_02193044  0x02193044  thumb  ov021
 *   func_02191FA0  0x02191FA0  thumb  ov021
 *   func_020456F8  0x020456F8  arm
 *   func_02041300  0x02041300  arm
 *   func_020452E8  0x020452E8  arm
 *   func_020437AC  0x020437AC  arm
 *   func_02045808  0x02045808  arm
 *   func_021927E8  0x021927E8  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_020458F8  0x020458F8  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0219214C  0x0219214C  thumb  ov021
 *   func_02192138  0x02192138  thumb  ov021
 *   func_021928C0  0x021928C0  thumb  ov021
 *   func_021927FC  0x021927FC  thumb  ov021
 *   func_02043814  0x02043814  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_021921C8  0x021921C8  thumb  ov021
 */
#include "../../matched/include/Obj17935.h"

struct Bmp;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct Fx;
struct G;
struct Obj020437AC;
struct U16Vec;
struct Cur;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short          s16;

typedef struct P { u8 pad[0xA0]; volatile u32 arr[8]; } P;

typedef struct Q {
    u32 f00;
    u32 f04;
    void *f08;
    u32 f0c;
    u32 f10;
    void *f14;
} Q;

extern int func_0219194C(void *a);
extern int func_02194974(u8 *p, int i);
extern u32 func_02194984(u32 a, u32 b);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern u32 func_0201CE30(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern void *func_02045770(struct Descriptor *w);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *w);
extern void func_02191D88(u32 a, u32 b, u32 c, u32 d);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045740(struct Descriptor *p);
extern void func_02191DC8(u32 layer, u32 x, u32 y, u32 w, u32 h, u32 tile, u32 pal);
extern void func_020409B4(u32 layer);
extern void func_021927C0(struct G *g, struct Fx *a);
extern void func_02193044(u32 a);
extern void func_02191FA0(u32 layer, u32 x, u32 y, u32 w, u32 h, u32 tile, u32 mode);
extern void func_020456F8(struct Descriptor *d);
extern void func_02041300(u32 layer, u32 tile, u32 x, u32 y, u32 w, u32 h, u32 mode);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_021927E8(u32 *p);
extern u32 func_020307B0(void *p);
extern u16 func_020458F8(struct U16Vec *vec);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern int func_0219214C(u32 a, u32 b, u32 c, u32 d, u32 *cnt, u8 col);
extern int func_02192138(u32 a, u32 b, u32 c);
extern void func_021928C0(struct Cur *c, u32 win, u32 col);
extern void func_021927FC(struct Cur *c, u32 win, u32 col);
extern void func_02043814(struct Bmp *dst, const struct Bmp *src);
extern void func_020061E4(u32 a);
extern int func_021921C8(u32 a, u32 b, u32 c, int n, u16 col);
void func_02191978(P *p);
int func_021919AC(u8 *p);
int func_021919C8(Q *q);
void func_02191A04(u8 *p, int a);
u32 *func_02191A10(u16 *a, u32 b, u32 c);
void func_02191B14(u32 *a);
u32 func_02191BE8(u32 *p, u32 b);
extern char d_021DDA50[];

/*
 * Addresses are Black-image addresses.
 */
void func_02191978(P *p)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (p->arr[i] != 0) {
            p->arr[i] = 0;
            {
                u32 t = p->arr[i];
                p->arr[i] = 0;
                func_0219194C((void *)t);
            }
        }
    }
}


int func_021919AC(u8 *p)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (((u32 *)(p + 0xA0))[i] != 0)
            return 1;
    }
    return 0;
}


int func_021919C8(Q *q)
{
    if (func_02194974((u8 *)q->f0c, (int)q->f08) == 0)
        return 0;
    func_020362DC();
    func_0203630C();
    switch (func_0201CE30((void *)func_02194984(q->f0c, (u32)q->f08))) {
    case 0:
    case 1:
        break;
    case 2:
        return 1;
    }
    return 0;
}


/*
 * Tail call passing the object, a pass-through argument and the word at +8.
 *
 * Addresses are Black-image addresses.
 */
void func_02191A04(u8 *p, int a)
{
    func_02191A10((u16 *)p, a, ((struct Obj17935 *)p)->f8);
}


u32 *func_02191A10(u16 *a, u32 b, u32 c)
{
    u32 *p;
    u32 x;
    u32 y;
    u32 w;
    u32 h;

    p = (u32 *)func_02030734(a[0], 0x34, 1, d_021DDA50, 0xee0);
    p[0] = (u32)a;
    p[12] = c;
    p[7] = -48;
    func_02040618((u8)a[1], 0, 0);
    func_02040618((u8)((u16 *)p[0])[1], 3, p[7]);
    p[1] = func_020450F0((u8)a[1], 2, 0x13, 0x1c, 4, 9, 1);
    p[2] = (u32)func_02043678(0x1c, 4, 0x20, a[0]);
    p[3] = (u32)func_02043678(0x1c, 4, 0x20, a[0]);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p[1])), 15);
    func_02045374((struct Cfg *)p[1]);
    func_02045334((struct Descriptor *)p[1]);
    func_02191D88(a[1], 9, b, a[0]);
    x = func_02045758((struct Descriptor *)p[1]);
    y = func_02045760((struct Descriptor *)p[1]);
    w = func_02045738((struct Descriptor *)p[1]);
    h = func_02045740((struct Descriptor *)p[1]);
    func_02191DC8((u8)a[1], x, y, w, h, 0x33, 9);
    func_020409B4((u8)a[1]);
    func_021927C0((struct G *)(p + 10), (struct Fx *)p[0]);
    a[3] = 11;
    func_02193044(0);
    return p;
}


void func_02191B14(u32 *a)
{
    u32 x;
    u32 y;
    u32 w;
    u32 h;

    func_02045770((struct Descriptor *)a[1]);
    x = func_02045758((struct Descriptor *)a[1]);
    y = func_02045760((struct Descriptor *)a[1]);
    w = func_02045738((struct Descriptor *)a[1]);
    h = func_02045740((struct Descriptor *)a[1]);
    func_02191FA0((u8)((u16 *)a[0])[1], x, y, w, h, 0, 15);
    func_020456F8((struct Descriptor *)a[1]);
    x = func_02045758((struct Descriptor *)a[1]);
    y = func_02045760((struct Descriptor *)a[1]);
    w = func_02045738((struct Descriptor *)a[1]);
    h = func_02045740((struct Descriptor *)a[1]);
    func_02041300((u8)((u16 *)a[0])[1], 0, x, y, w, h, 0x11);
    func_02045334((struct Descriptor *)a[1]);
    func_020452E8((struct Descriptor *)a[1]);
    func_020409B4((u8)((u16 *)a[0])[1]);
    func_02040618((u8)((u16 *)a[0])[1], 3, 0);
    func_020437AC((struct Obj020437AC *)a[3]);
    func_020437AC((struct Obj020437AC *)a[2]);
    if (a[5] != 0) {
        func_02045808((struct U16Vec *)a[5]);
    }
    func_021927E8(a + 10);
    func_020307B0(a);
}


u32 func_02191BE8(u32 *p, u32 b)
{
    switch (p[6]) {
    case 0:
        p[4] = b;
        p[5] = (u32)func_020457B0(func_020458F8((struct U16Vec *)b) + 2, *(u16 *)p[0]);
        func_0219214C((u32)func_02045770((struct Descriptor *)p[1]), p[12], p[4], p[5], p + 9, 15);
        func_02045334((struct Descriptor *)p[1]);
        func_020409B4((u8)((u16 *)p[0])[1]);
        p[6]++;
        break;
    case 1:
        *(int *)&p[7] += 12;
        if (*(int *)&p[7] >= 0) {
            p[7] = 0;
            p[6]++;
        }
        func_02040618((u8)((u16 *)p[0])[1], 3, p[7]);
        break;
    case 2:
        if (func_02192138(p[4], p[5], p[9]) == 1) {
            p[6] = 5;
            break;
        }
        p[6]++;
    case 3:
        if ((func_020362DC() & 3) == 0) {
            func_021928C0((struct Cur *)(p + 10), (u32)func_02045770((struct Descriptor *)p[1]), 15);
            func_02045334((struct Descriptor *)p[1]);
            break;
        }
        func_021927FC((struct Cur *)(p + 10), (u32)func_02045770((struct Descriptor *)p[1]), 15);
        func_02043814((struct Bmp *)((u32)func_02045770((struct Descriptor *)p[1])), (const struct Bmp *)p[3]);
        func_0219214C(p[2], p[12], p[4], p[5], p + 9, 15);
        p[8] = 0;
        func_020061E4(0x547);
        p[6]++;
    case 4:
        if (func_021921C8((u32)func_02045770((struct Descriptor *)p[1]), p[3], p[2], p[8], 15) == 1) {
            p[6] = 2;
        } else {
            p[8] += 4;
        }
        func_02045334((struct Descriptor *)p[1]);
        func_020409B4((u8)((u16 *)p[0])[1]);
        break;
    case 5:
        if ((func_020362DC() & 0xf3) == 0) {
            break;
        }
        p[6]++;
    case 6:
        *(int *)&p[7] -= 12;
        if (*(int *)&p[7] <= -48) {
            p[7] = -48;
        }
        func_02040618((u8)((u16 *)p[0])[1], 3, p[7]);
        if (*(int *)&p[7] == -48) {
            p[6]++;
            return 1;
        }
        break;
    case 7:
        return 1;
    }
    return 0;
}
