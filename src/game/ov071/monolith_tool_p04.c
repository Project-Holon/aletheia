/*
 * file:     monolith_tool_p04.c
 * unit:     yes
 * function: func_021B699C, func_021B69AC, func_021B6A0C, func_021B6B38, func_021B6B58, func_021B6B70, func_021B6B98, func_021B6BEC, func_021B6C30, func_021B6C48, func_021B6C54, func_021B6C74, func_021B6C7C, func_021B6DB4, func_021B6E00, func_021B6E0C, func_021B6E18, func_021B6E1C, func_021B6EEC, func_021B6F04
 * address:  0x021B699C
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
 *   func_0204A648 0x0204A648 arm
 *   func_02021D50 0x02021D50 thumb
 *   func_02048F60  0x02048F60  arm
 *   func_020490A8  0x020490A8  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02043678  0x02043678  arm
 *   func_0204B294  0x0204B294  arm
 *   func_020255A0  0x020255A0  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_0201C6FC  0x0201C6FC  thumb
 *   func_02045808  0x02045808  arm
 *   d_021BA80C     0x021BA80C  data  a2
 *   d_021BA814     0x021BA814  data  a4
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0202570C 0x0202570C thumb
 *   func_020437AC 0x020437AC arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02025774 0x02025774 thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_020257D0 0x020257D0 thumb
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02034714  0x02034714  arm
 *   func_02021F3C  0x02021F3C  thumb
 *   func_02021FD8  0x02021FD8  thumb
 *   d_021BABE0     0x021BABE0  data  a1
 *   d_021BA82C     0x021BA82C  data  a4
 */
#include "../../matched/include/Obj07693.h"
#include "../../matched/include/Obj06183.h"

struct S02021D50;
struct Bmp;
struct Grid;
struct MsgBank;
struct Sys;
struct U16Vec;
struct WordSet;
struct Obj;
struct PrintSys;
struct Obj020437AC;
struct Chan02021FD8;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef enum { IDX_FIRST, IDX_COUNT = 6 } Idx;

struct E24 {
    int w[6];
};

typedef unsigned short u16;

typedef signed short s16;

typedef enum { B_FALSE, B_TRUE } Bool;

struct Point {
    s16 x;
    s16 y;
    u16 f4;
    u8 f6;
    u8 f7;
};

struct Param {
    void *bmp;
    s16 x;
    s16 y;
    u32 f8;
    u32 fc;
    u8 f10;
    u8 f11;
    u16 f12;
    u32 f14;
};

typedef struct {
    u32 f40;
    u32 f44;
    u32 f48;
    u32 f4c;
} Res;

typedef struct {
    u8 pad0[8];
    void *f8;
    void *fc;
    u8 pad10[4];
    u32 f14;
    u8 pad18[0x10];
    void *f28;
    void *f2c;
    u8 pad30[0x10];
    Res res[1];
} Ctx_021B6A0C;

typedef struct {
    void *act;
    void *grid;
    void *bmp;
    u8 on;
} Out_021B6A0C;

typedef struct {
    u16 v;
    u8 state;
    u8 dir;
    u8 timer;
    u8 cnt;
    u8 pad[2];
} Ent;

typedef struct {
    u8 pad0[8];
    void *f8;
    void *fc;
    u8 pad10[0x18];
    void *f28;
    void *f2c;
    u8 pad30[0x10];
    Res res[1];
} Ctx_021B6E1C;

typedef struct {
    void *bmp;
    void *grid;
    u8 on;
} Out_021B6E1C;

