/*
 * file:     fldeff_namipoke_p01.c
 * unit:     yes
 * function: func_021AC810, func_021AC8E4, func_021AC900, func_021AC9D4, func_021AC9D8, func_021ACA38, func_021ACA5C, func_021ACA70, func_021ACB0C, func_021ACB38, func_021ACBB8, func_021ACBC8, func_021ACBE4, func_021ACC04, func_021ACC3C, func_021ACCAC, func_021ACCB0
 * address:  0x021AC810
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
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_02050340  0x02050340  arm
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_02050804  0x02050804  arm
 *   func_0205082C  0x0205082C  arm
 *   func_020507F0  0x020507F0  arm
 *   func_021AC1A0  0x021AC1A0  thumb  ov021
 *   func_021AC178  0x021AC178  thumb  ov021
 *   d_021DE050     0x021DE050  data  a4
 *   func_0216E1C4  0x0216E1C4  thumb  ov010
 *   func_0216D608  0x0216D608  thumb  ov010
 *   func_020508EC  0x020508EC  arm
 *   func_0205085C  0x0205085C  arm
 *   d_021D90C0     0x021D90C0  data
 *   d_021D90C8     0x021D90C8  data  a2
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 *   d_021DE080  0x021DE080  data
 *   func_020307B0  0x020307B0  arm
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_021C6AE0  0x021C6AE0  thumb  ov021
 *   func_021C6AF0  0x021C6AF0  thumb  ov021
 *   func_021C6AF8  0x021C6AF8  thumb  ov021
 *   func_021C6AFC  0x021C6AFC  thumb  ov021
 *   func_021C6574  0x021C6574  thumb  ov021
 *   func_021C6590  0x021C6590  thumb  ov021
 *   func_021C67D8  0x021C67D8  thumb  ov021
 *   func_021C6580  0x021C6580  thumb  ov021
 *   func_021C6628  0x021C6628  thumb  ov021
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216D590  0x0216D590  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021D915C     0x021D915C  data  a4
 *   d_021D9184     0x021D9184  data  a4
 *   func_021AC1E0  0x021AC1E0  thumb  ov021
 *   d_021D9198     0x021D9198  data  a2
 *   func_021C6658  0x021C6658  thumb  ov021
 *   func_020520FC  0x020520FC  arm
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   d_021D91C8     0x021D91C8  data  a4
 *   d_021D91B0     0x021D91B0  data  a2
 *   func_021C6678  0x021C6678  thumb  ov021
 */
#include "../../matched/include/Obj19872.h"
#include "../../matched/include/Obj05039.h"
#include "../../matched/include/Obj19874.h"

struct BbActDesc;
struct BbActSys;
struct X;
struct Mtx33;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct V3_021AC810 { int x, y, z; } V3_021AC810;

typedef struct Blk_021AC810 { u32 w[9]; } Blk_021AC810;

typedef struct Desc {
    u16 slot;
    u16 v12;
    u16 v14;
    u8 k;
    u8 pad;
    u32 flag;
    u32 w;
    V3_021AC810 pos;
    void (*f1c)(void);
    u32 f20;
} Desc;

typedef struct B_021AC810 {
    u32 f0;
    Blk_021AC810 blk;
    u16 f28[4];
    u16 f30;
} B_021AC810;

typedef signed short   s16;

typedef signed char    s8;

typedef struct P { u32 f0; u32 f4; u32 f8; } P;

typedef signed int     s32_021ACA5C;

typedef struct X { u32 f0; u16 h4; u16 h6; u16 h8; u16 ha; } X;

typedef int            s32_021ACB38;

typedef struct Vec3 { s32_021ACB38 x, y, z; } Vec3;

typedef struct Arg { u32 a; u32 b; u16 c, d, e; } Arg;

typedef struct E { int f0; int f4; int f8; } E;

typedef struct Blk_021AC9D8 { u32 w[7]; } Blk_021AC9D8;

typedef struct Inner_021AC810 { u16 a; u16 b; u8 pad[0x18]; u16 c; u16 pad2; u32 d, e, f; } Inner_021AC810;

typedef struct B_021AC9D8 {
    u8 pad0[9];
    u8 f9;
    u8 pad1[2];
    u16 fc;
    u8 pad2[2];
    u32 f10;
    u32 f14;
    u16 f18;
    u8 pad3[2];
    Blk_021AC9D8 blk;
    Inner_021AC810 in;
} B_021AC9D8;

typedef int            s32;

typedef struct V3_021ACCB0 { s32 x, y, z; } V3_021ACCB0;

