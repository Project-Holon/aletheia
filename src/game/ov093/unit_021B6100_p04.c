/*
 * file:     unit_021B6100_p04.c
 * unit:     yes
 * function: func_021B69FC, func_021B6A3C, func_021B6A70, func_021B6AAC, func_021B6C08, func_021B6C5C, func_021B6DD0, func_021B7050, func_021B71D4, func_021B734C, func_021B73C4
 * address:  0x021B69FC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9E38  0x021B9E38  thumb  ov093
 *   func_021B9E7C  0x021B9E7C  thumb  ov093
 *   func_021B6954  0x021B6954  thumb  ov093
 *   func_021EE644 0x021EE644 thumb ov093
 *   func_021CD938 0x021CD938 thumb ov093
 *   func_021E8F20 0x021E8F20 thumb ov093
 *   func_021CD95C 0x021CD95C thumb ov093
 *   func_021B6818 0x021B6818 thumb ov093
 *   func_021B6848 0x021B6848 thumb ov093
 *   func_021B93E0 0x021B93E0 thumb ov093
 *   func_021B9460 0x021B9460 thumb ov093
 *   func_021BA9C8 0x021BA9C8 thumb ov093
 *   func_021CD6F0 0x021CD6F0 thumb ov093
 *   func_021CD978 0x021CD978 thumb ov093
 *   func_021BAA94 0x021BAA94 thumb ov093
 *   func_021BAB40 0x021BAB40 thumb ov093
 *   func_021B83F4 0x021B83F4 thumb ov093
 *   func_021E9034  0x021E9034  thumb  ov093
 *   func_021CD8E0  0x021CD8E0  thumb  ov093
 *   func_021B9674  0x021B9674  thumb  ov093
 *   func_021BAB5C  0x021BAB5C  thumb  ov093
 *   func_021B8B9C 0x021B8B9C thumb ov093
 *   func_021B8B78 0x021B8B78 thumb ov093
 *   func_021B8BEC  0x021B8BEC  thumb  ov093
 *   d_021EFD1C     0x021EFD1C  data  a4
 *   d_021EFD00     0x021EFD00  data  a4
 */
#include "../../matched/include/Obj00661.h"
#include "../../matched/include/Obj06216.h"
#include "../../matched/include/Obj13267.h"
#include "../../matched/include/Obj13268.h"
#include "../../matched/include/Obj01230.h"
#include "../../matched/include/Obj00965.h"
#include "../../matched/include/Obj00886.h"
#include "../../matched/include/Obj02772.h"
#include "../../matched/include/Obj00817.h"
#include "../../matched/include/Obj00887.h"

struct A;
struct B;
struct Scene;
struct QA;
struct Copy24;
struct T;
struct QB;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct S_021B6C08 {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10[4];
    u8 pad20[0xa8];
    u8 fc8[0xe8];
};

struct T_021B734C {
    u8 pad00[0x21];
    u8 f21;
};

struct S_021B734C {
    struct T_021B734C *f00;
    u8 pad04[0x424];
    u8 f428[6];
    u8 pad42e[0x32];
    u32 f460;
    u8 pad464[7];
    u8 f46b;
    u8 f46c;
    u8 f46d;
};

struct T_021B73C4 {
    u8 pad00[0x21];
    u8 f21;
    u8 f22;
};

struct S_021B73C4 {
    struct T_021B73C4 *f00;
    u8 pad04[0x424];
    u8 f428[6];
    u8 pad42e[0x32];
    u32 f460;
    u8 pad464[7];
    u8 f46b;
    u8 f46c;
    u8 f46d;
    u8 pad46e[3];
    u8 f471;
};

