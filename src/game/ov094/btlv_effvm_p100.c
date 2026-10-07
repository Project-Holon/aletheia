/*
 * file:     btlv_effvm_p100.c
 * unit:     yes
 * function: func_022057CC, func_02205AB8, func_02205B80, func_02205B90, func_02205D34, func_02205D58, func_02205E30, func_02205E80
 * address:  0x022057CC
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
 *   d_0220A50C 0x0220A50C data a4
 *   d_0220A392 0x0220A392 data a2
 *   d_0220AEB0 0x0220AEB0 data a1
 *   func_020490F4 0x020490F4 arm
 *   func_0201BC78 0x0201BC78 thumb
 *   func_0201BCEC 0x0201BCEC thumb
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0204AEF4 0x0204AEF4 arm
 *   func_020216D4 0x020216D4 thumb
 *   func_02030734 0x02030734 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_0220684C 0x0220684C thumb ov094
 *   func_02204BCC 0x02204BCC thumb ov094
 *   func_0201BABC 0x0201BABC thumb
 *   func_0201BB5C 0x0201BB5C thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_02049238 0x02049238 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_02204C48 0x02204C48 thumb ov094
 *   d_0220A558 0x0220A558 data ov094 a4
 *   d_0220A56C 0x0220A56C data ov094 a4
 *   d_0220A544 0x0220A544 data ov094 a4
 *   func_02030DA8 0x02030DA8 arm
 *   func_02204A88 0x02204A88 thumb ov094
 *   func_02204AEC 0x02204AEC thumb ov094
 *   d_0220A580     0x0220A580  data   ov094  a4
 *   func_0204B3DC  0x0204B3DC  arm
 */
#include "../../matched/include/Obj01049.h"
#include "../../matched/include/Obj21785.h"
#include "../../matched/include/Obj00896.h"
#include "../../matched/include/Obj06327.h"
#include "../../matched/include/Obj00083.h"
#include "../../matched/include/Obj21787.h"

struct Obj;
struct PalAnmSlot;
struct Vec2;
struct Bank;
struct Ctx;
struct Node;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef struct Point { s16 x, y; } Point;

typedef struct Pair { void *obj; u32 pad; } Pair;

typedef struct Main {
    unsigned char pad00[0x50];
    int mode;
    unsigned char pad54[0x64 - 0x54];
    void *pal;
    unsigned char pad68[0x1b0 - 0x68];
    u32 h1b0[3];
    u32 h1bc;
    u32 h1c0;
    u32 h1c4;
    Pair h1c8[3];
    unsigned char pad1e0[0x240 - 0x1e0];
    u16 heap;
} Main;

typedef struct Info {
    unsigned char pad00[0x98];
    u32 species[3];
    u32 form[3];
    u32 gender[3];
    int sel;
} Info;

typedef struct { void *entry; int extra; } Entry;

typedef struct { char pad[0x1c8]; Entry entries[3]; } Work;

typedef struct Five { int v[5]; } Five;

typedef struct Bits { u32 low : 1; u32 count : 3; u32 high : 28; } Bits;

typedef struct { void *h; } E;

typedef struct { char pad[0x210]; E a[2]; } W;

typedef struct { void *h; int x; } Slot;

typedef struct {
    int v[6];
} Q;

extern void *func_020490F4(u32 id, u32 heap);
extern int func_0201BC78(void);
extern int func_0201BCEC(void);
extern int func_0201BC3C(void);
extern int func_0204AF28(void *, u32, u32, u32);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0204AEF4(u32 idx, u32 alternate);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *func_020056A0(void *cb, void *ctx, int a);
extern void func_0220684C(char *p, int a, int b);
extern void func_02204BCC(void *a0, int *c);
extern u32 func_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
extern u32 func_0201BB5C(u32 species, u32 form, u32 half, u32 isEgg);
extern int func_0204A6C8(void *, u32, u32, u32, u16);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_02049238(void *);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(unsigned int h);
extern void func_0204AFD8(unsigned int h);
extern void func_0204ADA4(unsigned int h);
extern void func_02204C48(void *, int *);
extern void func_0204B22C(struct Bank *bank, u32 mode);
extern struct Node *func_02030DA8(struct Ctx *c, u32 a, u32 b, u32 key);
extern void func_02204A88(int a0, struct Ctx *c);
extern void func_02204AEC(void *);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
void func_022057CC(Main *m, Info *q);
void func_02205AB8(char *p);
void func_02205B80(char *p, int a);
void func_02205B90(char *p, int n);
void func_02205D34(W *p);
void func_02205D58(char *p, int mode);
void func_02205E30(char *o);
void func_02205E80(char *m);
extern const Point d_0220A50C[][3];
extern const u16 d_0220A392[];
extern const char d_0220AEB0[];
extern const Five d_0220A558, d_0220A56C, d_0220A544;
extern const Q d_0220A580;

