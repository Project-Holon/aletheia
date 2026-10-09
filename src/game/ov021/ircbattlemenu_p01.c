/*
 * file:     ircbattlemenu_p01.c
 * unit:     yes
 * function: func_0219728C, func_021973A0, func_0219749C, func_021974A0, func_02197534, func_021975D0, func_02197644, func_02197700, func_02197738
 * address:  0x0219728C
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
 *   d_021D3FC0     0x021D3FC0  data   a1
 *   d_021D3FD0     0x021D3FD0  data   a1
 *   d_021D3FB8     0x021D3FB8  data   a1
 *   func_02197058  0x02197058  thumb  ov021
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B688  0x0204B688  arm
 *   d_021D3F98     0x021D3F98  data   a1
 *   d_021D3FA4     0x021D3FA4  data   a1
 *   d_021D3F90     0x021D3F90  data   a1
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02027778  0x02027778  thumb
 *   func_02027CD8  0x02027CD8  thumb
 *   func_02045808  0x02045808  arm
 *   func_020286C4  0x020286C4  thumb
 *   func_0201CE30  0x0201CE30  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_0201CE5C  0x0201CE5C  thumb
 *   func_02035C60  0x02035C60  arm
 *   func_02035C38  0x02035C38  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_0201F73C  0x0201F73C  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02196228  0x02196228  thumb  ov021
 *   func_02041570  0x02041570  arm
 *   func_02196034  0x02196034  thumb  ov021
 *   func_021978AC  0x021978AC  thumb  ov021
 *   func_02012DD0  0x02012DD0  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020456F8  0x020456F8  arm
 *   func_02196A60  0x02196A60  thumb  ov021
 *   func_02196804  0x02196804  thumb  ov021
 */
#include "../../matched/include/Obj00094.h"
#include "../../matched/include/Obj05989.h"

struct Obj_0219728C;
struct Actor;
struct MsgBank;
struct U16Vec;
struct TaskMenu;
struct TaskMenuTmpl;
struct Ctx;
struct Rec;
struct Rec3;
struct Descriptor;
struct Cfg;
struct CharBuf;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct { u16 a, b, c; u8 d, e; } Rect;

typedef struct { u8 v[5]; } B5;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int arr[5];
} Sub_0219728C;

typedef struct {
    u8 pad0[0x10];
    u16 f10;
    u8 pad12[0x26C - 0x12];
    Sub_0219728C sub;
} Obj_0219728C;

typedef struct { u8 v[3]; } B3;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int arr[3];
} Sub_021973A0;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Obj_0219749C {
    u8 pad[0x270];
    void *c[6];
    u32 x288;
    void *b[2];
    void *a[5];
} Obj_0219749C;

typedef struct { u32 w; u16 h; u16 pad; u32 z; } Ent;

typedef struct Obj {
    u8 pad0[0x10];
    u16 x10;
    u8 pad12[0x16];
    u32 x28;
    u8 pad2c[0x294];
    u32 x2c0;
    Ent e[2];
    u32 x2dc;
} Obj;

typedef struct {
    u32 x0;
    u8 x4;
    Ent *x8;
    u32 xc;
    u8 x10;
    u8 x11;
    u8 x12;
    u8 x13;
} Desc;

typedef signed int     s32;

