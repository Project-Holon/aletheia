/*
 * file:     field_g3dobj_p04.c
 * unit:     yes
 * function: func_021C62F0, func_021C6368, func_021C63AC, func_021C6400, func_021C6470, func_021C64E0
 * address:  0x021C62F0
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
 *   d_021DAAB4     0x021DAAB4  data  a2
 *   func_02040588  0x02040588  arm
 *   func_02040E78  0x02040E78  arm
 *   func_02040C14  0x02040C14  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   func_021D325C  0x021D325C  thumb  ov021
 *   func_021D3244  0x021D3244  thumb  ov021
 *   func_02040DA8  0x02040DA8  arm
 *   func_02030734  0x02030734  arm
 *   d_021DE4A8     0x021DE4A8  data  ov021  a1
 *   func_021C6A90  0x021C6A90  thumb  ov021
 *   func_021C6940  0x021C6940  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_021C6854  0x021C6854  thumb  ov021
 *   func_021C69B4  0x021C69B4  thumb  ov021
 *   func_02047AC8  0x02047AC8  arm
 *   func_02047A60  0x02047A60  arm
 */
#include "../../matched/include/Obj00458.h"

struct St021D3244;
struct St021D325C;
struct Arg;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    u16 x;
    u16 y;
} Pt;

typedef unsigned int   u32;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    void *f8;
    void *fC;
} Work;

typedef struct {
    u32 kind : 2;
    u32 rest : 30;
    u16 f4;
    u16 f6;
    u8 pad8[0x3C];
    void *f44;
    u8 pad48[0x20];
} Elem_021C6400;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u8 *f8;
    Elem_021C6400 *fC;
} Mgr_021C6400;

typedef struct {
    u32 kind : 2;
    u32 rest : 30;
    u16 f4;
    u16 f6;
    u8 pad8[0x3C];
    void *f44;
    u8 pad48[0x20];
} Elem_021C6470;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u8 *f8;
    Elem_021C6470 *fC;
} Mgr_021C6470;

typedef struct {
    u32 kind : 2;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 rest : 26;
    u16 f4;
    u16 f6;
    u8 f8[0x3C];
    void *f44;
    u8 pad48[0x20];
} Elem_021C64E0;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    void *f8;
    Elem_021C64E0 *fC;
} Mgr_021C64E0;

extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040E78(u32 r7, void *r6, u32 r5, u32 r4);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern void func_02041300(int, int, int, int, int, int, int);
extern void func_020409B4(u32 index);
extern void func_021D325C(struct St021D325C *p, u32 a, u32 b, u32 c, u32 d);
extern void func_021D3244(struct St021D3244 *p, int i, u8 v);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021C6A90(u32 *p, u8 *q);
extern void func_021C6940(u8 *p);
extern u32 func_020307B0(void *p);
extern void func_021C6854(u8 *s);
extern void func_021C69B4(Elem_021C6470 *e, u8 *s, int a, int b, int c, int d, int f);
extern int func_02047AC8(void *a0, struct Arg *a1);
extern void func_02047A60(void *a0, struct Arg *a1);
void func_021C62F0(u8 *p);
void func_021C6368(u8 *p);
Work *func_021C63AC(u32 heap, u32 n, u32 m);
void func_021C6400(Mgr_021C6400 *m);
void func_021C6470(Mgr_021C6470 *m);
void func_021C64E0(Mgr_021C64E0 *m);
extern const Pt d_021DAAB4;
extern char d_021DE4A8[];


void func_021C62F0(u8 *p)
{
    Pt pt;

    pt = d_021DAAB4;
    func_02040588(p[0], 0);
    func_02040E78(p[0], &pt, 8, 0x20);
    func_02040C14(p[0], 1, 1, 0x100);
    func_02041300(p[0], 0x100, 0, 0, 0x20, 0x20, 1);
    func_020409B4(p[0]);
    func_021D325C(((struct Obj00458 *)p)->f4, 8, 0x37, p[1], 0x10 - p[1]);
    func_021D3244(((struct Obj00458 *)p)->f4, p[0], 1);
}


void func_021C6368(u8 *p)
{
    Pt pt = {0, 0};

    func_02040E78(p[0], &pt, 8, 0x20);
    func_02041300(p[0], 0, 0, 0, 0x20, 0x20, 1);
    func_020409B4(p[0]);
    func_02040DA8(p[0], 1, 0x100);
}


Work *func_021C63AC(u32 heap, u32 n, u32 m)
{
    Work *w;

    w = func_02030734(heap, 0x14, 1, d_021DE4A8, 0x72);
    w->f8 = func_02030734(heap, n * 0x2c, 1, d_021DE4A8, 0x75);
    w->fC = func_02030734(heap, m * 0x68, 1, d_021DE4A8, 0x78);
    w->f0 = heap;
    w->f4 = n;
    w->f6 = m;
    w->f2 = 1;
    return w;
}


void func_021C6400(Mgr_021C6400 *m)
{
    u32 i;
    Elem_021C6400 *e;
    u8 *s;

    i = 0;
    m->f2 = 0;
    e = m->fC;
    if (i < m->f6)
        for (; i < m->f6; i++) {
            if (e->kind == 1 && e->f44 != 0)
                func_021C6A90((u32 *)e, m->f8 + e->f4 * 0x2c);
            e++;
        }
    func_020307B0(m->fC);
    i = 0;
    s = m->f8;
    if (i < m->f4)
        for (; i < m->f4; i++) {
            func_021C6940(s);
            s += 0x2c;
        }
    func_020307B0(m->f8);
    func_020307B0(m);
}


void func_021C6470(Mgr_021C6470 *m)
{
    int i;
    int j;
    Elem_021C6470 *e;
    u8 *s;

    if (m->f2 == 1) {
        e = m->fC;
        s = m->f8;
        for (i = 0; i < m->f4; i++) {
            if (s[0x29] == 2)
                func_021C6854(s);
            s += 0x2c;
        }
        s = m->f8;
        for (j = 0; j < m->f6; j++) {
            if (e->kind == 2)
                func_021C69B4(e, s + e->f4 * 0x2c, e->f4, e->f6, m->f0, 0, 0);
            e++;
        }
    }
}


void func_021C64E0(Mgr_021C64E0 *m)
{
    u32 i;
    Elem_021C64E0 *e;

    e = m->fC;
    for (i = 0; i < m->f6; i++) {
        if (e->kind == 1) {
            if (e->b4 == 0 && e->b3 == 0) {
                if (e->b2 == 1)
                    func_02047AC8(e->f44, (struct Arg *)e->f8);
                else
                    func_02047A60(e->f44, (struct Arg *)e->f8);
            }
            e->b5 = 0;
        }
        e++;
    }
}
