/*
 * file:     save_control_intr_p01.c
 * unit:     yes
 * function: func_021BC2FC, func_021BC3B8, func_021BC3E4, func_021BC430, func_021BC4A4, func_021BC4EC
 * address:  0x021BC2FC
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020070A4  0x020070A4  thumb
 *   func_02005B04  0x02005B04  thumb
 *   func_021BD29C  0x021BD29C  thumb  ov088
 *   func_02008730  0x02008730  thumb
 *   func_02008494  0x02008494  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_02008314  0x02008314  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_0203133C  0x0203133C  arm
 *   func_02007210  0x02007210  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021DFC20  0x021DFC20  thumb  ov228
 *   func_021DFE90  0x021DFE90  thumb  ov228
 *   func_021DFEB0  0x021DFEB0  thumb  ov228
 *   func_021DFDB8  0x021DFDB8  thumb  ov228
 *   func_02011EEC  0x02011EEC  thumb
 *   func_0216C0C0  0x0216C0C0  thumb  ov010
 *   func_020315D4  0x020315D4  arm
 *   func_020312F8  0x020312F8  arm
 *   ov228_id       0x000000E4  data
 *   d_0209DF9C     0x0209DF9C  data  a4
 *   func_0203159C  0x0203159C  arm
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_020312CC  0x020312CC  arm
 *   func_02008450  0x02008450  thumb
 *   d_021BD830     0x021BD830  data  a4
 *   func_02008448  0x02008448  thumb
 *   func_0200C31C  0x0200C31C  thumb
 *   func_020070C8  0x020070C8  thumb
 *   func_02008414  0x02008414  thumb
 *   func_0200890C  0x0200890C  thumb
 *   func_0200C324  0x0200C324  thumb
 *   func_020084E4  0x020084E4  thumb
 *   func_0200854C  0x0200854C  thumb
 *   func_02005728  0x02005728  thumb
 *   func_0200852C  0x0200852C  thumb
 *   func_0203F0A8  0x0203F0A8  arm
 *   func_02008550  0x02008550  thumb
 *   func_02008558  0x02008558  thumb
 *   func_0203064C  0x0203064C  arm
 *   func_021BC62C  0x021BC62C  thumb  ov088
 *   func_021BC75C  0x021BC75C  thumb  ov088
 */
#include "../../matched/include/Obj03676.h"
#include "../../matched/include/Obj09923.h"

struct Sub02007084Ctrl;
struct Sub020071E4Ctrl;
struct Sub0200852CObj;
struct Sub02008700Obj;
struct S020314B8;
struct S020315D4;
struct Obj0203159C;
struct Flags02008450;
struct Blk34;
struct Flags02008414;
struct Sub02008828Rec;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Rec12 {
    u32 a, b, c;
} Rec12;

typedef short s16;

typedef struct S1C {
    u16 f0;
    u16 pad;
    Rec12 rec;
    u32 x, y;
    s16 f18;
    s16 f1a;
} S1C;

typedef unsigned long long u64;

extern struct Sub02007084Ctrl *func_020070A4(void);
extern void func_02005B04(const u32 *arg);
extern void func_021BD29C(void *p);
extern struct Sub0200852CObj *func_02008730(void *sys);
extern void func_02008494(void *, void *);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern void func_02008314(void *, void *);
extern u32 func_020307B0(void *p);
extern void func_0203133C(struct S020314B8 *p);
extern u8 func_02007210(const struct Sub020071E4Ctrl *ctrl);
extern int func_02034AC4(int id);
extern void func_02034A5C(int id);
extern void *func_021DFC20(u32 heap);
extern u8 func_021DFE90(u8 *p);
extern void func_021DFEB0(char *p, void *ctrl);
extern void func_021DFDB8(void *);
extern void *func_02011EEC(u32 a0, u16 a1, struct Rec12 *a2, int a3);
extern int func_0216C0C0(int);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020312F8(u32 a1, u32 a2, u32 a3);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void *func_0200C0F0(void *sys);
extern void func_020312CC(u32 a0, u32 a1, u32 a2);
extern void func_02008450(struct Flags02008450 *p, int on);
extern unsigned int func_02008448(int a0);
extern u8 func_0200C31C(struct Blk34 *p);
extern int func_020070C8(char *self);
extern u8 func_02008414(const struct Flags02008414 *p);
extern void func_0200890C(void *sys, struct Sub02008828Rec *dest);
extern void func_0200C324(struct Blk34 *p, u8 v);
extern void func_020084E4(u16 *out, struct U16Vec *vec);
extern void func_0200854C(int, int);
extern u32 func_02005728(u32 range);
extern void func_0200852C(struct Sub0200852CObj *obj, u32 value);
extern u32 func_0203F0A8(void);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_02008558(struct Sub0200852CObj *obj, u8 value);
extern void func_0203064C(unsigned int, unsigned int, unsigned int);
extern void func_021BC62C(char *);
extern void func_021BC75C(u8 *p);
int func_021BC2FC(int a, int b, int c, char *t);
int func_021BC3B8(struct Obj0203159C *a0);
int func_021BC3E4(int a, int *st, int k, int *p);
int func_021BC430(int a, int b, int c, u32 *q);
void func_021BC4A4(int a, int b, int c);
int func_021BC4EC(struct Obj0203159C *a, int b, int *c);
extern u8 ov228_id[];
extern char d_0209DF9C[];
extern char d_021BD830[];