extern void func_0204A648(void);
extern void func_02021D50(struct S02021D50 *);
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern u32 func_020490A8(u32 a, u32 b);
extern u32 func_020307B0(void *p);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern struct Grid *func_020255A0(struct Sys *sys, const struct Param *param);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_02045808(struct U16Vec *vec);
extern void func_0204B3B4(struct Obj *);
extern void func_0202570C(struct Grid *);
extern void func_020437AC(struct Obj020437AC *);
extern void func_0204B3DC(struct Obj *, u32);
extern void func_02025774(u8 *, u32);
extern u32 func_0201C6C4(struct PrintSys *, void *);
extern void func_020257D0(struct Obj *);
extern void func_02082BCC(void *, int, int);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u16 func_02021F3C(int base, int idx, int which, u16 pos);
extern void func_02021FD8(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
void func_021B699C(void *unused, struct S02021D50 **p);
void func_021B69AC(u8 *a, u8 *b);
void func_021B6A0C(Ctx_021B6A0C *a, Out_021B6A0C *b, int c, int d, int e, int f, int g, void *h);
void func_021B6B38(void **p);
void func_021B6B58(void **p, int v);
int func_021B6B70(void **p, u8 *q);
void func_021B6B98(void *p, int *tbl, int n, int sel, int c);
void func_021B6BEC(void *p, int *tbl, int n, int sel, int c);
void func_021B6C30(int *p, int flag, int index);
void func_021B6C48(void *p, int a);
void func_021B6C54(char *p);
u8 func_021B6C74(void *p, int i);
void func_021B6C7C(int *p, int idx);
void func_021B6DB4(int *p, int a, int idx);
int func_021B6E00(unsigned int x);
int func_021B6E0C(unsigned int x);
int func_021B6E18(int a0);
void func_021B6E1C(Ctx_021B6E1C *a, Out_021B6E1C *b, int c, int x, int y, int w, int h, int g, void *ws);
void func_021B6EEC(void **p);
int func_021B6F04(void **p, u8 *q);
extern const struct Point d_021BA80C;
extern const struct Param d_021BA814;
extern char d_021BABE0[];
extern const struct Param d_021BA82C;

void func_021B699C(void *unused, struct S02021D50 **p)
{
    func_0204A648();
    func_02021D50(*p);
}


void func_021B69AC(u8 *a, u8 *b)
{
    struct E24 *tbl;
    u32 n;
    u32 idx;
    Idx i;

    if (b[0x3d] != 0) {
        tbl = func_02048F60(0x25, 0, 0x61);
        n = func_020490A8(0x25, 0);
        for (i = IDX_FIRST; i < IDX_COUNT; i++) {
            idx = b[4 + i];
            if (idx >= n) {
                idx = 0;
            }
            *(struct E24 *)(a + 0x60 + i * 24) = tbl[idx];
        }
        func_020307B0(tbl);
    }
}


/*
 * The 0/1 flag keeps its bne-to-one polarity only as an enum ternary
 * (a-flag-ternary-over-enum-constants-keeps-the-bne-to-one-polarity.md);
 * `case 2:` shares its arm with `default:` (the dead `cmp r6, #2; b`).
 */
void func_021B6A0C(Ctx_021B6A0C *a, Out_021B6A0C *b, int c, int d, int e, int f, int g, void *h)
{
    struct Point pt = d_021BA80C;
    struct Param param = d_021BA814;
    u32 w;
    void *bmp;
    void *s;
    void *t;
    int x;

    switch (d) {
    case 0:
        w = 0x16;
        pt.f4 = 0;
        param.x = e - 0x58;
        break;
    case 1:
        w = 0x12;
        pt.f4 = 1;
        param.x = e - 0x48;
        break;
    case 2:
    default:
        w = 0xc;
        pt.f4 = 8;
        param.x = e - 0x30;
        break;
    }
    bmp = func_02043678(w, 2, 0x20, 0x61);
    b->bmp = bmp;
    pt.x = e;
    pt.y = f;
    param.y = f - 8;
    param.bmp = bmp;
    param.f8 = a->res[c].f4c;
    x = c == 0 ? B_FALSE : B_TRUE;
    param.f14 = x;
    param.f12 = x;
    b->act = func_0204B294((void *)a->f14, a->res[c].f44, a->res[c].f40, a->res[c].f48, &pt, x, 0x61);
    b->grid = func_020255A0(a->f2c, &param);
    s = func_02045EC0(a->f28, g);
    if (h) {
        t = func_020457B0(0x80, 0x61);
        func_0201F250(h, t, s);
        func_0201C6FC(a->f8, (u32)b->bmp, 0, 0, t, (u32)a->fc);
        func_02045808(t);
    } else {
        func_0201C6FC(a->f8, (u32)b->bmp, 0, 0, s, (u32)a->fc);
    }
    func_02045808(s);
    b->on = 1;
}

void func_021B6B38(void **p)
{
    func_0204B3B4(p[0]);
    func_0202570C(p[1]);
    func_020437AC(p[2]);
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
}

/*
 * extent: two-byte alignment padding at 0x021B6B6E.
 */
void func_021B6B58(void **p, int v)
{
    func_0204B3DC(p[0], v);
    func_02025774(p[1], v);
}

int func_021B6B70(void **p, u8 *q)
{
    if (q[12] == 1) {
        if (func_0201C6C4(p[2], ((struct Obj07693 *)q)->f8) == 0) {
            func_020257D0(*(struct Obj * *)&((struct Obj07693 *)q)->f4);
            q[12] = 0;
            return 1;
        }
    }
    return 0;
}

void func_021B6B98(void *p, int *tbl, int n, int sel, int c)
{
    void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
    void func_021B6DB4(int *p, int a, int idx);
    int i;

    for (i = 0; i < n; i++) {
        if (i == sel) {
            func_0204B6F4((struct Obj *)tbl[i * 4], 1, 1);
            func_021B6DB4(p, 1, c);
        } else {
            func_0204B6F4((struct Obj *)tbl[i * 4], 0, 1);
        }
    }
    if (sel == 0xff) {
        func_021B6DB4(p, 0, c);
    }
}

void func_021B6BEC(void *p, int *tbl, int n, int sel, int c)
{
    void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
    void func_021B6DB4(int *p, int a, int idx);
    int i;

    for (i = 0; i < n; i++) {
        if (i == sel) {
            func_0204B6F4((struct Obj *)tbl[i * 4], 1, 1);
            func_021B6DB4(p, 2, c);
        } else {
            func_0204B6F4((struct Obj *)tbl[i * 4], 0, 1);
        }
    }
}

void func_021B6C30(int *p, int flag, int index)
{
    if (flag == 1) {
        func_021B6DB4(p, 1, index);
    } else {
        func_021B6DB4(p, 0, index);
    }
}

void func_021B6C48(void *p, int a)
{
    void func_021B6DB4(int *p, int a, int idx);
    func_021B6DB4(p, 2, a);
}

void func_021B6C54(char *p) { int i; for(i=0;i<4;i++) func_02082BCC(p+12+i*8,0,8); }


u8 func_021B6C74(void *p, int i)
{
    return ((u8 *)p + i * 8)[0xe];
}


/*
 * sites to func_02021F3C stay wildcarded because 0x02021F3C is an
 * unlabelled arm9 Thumb leaf (a bare `cmp r2, #1` entry, no lr save), so
 * no class attests it. The leaf verifies EXACT with this body
 * (`one --thumb`, no --region), outside this lane's write set (arm9):
 *
 *   typedef struct { u16 *a; u16 *b; int pad[3]; } Slot;
 *   u16 func_02021F3C(Slot *s, int idx, int which, u16 pos)
 *   {
 *       if (which == 1) {
 *           return s[idx].a[pos];
 *       }
 *       if (which == 0) {
 *           return s[idx].b[pos];
 *       }
 *       return 0;
 *   }
 *
 * note 2026-10-05 (D8 lane16): witness func_02021F3C filed as src/matched/arm9/func_02021F3C.c (EXACT); this file becomes EXACT once the integrator seeds that label/manifest. Body unchanged.
 */
void func_021B6C7C(int *p, int idx)
{
    Ent *e;
    int a, b, n;
    int i;
    int v;

    e = (Ent *)((u8 *)p + 0xC + idx * 8);
    if (idx >= 4) {
        func_02034714(d_021BABE0, (int)0, d_021BABE0);
    }
    a = func_021B6E00((int)idx);
    b = func_021B6E0C((int)idx);
    n = func_021B6E18(idx);
    switch (e->state) {
    case 1:
        v = e->v;
        if (e->dir == 0) {
            v += 0x80;
            if (v >= 0x1100) {
                v = 0x1000;
                e->dir ^= 1;
            }
        } else {
            v -= 0x80;
            if (v <= 0) {
                v = 0x100;
                e->dir ^= 1;
            }
        }
        e->v = v;
        for (i = 0; i < n; i++) {
            func_02021FD8((struct Chan02021FD8 *)(*(int *)p[1]), (int)idx, (u16)(a + i), (u16)1, v >> 8,
                          func_02021F3C(*(int *)p[1], idx, 1, b + i));
        }
        break;
    case 2:
        if (e->timer == 0) {
            e->timer = 3;
            if (e->v == 0) {
                e->v = 0x1000;
            } else {
                e->v = 0;
                e->cnt++;
                if (e->cnt > 1) {
                    func_021B6DB4(p, 0, idx);
                }
            }
            for (i = 0; i < n; i++) {
                func_02021FD8((struct Chan02021FD8 *)(*(int *)p[1]), (int)idx, (u16)(a + i), (u16)1, e->v >> 8,
                              func_02021F3C(*(int *)p[1], idx, 1, b + i));
            }
        } else {
            e->timer--;
        }
        break;
    }
}

void func_021B6DB4(int *p, int a, int idx)
{
    void func_02082BCC(void *, int, int);
    int func_021B6E00(unsigned int x);
    int func_021B6E18(int);
    void func_02021FD8(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
    u8 *e;

    e = (u8 *)p + 0xC + idx * 8;
    func_02082BCC(e, 0, 8);
    e[2] = a;
    func_02021FD8((struct Chan02021FD8 *)(*(int *)p[1]), (int)idx, (u16)func_021B6E00(idx), (u16)func_021B6E18(idx), 0, 0);
}

/*
 * Two bounded constant selectors and a constant return.
 */
int func_021B6E00(unsigned int x)
{
    return x <= 1 ? 0x32 : 0x12;
}


int func_021B6E0C(unsigned int x)
{
    return x <= 1 ? 0x42 : 0x22;
}


int func_021B6E18(int a0)
{
    return 3;
}


/*
 * The 0/1 flag is written in each if/else arm (param.f14 and param.f12 stores), so the
 * param address stays in r0 across the diamond and tail merging rebuilds the join. Callee
 * types from matched definitions (02043678 returns Bmp *, 020255A0 Grid *, 02045EC0 void *,
 * 020457B0 U16Vec *). Twin ov071 021B6A0C. final push 2026-10-05 G7L5.
 */
void func_021B6E1C(Ctx_021B6E1C *a, Out_021B6E1C *b, int c, int x, int y, int w, int h, int g, void *ws)
{
    struct Param param = d_021BA82C;
    void *bmp;
    void *s;
    void *t;

    bmp = func_02043678(w, h, 0x20, 0x61);
    b->bmp = bmp;
    param.x = x - (w / 2) * 8;
    param.y = y - (h / 2) * 8;
    param.bmp = bmp;
    param.f8 = a->res[c].f4c;
    if (c == 0) {
        param.f14 = 0;
        param.f12 = 0;
    } else {
        param.f14 = 1;
        param.f12 = 1;
    }
    b->grid = func_020255A0(a->f2c, &param);
    s = func_02045EC0(a->f28, g);
    if (ws) {
        t = func_020457B0(0x80, 0x61);
        func_0201F250(ws, t, s);
        func_0201C6FC(a->f8, (u32)b->bmp, 0, 0, t, (u32)a->fc);
        func_02045808(t);
    } else {
        func_0201C6FC(a->f8, (u32)b->bmp, 0, 0, s, (u32)a->fc);
    }
    func_02045808(s);
    b->on = 1;
}

void func_021B6EEC(void **p) { func_0202570C(p[1]); func_020437AC(p[0]); p[1] = 0; p[0] = 0; }

int func_021B6F04(void **p, u8 *q) { if(q[8]==1) { if(func_0201C6C4(p[2], (void *)(*(unsigned *)&((struct Obj06183 *)q)->f0))==0) { func_020257D0(((struct Obj06183 *)q)->f4); q[8]=0; return 1; } } return 0; }
