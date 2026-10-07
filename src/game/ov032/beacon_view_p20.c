/*
 * file:     beacon_view_p20.c
 * unit:     yes
 * function: func_021F31A8, func_021F3214, func_021F3264, func_021F32D4, func_021F32F8
 * address:  0x021F31A8
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204BA20 0x0204BA20 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   d_021F35F0 0x021F35F0 data ov032 a2
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_02043678  0x02043678  arm
 *   func_020255A0  0x020255A0  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_020257D0  0x020257D0  thumb
 *   func_02025774  0x02025774  thumb
 */
#include "../../matched/include/Obj13068.h"
#include "../../matched/include/Obj13069.h"
#include "../../matched/include/Obj00007.h"

struct Actor;
struct Obj;
struct Grid;
struct Param;
struct Sys;
struct Bmp;
struct CharBuf;
struct U16Vec;
typedef unsigned int   u32;

typedef struct {
    unsigned n0;
    unsigned *a0;
    unsigned n1;
    unsigned *a1;
    unsigned n2;
    unsigned *a2;
} T;

typedef struct {
    short x;
    short y;
    unsigned short w;
    unsigned char z;
    unsigned char h;
} Rect;

typedef struct {
    short x;
    short y;
} Pt;

typedef struct {
    char pad[0x138];
    unsigned *a;        /* 0x138 */
    int pad2;
    unsigned *b;        /* 0x140 */
    int pad3;
    unsigned *c;        /* 0x148 */
    char pad4[0x2BC - 0x14C];
    void *o[6];         /* 0x2BC */
} S;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef short          s16;

typedef struct {
    u8 f00;
    u8 f01;
    u8 f02;
    u8 pad03[5];
    s16 x;
    s16 y;
    void *f0c;
    void *f10;
    void *f14;
    void *f18;
    void *f1c;
    void *f20;
    void *f24;
    u32 f28;
    u8 pad2c[8];
} Rec;

typedef struct {
    void *bmp;
    s16 x;
    s16 y;
    u32 f08;
    u32 f0c;
    u8 f10;
    u8 f11;
    u16 f12;
    u32 f14;
} Tmpl;

extern void func_0204AFD8(unsigned);
extern void func_0204A8D4(unsigned);
extern void func_0204ADA4(unsigned);
extern u32 func_020307B0(void *p);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204BA20(struct Actor *a, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B3B4(struct Obj *);
extern void func_02082BCC(void *p, int v, int n);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern struct Grid *func_020255A0(struct Sys *sys, const struct Param *param);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_020257D0(struct Obj *o);
extern void func_02025774(u8 *g, u32 a);
void func_021F31A8(void *unused, T *p);
void *func_021F3214(char *p, unsigned a, unsigned b, unsigned c, short x, short y, unsigned char w, unsigned char h, unsigned char z);
void func_021F3264(S *p);
void func_021F32D4(char *p);
void func_021F32F8(char *p, u8 idx);
extern Pt d_021F35F0[];


void func_021F31A8(void *unused, T *p)
{
    unsigned i;
    int j;
    for (i = 0; i < p->n2; i++)
        func_0204AFD8(p->a2[i]);
    for (i = 0; i < p->n1; i++)
        func_0204A8D4(p->a1[i]);
    for (i = 0; i < p->n0; i++)
        func_0204ADA4(p->a0[i]);
    for (j = 0; j < 3; j++) {
        if (((unsigned *)p)[j * 2 + 1] != 0)
            func_020307B0((void *)(((unsigned *)p)[j * 2 + 1]));
    }
}


void *func_021F3214(char *p, unsigned a, unsigned b, unsigned c, short x, short y, unsigned char w, unsigned char h, unsigned char z)
{
    Rect r;
    void *res;
    r.x = x;
    r.y = y;
    r.w = w;
    r.h = h;
    r.z = z;
    res = func_0204B294((void *)((struct Obj13068 *)p)->f128, a, b, c, &r, 0, ((struct Obj13068 *)p)->f94);
    func_0204B92C(res, 1);
    func_0204BA20(res, 0);
    return res;
}


/*
 * note:     the object array at +0x2BC must be a struct array member: raw
 *           (p + i * 4) arithmetic schedules p+i*4 ahead of &d[i] (2-byte DIFF).
 */
void func_021F3264(S *p)
{
    int i;
    for (i = 0; i < 6; i++) {
        p->o[i] = func_021F3214((char *)p, *p->b, *p->a, *p->c, d_021F35F0[i].x, d_021F35F0[i].y, i * 3 + 1, 1, 1);
        func_0204B3DC(p->o[i], 1);
    }
}

void func_021F32D4(char *p)
{
    int i;
    char *q;
    for (i = 0; i < 6; i++) {
        q = p + i * 4;
        func_0204B3DC(*(struct Obj * *)&((struct Obj13069 *)q)->f2BC, 0);
        func_0204B3B4(*(struct Obj * *)&((struct Obj13069 *)q)->f2BC);
    }
}


/*
 * Builds the 0x34-byte record at +0x1B8 that func_021F34C8 tears down.
 */
void func_021F32F8(char *p, u8 idx)
{
    Rec *r;
    Tmpl t;

    r = (Rec *)(p + 0x1b8 + idx * 0x34);
    func_02082BCC(r, 0, 0x34);
    r->f00 = idx;
    r->f01 = 0xff;
    r->f02 = 0;
    r->f28 = ((struct Obj00007 *)p)->fB4;
    r->x = idx * 13;
    r->y = idx * 0x28;
    r->f0c = func_021F3214(p, **(u32 * *)&((struct Obj00007 *)p)->f140, **(u32 * *)&((struct Obj00007 *)p)->f138, **(u32 * *)&((struct Obj00007 *)p)->f148,
                           r->x, r->y, 0, 3, idx + 0x14);
    func_0204B6F4(r->f0c, (u8)idx, 0);
    r->f10 = func_021F3214(p, (*(u32 **)(p + 0x158))[idx], **(u32 * *)&((struct Obj00007 *)p)->f138, **(u32 * *)&((struct Obj00007 *)p)->f160,
                           r->x + 0x20, r->y + 0x18, 0, 3, idx + 10);
    func_0204B6F4(r->f10, (u8)(idx + 9), 1);
    r->f14 = func_021F3214(p, (*(u32 **)(p + 0x170))[idx], **(u32 * *)&((struct Obj00007 *)p)->f138, **(u32 * *)&((struct Obj00007 *)p)->f178,
                           r->x + 0x3c, r->y + 0x18, 0, 3, idx + 5);
    r->f1c = func_02043678(0xc, 2, 0x20, ((struct Obj00007 *)p)->f98);
    t.bmp = r->f1c;
    t.x = r->x + 0x48;
    t.y = r->y + 0x10;
    t.f08 = **(u32 * *)&((struct Obj00007 *)p)->f138;
    t.f0c = 3;
    t.f10 = 0;
    t.f11 = 3;
    t.f12 = 0;
    t.f14 = 1;
    r->f18 = func_020255A0(((struct Obj00007 *)p)->f124, (const struct Param *)(&t));
    r->f20 = func_020457B0(0xb, ((struct Obj00007 *)p)->f98);
    r->f24 = func_020457B0(8, ((struct Obj00007 *)p)->f98);
    func_02043B5C(r->f1c, 0);
    func_020257D0(r->f18);
    func_02025774(r->f18, 0);
    func_0204B3DC(r->f0c, 0);
    func_0204B3DC(r->f10, 0);
    func_0204B3DC(r->f14, 0);
}
