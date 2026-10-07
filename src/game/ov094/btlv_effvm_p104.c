/*
 * file:     btlv_effvm_p104.c
 * unit:     yes
 * function: func_0220663C, func_02206710, func_02206728, func_022067E8, func_0220680C, func_0220684C, func_02206864, func_0220687C, func_022068C4, func_022068E8, func_02206908, func_02206950, func_02206A14, func_02206A58, func_02206A7C, func_02206AF8
 * address:  0x0220663C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0202173C 0x0202173C thumb
 *   func_02021ED8 0x02021ED8 thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201DE00  0x0201DE00  thumb
 *   func_0201DD78  0x0201DD78  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02204C98  0x02204C98  thumb  ov094
 *   func_021F88F4  0x021F88F4  thumb  ov094
 *   func_021F8AC0  0x021F8AC0  thumb  ov094
 *   func_021F8554  0x021F8554  thumb  ov094
 *   func_021F86B4  0x021F86B4  thumb  ov094
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_02207D78  0x02207D78  thumb  ov094
 *   func_022005C4  0x022005C4  thumb  ov094
 *   func_02030EE8  0x02030EE8  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_021F8754  0x021F8754  thumb  ov094
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_021F8914  0x021F8914  thumb  ov094
 *   func_02021F64  0x02021F64  thumb
 *   func_021F86E0  0x021F86E0  thumb  ov094
 *   func_020215BC  0x020215BC  thumb
 *   func_021F88A8  0x021F88A8  thumb  ov094
 */
#include "../../matched/include/Obj21789.h"
#include "../../matched/include/Obj21791.h"
#include "../../matched/include/Obj21793.h"
#include "../../matched/include/Obj21794.h"
#include "../../matched/include/Obj21796.h"
#include "../../matched/include/Obj21798.h"
#include "../../matched/include/Obj05249.h"
#include "../../matched/include/Obj21799.h"
#include "../../matched/include/Obj21800.h"
#include "../../matched/include/Obj10159.h"
#include "../../matched/include/Obj18616.h"
#include "../../matched/include/Obj00823.h"
#include "../../matched/include/Obj04404.h"
#include "../../matched/include/Obj21803.h"
#include "../../matched/include/Obj06328.h"
#include "../../matched/include/Obj13619.h"

struct WordSet;
struct MsgBank;
struct U16Vec;
struct StrObj;
struct S02030EE8;
struct Node;
struct PalAnmSlot;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef struct PalAnmObj PalAnmObj;

typedef struct { char *p; int state, colour, flag; } Ctx;

typedef struct { char pad[0x68]; unsigned int f68; } W_02206710;

typedef struct {
    unsigned int lo : 4;
    unsigned int b4 : 1;
} Bf;

typedef struct {
    char p0[0x58];
    int f58;
    char p5c[0x68 - 0x5c];
    u32 b0 : 5;
    u32 sel : 4;
    u32 rest : 23;
    char p6c[0x242 - 0x6c];
    u8 row[4][8];
    char p262[0x266 - 0x262];
    u16 a266[3];
    u16 a26c[8];
    int k;
} W_02206950;

