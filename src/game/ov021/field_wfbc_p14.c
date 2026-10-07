/*
 * file:     field_wfbc_p14.c
 * unit:     yes
 * function: func_021945A0, func_021945A4, func_021945E0, func_02194670, func_02194704
 * address:  0x021945A0
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
 *   func_02188CCC  0x02188CCC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_021A0ED4  0x021A0ED4  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_020124E4  0x020124E4  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_020129D0  0x020129D0  thumb
 *   func_021A0F30  0x021A0F30  thumb  ov021
 *   func_020129B8  0x020129B8  thumb
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   func_0203101C  0x0203101C  arm
 *   func_02194A58  0x02194A58  thumb  ov021
 *   func_021954CC  0x021954CC  thumb  ov021
 *   d_021DDAC4     0x021DDAC4  data  a4
 *   d_020A8140     0x020A8140  data  a4
 *   d_020A8148     0x020A8148  data  a4
 *   func_02195530  0x02195530  thumb
 */
#include "../../matched/include/Obj02693.h"
#include "../../matched/include/Obj07451.h"

struct Desc;
struct Obj;
struct BigObj;
struct Tcbl;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { unsigned w[6]; } T24;

extern u32 func_02188CCC(u8 *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_02082BCC(void *p, int v, int n);
extern int func_021A0ED4(u32 a);
extern void *func_02188C7C(u8 *p);
extern void *func_020124E4(struct Obj *p);
extern u32 func_020120F4(void);
extern void func_0216D9A0(void *a);
extern void func_020129D0(struct BigObj *p, u8 v);
extern int func_021A0F30(u32 a, u32 b);
extern void func_020129B8(struct BigObj *p, u32 v);
extern u32 *func_0216D9E4(void *c);
extern void *func_02030734(unsigned int heap, unsigned int size, int clear, const char *site, u16 tag);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern int func_02194A58(u32 a);
extern u32 func_021954CC(u32 p, u8 *e);
extern void func_02195530(char *p);
int func_021945A0(int x);
void *func_021945A4(void *a, u32 b, u32 c);
int func_021945E0(void *a, int b, u8 *c);
void *func_02194670(u16 *a);
void func_02194704(char *a0);
extern int d_021DDAC4;


/*
 * An empty function.
 */
int func_021945A0(int x)
{
    return x;
}


/*
 * Addresses are Black-image addresses.
 */
void *func_021945A4(void *a, u32 b, u32 c)
{
    void *t;
    u32 *w;

    func_02188CCC((u8 *)b);
    t = func_020122C0(a, 0, func_021945E0, 0x14);
    w = func_020124E8(t);
    func_02082BCC(w, 0, 0x14);
    w[1] = (u32)a;
    w[0] = (u32)t;
    w[2] = b;
    w[3] = c;
    return t;
}


int func_021945E0(void *a, int b, u8 *c)
{
    void *r6;
    u32 r4;

    switch (c[0x10]) {
    case 0:
        if (func_021A0ED4(func_02188CCC(((struct Obj02693 *)c)->f8)) == 1) {
            r6 = func_02188C7C(((struct Obj02693 *)c)->f8);
            func_020124E4(a);
            r4 = func_020120F4();
            func_0216D9A0(r6);
            func_020129D0((struct BigObj *)r4, 1);
            func_021A0F30(func_02188CCC(((struct Obj02693 *)c)->f8), ((struct Obj02693 *)c)->fC);
            c[0x10]++;
        }
        break;
    case 1:
        if (func_021A0ED4(func_02188CCC(((struct Obj02693 *)c)->f8)) == 1) {
            func_020124E4(a);
            func_020129B8((struct BigObj *)func_020120F4(), ((struct Obj02693 *)c)->fC & 0xff);
            c[0x10]++;
        }
        break;
    case 2:
        func_0216D9E4(func_02188C7C(((struct Obj02693 *)c)->f8));
        return 1;
    }
    return 0;
}

extern void *(*d_020A8140)(int, int, int);

extern void *(*d_020A8148)(int, int, int);


void *func_02194670(u16 *a)
{
    unsigned char *r6;
    int i;

    r6 = (unsigned char *)func_02030734(*a, 0xcd0, 1, (const char *)&d_021DDAC4, 0xec);
    *(T24 *)r6 = *(T24 *)a;
    ((struct Obj07451 *)r6)->fC98 = func_0203101C(*a, *a, 0x20, 0x20);
    for (i = 0; i < 0x20; i++)
        func_02194A58((u32)(r6 + 0x18 + i * 0x64));
    ((struct Obj07451 *)r6)->fCC8 = d_020A8140(0x20, 0, 0);
    ((struct Obj07451 *)r6)->fCCC = d_020A8148(0x20, 0, 0);
    ((struct Obj07451 *)r6)->fC9C = func_021954CC((u32)r6, r6) >> 5;
    return r6;
}


/*
 * Tail-call thunk: forwards to func_02195530 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_02194704(char *a0)
{
    func_02195530(a0);
}