extern void func_021B9E38(char *p, int a, int b);
extern void func_021B9E7C(struct A *p, struct B *src);
extern void func_021B6954(int, int);
extern void func_021EE644(void *, int, int);
extern void func_021CD938(u8 *p, void *a);
extern struct Scene *func_021E8F20(void *,void *,u32,int,u16);
extern void func_021CD95C(struct QA *p, u32 v);
extern unsigned int func_021B6818(unsigned int *p);
extern void func_021B6848(u8 *, struct T *);
extern void func_021B93E0(char *, u32, u32);
extern void func_021B9460(char *a, char *b, u8 c);
extern u8 *func_021BA9C8(void *a, struct Copy24 *b, void *c, int d, u16 heap);
extern u8 *func_021CD6F0(u8 *a, u8 *b, int c, int d, u16 idx, u16 kind, u8 e, int f, int g, struct Copy24 *h, u16 heap);
extern u32 func_021CD978(struct QB *p);
extern void func_021BAA94(char *p, int b, u8 c, u8 d);
extern void func_021BAB40(char *p);
extern int func_021B83F4(int a);
extern void func_021E9034(char *p);
extern void func_021CD8E0(u8 *p);
extern void func_021B9674(char *p);
extern void func_021BAB5C(int a);
extern int func_021B8B9C(unsigned char *p, unsigned char k);
extern unsigned int func_021B8B78(unsigned char *p, int k);
extern u8 func_021B8BEC(u8 *p, u32 k, u8 n);
void func_021B69FC(int a, char *b);
void func_021B6A3C(unsigned char *p, unsigned char *q);
void func_021B6A70(unsigned char *p,unsigned char *q,int r);
int func_021B6AAC(int unused, u8 *p);
int func_021B6C08(int a0, struct S_021B6C08 *s);
int func_021B6C5C(int unused, u8 *p);
int func_021B6DD0(int unused, u8 *p);
int func_021B7050(int unused, u8 *p);
int func_021B71D4(int unused, u8 *p);
int func_021B734C(u32 *pp, struct S_021B734C *s);
int func_021B73C4(u32 *pp, struct S_021B73C4 *s);


void func_021B69FC(int a, char *b)
{
    if (((struct Obj00661 *)b)->f23 == 0) {
        func_021B9E38((char *)(a + 0x20), ((struct Obj06216 *)a)->f468, ((struct Obj06216 *)a)->fC0);
        func_021B9E7C((struct A *)(a + 0x48), (struct B *)(((struct Obj00661 *)b)->f4C));
    } else {
        func_021B6954(a, 0);
        func_021B6954(a, 1);
    }
}

void func_021B6A3C(unsigned char *p, unsigned char *q) { if(q[0x23]) { func_021EE644(p+0x2c8, ((struct Obj00661 *)q)->f94, ((struct Obj00661 *)q)->f98); func_021CD938(((struct Obj13267 *)p)->f10,p+0x2c8); func_021CD938(((struct Obj13267 *)p)->f14,p+0x2c8); } }

/*
 * extent: final two zero bytes are alignment padding before the next labelled function.
 */
void func_021B6A70(unsigned char *p,unsigned char *q,int r) { void *v; struct Scene *s; if(q[0x23]) v=*(void **)(p+0x10+q[0x21]*4); else v=((struct Obj13268 *)p)->f10; s=func_021E8F20(p,v,(u32)(p+0xc8),r,0x13); *(struct Scene * *)&((struct Obj13268 *)p)->f4=s; func_021CD95C(v,(u32)s); }

int func_021B6AAC(int unused, u8 *p)
{
    u8 *q;
    int t;
    q = *(u8 * *)&((struct Obj01230 *)p)->f0;
    t = func_021B6818((unsigned int *)q);
    p[0x46b] = 2;
    p[0x428] = 0;
    p[0x429] = 1;
    func_021B6848(p, (struct T *)q);
    func_021B93E0((char *)p + 0xc8, (u32)p, 0);
    func_021B9460((char *)(p + 0xc8), (char *)p, 0);
    func_021B9460((char *)(p + 0xc8), (char *)p, 1);
    func_021B93E0((char *)p + 0x1b0, (u32)p, 1);
    func_021B9460((char *)(p + 0x1b0), (char *)p, 0);
    func_021B9460((char *)(p + 0x1b0), (char *)p, 1);
    ((struct Obj01230 *)p)->f8 = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, ((struct Obj01230 *)p)->f468);
    p[0x46e] = 1;
    func_021B69FC((int)p, (char *)q);
    ((struct Obj01230 *)p)->f10 = (int)func_021CD6F0(p, p + 0xc8, 0, ((struct Obj00661 *)q)->f1C, 0, 1, 0, t, q[0x23], (struct Copy24 *)(p + 0x3f0), ((struct Obj01230 *)p)->f468);
    ((struct Obj01230 *)p)->f14 = (int)func_021CD6F0(p, p + 0xc8, 0, ((struct Obj00661 *)q)->f1C, 1, 1, 1, t, q[0x23], (struct Copy24 *)(p + 0x3f0), ((struct Obj01230 *)p)->f468);
    func_021B6A3C(p, q);
    func_021B6A70(p, q, t);
    func_021BAA94((char *)(((struct Obj01230 *)p)->f8), func_021CD978((struct QB *)(((struct Obj01230 *)p)->f10)), 0, 1);
    func_021BAA94((char *)(((struct Obj01230 *)p)->f8), func_021CD978((struct QB *)(((struct Obj01230 *)p)->f14)), 1, 1);
    func_021BAB40((char *)(((struct Obj01230 *)p)->f8));
    ((struct Obj01230 *)p)->f464 = (u32)func_021B83F4;
    return 1;
}