typedef struct Ang { u16 x, y, z; } Ang;

typedef struct AngTbl { Ang e[4]; } AngTbl;

typedef struct PosTbl { V3_021ACCB0 e[4]; } PosTbl;

typedef struct Node {
    V3_021ACCB0 pos;
    V3_021ACCB0 scale;
    u8 mtx[0x24];
} Node;

typedef struct Inner_021ACCB0 {
    u16 a;
    u16 b;
    u8 pad[0x18];
    u16 c;
    u16 pad2;
    V3_021ACCB0 scale;
    V3_021ACCB0 pos;
} Inner_021ACCB0;

typedef struct B {
    u8 pad0[0xc];
    u16 fc;
    u8 pad1[0xa];
    u16 f18;
    u8 pad2[2];
    u32 *f1c;
    u8 pad3[0x18];
    Inner_021ACCB0 in;
} B;

extern int func_021AC1AC(u32 a);
extern int func_0216E1A4(int a0, int a1);
extern void func_021AC1CC(u32 a, u8 *b);
extern u16 func_02050340(struct BbActSys *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode);
extern void func_021AC154(u32 a);
extern void func_02050804(void *p, int idx, u32 v, u16 h);
extern void func_0205082C(void *p, int idx, u32 h);
extern void func_020507F0(void *p, int idx, u32 v);
extern int func_021AC1A0(u32 a);
extern void func_021AC178(u32 a);
extern void func_02050468(struct BbActSys *o, u16 first, u32 count);
extern int func_0216E1C4(int a0, int a1);
extern u16 func_0216D608(void *p);
extern u32 func_020508EC(u8 *p, int i, u16 *out);
extern void func_0205085C(void *p, int idx, u32 v);
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
extern int func_0216D804(void *p);
extern int func_0216D81C(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u32 func_021ABE18(u8 *p);
extern u32 func_021ABE24(u8 *p);
extern void func_021C6AE0(u32 a);
extern int func_021C6AF0(u32 a, u32 b, u32 c);
extern void func_021C6AF8(u32 *p, u32 v);
extern void func_021C6AFC(u32 *a, u32 b);
extern int func_021C6574(u32 a, u32 b, u32 c);
extern u32 func_021C6590(u32 a, u32 b, u32 c, u32 d);
extern void func_021C67D8(u32 a, u32 b, u32 c);
extern void func_021C6628(u32 a, u32 b);
extern void func_021C6580(u8 *p, int i);
extern int func_021ABEA0(u32 a, u32 b);
extern u16 func_0216D588(void *p);
extern u16 func_0216D590(void *p);
extern int func_0216D55C(int a0, int a1);
extern void func_021ABFA8(u32 a, u8 *b, Vec3 *c, u32 d, Arg *e, u32 f);
extern int func_021AC1E0(u32 a);
extern int func_021C6658(u32 a, u32 b);
extern void func_020520FC(int ax, int ay, int az, struct Mtx33 *dst);
extern void func_021AC1B8(u32 a, Node *n);
extern void func_021C6678(u32 a, u32 b, u32 c);
void func_021AC810(u32 a, B_021AC810 *b);
void func_021AC8E4(u32 a, B_021AC810 *b);
void func_021AC900(u32 a, B_021AC810 *b);
void func_021AC9D4(void);
int func_021AC9D8(u8 *p);
P *func_021ACA38(u32 a, int heap);
void func_021ACA5C(u32 a, u8 *p);
void func_021ACA70(u32 *a);
void func_021ACB0C(X *x);
void func_021ACB38(u32 a, u32 b, Vec3 *c, u32 d, u32 e);
void func_021ACBB8(u32 a, u8 v);
void func_021ACBC8(u32 a, int v);
int func_021ACBE4(int n);
int func_021ACC04(E *a, E *b, u32 mode);
void func_021ACC3C(u32 a, B_021AC9D8 *b);
void func_021ACCAC(void);
void func_021ACCB0(u32 a, B *b);
extern u32 d_021DE050[];
extern u8 d_021D90C0[];
extern u16 d_021D90C8[];
extern char d_021DE080[];
extern u8 d_021D915C[];
extern u8 d_021D9184[];
extern AngTbl d_021D9198;
extern PosTbl d_021D91C8;
extern AngTbl d_021D91B0;







/*
 * Addresses are Black-image addresses.
 */
void func_021AC810(u32 a, B_021AC810 *b)
{
    u8 *p = (u8 *)func_021AC1AC(a);
    Desc s;
    u16 idx;
    u32 h;
    u16 r;

    b->blk = *(Blk_021AC810 *)p;
    func_0216E1A4(((struct Obj19872 *)p)->f4, (int)b->f28);
    func_021AC1CC(a, p + 0x14);
    idx = b->blk.w[8];
    s.slot = *(u16 *)(b->blk.w[0] + idx * 2 + 8);
    s.v12 = 0x2000;
    s.v14 = 0x2000;
    s.k = 0x1f;
    s.flag = 1;
    s.w = 1;
    s.pos = *(V3_021AC810 *)(p + 0x14);
    s.f1c = 0;
    s.f20 = (u32)b;
    h = *(u32 *)(b->blk.w[0] + 4);
    b->f30 = func_02050340((struct BbActSys *)h, 0, (const struct BbActDesc *)(&s), 1, 0);
    if (b->f30 == 0xFFFF) {
        func_021AC154(a);
        return;
    }
    func_02050804((void *)h, b->f30, d_021DE050[idx], 1);
    r = b->f30;
    func_0205082C((void *)h, r, 0);
    func_020507F0((void *)h, r, 1);
    if (func_021AC1A0(a) == 0)
        b->f0 = 1;
    func_021AC178(a);
}







void func_021AC8E4(u32 a, B_021AC810 *b)
{
    u32 h = *(u32 *)(b->blk.w[0] + 4);

    if (b->f30 != 0xFFFF)
        func_02050468((struct BbActSys *)h, b->f30, 1);
}






/*
 * Compiled 212 of a 216-byte extent: the follower at 0x021AC9D4 is an
 * unlabelled `bx lr` stub.
 *
 * Addresses are Black-image addresses.
 */
void func_021AC900(u32 a, B_021AC810 *b)
{
    u32 h = *(u32 *)(b->blk.w[0] + 4);
    u32 m;
    u16 tmp;

    switch (b->f0) {
    case 0:
        if (d_021D90C0[b->blk.w[8]] == 1) {
            m = b->blk.w[1];
            if (func_0216E1C4(m, (int)b->f28) == 1 && func_021AC9D8((u8 *)b) == 0 && func_0216D608((void *)m) == 1) {
                func_021AC154(a);
                return;
            }
        }
        if (func_020508EC((u8 *)h, b->f30, &tmp) != 0)
            b->f0++;
        break;
    case 1:
        if (func_0216E1C4(b->blk.w[1], (int)b->f28) == 0) {
            func_021AC154(a);
            return;
        }
        func_0205085C((void *)h, b->f30, d_021D90C8[b->blk.w[8]]);
        b->f0++;
        break;
    case 2:
        b->f0++;
    case 3:
        if (func_0216E1C4(b->blk.w[1], (int)b->f28) == 0) {
            func_021AC154(a);
            return;
        }
        if (func_021AC9D8((u8 *)b) == 0)
            func_021AC154(a);
        break;
    }
}




void func_021AC9D4(void) {}








int func_021AC9D8(u8 *p)
{
    u32 a = ((struct Obj05039 *)p)->f8;
    u32 x = func_0216D83C((void *)a);
    u32 y = func_0216D86C((void *)a);
    u32 f = d_021D90C0[((struct Obj05039 *)p)->f24];
    if (((struct Obj05039 *)p)->fC == x && ((struct Obj05039 *)p)->f10 == y)
        goto yes;
    if (f == 0 && func_0216D608((void *)a) == 0) {
        x = func_0216D804((void *)a);
        y = func_0216D81C((void *)a);
        if (((struct Obj05039 *)p)->fC == x && ((struct Obj05039 *)p)->f10 == y)
            return 1;
    }
    return 0;
yes:
    return 1;
}








P *func_021ACA38(u32 a, int heap)
{
    P *p;

    p = (P *)func_02030734(heap, 0xc, 1, d_021DE080, 0xac);
    p->f0 = a;
    func_021ACA70((u32 *)p);
    return p;
}








/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021ACA5C(u32 a, u8 *p)
{
    func_021ACB0C((struct X *)p);
    func_020307B0(p);
}








void func_021ACA70(u32 *a)
{
    u32 buf[9];
    u16 *h = (u16 *)a;
    u32 r4 = func_021ABE18((u8 *)a[0]);
    u32 r6 = func_021ABE24((u8 *)a[0]);
    func_021C6AE0((u32)buf);
    func_021C6AF0((u32)buf, r6, 0x31);
    h[2] = func_021C6574(r4, (u32)buf, 0);
    h[4] = func_021C6590(r4, h[2], 0, 0);
    func_021C67D8(r4, h[4], 1);
    func_021C6AE0((u32)buf);
    func_021C6AF0((u32)buf, r6, 0x36);
    func_021C6AF8((u32 *)buf, r6);
    func_021C6AFC(buf, 0x6b);
    func_021C6AFC(buf, 0x85);
    h[3] = func_021C6574(r4, (u32)buf, 0);
    h[5] = func_021C6590(r4, h[3], 0, 0);
    func_021C67D8(r4, h[5], 1);
}








void func_021ACB0C(X *x)
{
    u32 h = func_021ABE18((u8 *)x->f0);

    func_021C6628(h, x->h8);
    func_021C6628(h, x->ha);
    func_021C6580((u8 *)h, x->h4);
    func_021C6580((u8 *)h, x->h6);
}








void func_021ACB38(u32 a, u32 b, Vec3 *c, u32 d, u32 e)
{
    Vec3 v;
    Arg s;
    s.a = func_021ABEA0(a, 3);
    s.b = d;
    s.c = func_0216D588((void *)d);
    s.d = func_0216D590((void *)d);
    s.e = b;
    v = *c;
    if (func_0216D55C(d, 0x2000) != 0)
        func_021ABFA8(a, d_021D915C, &v, e, &s, 0);
    else
        func_021ABFA8(a, d_021D9184, &v, e, &s, 0);
}








void func_021ACBB8(u32 a, u8 v)
{
    if (a != 0)
        ((u8 *)func_021AC1E0(a))[9] = v;
}








void func_021ACBC8(u32 a, int v)
{
    u8 *p;

    if (a != 0) {
        p = (u8 *)func_021AC1E0(a);
        if (v == 1)
            p[10] = 0;
        else
            p[10] = 1;
    }
}







int func_021ACBE4(int n)
{
    if (n > 0x40000)
        n = 0x40000;
    return n / 0xA3D * 0x28;
}







int func_021ACC04(E *a, E *b, u32 mode)
{
    int r = 0;

    switch (mode) {
    case 0:
        r = b->f8 - a->f8;
        break;
    case 1:
        r = a->f8 - b->f8;
        break;
    case 2:
        r = b->f0 - a->f0;
        break;
    case 3:
        r = a->f0 - b->f0;
        break;
    }
    return r;
}





void func_021ACC3C(u32 a, B_021AC9D8 *b)
{
    u8 *p = (u8 *)func_021AC1AC(a);
    Inner_021AC810 *q;
    u32 k = 0x1000;
    b->blk = *(Blk_021AC9D8 *)p;
    func_021AC1CC(a, p + 0x10);
    b->fc = ((struct Obj19874 *)p)->fC;
    func_021ABE18((u8 *)(*(u32 *)b->blk.w[0]));
    b->f18 = *(u16 *)(b->blk.w[0] + 8);
    b->f9 = func_021AC1A0(a);
    b->f10 = k;
    b->f14 = k >> 2;
    q = &b->in;
    q->c = *(u16 *)(b->blk.w[0] + 0xa);
    b->in.a = 1;
    q->b = 9;
    q->d = k;
    q->e = k;
    q->f = k;
    func_021AC178(a);
}



void func_021ACCAC(void) {}


void func_021ACCB0(u32 a, B *b)
{
    AngTbl t = d_021D9198;
    Ang *e = &t.e[b->fc];
    u32 obj;
    Node *n;

    obj = func_021ABE18((u8 *)(*b->f1c));
    n = (Node *)func_021C6658(obj, b->f18);
    func_020520FC(e->x, e->y, e->z, (struct Mtx33 *)n->mtx);
    func_021AC1B8(a, n);
    if (b->in.a == 0) {
        Inner_021ACCB0 *in = &b->in;
        PosTbl pt = d_021D91C8;
        AngTbl at = d_021D91B0;
        V3_021ACCB0 *p = &pt.e[b->fc];
        Ang *g = &at.e[b->fc];
        n = (Node *)func_021C6658(obj, in->c);
        func_020520FC(g->x, g->y, g->z, (struct Mtx33 *)n->mtx);
        func_021AC1B8(a, n);
        n->pos.x = n->pos.x + (in->pos.x + p->x);
        n->pos.y = n->pos.y + (in->pos.y + p->y);
        n->pos.z = n->pos.z + (in->pos.z + p->z);
        n->scale = in->scale;
        func_021C6678(obj, in->c, 0);
    } else {
        func_021C6678(obj, b->in.c, 1);
    }
}