void func_022057CC(Main *m, Info *q)
{
    int n;
    void *arc;
    int i;
    int k;
    void **r;
    const Point *pt;
    s16 x, y;

    n = (m->mode == 3) ? 2 : m->mode + 1;
    k = 0;
    if (m->mode == 0 || m->mode == 3)
        return;
    arc = func_020490F4(7, (u16)((m->heap & 0x7fff) | 0x8000));
    m->h1c0 = func_0204AF28(arc, func_0201BC78(), func_0201BCEC(), m->heap);
    m->h1bc = func_0204ACEC(arc, func_0201BC3C(), 1, 0x160, m->heap);
    func_020216D4(m->pal, 3, (u16)(func_0204AEF4(m->h1bc, 1) >> 1), 0x60);
    *(volatile u16 *)0x04001040 = 0x100;
    *(volatile u16 *)0x04001044 = 0;
    *(volatile u16 *)0x04001042 = 0x100;
    *(volatile u16 *)0x04001046 = 0;
    if (n > 1) {
        r = func_02030734((u16)((m->heap & 0x7fff) | 0x8000), 8, 0, d_0220AEB0, 0x1145);
        r[0] = m;
        r[1] = (void *)n;
        func_0220684C((char *)m, (int)func_020056A0((void *)func_02204BCC, r, 0), 0);
    }
    for (i = 0; i < n; i++) {
        if (q->species[i] != 0) {
            m->h1b0[i] = func_0204A6C8(arc, func_0201BABC(q->species[i], q->form[i], q->gender[i], 0), 0, 1, m->heap);
            m->h1c8[i].obj = func_0204B294((void *)m->h1c4, m->h1b0[i], m->h1bc, m->h1c0, d_0220A392, 1, m->heap);
            func_0204B404(m->h1c8[i].obj, (const struct Vec2 *)(&d_0220A50C[m->mode][i]), 1);
            func_0204B92C(m->h1c8[i].obj, 1);
            if (q->sel == i) {
                func_0204B878(m->h1c8[i].obj, 1);
            } else if (k == 0) {
                pt = &d_0220A50C[m->mode][i];
                x = pt->x;
                y = pt->y;
                *(volatile u16 *)0x04001040 = (((x - 16) << 8) & 0xff00) | (u8)(x + 16);
                *(volatile u16 *)0x04001044 = (((y - 16) << 8) & 0xff00) | (u8)(y + 16);
                k++;
            } else {
                pt = &d_0220A50C[m->mode][i];
                x = pt->x;
                y = pt->y;
                *(volatile u16 *)0x04001042 = (((x - 16) << 8) & 0xff00) | (u8)(x + 16);
                *(volatile u16 *)0x04001046 = (((y - 16) << 8) & 0xff00) | (u8)(y + 16);
            }
            func_0204B6F4(m->h1c8[i].obj, func_0201BB5C(q->species[i], q->form[i], q->gender[i], 0), 0);
        }
    }
    func_02049238(arc);
}

/*
 * lever: entry reads use the indexed aggregate; the zero store uses its raw
 * offset. This avoids retaining a common entry pointer across both frees.
 */
void func_02205AB8(char *p)
{
    int i;
    int empty = 1;
    int *ctx;
    for (i = 0; i < 3; i++) {
        if (((Work *)p)->entries[i].entry != 0) {
            func_0204B3B4(((Work *)p)->entries[i].entry);
            func_0204A8D4(*(int *)(p + i * 4 + 0x1b0));
            *(void **)(p + i * 8 + 0x1c8) = 0;
            *(int *)(p + i * 4 + 0x1b0) = -1;
            empty = 0;
        }
    }
    if (((struct Obj01049 *)p)->f1C0 != -1) {
        func_0204AFD8(((struct Obj01049 *)p)->f1C0);
        ((struct Obj01049 *)p)->f1C0 = -1;
    }
    if (((struct Obj01049 *)p)->f1BC != -1) {
        func_0204ADA4(((struct Obj01049 *)p)->f1BC);
        ((struct Obj01049 *)p)->f1BC = -1;
    }
    if (!empty) {
        ctx = func_02030734((u16)((((struct Obj01049 *)p)->f240 & 0x7fff) | 0x8000), 8, 0, d_0220AEB0, 0x11b2);
        ctx[0] = (int)p;
        func_0220684C(p, (int)func_020056A0((void *)func_02204C48, ctx, 0), 0);
    }
}


void func_02205B80(char *p, int a)
{
    func_0204B22C(((struct Obj21785 *)p)->f1C4, a);
}