int func_021B6C08(int a0, struct S_021B6C08 *s)
{
    u32 i;

    if (s->f04 != 0) {
        func_021E9034((char *)s->f04);
        s->f04 = 0;
    }
    for (i = 0; i < 4; i++) {
        if (s->f10[i] != 0) {
            func_021CD8E0((u8 *)s->f10[i]);
        }
    }
    func_021B9674((char *)((u8 *)s + 0xc8));
    func_021B9674((char *)((u8 *)s + 0x1b0));
    if (s->f08 != 0) {
        func_021BAB5C(s->f08);
    }
    if (s->f0c != 0) {
        func_021BAB5C(s->f0c);
    }
    return 1;
}

int func_021B6C5C(int unused, u8 *p)
{
    u8 *q;
    int t;
    q = *(u8 * *)&((struct Obj00965 *)p)->f0;
    t = func_021B6818((unsigned int *)q);
    p[0x46c] = 0;
    p[0x46b] = 2;
    p[0x428] = 0;
    p[0x429] = 1;
    p[0x42a] = 0;
    p[0x42b] = 1;
    func_021B6848(p, (struct T *)q);
    func_021B93E0((char *)p + 0xc8, (u32)p, 0);
    func_021B9460((char *)(p + 0xc8), (char *)p, 0);
    func_021B9460((char *)(p + 0xc8), (char *)p, 1);
    func_021B93E0((char *)p + 0x1b0, (u32)p, 1);
    func_021B9460((char *)(p + 0x1b0), (char *)p, 0);
    func_021B9460((char *)(p + 0x1b0), (char *)p, 1);
    func_021B69FC((int)p, (char *)q);
    ((struct Obj00965 *)p)->f8 = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, ((struct Obj00965 *)p)->f468);
    p[0x46e] = 1;
    ((struct Obj00965 *)p)->f10 = (int)func_021CD6F0(p, p + 0xc8, 0, ((struct Obj00661 *)q)->f1C, 0, 2, 0, t, q[0x23], (struct Copy24 *)(p + 0x3f0), ((struct Obj00965 *)p)->f468);
    ((struct Obj00965 *)p)->f14 = (int)func_021CD6F0(p, p + 0xc8, 0, ((struct Obj00661 *)q)->f1C, 1, 2, 1, t, q[0x23], (struct Copy24 *)(p + 0x3f0), ((struct Obj00965 *)p)->f468);
    func_021B6A3C(p, q);
    func_021B6A70(p, q, t);
    func_021BAA94((char *)(((struct Obj00965 *)p)->f8), func_021CD978((struct QB *)(((struct Obj00965 *)p)->f10)), 0, 2);
    func_021BAA94((char *)(((struct Obj00965 *)p)->f8), func_021CD978((struct QB *)(((struct Obj00965 *)p)->f14)), 1, 2);
    func_021BAB40((char *)(((struct Obj00965 *)p)->f8));
    ((struct Obj00965 *)p)->f464 = (u32)func_021B83F4;
    return 1;
}

/*
 * lever: the boolean passed narrow is an int local; t declared after desc puts t at sp+0x1c.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`desc = p;` before `desc = p + 0xc8;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 */
