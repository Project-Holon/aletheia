/*
 * file:     beacon_view_p09.c
 * unit:     yes
 * function: func_021F1080, func_021F10D8, func_021F1144, func_021F1218, func_021F1268, func_021F12B8, func_021F1340, func_021F13A0, func_021F1418
 * address:  0x021F1080
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
 *   func_02026D48  0x02026D48  thumb
 *   func_021F2144  0x021F2144  thumb  ov032
 *   func_02165CB4 0x02165CB4 thumb ov010
 *   func_020215BC 0x020215BC thumb
 *   func_02165CE4  0x02165CE4  thumb  ov010
 *   func_02165D08  0x02165D08  thumb  ov010
 *   func_02165C34  0x02165C34  thumb  ov010
 *   func_0204581C  0x0204581C  arm
 *   func_02165D50  0x02165D50  thumb  ov010
 *   func_021F0F74  0x021F0F74  thumb  ov032
 *   func_021F1004  0x021F1004  thumb  ov032
 *   func_02165E24  0x02165E24  thumb  ov010
 *   func_02165D6C  0x02165D6C  thumb  ov010
 *   func_02165D8C  0x02165D8C  thumb  ov010
 *   func_021F1070  0x021F1070  thumb  ov032
 *   func_021F1E40  0x021F1E40  thumb  ov032
 *   func_021F0DE0 0x021F0DE0 thumb
 *   func_0202590C 0x0202590C thumb
 *   func_021659F0 0x021659F0 thumb ov010
 *   func_021F0F44 0x021F0F44 thumb
 *   func_021F0DD8 0x021F0DD8 thumb
 *   func_020275B8 0x020275B8 thumb
 *   func_02165AC4 0x02165AC4 thumb ov010
 *   func_021F029C 0x021F029C thumb
 *   func_021F0DF4 0x021F0DF4 thumb
 *   func_021F05E8 0x021F05E8 thumb
 *   func_021F0F30 0x021F0F30 thumb
 *   func_020311B8 0x020311B8 arm
 *   func_02031290 0x02031290 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021F0EA4 0x021F0EA4 thumb
 *   func_021F0ED0 0x021F0ED0 thumb
 *   func_021F150C 0x021F150C thumb
 *   func_021F1484 0x021F1484 thumb
 *   func_02031194 0x02031194 arm
 */
#include "../../matched/include/Obj00225.h"
#include "../../matched/include/Obj00007.h"
#include "../../matched/include/Obj09797.h"
#include "../../matched/include/Obj13063.h"
#include "../../matched/include/Obj00188.h"
#include "../../matched/include/Obj06134.h"
#include "../../matched/include/Obj01676.h"

struct PalAnmSlot;
struct Rec;
struct U16Vec;
struct Strbuf;
struct Grid;
struct Queue;
struct S02030FB4;
struct TcblNode;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short   s16;

