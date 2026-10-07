/*
 * file:     monolith_tool_p05.c
 * unit:     yes
 * function: func_021B6F2C, func_021B6F40, func_021B6F54, func_021B6FD8, func_021B6FE0, func_021B7014, func_021B7068, func_021B7070, func_021B70B8, func_021B70C4, func_021B7108, func_021B7114, func_021B7118, func_021B7168, func_021B7170, func_021B7174, func_021B718C, func_021B7194, func_021B71FC, func_021B7204
 * address:  0x021B6F2C
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_021583EC 0x021583EC thumb ov010
 *   func_021583CC 0x021583CC thumb ov010
 *   d_021BA844     0x021BA844  data  a2
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204B8A0 0x0204B8A0 arm
 *   d_021BA854     0x021BA854  data  a4
 *   d_021BA84C     0x021BA84C  data  a4
 *   func_0204B6F4  0x0204B6F4  arm
 *   d_021BA804     0x021BA804  data  a4
 *   func_02027F60 0x02027F60 thumb
 *   func_02027FD8  0x02027FD8  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_02027778  0x02027778  thumb
 *   func_02027858  0x02027858  thumb
 *   func_02027974 0x02027974 thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 */
#include "../../matched/include/Obj13166.h"
#include "../../matched/include/Obj13167.h"
#include "../../matched/include/Obj09886.h"
#include "../../matched/include/Obj20689.h"

struct Ctx;
struct Obj;
struct R;
struct TaskMenuState;
struct MsgBank;
struct U16Vec;
struct TaskMenu;
struct TaskMenuTmpl;
typedef unsigned char u8;

typedef unsigned short u16;

typedef enum { B_FALSE, B_TRUE } Bool;

struct H4 {
    u16 a, b, c, d;
};

struct Ent {
    int w[4];
};

struct P { int w[6]; int pad[10]; struct Ent e[2]; };

typedef enum { V4 = 4, V5 = 5 } Value;

typedef unsigned int   u32;

typedef struct { u16 a, b, c, d; } Rect;

typedef struct { int h; u8 a, b, c; } St;

typedef struct { void *s; u16 h; int z; } Item;

extern void *func_020120F4(const struct Ctx *p);
extern int func_021583EC(void *a0, int a1);
extern int func_021583CC(void *a0, int a1);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B92C(struct Obj *, unsigned int);
extern void func_0204B8A0(struct Obj *p, u16 v);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_02027974(void *);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
void *func_021B6F2C(u8 **p);
void *func_021B6F40(u8 **p);
int func_021B6F54(struct P *p, u8 *q, int c, const int *d, int e);
void func_021B6FD8(void *p);
void func_021B6FE0(void *p, u8 *q, int i);
int func_021B7014(int *p, const int *pos, int flag);
void func_021B7068(void *p);
void func_021B7070(int *p, int *out);
void func_021B70B8(void **p);
void func_021B70C4(St *p);
void func_021B7108(void *p);
int func_021B7114(void *p);
struct Obj *func_021B7118(int *p, int x, int y, int w);
void func_021B7168(void *p);
void func_021B7170(void *a);
struct R *func_021B7174(u32 *p, int a, u16 heap);
void func_021B718C(void *p);
void *func_021B7194(int *p, void *arg1, u32 heap);
void func_021B71FC(void *p);
int func_021B7204(int a, int b, void *p, int *q);
extern struct H4 d_021BA844;
extern const Rect d_021BA854;
extern const Rect d_021BA84C;
extern const Rect d_021BA804;

void *func_021B6F2C(u8 **p)
{
    u8 *q = *p;
    return (void *)func_021583EC(func_020120F4(((struct Obj13166 *)q)->f0), q[0x3c]);
}

void *func_021B6F40(u8 **p)
{
    u8 *q = *p;
    return (void *)func_021583CC(func_020120F4(((struct Obj13167 *)q)->f0), q[0x3c]);
}


/*
 * The flag is a u16 local assigned from a ternary over enum constants: every
 * int-constant spelling (ternary, if/else, e != 0) is folded to a boolean and
 * comes out with the opposite branch polarity (beq to 0, not bne to 1).
 * const on d lets both d[] loads go ahead of the stores into s.
 */
int func_021B6F54(struct P *p, u8 *q, int c, const int *d, int e)
{
    struct H4 s;
    int r;
    u16 flag;
    u8 *m;

    s = d_021BA844;
    flag = e == 0 ? B_FALSE : B_TRUE;
    s.a = d[0];
    s.b = d[1];
    m = q + 6;
    if (m[c] == 1) {
        s.c = 5;
    }
    r = (int)func_0204B294((void *)p->w[5], p->e[e].w[1], p->e[e].w[0], p->e[e].w[2], &s, flag, 0x61);
    if (m[c] == 0) {
        func_0204B3DC((struct Obj *)r, 0);
    }
    func_0204B92C((struct Obj *)r, 1);
    return r;
}