int func_021B6DD0(int unused, u8 *p)
{
    u8 *q;
    int i;
    u8 k;
    int b;
    u8 *desc;
    u8 *table;
    int t;
    q = *(u8 * *)&((struct Obj00886 *)p)->f0;
    t = (int)func_021B6818((unsigned int *)q);
    p[0x46c] = 0;
    p[0x46b] = 2;
    p[0x428] = 0;
    p[0x42a] = 0;
    p[0x429] = 1;
    p[0x42b] = 1;
    switch (q[0x22]) {
    case 0: break;
    case 1: case 2: case 3:
        p[0x42a] = 2;
        p[0x42b] = 3;
        p[0x46b] = 4;
        break;
    case 4:
        p[0x42b] = 3;
        p[0x46b] = 3;
        break;
    }
    func_021B6848(p, (struct T *)q);
    func_021B93E0((char *)p + 0xc8, (u32)p, 0);
    func_021B93E0((char *)p + 0x1b0, (u32)p, 1);
    for (i = 0; i < 4; i++) {
        if (func_021B8B9C(p, i)) {
            func_021B9460((char *)(p + 0xc8), (char *)p, i);
            func_021B9460((char *)(p + 0x1b0), (char *)p, i);
        }
    }
    if (!q[0x23]) {
        func_021B9E38((char *)((int)(p + 0x20)), ((struct Obj00886 *)p)->f468, ((struct Obj00886 *)p)->fC0);
        func_021B9E7C((struct A *)((int)(p + 0x48)), (struct B *)(((struct Obj02772 *)q)->f4C));
        if (func_021B8B9C(p, 2)) func_021B9E7C((struct A *)((int)(p + 0x70)), (struct B *)(((struct Obj02772 *)q)->f50));
        if (func_021B8B9C(p, 3)) func_021B9E7C((struct A *)((int)(p + 0x98)), (struct B *)(((struct Obj02772 *)q)->f54));
    } else {
        for (i = 0; i < 4; i++) {
            if (func_021B8B9C(p, i)) func_021B6954((int)p, (u8)i);
        }
    }
    ((struct Obj00886 *)p)->f8 = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, ((struct Obj00886 *)p)->f468);
    p[0x46e] = 1;
    table = p + 0x3f0;
    desc = p + 0xc8;
    for (i = 0; i < 4; i++) {
        if (func_021B8B9C(p, i)) {
            k = func_021B8B78(p, (unsigned char)i);
            b = 0;
            if (i != 0) b = 1;
            *(int *)(p + i * 4 + 0x10) = (int)func_021CD6F0(p, desc, 0, ((struct Obj02772 *)q)->f1C, i, (u8)k, b, t, (u8)q[0x23], (struct Copy24 *)table, ((struct Obj00886 *)p)->f468);
        }
    }
    if (q[0x23]) {
        func_021EE644(p + 0x2c8, ((struct Obj02772 *)q)->f94, ((struct Obj02772 *)q)->f98);
        for (i = 0; i < 4; i++) {
            if (func_021B8B9C(p, i)) func_021CD938((u8 *)(*(int *)(p + i * 4 + 0x10)), p + 0x2c8);
        }
    }
    func_021B6A70(p, q, t);
    for (i = 0; i < 4; i++) {
        if (func_021B8B9C(p, i)) {
            k = func_021B8B78(p, (unsigned char)i);
            func_021BAA94((char *)(((struct Obj00886 *)p)->f8), func_021CD978((struct QB *)(*(int *)(p + i * 4 + 0x10))), i, k);
        }
    }
    func_021BAB40((char *)(((struct Obj00886 *)p)->f8));
    ((struct Obj00886 *)p)->f464 = (u32)func_021B83F4;
    return 1;
}

int func_021B7050(int unused, u8 *p)
{
    u8 *q;
    int t;
    q = *(u8 * *)&((struct Obj00817 *)p)->f0;
    t = func_021B6818((unsigned int *)q);
    p[0x46b] = 2;
    p[0x46e] = 1;
    p[0x428] = 0;
    p[0x429] = 1;
    p[0x42a] = 0;
    p[0x42b] = 1;
    p[0x42c] = 0;
    p[0x42d] = 1;
    func_021B6848(p, (struct T *)q);
    func_021B93E0((char *)p + 0xc8, (u32)p, 0);
    func_021B9460((char *)(p + 0xc8), (char *)p, 0);
    func_021B9460((char *)(p + 0xc8), (char *)p, 1);
    func_021B93E0((char *)p + 0x1b0, (u32)p, 1);
    func_021B9460((char *)(p + 0x1b0), (char *)p, 0);
    func_021B9460((char *)(p + 0x1b0), (char *)p, 1);
    func_021B69FC((int)p, (char *)q);
    ((struct Obj00817 *)p)->f8 = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, ((struct Obj00817 *)p)->f468);
    p[0x46e] = 1;
    ((struct Obj00817 *)p)->f10 = (int)func_021CD6F0(p, p + 0xc8, 0, ((struct Obj00661 *)q)->f1C, 0, 3, 0, t, q[0x23], (struct Copy24 *)(p + 0x3f0), ((struct Obj00817 *)p)->f468);
    ((struct Obj00817 *)p)->f14 = (int)func_021CD6F0(p, p + 0xc8, 0, ((struct Obj00661 *)q)->f1C, 1, 3, 1, t, q[0x23], (struct Copy24 *)(p + 0x3f0), ((struct Obj00817 *)p)->f468);
    func_021B6A3C(p, q);
    func_021B6A70(p, q, t);
    func_021BAA94((char *)(((struct Obj00817 *)p)->f8), func_021CD978((struct QB *)(((struct Obj00817 *)p)->f10)), 0, 3);
    func_021BAA94((char *)(((struct Obj00817 *)p)->f8), func_021CD978((struct QB *)(((struct Obj00817 *)p)->f14)), 1, 3);
    func_021BAB40((char *)(((struct Obj00817 *)p)->f8));
    ((struct Obj00817 *)p)->f464 = (u32)func_021B83F4;
    return 1;
}