extern u16 func_02026D48(u16 v);
extern void func_021F2144(char *p, char *q, void *text, u16 col, u32 a4);
extern u8 func_02165CB4(int a);
extern void func_020215BC(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
extern u16 func_02165CE4(u8 *r);
extern u8 func_02165D08(struct Rec *r);
extern void func_02165C34(struct Rec *r, void *buf);
extern void func_0204581C(struct U16Vec *vec);
extern void func_02165D50(struct Rec *r, struct Strbuf *buf);
extern void func_021F0F74(char *p, u8 *q, void *r);
extern void func_021F1004(char *p, u8 *q, int r);
extern int func_02165E24(int a0);
extern int func_02165D6C(int a0, int a1);
extern int func_02165D8C(int a0, int a1);
extern void func_021F1070(char *p, char *q, void *text, int a4);
extern void func_021F1E40(char *p, char *q, void *x, int flag);
extern void func_021F0DE0(void *, short, short);
extern void func_0202590C(struct Grid *g, s16 x, s16 y);
extern int func_021659F0(u8 *q, int delta);
extern char *func_021F0F44(char *this, u8 id);
extern void func_021F0DD8(unsigned int a);
extern void func_020275B8(char *p, int v);
extern int func_02165AC4(struct Queue *q, struct Rec *out, u16 *tag, int delta);
extern void func_021F029C(char *this, int a);
extern void func_021F0DF4(void *p, unsigned short v);
extern void func_021F05E8(u8 *p, int a, u32 b);
extern void func_021F0F30(char *e, int a, int b);
extern void *func_020311B8(u32 a, void *fn, u32 sz, u32 a3);
extern void *func_02031290(struct S02030FB4 *p);
extern void func_02082BCC(void *p, int v, int n);
extern void func_021F0EA4(char *p, unsigned a);
extern void func_021F0ED0(char *p, int a);
extern void func_021F150C(u8 *this, u8 *p, void *s);
extern void func_021F1484(char *this, int a, u8 *b, u8 *c, void *s);
extern void func_02031194(struct TcblNode *n);
void func_021F1080(char *p, char *q, int r, int t);
void func_021F10D8(char *this, u8 *p, int a);
void func_021F1144(u8 *p, u8 *q, void *r, int mode, int skip, int t);
void func_021F1218(char *p, short x, short y);
void func_021F1268(char *this);
void func_021F12B8(u8 *this, int dir);
void func_021F1340(char *this, int a, u8 b);
void func_021F13A0(char *this, int a, int b, int c, int s);
void func_021F1418(void *h, u8 *t);


void func_021F1080(char *p, char *q, int r, int t)
{
    u8 c;

    c = (func_02026D48(((struct Obj00225 *)q)->f6) >= 0x2a30) ? 1 : 0;
    if (c == ((struct Obj00225 *)q)->f5 && r == 0) {
        return;
    }
    ((struct Obj00225 *)q)->f5 = c;
    if (c != 0) {
        func_021F2144(p, q, (void *)(*(int *)&((struct Obj00225 *)q)->f24), 0xca0, t);
    } else {
        func_021F2144(p, q, (void *)(*(int *)&((struct Obj00225 *)q)->f24), 0x3c60, t);
    }
}


void func_021F10D8(char *this, u8 *p, int a)
{
    u8 v;
    int k;

    p[3] = func_02165CB4(a);
    v = p[3];
    if (v == 0) {
        k = 0x30;
        v = 5;
    } else {
        k = 0x35;
    }
    func_020215BC((struct PalAnmSlot *)(*(int *)&((struct Obj00007 *)this)->fAC), *(u16 * *)&((struct Obj00007 *)this)->f3C8 + 0x30, (int)3, (u16)((p[0] + 4) * 16 + 8), 10);
    func_020215BC((struct PalAnmSlot *)(*(int *)&((struct Obj00007 *)this)->fAC), *(u16 * *)&((struct Obj00007 *)this)->f3C8 + k, (int)3, (u16)((p[0] + 4) * 16 + 8), v * 2);
}


void func_021F1144(u8 *p, u8 *q, void *r, int mode, int skip, int t)
{
    ((struct Obj00225 *)q)->f6 = func_02165CE4(r);
    q[4] = func_02165D08(r);
    func_02165C34(r, ((struct Obj00225 *)q)->f24);
    func_0204581C(((struct Obj00225 *)q)->f20);
    func_02165D50(r, ((struct Obj00225 *)q)->f20);
    func_021F10D8((char *)p, q, (int)r);
    func_021F0F74((char *)p, q, r);
    func_021F1004((char *)p, q, (int)r);
    if (skip != 0)
        return;
    switch (mode) {
    case 0:
        switch (func_02165E24((int)r)) {
        case 0x18:
            func_02165D6C((int)r, (int)(((struct Obj00007 *)p)->f118));
            func_021F1070((char *)p, (char *)q, ((struct Obj00007 *)p)->f118, t);
            break;
        case 0x31:
            func_02165D8C((int)r, (int)(((struct Obj00007 *)p)->f118));
            func_021F1070((char *)p, (char *)q, ((struct Obj00007 *)p)->f118, t);
            break;
        }
        func_021F1E40((char *)p, (char *)q, r, 0);
        break;
    case 1:
        func_021F1070((char *)p, (char *)q, ((struct Obj00225 *)q)->f20, t);
        func_021F1E40((char *)p, (char *)q, r, 1);
        break;
    case 2:
        func_021F1080((char *)p, (char *)q, 1, t);
        break;
    }
}


void func_021F1218(char *p, short x, short y)
{
    ((struct Obj00225 *)p)->f8 = x;
    ((struct Obj00225 *)p)->fA = y;
    func_021F0DE0(((struct Obj00225 *)p)->fC, x, y);
    func_021F0DE0(((struct Obj00225 *)p)->f10, x + 0x20, y + 0x18);
    func_021F0DE0(((struct Obj00225 *)p)->f14, x + 0x3c, y + 0x18);
    func_0202590C(((struct Obj00225 *)p)->f18, x + 0x48, y + 0x10);
}


void func_021F1268(char *this)
{
    int i;
    char *e;

    for (i = 0; i < ((struct Obj09797 *)this)->f7D; i++) {
        e = func_021F0F44(this, func_021659F0(*(u8 * *)&((struct Obj09797 *)this)->f3C, ((struct Obj09797 *)this)->f7C + i));
        if (((struct Obj13063 *)e)->f30 == 0 || ((struct Obj13063 *)e)->f2C != 0)
            func_021F1080(this, e, 0, 0);
    }
}


/*
 * Byte-correct; the only wildcard is the bl to func_020275B8 (blocker: no
 * witness outside the range for an unlabelled arm9 leaf, Ilias's). Verified
 * leaf C (EXACT, arm9 0x020275B8, thumb, 12 bytes incl. pool word 0x0B0E):
 *   typedef unsigned char u8;
 *   void func_020275B8(char *p, u8 v) { p[0xb0e] = v; }
 * The this+0x7c/0x7d reads are volatile: the original re-reads them.
 *
 * note (2026-10-04): wave D2 filed the arm9 leaf witnesses (src/matched/arm9/func_020275A8,
 *   AC, B8, D0 EXACT); the tool still reports them unresolved, so the label seeding for
 *   0x020275A8/AC/B8/D0 (asm/layout, not this lane) is the only blocker.
 */
void func_021F12B8(u8 *this, int dir)
{
    u8 t;
    int n;
    u8 idx;

    func_021F0DD8(0x54b);
    if (dir == 0) {
        t = *(volatile u8 *)(this + 0x7c) + *(volatile u8 *)(this + 0x7d);
        n = *(volatile u8 *)(this + 0x7c) + 1;
    } else {
        t = *(volatile u8 *)(this + 0x7c) - 1;
        n = *(volatile u8 *)(this + 0x7c) - 1;
    }
    *(volatile u8 *)(this + 0x7c) = n;
    func_020275B8(*(void **)(this + 0x34), *(volatile u8 *)(this + 0x7c));
    func_02165AC4(*(void **)(this + 0x3c), *(void **)(this + 0x40), (u16 *)(this + 0x48), t);
    idx = func_021659F0(*(void **)(this + 0x3c), t);
    func_021F13A0((char *)this, (int)(*(void **)(this + 0x40)), idx, (u8)dir, 2);
}


void func_021F1340(char *this, int a, u8 b)
{
    this[0x81] = 1;
    this[0x82] = 0;
    ((struct Obj00188 *)this)->f84 = a;
    this[0x83] = b;
    ((struct Obj00188 *)this)->f88 = 0;
    func_021F029C(this, 1);
    if (((struct Obj00188 *)this)->f84 == 0)
        func_021F0DF4((void *)(((struct Obj00188 *)this)->f2D0), 0x13);
    else
        func_021F0DF4((void *)(((struct Obj00188 *)this)->f2CC), 0xf);
    func_021F05E8((u8 *)this, 4, 2);
    func_021F12B8((u8 *)this, a);
}


void func_021F13A0(char *this, int a, int b, int c, int s)
{
    char *e;
    u8 *r;

    e = func_021F0F44(this, 0xff);
    if (e != 0) {
        r = func_02031290(func_020311B8(*(u32 *)&((struct Obj00007 *)this)->fA0, (void *)func_021F1418, 0x18, 0));
        func_02082BCC(r, 0, 0x18);
        *(char * *)&((struct Obj06134 *)r)->fC = this;
        r[1] = c;
        *(char * *)&((struct Obj06134 *)r)->f8 = e;
        ((struct Obj06134 *)r)->f4 = s;
        *(int * *)&((struct Obj06134 *)r)->f14 = (int *)(this + 0xa8);
        ((struct Obj00007 *)this)->fA8 = ((struct Obj00007 *)this)->fA8 + 1;
        func_021F0F30(e, b, 0);
        func_021F1144((u8 *)this, (u8 *)e, (void *)a, s, 0, (int)(r + 0x10));
    }
}


void func_021F1418(void *h, u8 *t)
{
    void *this;

    this = ((struct Obj01676 *)t)->fC;
    if (((struct Obj01676 *)t)->f10 > 0)
        return;
    if (t[0] == 0) {
        func_021F0EA4(((struct Obj01676 *)t)->f8, 1);
        if (((struct Obj01676 *)t)->f4 == 1) {
            func_021F150C(this, ((struct Obj01676 *)t)->f8, t + 0x10);
            func_021F0ED0(((struct Obj01676 *)t)->f8, 1);
        } else {
            func_021F1484(this, t[1], ((struct Obj01676 *)t)->f8, 0, t + 0x10);
        }
        t[0] = t[0] + 1;
        return;
    }
    if (*(int * *)&((struct Obj01676 *)t)->f14 != 0)
        *(*(int * *)&((struct Obj01676 *)t)->f14) = *(*(int * *)&((struct Obj01676 *)t)->f14) - 1;
    func_02031194(h);
}