extern int func_0202173C(PalAnmObj *, u16, u16, s16, u8, u8, u16, void *);
extern u32 func_02021ED8(const char *);
extern W_02206710 **func_02030EE8(void *h);
extern int func_021F88F4(void);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201DE00(u8 *a, u8 *b, u8 *c);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02204C98(struct StrObj *a, int b, int *outn, int *outq);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_021F8AC0(int a);
extern void func_021F8554(u32 flags, int kind, int n, int s, int t);
extern int func_021F86B4(void);
extern int func_021F8694(void);
extern int func_02207D78(char *p, int i);
extern int func_022005C4(void *w, int key);
extern u32 func_020307B0(void *p);
extern void func_02030EAC(struct Node *n);
extern int func_021F8754(void);
extern void *func_021B86B8(void ***p);
extern int func_021F8914(void);
extern void func_02021F64(u16 *src, u16 *dst, u32 count, int weight, u16 color);
extern int func_021F86E0(void);
extern void func_020215BC(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
extern int func_021F88A8(void);
extern void func_020061E4(u32 a);
void func_0220663C(void *task, Ctx *c);
void func_02206710(void *h);
void func_02206728(char *s, char *b);
void func_022067E8(char *p);
void func_0220680C(char *p);
void func_0220684C(char *p, int a, int b);
int func_02206864(char *p, int v);
void func_0220687C(char *p, void *q);
int func_022068C4(char *p);
void func_022068E8(char *p);
int func_02206908(char *p, char *q, int i);
void func_02206950(W_02206950 *p);
void func_02206A14(char *p);
void func_02206A58(char *p);
int func_02206A7C(char *p);
void func_02206AF8(char *p);

void func_0220663C(void *task, Ctx *c)
{
    switch (c->state) {
    case 0:
        if (c->flag == 1)
            func_0202173C(*(PalAnmObj * *)&((struct Obj21789 *)(c->p))->f64, 8, 2, 0, 0, 8, 0x7fff, *(void **)c->p);
        else
            func_0202173C(*(PalAnmObj * *)&((struct Obj21791 *)(c->p))->f64, 2, c->colour, 0, 0, 8, 0x7fff, *(void **)c->p);
        c->state++;
        break;
    case 1:
        if (func_02021ED8(*(char * *)&((struct Obj21793 *)(c->p))->f64) == 0) {
            if (c->flag == 1)
                func_0202173C(*(PalAnmObj * *)&((struct Obj21794 *)(c->p))->f64, 8, 2, 0, 8, 0, 0x7fff, *(void **)c->p);
            else
                func_0202173C(*(PalAnmObj * *)&((struct Obj21796 *)(c->p))->f64, 2, c->colour, 0, 8, 0, 0x7fff, *(void **)c->p);
            c->state++;
        }
        break;
    case 2:
        if (func_02021ED8(*(char * *)&((struct Obj21798 *)(c->p))->f64) == 0)
            func_0220687C(c->p, task);
        break;
    }
}


void func_02206710(void *h)
{
    (*func_02030EE8(h))->f68 &= 0x7fffffff;
}


void func_02206728(char *s, char *b)
{
    int h;
    void *v;
    void *w;
    int v18;
    int v14;
    u8 c[3];

    if (func_021F88F4() == 0)
        return;
    h = (int)func_0201EC64(((struct Obj05249 *)s)->f240);
    v = func_020457B0(6, ((struct Obj05249 *)s)->f240);
    w = func_02045EC0(((struct Obj05249 *)s)->f5C, 8);
    func_0201DE00(&c[2], &c[1], &c[0]);
    func_0201DD78(1, 2, 0);
    func_0201EFA4((struct WordSet *)h, 0, ((struct Obj21799 *)b)->fC4, 2, 0, 1);
    func_0201F250((struct WordSet *)h, v, w);
    func_02204C98((struct StrObj *)v, ((struct Obj05249 *)s)->f224, &v18, &v14);
    func_0201C7A4((void *)(((struct Obj05249 *)s)->f234), 12 - v18 / 2, 0, v, (void *)(((struct Obj05249 *)s)->f224));
    func_0201DD78(c[2], c[1], c[0]);
    func_0201ED04((struct WordSet *)h);
    func_02045808(w);
    func_02045808(v);
}


void func_022067E8(char *p)
{
    func_021F8AC0(2);
    func_021F8554((u32)(((struct Obj21800 *)p)->f278), 1, 10, 0, 8);
}


void func_0220680C(char *p)
{
    int a = func_02207D78((char *)func_021F86B4(), ((struct Obj10159 *)p)->f278);
    int b = func_022005C4((void *)func_021F8694(), ((struct Obj10159 *)p)->f278);
    int i;

    if ((b | a) == 1) {
        for (i = 0; i < 8; i++)
            *(char *)(p + ((struct Obj10159 *)p)->f27C * 8 + i + 0x242) = 0;
    }
}


/*
 * lane O10 candidate
 */
void func_0220684C(char *p, int a, int b)
{
    int i = func_022068C4(p);

    *(int *)(p + i * 4 + 8) = a;
    *(int *)(p + i * 4 + 0x28) = b;
}

/*
 * lane S13 leaf of func_0220687C
 */
int func_02206864(char *p, int v)
{
    int i;
    int x;

    for (i = 0; i < 8; i++) {
        x = *(int *)(p + i * 4 + 8);
        if (x == v)
            break;
    }
    return i;
}


void func_0220687C(char *p, void *q)
{
    int i = func_02206864(p, (int)q);
    int off;

    if (q != 0) {
        void *r = (void *)func_02030EE8(q);
        char *t = p + 0x28;
        void (*cb)(void *);

        off = i * 4;
        cb = *(void (**)(void *))(t + off);
        if (cb != 0)
            cb(q);
        if (r != 0)
            func_020307B0(r);
        func_02030EAC(q);
        *(int *)(p + off + 8) = 0;
        *(int *)(t + off) = 0;
    }
}


int func_022068C4(char *p)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (*(int *)(p + 8 + i * 4) == 0)
            break;
    }
    if (i == 8) {
        func_0220687C(p, (void *)(((struct Obj18616 *)p)->f8));
        i = 0;
    }
    return i;
}