int func_021B71D4(int unused, u8 *p)
{
    u8 *q;
    int t;
    q = *(u8 * *)&((struct Obj00887 *)p)->f0;
    t = func_021B6818((unsigned int *)q);
    p[0x46b] = 2;
    p[0x428] = 0;
    p[0x429] = 1;
    p[0x42a] = 0;
    p[0x42b] = 1;
    p[0x42c] = 0;
    p[0x42d] = 1;
    func_021B6848(p, (struct T *)q);
    func_021B93E0((char *)p + 0xc8, (u32)p, 0);
    func_021B9460((char *)(p + 0xc8), (char *)p, 0);
    func_021B9460((char *)(p + 0xc8), (char *)p, 1);
    func_021B93E0((char *)p + 0x1b0, (u32)p, 1);
    func_021B9460((char *)(p + 0x1b0), (char *)p, 0);
    func_021B9460((char *)(p + 0x1b0), (char *)p, 1);
    ((struct Obj00887 *)p)->f8 = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, ((struct Obj00887 *)p)->f468);
    p[0x46e] = 1;
    func_021B69FC((int)p, (char *)q);
    ((struct Obj00887 *)p)->f10 = (int)func_021CD6F0(p, p + 0xc8, 0, ((struct Obj00661 *)q)->f1C, 0, 1, 0, t, q[0x23], (struct Copy24 *)(p + 0x3f0), ((struct Obj00887 *)p)->f468);
    ((struct Obj00887 *)p)->f14 = (int)func_021CD6F0(p, p + 0xc8, 0, ((struct Obj00661 *)q)->f1C, 1, 1, 1, t, q[0x23], (struct Copy24 *)(p + 0x3f0), ((struct Obj00887 *)p)->f468);
    func_021B6A3C(p, q);
    func_021B6A70(p, q, t);
    func_021BAA94((char *)(((struct Obj00887 *)p)->f8), func_021CD978((struct QB *)(((struct Obj00887 *)p)->f10)), 0, 1);
    func_021BAA94((char *)(((struct Obj00887 *)p)->f8), func_021CD978((struct QB *)(((struct Obj00887 *)p)->f14)), 1, 1);
    func_021BAB40((char *)(((struct Obj00887 *)p)->f8));
    ((struct Obj00887 *)p)->f464 = (u32)func_021B83F4;
    return 1;
}

extern int (*d_021EFD1C[7])(struct S_021B734C *, u32 *);


int func_021B734C(u32 *pp, struct S_021B734C *s)
{
    if (*pp == 0) {
        s->f46b = 2;
        s->f428[0] = 0;
        s->f428[1] = 1;
        s->f46c = s->f00->f21;
        s->f46d = func_021B8BEC((u8 *)s, s->f46c, 0);
        *pp = *pp + 1;
        return 0;
    }
    if (*pp < 7) {
        if (d_021EFD1C[*pp](s, &s->f460) != 0) {
            s->f460 = 0;
            *pp = *pp + 1;
        }
        return 0;
    }
    return 1;
}

extern int (*d_021EFD00[7])(struct S_021B73C4 *, u32 *);


int func_021B73C4(u32 *pp, struct S_021B73C4 *s)
{
    if (*pp == 0) {
        switch (s->f00->f22) {
        case 0:
        default:
            s->f46b = 2;
            s->f428[0] = 0;
            s->f428[1] = 1;
            s->f428[2] = 0;
            s->f428[3] = 1;
            break;
        case 2:
            s->f471 = 2;
        case 1:
            s->f46b = 4;
            s->f428[0] = 0;
            s->f428[1] = 1;
            s->f428[2] = 2;
            s->f428[3] = 3;
            break;
        }
        s->f46c = s->f00->f21;
        s->f46d = func_021B8BEC((u8 *)s, s->f46c, 0);
        *pp = *pp + 1;
        return 0;
    }
    if (*pp < 7) {
        if (d_021EFD00[*pp](s, &s->f460) != 0) {
            s->f460 = 0;
            *pp = *pp + 1;
        }
        return 0;
    }
    return 1;
}
