/*
 * file:     musical_dressup_sys_p08.c
 * unit:     yes
 * function: func_02157000, func_0215700C, func_02157028, func_0215716C, func_02157174, func_0215725C, func_02157260, func_02157278, func_02157298, func_021572A8, func_021572C0, func_021572E4, func_02157364, func_0215736C, func_02157374, func_02157384, func_02157394, func_0215739C, func_02157450, func_02157650, func_0215765C, func_02157660, func_02157664, func_02157668
 * address:  0x02157000
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   _s32_div_f  0x0209C0A4  arm
 *   func_0203F0A8  0x0203F0A8  arm
 *   _ull_mul  0x0209C054  arm
 *   d_02172768  0x02172768  data
 *   func_020307B0  0x020307B0  arm
 *   func_021F4F14  0x021F4F14  thumb  ov112
 *   func_021F5140  0x021F5140  thumb  ov112
 *   func_021F4F40  0x021F4F40  thumb  ov112
 *   func_02156FD0  0x02156FD0  thumb  ov010
 *   func_02029BCC  0x02029BCC  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020124AC  0x020124AC  thumb
 *   func_020130DC  0x020130DC  thumb
 *   func_02029C00  0x02029C00  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_02029CC0  0x02029CC0  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_021550A0  0x021550A0  thumb  ov008
 *   ov008_id       0x00000008  data
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_02013790  0x02013790  thumb
 *   func_020137C0  0x020137C0  thumb
 *   func_02013864  0x02013864  thumb
 *   func_02013894  0x02013894  thumb
 *   func_020137F0  0x020137F0  thumb
 *   func_02013128  0x02013128  thumb
 *   func_02013160  0x02013160  thumb
 *   func_02013980  0x02013980  thumb
 *   func_02034714  0x02034714  arm
 *   d_0217277C     0x0217277C  data
 */
#include "../../matched/include/Obj17621.h"
#include "../../matched/include/Obj18732.h"
#include "../../matched/include/Obj18733.h"
#include "../../matched/include/Obj12027.h"
#include "../../matched/include/Obj17622.h"

struct Stage;
struct Evt;
struct Desc;
struct Ctx;
struct Entry;
struct ZoneData;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef struct Rec6_02157000 {
    u16 id;             /* 0x00 */
    s16 f02;            /* 0x02 */
    u8 f04;             /* 0x04 */
    u8 pad05;
} Rec6_02157000;

typedef struct Obj_02157000 {
    u8 pad00[0x14];
    Rec6_02157000 recs[9];       /* 0x14 */
} Obj_02157000;

typedef struct Stage {
    void *f00;          /* 0x00 */
    Obj_02157000 *f04[4];        /* 0x04 */
} Stage;

typedef unsigned long long u64;

typedef struct Ent_02157028 {
    u8 f00;             /* 0x00 */
    u8 f01[4];          /* 0x01 */
    u8 f05;             /* 0x05 */
    u8 pad06[0x14 - 0x06];
    u16 f14;            /* 0x14 */
    u8 pad16[0x2C - 0x16];
} Ent_02157028;

typedef struct Src {
    u32 f00;
    Ent_02157028 *f04;           /* 0x04 */
} Src;

typedef struct Deal_02157028 {
    u8 f00[4];          /* 0x00 */
    u8 f04[4];          /* 0x04 */
    u8 f08[4];          /* 0x08 */
    Ent_02157028 *f0C;           /* 0x0C */
} Deal_02157028;

typedef struct Rec6_02157028 {
    u16 id;
    u8 pad[4];
} Rec6_02157028;

typedef struct Member {
    u8 pad00[0x14];
    Rec6_02157028 recs[9];       /* 0x14 */
    u16 total;          /* 0x4A */
    u16 part[4];        /* 0x4C */
} Member;

typedef struct Party {
    u32 f00;
    Member *members[4]; /* 0x04 */
} Party;

typedef struct Deal_02157174 {
    u8 f00[4];          /* 0x00 */
    u8 f04[4];          /* 0x04 */
} Deal_02157174;

typedef short s16_02157278;

typedef short s16_021572A8;

typedef struct Deal_021572A8 {
    u8 f00[4];          /* 0x00 */
    u8 f04[4];          /* 0x04 */
    u8 f08[4];          /* 0x08 */
} Deal_021572A8;

typedef struct Deal_021572C0 {
    u8 f00[4];          /* 0x00 */
} Deal_021572C0;