void func_022068E8(char *p)
{
    int i;

    for (i = 0; i < 8; i++) {
        int v = *(int *)(p + 8 + i * 4);

        if (v != 0)
            func_0220687C(p, (void *)v);
    }
}


int func_02206908(char *p, char *q, int i)
{
    int r;

    if (!((Bf *)(p + 0x68))->b4 || ((struct Obj00823 *)p)->f58 != 1)
        return 1 & ((int *)*(int * *)&((struct Obj04404 *)q)->f4)[i];
    r = (((int *)*(int * *)&((struct Obj04404 *)q)->f4)[i] & 2) >> 1;
    if (r == 1)
        *(char *)(p + ((struct Obj00823 *)p)->f27C * 8 + 0x242 + ((struct Obj00823 *)p)->f58) = 0;
    return r;
}


void func_02206950(W_02206950 *p)
{
    u8 b;

    switch (p->f58) {
    case 2:
        if (p->a266[p->k] != p->a26c[p->row[p->k][p->f58]])
            p->row[p->k][3] = 0;
    case 1:
    case 5:
        p->sel = p->row[p->k][p->f58];
        break;
    case 3:
        b = p->row[p->k][p->f58];
        if (((b & 0xf0) >> 4) == p->row[p->k][2])
            p->sel = b;
        else
            p->sel = 0;
        break;
    default:
        p->sel = 0;
        break;
    }
}


void func_02206A14(char *p)
{
    u16 buf[16];

    if ((int)func_021B86B8((void ***)func_021F8754()) != 4 && func_021F8914() == 0) {
        func_02021F64((u16 *)(p + 0x284), buf, 0x10, 8, 0);
        func_020215BC((struct PalAnmSlot *)func_021F86E0(), buf, 1, 0x20, 0x20);
    }
}


void func_02206A58(char *p)
{
    if (((struct Obj21803 *)p)->f23C == 1)
        func_020215BC((struct PalAnmSlot *)func_021F86E0(), (u16 *)(p + 0x284), 1, 0x20, 0x20);
}


int func_02206A7C(char *p)
{
    if (!((Bf *)(p + 0x68))->b4) {
        if (((struct Obj06328 *)p)->f50 == 2) {
            if (func_021F88A8() == 1) {
                if (((struct Obj06328 *)p)->f278 == 4)
                    return 0x65;
                return 0x5f;
            }
            if (((struct Obj06328 *)p)->f278 == 4)
                return 0x5d;
            return 0x5e;
        }
        if (func_021F88A8() == 1)
            return 0x65;
        return 0x5d;
    }
    if (((struct Obj06328 *)p)->f50 == 2 && ((struct Obj06328 *)p)->f278 != 4) {
        if (func_021F88A8() == 1)
            return 0x67;
        return 0x61;
    }
    if (func_021F88A8() == 1)
        return 0x66;
    return 0x60;
}


void func_02206AF8(char *p)
{
    if (((struct Obj13619 *)p)->f54 != 3 || ((struct Obj13619 *)p)->f58 == 6)
        func_020061E4(0x555);
}