extern void func_02197058(Obj_0219728C *);
extern struct Obj_0219728C *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B92C(struct Obj_0219728C *, unsigned int);
extern void func_0204B3DC(struct Obj_0219728C *, unsigned int);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B3B4(struct Obj_0219749C *p);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern int func_02027CD8(int a0, int a1);
extern void func_02045808(struct U16Vec *vec);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern u32 func_0201CE30(void *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201CE38(void *h);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern int func_02035C60(void);
extern int func_02035C38(void);
extern void func_020061E4(u32 a);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(u32, u32, u32);
extern signed char func_02012FFC(void);
extern u32 func_0201CCE4(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32);
extern void func_02196228(u8 *p, int flag);
extern void func_02041570(int channel, u16 val);
extern void func_02196034(u8 *, void (*)(), u32);
extern void func_021978AC(u8 *a);
extern int func_02012DD0(u8 *p);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_020456F8(struct Descriptor *d);
extern void func_02196A60(u8 *p);
extern void func_02196804(u8 *p);
void func_0219728C(Obj_0219728C *p);
void func_021973A0(Obj_0219728C *p);
void func_0219749C(u8 *a0, u32 a1, u32 a2, u32 a3, u32 a4);
void func_021974A0(Obj_0219749C *o);
void func_02197534(Obj *a);
int func_021975D0(u8 *p);
void func_02197644(u8 *a, u32 b);
void func_02197700(u8 *a);
void func_02197738(u8 *a);
extern const B5 d_021D3FC0;
extern const B5 d_021D3FD0;
extern const B5 d_021D3FB8;
extern const B3 d_021D3F98;
extern const B3 d_021D3FA4;
extern const B3 d_021D3F90;




/*
 * Addresses are Black-image addresses.
 */
void func_0219728C(Obj_0219728C *p)
{
    B5 x0 = d_021D3FC0;
    B5 x1 = d_021D3FD0;
    B5 x2 = d_021D3FB8;
    Rect r;
    int i;

    func_02197058(p);
    for (i = 0; i < 5; i++) {
        r.a = x0.v[i];
        r.b = x1.v[i];
        r.c = x2.v[i];
        r.d = 0;
        r.e = 1;
        p->sub.arr[i] = (int)func_0204B294((void *)p->sub.f0, p->sub.f10, p->sub.f8, p->sub.f18, &r, 1, p->f10);
        func_0204B92C((struct Obj_0219728C *)p->sub.arr[i], 0);
        func_0204B3DC((struct Obj_0219728C *)p->sub.arr[i], 1);
        func_0204B688((struct Actor *)p->sub.arr[i], 1);
    }
}




void func_021973A0(Obj_0219728C *p)
{
    B3 x0 = d_021D3F98;
    B3 x1 = d_021D3FA4;
    B3 x2 = d_021D3F90;
    Rect r;
    int i;

    func_02197058(p);
    for (i = 0; i < 3; i++) {
        r.a = x0.v[i];
        r.b = x1.v[i];
        r.c = x2.v[i];
        r.d = 0;
        r.e = 1;
        p->sub.arr[i] = (int)func_0204B294((void *)p->sub.f0, p->sub.f10, p->sub.f8, p->sub.f18, &r, 1, p->f10);
        func_0204B92C((struct Obj_0219728C *)p->sub.arr[i], 0);
        func_0204B3DC((struct Obj_0219728C *)p->sub.arr[i], 1);
        func_0204B688((struct Actor *)p->sub.arr[i], 1);
    }
}




/*
 * An empty function.
 */
void func_0219749C(u8 *a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
}




void func_021974A0(Obj_0219749C *o)
{
    int i;

    for (i = 0; i < 5; i++) {
        if (o->a[i] != 0) {
            func_0204B3B4(o->a[i]);
            o->a[i] = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        if (o->b[i] != 0) {
            func_0204B3B4(o->b[i]);
            o->b[i] = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        if (o->c[i] != 0) {
            func_0204ADA4((u32)o->c[i]);
        }
    }
    for (; i < 4; i++) {
        if (o->c[i] != 0) {
            func_0204A8D4((u32)o->c[i]);
        }
    }
    for (; i < 6; i++) {
        if (o->c[i] != 0) {
            func_0204AFD8((u32)o->c[i]);
        }
    }
}



void func_02197534(Obj *a)
{
    Desc d;

    d.x0 = a->x10;
    d.x4 = 2;
    d.x8 = a->e;
    d.xc = 1;
    d.x10 = 0x20;
    d.x11 = 0xE;
    d.x12 = 0xD;
    d.x13 = 3;
    a->e[0].w = (u32)func_020457B0(100, a->x10);
    func_02045CAC((struct MsgBank *)a->x28, 26, (void *)a->e[0].w);
    a->e[0].h = 0x39E3;
    a->e[1].w = (u32)func_020457B0(100, a->x10);
    func_02045CAC((struct MsgBank *)a->x28, 27, (void *)a->e[1].w);
    a->e[1].h = 0x39E3;
    a->e[0].z = 0;
    a->e[1].z = 0;
    a->x2c0 = (u32)func_02027778((struct TaskMenuTmpl *)(&d), (void *)a->x2dc);
    func_02027CD8(a->x2c0, 1);
    func_02045808((struct U16Vec *)a->e[0].w);
    func_02045808((struct U16Vec *)a->e[1].w);
}



/*
 * Per-frame poll of the object at +0x2B4; returns 1 when it is absent.
 *
 * Addresses are Black-image addresses.
 */
int func_021975D0(u8 *p)
{
    if (((struct Obj00094 *)p)->f2B4 != 0) {
        if (((struct Obj00094 *)p)->f2B0 != 0)
            func_020286C4(((struct Obj00094 *)p)->f2A8, ((struct Obj00094 *)p)->f2B4, ((struct Obj00094 *)p)->f2B0);
        switch (func_0201CE30(((struct Obj00094 *)p)->f2B4)) {
        case 2:
            func_0201CE48(((struct Obj00094 *)p)->f2B4);
            ((struct Obj00094 *)p)->f2B4 = 0;
            break;
        case 1:
            if (func_02035C60() != 0) {
                func_020061E4(0x547);
                func_0201CE38(((struct Obj00094 *)p)->f2B4);
            }
            break;
        case 0:
            if (func_02035C38() != 0)
                func_0201CE5C(((struct Obj00094 *)p)->f2B4, 0);
            break;
        }
        return 0;
    }
    return 1;
}



void func_02197644(u8 *a, u32 b)
{
    u32 t;

    if (*(u32 *)&((struct Obj00094 *)a)->f2B0 == 0) {
        *(u32 *)&((struct Obj00094 *)a)->f2B0 = func_020450F0(5, 1, 3, 30, 4, 11, 1);
    }
    t = *(u32 *)&((struct Obj00094 *)a)->f2B0;
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)t)), 15);
    func_0201DD78(1, 2, 15);
    if (b == 0) {
        *(u32 *)&((struct Obj00094 *)a)->f2B4 = func_0201CCE4(t, 0, 0, ((struct Obj00094 *)a)->f38, ((struct Obj00094 *)a)->f2C, func_02012FFC(), ((struct Obj00094 *)a)->f2B8, 2, ((struct Obj00094 *)a)->f10, 15);
    } else {
        func_0201C7A4((void *)((u32)func_02045770((struct Descriptor *)t)), 0, 0, (void *)(((struct Obj00094 *)a)->f38), (void *)(((struct Obj00094 *)a)->f2C));
        *(u32 *)&((struct Obj00094 *)a)->f2B4 = 0;
    }
    func_0201F73C((void *)t, 1, (u16)((struct Obj00094 *)a)->f3C, 12);
    func_02045334((struct Descriptor *)t);
    func_02045374((struct Cfg *)t);
    func_02041B6C(5);
}



void func_02197700(u8 *a)
{
    func_02196228(a, 1);
    func_02041570(5, 0);
    func_02045CAC((struct MsgBank *)(((struct Obj00094 *)a)->f28), 25, (void *)(((struct Obj00094 *)a)->f38));
    func_02197644(a, 0);
    func_02196034(a, func_021978AC, 0x761);
}



void func_02197738(u8 *a)
{
    if (func_02012DD0(*(u8 * *)&((struct Obj05989 *)a)->f30) == 2) {
        func_02196228(a, 0);
        func_0201F7A8((void *)(((struct Obj05989 *)a)->f2B0), 2);
        func_020456F8((struct Descriptor *)(((struct Obj05989 *)a)->f2B0));
        func_02041B6C(5);
        if (((struct Obj05989 *)a)->f8 == 1) {
            func_02196034(a, func_02196A60, 0x776);
        } else {
            func_02196034(a, func_02196804, 0x779);
        }
        ((struct Obj05989 *)a)->f2F8 = 1;
    }
}