void func_02205B90(char *p, int n)
{
    Five a = d_0220A558;
    Five b = d_0220A56C;
    Five c = d_0220A544;
    Point v;
    int index;
    void **q;
    if (n == 0) return;
    ((struct Obj00896 *)p)->f210 = func_0204B294((void *)((struct Obj00896 *)p)->f20C, ((struct Obj00896 *)p)->f104, ((struct Obj00896 *)p)->f108, ((struct Obj00896 *)p)->f10C, d_0220A392, 1, ((struct Obj00896 *)p)->f240);
    index = n - 1;
    v.x = 0x130 + b.v[index];
    v.y = 0x20 + c.v[index];
    func_0204B404(((struct Obj00896 *)p)->f210, (const struct Vec2 *)(&v.x), (int)1);
    func_0204B92C(((struct Obj00896 *)p)->f210, 1);
    n += 14;
    func_0204B878(((struct Obj00896 *)p)->f210, n);
    ((struct Obj00896 *)p)->f214 = func_0204B294((void *)((struct Obj00896 *)p)->f20C, ((struct Obj00896 *)p)->f104, ((struct Obj00896 *)p)->f108, ((struct Obj00896 *)p)->f10C, d_0220A392, 1, ((struct Obj00896 *)p)->f240);
    v.x = 0x130;
    v.y = 0x20;
    func_0204B404(((struct Obj00896 *)p)->f214, (const struct Vec2 *)(&v.x), (int)1);
    func_0204B92C(((struct Obj00896 *)p)->f214, 1);
    func_0204B878(((struct Obj00896 *)p)->f214, 14);
    func_0204B6F4(((struct Obj00896 *)p)->f214, (u8)a.v[index], 0);
    q = func_02030734((u16)((((struct Obj00896 *)p)->f240 & 0x7fff) | 0x8000), 4, 0, d_0220AEB0, 0x11ec);
    q[0] = p;
    func_0220684C(p, (int)func_02030DA8(((struct Obj00896 *)p)->f0, (u32)func_02204A88, (u32)q, 0), (int)((void *)func_02204AEC));
    ((Bits *)(p + 0x68))->count++;
}


void func_02205D34(W *p)
{
    int i;

    for (i = 0; i < 2; i++) {
        if (p->a[i].h != 0) {
            func_0204B3B4(p->a[i].h);
            p->a[i].h = 0;
        }
    }
}


void func_02205D58(char *p, int mode)
{
    Slot *slots;
    Point pos;
    int add;
    int step;
    char *row;
    int i;

    if (mode == 1) {
        slots = (Slot *)(p + 0x14c);
        pos.x = 0x94;
        pos.y = 0x30;
        step = -8;
        add = 4;
    } else {
        slots = (Slot *)(p + 0x11c);
        pos.x = 0x58;
        pos.y = 0x88;
        step = 0x10;
        add = 0;
    }
    i = 0;
    row = p + mode * 0x48;
    for (; i < 6; i++) {
        slots[i].h = func_0204B294((void *)((struct Obj06327 *)p)->f118, ((struct Obj06327 *)p)->f104, ((struct Obj06327 *)p)->f108, ((struct Obj06327 *)p)->f10C, d_0220A392, 1, ((struct Obj06327 *)p)->f240);
        func_0204B404(slots[i].h, (const struct Vec2 *)(&pos), 1);
        func_0204B92C(slots[i].h, 1);
        func_0204B878(slots[i].h, add + *(u8 *)(row + i * 12 + 0x75));
        pos.x += (s16)step;
    }
}


/*
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`off = 0x11c;` before `off = 0x14c;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT* in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 */
void func_02205E30(char *o)
{
    int i;
    int j;
    int off;
    char *p;

    i = 0;
    off = 0x14c;
    for (; i < 2; i++) {
        if (i != 0) {
            p = o + off;
        } else {
            p = o + 0x47 * 4;
        }
        for (j = 0; j < 6; j++) {
            if (*(void **)(p + j * 8) != 0) {
                func_0204B3B4(*(void **)(p + j * 8));
                *(void **)(p + j * 8) = 0;
            }
        }
    }
}


/*
 * note 2026-10-05 (wave D9r lane 131): removed the 5 dead first assignments
 * (`o0 = 0x240;` before `o0 = 0x17c;`; `o1 = 0x110;` before `o1 = 0x108;`
 * and 3 more). Game code has no line table, so these were stand-ins. The
 * plain single assignment gives EXACT in --lang c99 and --lang c: the output
 * bytes do not change. Older text in this header that asks for the double
 * assignment is superseded.
 */
void func_02205E80(char *m)
{
    Q q = d_0220A580;
    int o0;
    int o1;
    int o2;
    int o3;
    int o4;
    int o5;
    char *p;
    int j;

    o0 = 0x17c;
    o1 = 0x108;
    o2 = 0x114;
    o3 = 0x180;
    o4 = 0x180;
    o5 = 0x180;
    for (j = 0; j < 6; j++) {
        p = m + j * 8;
        *(u32 *)(p + o3) = (u32)func_0204B294((void *)*(u32 *)(m + o0), ((struct Obj00083 *)m)->f110, *(u32 *)(m + o1),
                                         *(u32 *)(m + o2), d_0220A392, 1, ((struct Obj00083 *)m)->f240);
        func_0204B92C((struct Obj *)*(int *)(p + o4), 1);
        func_0204B878((struct Obj *)(*(int *)(p + o5)), q.v[j]);
        func_0204B3DC((struct Obj *)((struct Obj21787 *)p)->f180, 0);
    }
}