typedef struct Move {
    u16 id;             /* 0x00 */
    u8 f02;             /* 0x02 */
    u8 pad03;
} Move;

typedef struct Ent_021572E4 {
    u16 f00;            /* 0x00 */
    u8 f02[4];          /* 0x02 */
    u16 f06;            /* 0x06 */
    u8 pad08[4];
    Move moves[8];      /* 0x0C */
} Ent_021572E4;

typedef struct Tbl {
    u8 pad00[0x0C];
    Ent_021572E4 ents[1];        /* 0x0C */
} Tbl;

typedef struct Deal_021572E4 {
    u8 f00[4];          /* 0x00 */
    u8 f04[4];          /* 0x04 */
    u8 f08[4];          /* 0x08 */
    Tbl *f0C;           /* 0x0C */
} Deal_021572E4;

typedef signed short   s16_021572E4;

typedef signed char s8;

typedef short s16_02157374;

typedef struct Slot {
    u8 pad00[0xE];
    u8 f0e;             /* 0x0E */
    u8 pad0f[0x2C - 0xF];
} Slot;

typedef struct Deal_02157374 {
    u8 pad00[8];
    u8 map[4];          /* 0x08 */
    Slot *slots;        /* 0x0C */
} Deal_02157374;

typedef struct Rec2C {
    u8 pad[0xF];
    u8 f0f;
    u8 pad10[0x1C];
} Rec2C;

typedef struct Table {
    u8 pad[8];
    u8 index[4];        /* 0x08 */
    Rec2C *recs;        /* 0x0C */
} Table;

typedef struct Obj_02157028 {
    u8 pad00[0x18];
    u16 f18;            /* 0x18 */
} Obj_02157028;

typedef struct Work_0215739C {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    Obj_02157028 f08;            /* 0x08 */
    u8 pad[0xF8 - 0x08 - sizeof(Obj_02157028)];
    void *fF8;          /* 0xF8 */
} Work_0215739C;

typedef struct Args {
    Obj_02157028 *obj;
    void *sub;
    u32 zero;
} Args;

typedef struct Sub {
    u8 pad00[0x48];
    int f48;            /* 0x48 */
    int f4c;            /* 0x4C */
} Sub;

typedef struct Rec {
    void *f00;          /* 0x00 */
    u8 pad04[0x0C];
    u16 f10;            /* 0x10 */
    u8 f12;             /* 0x12 */
    u8 pad13;
    void *f14;          /* 0x14 */
    Sub f18;            /* 0x18 */
} Rec;

typedef struct Work_02157450 {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    Obj_02157028 f08;            /* 0x08 */
    u8 pad[0xF8 - 0x08 - sizeof(Obj_02157028)];
    Sub *fF8;           /* 0xF8 */
} Work_02157450;

extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern u32 func_0203F0A8(void);
extern u32 func_020307B0(void *);
extern u32 *func_021F4F14(int heap);
extern unsigned char func_021F5140(void *p, int i);
extern void func_021F4F40(void **p);
extern int _s32_div_f(int dividend, int divisor);
extern void func_02156FD0(Stage *, u8, u16, u8, u32, u16, u16);
extern void *func_02029BCC(void *a, u32 b);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern struct Desc *func_020124AC(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern void func_020130DC(Obj_02157028 *o);
extern void *func_02029C00(void *h);
extern void *func_020145CC(void *h);
extern void *func_02029CC0(void *h);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void *func_021550A0(void *a, const int *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *);
extern void *func_020120F4(const struct Ctx *p);
extern struct Entry *func_020399A8(void);
extern void func_02013790(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void func_020137C0(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void func_02013864(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void func_02013894(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void func_020137F0(u32 p0, u32 p1, u32 p2, u32 p3, u8 p4, u16 p5);
extern void func_02013128(void *p, void *src, int i);
extern void func_02013160(u8 *o, void *a1, u32 a2);
extern void func_02013980(struct ZoneData *o, u32 heap);
extern void func_02034714(const char *expr, u32 line, const char *file);
int func_02157000(int a0, int a1, int a2);
void func_0215700C(Stage *s, u8 idx, u8 j, u16 id, s16 a, u8 b);
int func_0215716C(void *);
void func_02157174(u32 heap, Deal_02157174 *d, Party *party);
u8 func_0215725C(u8 *p, int i);
u32 func_02157260(const u8 *p);
void func_02157278(u8 *p, u32 v);
u32 func_02157298(const u8 *p);
void func_021572A8(Deal_021572A8 *d, u32 v);
u8 func_021572C0(Deal_021572C0 *d);
u8 func_02157364(char *a0);
int func_0215736C(int a0);
u8 func_02157374(Deal_02157374 *d, u8 i);
u8 func_02157384(struct Table *, int);
u16 func_02157394(int a0, int a1);
int func_0215739C(void *evt, u32 *state, Work_0215739C *w);
void *func_02157450(void *a0, void *a1, u32 kind, Rec *rec);
void func_02157650(int *p, int v);
extern const char d_02172768[];
extern u8 ov008_id[];
extern u8 d_0217277C[];





int func_02157000(int a0, int a1, int a2)
{
    int a3;

a3 = a0 + 4;
a0 = a1 << 2;
*(int *)((char *)a3 + a0) = a2;
a0 = 1;
((struct Obj17621 *)((char *)a2))->f0 = a0;
    return a0;}



void func_0215700C(Stage *s, u8 idx, u8 j, u16 id, s16 a, u8 b)
{
    Obj_02157000 *o;

    o = s->f04[idx];
    o->recs[j].id = id;
    o->recs[j].f02 = a;
    o->recs[j].f04 = b;
}



static inline u32 RandN(u32 n)
{
    u32 r = func_0203F0A8();

    if (n != 0)
        r = ((u64)r * n) >> 32;
    return r;
}



/*
 * Deals four stat bonuses and picks three of six entries at random. The
 * candidate buffer is `u8 buf[6] = {0, ...}` in a nested block (see
 * docs/idioms/an-initialised-local-array-takes-its-address-before-the-stores.md):
 * six explicit zero stores rematerialise sp+8 for the fill loop, and a plain
 * block-scope array hoists d->f0C out of it. RandN is the inline
 * `(u64)rand * n >> 32` helper; its n != 0 test folds away for constant n.
 */
Deal_02157028 *func_02157028(u32 heap, Src *src, u16 lim)
{
    Deal_02157028 *d;
    u8 i;
    u8 n;
    u8 k;
    u8 cnt;
    u8 a;
    u8 b;
    u8 t;

    d = func_02030734(heap, 0x10, 0, d_02172768, 100);
    d->f0C = src->f04;
    for (i = 0; i < 4; i++) {
        d->f00[i] = 0;
        d->f04[i] = 0;
    }
    for (i = 0; i < 4; i++)
        d->f00[i] = d->f0C->f01[i];
    n = d->f0C->f05 / 5;
    while (n != 0) {
        k = RandN(3) + 1;
        if (k > n)
            k = n;
        d->f00[RandN(4)] += (u8)(k * 5);
        n -= k;
    }
    {
        u8 buf[6] = {0, 0, 0, 0, 0, 0};

        cnt = 0;
        for (i = 0; i < 6; i++) {
            if (d->f0C[i].f14 <= lim) {
                buf[cnt] = i;
                cnt++;
            }
        }
        if (cnt < 3) {
            buf[0] = 0;
            buf[1] = 1;
            buf[2] = 2;
            cnt = 3;
        }
        for (t = 0; t < 30; t++) {
            a = RandN(cnt);
            b = RandN(cnt);
            k = buf[a];
            buf[a] = buf[b];
            buf[b] = k;
        }
        for (i = 0; i < 3; i++)
            d->f08[i] = buf[i];
    }
    return d;
}



/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_020307B0, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0215716C.c \
 *       --func func_0215716C --addr 0x0215716C --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0215716C(void *a0){

    func_020307B0(a0);
}



/*
 * Splits each deal bonus over the four members by how many of their nine
 * records fall in each category (232 bytes, ov010 battle overlay).
 * recoup 2026-10-05 (wave P10 Y7): the loop 2 and loop 4 member pointer and
 * the loop 2 byte counter j are block-local declarations (Member *m inside each
 * for body, u8 j inside the loop 2 body). Function-scope m and j gave 21 bytes
 * of register swaps. Pragmas (lifetimes, propagation, common_subs,
 * dead_assignments, scheduling, peephole), row pointer, id local, const party
 * all left 21 or worse. Verified EXACT in c99 and c.
 */
void func_02157174(u32 heap, Deal_02157174 *d, Party *party)
{
    void *h;
    u8 i;
    u8 j;
    u8 t;
    u8 v;
    u8 tot[4];
    u8 cnt[4][4];

    h = func_021F4F14((u32)heap);
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++)
            cnt[j][i] = 0;
        tot[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        Member *m = party->members[i];
        u8 j;
        for (j = 0; j < 9; j++) {
            if (m->recs[j].id != 0xFF) {
                t = (u32)func_021F5140(h, (u16)m->recs[j].id);
                cnt[i][t]++;
                tot[t]++;
            }
        }
    }
    for (i = 0; i < 4; i++)
        d->f04[i] = _s32_div_f(d->f00[i], tot[i]);
    for (i = 0; i < 4; i++) {
        Member *m = party->members[i];
        for (j = 0; j < 4; j++) {
            v = d->f04[j] * cnt[i][j];
            m->total += v;
            m->part[j] = v;
        }
    }
    func_021F4F40(h);
}


u8 func_0215725C(u8 *p, int i) { return p[i]; }



/*
 * Little-endian 32-bit read from a byte record (inverse of func_02157278).
 */
u32 func_02157260(const u8 *p)
{
    return p[0] + (p[1] << 8) + (p[2] << 16) + (p[3] << 24);
}



/*
 * EXACT* because the listing folds the unlabelled 24-bit reader at
 * 0x02157298 into this extent.
 */
void func_02157278(u8 *p, u32 v)
{
    p[0] = v;
    p[1] = (v & 0xFF00) >> 8;
    p[2] = (v & 0xFF0000) >> 16;
    p[3] = (v & 0xFF000000) >> 24;
}



/*
 * Little-endian 24-bit read from bytes 8..10 of a record (inverse of
 * func_021572A8).
 */
u32 func_02157298(const u8 *p)
{
    return p[8] + (p[9] << 8) + (p[10] << 16);
}



void func_021572A8(Deal_021572A8 *d, u32 v)
{
    d->f08[0] = v;
    d->f08[1] = (v & 0xFF00) >> 8;
    d->f08[2] = (v & 0xFF0000) >> 16;
}



/*
 * Declaration order i, max, idx is what colours them r2, r3, r4.
 */
u8 func_021572C0(Deal_021572C0 *d)
{
    u8 i;
    u8 max;
    u8 idx;

    max = 0;
    idx = 0;
    for (i = 0; i < 4; i++) {
        if (max < d->f00[i]) {
            max = d->f00[i];
            idx = i;
        }
    }
    return idx;
}



/*
 * The stage slot b is a u8 (as wide as either callee's parameter); a u32
 * or int b is reloaded from its spill one instruction early. The u32 is
 * spelled out in the call, not through an inline reader, so the top byte is
 * loaded once and kept in ip for the fourth argument.
 */
void func_021572E4(Deal_021572E4 *d, void *a, u8 b, u8 slot, u16 y)
{
    Ent_021572E4 *e;
    u8 j;

    e = &d->f0C->ents[d->f08[slot]];
    func_02156FD0(a, b, e->f00, e->f02[3], e->f02[0] + (e->f02[1] << 8) + (e->f02[2] << 16) + (e->f02[3] << 24), e->f06, y);
    for (j = 0; j < 8; j++) {
        if (e->moves[j].id != 0x1FE && e->moves[j].id != 0x1FF)
            func_0215700C(a, b, e->moves[j].f02, e->moves[j].id, 0, j);
    }
}



/*
 * Recursive MATCH unblocker: callee of func_021F8D88 (ov132) +0008. Coherent
 * Thumb leaf in ov010 (ARM code in ov009), so the ov010 shard makes that site
 * attest as `matched` -- the earlier `arm` declaration was wrong.
 */
u8 func_02157364(char *a0)
{
    return ((struct Obj18733 *)(((struct Obj18732 *)a0)->fC))->f0;
}





int func_0215736C(int a0)
{

a0 = ((struct Obj12027 *)a0)->fC;
a0 = ((struct Obj12027 *)a0)->f6;
    return a0;}



u8 func_02157374(Deal_02157374 *d, u8 i)
{
    return d->slots[d->map[i]].f0e;
}



/*
 * Unlabelled leaf: the byte at +0xF of the 0x2C-byte record that slot i
 * of the index table at +8 selects.
 */
u8 func_02157384(struct Table *t, int i){
    return t->recs[t->index[i]].f0f;
}





u16 func_02157394(int a0, int a1)
{

a0 = a0 + a1;
a0 = ((struct Obj17622 *)a0)->f4;
    return a0;}



/*
 * Task callback of func_02157450: a 10-state sequence that pushes the
 * field-effect child tasks (the ov008 effect runner gets the effect
 * object, its direction record and a zero word) and returns 1 when done.
 */
int func_0215739C(void *evt, u32 *state, Work_0215739C *w)
{
    void *h = w->f00;

    switch (*state) {
    case 0:
        *state = 3;
        break;
    case 1:
    case 2:
        break;
    case 3:
        func_02012374(evt, func_02029BCC(h, w->f08.f18));
        (*state)++;
        break;
    case 4: {
        Args a;

        a.obj = &w->f08;
        a.sub = w->fF8;
        a.zero = 0;
        func_02012374(evt, (struct Evt **)func_020124AC(h, (u32)ov008_id, (u32 (*)(void *, u32))func_021550A0, (u32)(&a)));
        (*state)++;
        break;
    }
    case 5:
        func_020130DC(&w->f08);
        func_02012374(evt, func_02029C00(h));
        (*state)++;
        break;
    case 6:
        func_02012374(evt, func_020145CC(h));
        (*state)++;
        break;
    case 7:
        func_02012374(evt, (struct Evt **)func_021BE92C(h, (int)w->f04, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 8:
        func_02012374(evt, func_02029CC0(h));
        (*state)++;
        break;
    case 9:
        return 1;
    }
    return 0;
}



/*
 * Create the ov010 field-effect task: allocate it with func_0215739C as
 * its callback, pick the direction slot for effect kinds 4..23 (four kinds
 * per effect, the first matching case wins), start the effect object and
 * return the task.
 */
void *func_02157450(void *a0, void *a1, u32 kind, Rec *rec)
{
    int dir = 0x29;
    void *task = func_020122C0(a0, 0, func_0215739C, 0xFC);
    Work_02157450 *w = func_020124E8(task);
    Obj_02157028 *o;
    void *sys;

    w->f00 = a0;
    w->f04 = a1;
    w->fF8 = &rec->f18;
    o = &w->f08;
    switch (kind) {
    case 5:
        func_02157650(&dir, 0);
    case 4:
        func_02157650(&dir, 2);
    case 7:
        func_02157650(&dir, 1);
    case 6:
        func_02157650(&dir, 3);
        sys = func_020120F4(a0);
        func_02013790((u32)o, (u32)sys, (u32)func_020399A8(), 1, 4);
        break;
    case 9:
        func_02157650(&dir, 4);
    case 8:
        func_02157650(&dir, 6);
    case 11:
        func_02157650(&dir, 5);
    case 10:
        func_02157650(&dir, 7);
        sys = func_020120F4(a0);
        func_020137C0((u32)o, (u32)sys, (u32)func_020399A8(), 1, 4);
        break;
    case 13:
        func_02157650(&dir, 8);
    case 12:
        func_02157650(&dir, 10);
    case 15:
        func_02157650(&dir, 9);
    case 14:
        func_02157650(&dir, 11);
        sys = func_020120F4(a0);
        func_02013864((u32)o, (u32)sys, (u32)func_020399A8(), 1, 4);
        break;
    case 17:
        func_02157650(&dir, 12);
    case 16:
        func_02157650(&dir, 14);
    case 19:
        func_02157650(&dir, 13);
    case 18:
        func_02157650(&dir, 15);
        sys = func_020120F4(a0);
        func_02013894((u32)o, (u32)sys, (u32)func_020399A8(), 1, 4);
        break;
    case 21:
        func_02157650(&dir, 16);
    case 20:
        func_02157650(&dir, 18);
    case 23:
        func_02157650(&dir, 17);
    case 22:
        func_02157650(&dir, 19);
        sys = func_020120F4(a0);
        func_020137F0((u32)o, (u32)sys, (u32)func_020399A8(), 1, rec->f12, 4);
        break;
    default:
        func_02034714((const char *)d_0217277C, 0, (const char *)d_0217277C);
        return 0;
    }
    func_02013128(o, rec->f00, 0);
    func_02013160((u8 *)o, rec->f14, 4);
    o->f18 = rec->f10;
    w->fF8->f48 = dir;
    w->fF8->f4c = 0;
    func_02013980((struct ZoneData *)o, 1);
    return task;
}


/*
 * Unlabelled leaf after func_02157450's pool: store v into *p only while
 * *p still holds the unset sentinel 0x29, so the first call wins.
 */
void func_02157650(int *p, int v)
{
    if (*p == 0x29)
        *p = v;
}


void func_0215765C(void);
void func_02157660(void);
void func_02157664(void);
void func_02157668(void);

/* Four empty leaves (unused callback slots). */
void func_0215765C(void)
{
}

void func_02157660(void)
{
}

void func_02157664(void)
{
}

void func_02157668(void)
{
}