/*
 * Tail call to func_0204B3B4.
 */
void func_021B6FD8(void *p)
{
    void func_0204B3B4(struct Obj *p);
    func_0204B3B4(p);
}

void func_021B6FE0(void *p, u8 *q, int i) { Value v; if((q+i)[6]==1) v=V5; else if((q+i)[6]==2) v=V4; else {func_0204B3DC(p,0);return;} func_0204B3DC(p,1);func_0204B8A0(p,v); }


int func_021B7014(int *p, const int *pos, int flag)
{
    Rect r;
    int f;

    r = d_021BA854;
    f = 0;
    if (flag != 0)
        f = 1;
    r.a = pos[0];
    r.b = pos[1];
    return (int)func_0204B294((void *)p[0x14 / 4], *(int *)((char *)p + 0x44 + flag * 16), *(int *)((char *)p + 0x40 + flag * 16), *(int *)((char *)p + 0x48 + flag * 16), &r, (u16)f, 0x61);
}

void func_021B7068(void *p)
{
    void func_0204B3B4(struct Obj *p);
    func_0204B3B4(p);
}


void func_021B7070(int *p, int *out)
{
    Rect r;
    int h;

    r = d_021BA84C;
    h = (int)func_0204B294((void *)p[0x14 / 4], p[0x54 / 4], p[0x50 / 4], p[0x58 / 4], &r, 1, 0x61);
    func_0204B92C((struct Obj *)h, 1);
    *out = h;
}

/*
 * Unlabelled leaf thunk: loads *p then tail-calls the ARM9 ARM function
 * func_0204B3B4 with it.  It is the callee whose only image-wide callers are
 * the three ov071 offset-thunks (matched via this EXACT entry).
 */
void func_021B70B8(void **p)
{
    void func_0204B3B4(struct Obj *p);
    func_0204B3B4(*p);
}


void func_021B70C4(St *p)
{
    if (p->a == 1) {
        if (p->b % 5 == 0) {
            func_0204B6F4((struct Obj *)p->h, p->c, 1);
            p->c ^= 1;
            if (p->b / 5 == 3)
                p->a = 0;
        }
        p->b++;
    }
}


/*
 * Byte initialiser and its getter.
 */
void func_021B7108(void *p)
{
    ((struct Obj09886 *)p)->f4 = 1;
    ((struct Obj09886 *)p)->f5 = 0;
    ((struct Obj09886 *)p)->f6 = 1;
}


int func_021B7114(void *p)
{
    return ((struct Obj20689 *)p)->f4;
}


struct Obj *func_021B7118(int *p, int x, int y, int w)
{
    Rect r;
    struct Obj *h;

    r = d_021BA804;
    r.a = x;
    r.b = y;
    r.c = w;
    h = func_0204B294((void *)p[0x14 / 4], p[0x54 / 4], p[0x50 / 4], p[0x58 / 4], &r, 1, 0x61);
    func_0204B92C(h, 1);
    return h;
}

/*
 * ARM9 tail call followed by an empty function.
 */
void func_021B7168(void *p)
{
    void func_0204B3B4(struct Obj *p);
    func_0204B3B4(p);
}


void func_021B7170(void *a)
{
}


struct R *func_021B7174(u32 *p, int a, u16 heap)
{
    return func_02027F60((u8)a, 14, p[3], p[2], heap);
}

/*
 * Tail call to func_02027FD8.
 */
void func_021B718C(void *p)
{
    u32 func_02027FD8(struct TaskMenuState *s);
    func_02027FD8(p);
}


void *func_021B7194(int *p, void *arg1, u32 heap)
{
    Item it[2];
    struct {
        u32 heapId;
        u8 count;
        u8 pad05[3];
        Item *items;
        u32 unk0c;
        u8 b0, b1, b2, b3;
    } t;
    void *r;

    it[0].s = func_02045EC0((void *)p[0x28 / 4], 0x1e);
    it[1].s = func_02045EC0((void *)p[0x28 / 4], 0x1f);
    it[0].h = 0x39E0;
    it[1].h = 0x39E0;
    it[0].z = 0;
    it[1].z = 0;
    t.heapId = heap;
    t.count = 2;
    t.items = it;
    t.unk0c = 0;
    t.b0 = 0x18;
    t.b1 = 0xc;
    t.b2 = 8;
    t.b3 = 3;
    r = func_02027778((struct TaskMenuTmpl *)(&t), arg1);
    func_02045808(it[0].s);
    func_02045808(it[1].s);
    return r;
}

/*
 * Tail call to func_02027858.
 */
void func_021B71FC(void *p)
{
    void func_02027858(struct TaskMenu *m);
    func_02027858(p);
}

int func_021B7204(int a, int b, void *p, int *q) { func_02027974(p); if(func_020279E8(p)==1) { *q=func_02027A04(p)==0 ? 1 : 0;return 1;} return 0; }