int func_021BC2FC(int a, int b, int c, char *t)
{
    void *r4 = func_020070A4();
    void *r6;
    Rec12 z = {0, 0, 0};
    func_02005B04((const u32 *)(((struct Obj03676 *)t)->f34));
    func_021BD29C((void *)(((struct Obj03676 *)t)->f2C));
    func_02008494(((struct Obj03676 *)t)->f54, func_02008730(r4));
    func_02008314(((struct Obj03676 *)t)->f58, func_0200873C(r4));
    func_020307B0(((struct Obj03676 *)t)->f54);
    func_020307B0(((struct Obj03676 *)t)->f58);
    func_0203133C((struct S020314B8 *)((struct Obj03676 *)t)->f30);
    if (func_02007210(r4) == 1) {
        func_02034AC4((int)ov228_id);
        r6 = func_021DFC20(1);
        if (func_021DFE90(r6) == 1)
            func_021DFEB0(r6, r4);
        func_021DFDB8(r6);
        func_02034A5C((int)ov228_id);
    }
    r4 = func_02011EEC(0, 0, &z, 0);
    func_0216C0C0(((struct Obj03676 *)t)->f28);
    func_020315D4((struct S020315D4 *)a);
    func_020312F8(-1, (u32)d_0209DF9C, (u32)r4);
    return 1;
}


int func_021BC3B8(struct Obj0203159C *a0)
{
    u32 *q = func_0203159C(a0, 0x5c, 1);

    q[0] = 1;
    q[1] = (u32)func_0200873C(func_020070A4());
    q[3] = (u32)func_0200C0F0(func_020070A4());
    q[2] = 0;
    return 1;
}


int func_021BC3E4(int a, int *st, int k, int *p)
{
    switch (*st) {
    case 0:
        if (k == 0) {
            func_020312CC(-1, (u32)d_021BD830, (u32)p);
        } else if (k == 1) {
            func_02008450((struct Flags02008450 *)p[1], 0);
        } else if (k == 2) {
            func_02008450((struct Flags02008450 *)p[1], 1);
        }
        *st = *st + 1;
        break;
    case 1:
        return 1;
    }
    return 1;
}


int func_021BC430(int a, int b, int c, u32 *q)
{
    S1C s;
    void *r;
    u32 t;
    u8 h;

    r = func_020070A4();
    t = func_02008448((int)((void *)q[1]));
    h = func_0200C31C((void *)q[3]);
    func_020070C8(r);
    func_02008414((const struct Flags02008414 *)func_0200873C(r));
    func_0200890C(r, (struct Sub02008828Rec *)(&s));
    func_020312F8(-1, (u32)d_0209DF9C, (u32)func_02011EEC(1, s.f0, &s.rec, s.f18));
    func_02008450((void *)q[1], t);
    func_0200C324((void *)q[3], h);
    func_020315D4((struct S020315D4 *)a);
    return 1;
}


void func_021BC4A4(int a, int b, int c)
{
    u64 x;
    u32 y;
    func_020084E4((u16 *)a, (struct U16Vec *)b);
    func_0200854C(a, c);
    func_0200852C((struct Sub0200852CObj *)a, func_02005728(-1));
    x = func_0203F0A8();
    y = func_02008550((const struct Sub0200852CObj *)a);
    func_02008558((struct Sub0200852CObj *)a, (u8)((u32)((x * 8) >> 32) + y * 8));
}


/*
 * EXACT*: inferred extent runs two bytes long; the follower is an unlabelled
 * padding pair.
 */
int func_021BC4EC(struct Obj0203159C *a, int b, int *c)
{
    char *r;
    func_0203064C(1, 0x39, 0x80000);
    r = func_0203159C(a, 0x1c, 0x39);
    if (*c == 0)
        ((struct Obj09923 *)r)->f4 = 0;
    else
        ((struct Obj09923 *)r)->f4 = 2;
    ((struct Obj09923 *)r)->f18 = 0;
    func_021BC62C(r);
    func_021BC75C((u8 *)r);
    return 1;
}
