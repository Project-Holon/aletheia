/*
 * file:     musical_dressup_sys_p06.c
 * unit:     yes
 * function: func_02156530, func_02156710, func_02156770, func_021567D8, func_02156824, func_02156888, func_021568A8, func_021568E0, func_021568E8
 * address:  0x02156530
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
 *   func_0200A750  0x0200A750  thumb
 *   func_0200A81C  0x0200A81C  thumb
 *   func_02156934  0x02156934  thumb  ov010
 *   func_021FD8F8  0x021FD8F8  thumb  ov132
 *   func_021FD4F8  0x021FD4F8  thumb  ov132
 *   func_0215736C  0x0215736C  thumb  ov010
 *   func_0200A644  0x0200A644  thumb
 *   func_021572C0  0x021572C0  thumb  ov010
 *   func_02005728  0x02005728  thumb
 *   func_020307B0  0x020307B0  arm
 *   d_02172714  0x02172714  data
 *   d_0216FF14  0x0216FF14  data
 *   d_0216FF28  0x0216FF28  data
 *   func_020120F4  0x020120F4  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02029690  0x02029690  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_02029CC0  0x02029CC0  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_020295A4  0x020295A4  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_02029C64  0x02029C64  thumb
 *   func_021854B0  0x021854B0  thumb  ov020
 *   d_0216FEFC  0x0216FEFC  data
 *   d_0216FEF0  0x0216FEF0  data
 *   d_0216FF08  0x0216FF08  data
 *   func_02158768   0x02158768  thumb  ov010
 *   func_021589D0   0x021589D0  thumb  ov010
 *   func_021FCE28  0x021FCE28  thumb
 */
#include "../../matched/include/Obj17617.h"
#include "../../matched/include/Obj17618.h"

struct Big;
struct BigSub4;
struct Ctx;
struct Deal;
struct BigObj;
struct Evt;
struct Desc;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Rec6 {
    u16 id;
    u8 pad[4];
} Rec6;

typedef struct Member {
    u8 pad00[0x14];
    Rec6 recs[9];       /* 0x14 */
    u16 total;          /* 0x4A */
} Member;

typedef struct Party {
    u32 f00;
    Member *members[4]; /* 0x04 */
} Party;

typedef struct Work_02156530 {
    u8 pad00[0x04];
    void *f04;          /* 0x04 */
    u8 pad08[0x14 - 0x08];
    u32 f14;            /* 0x14 */
    void *f18;          /* 0x18 */
    u8 pad1C[0x28 - 0x1C];
    void *f28;          /* 0x28 */
    u8 pad2C[0x30 - 0x2C];
    Party *party;       /* 0x30 */
    u8 pad34[0x38 - 0x34];
    void *f38;          /* 0x38 */
    u8 pad3C[0x40 - 0x3C];
    void *f40;          /* 0x40 */
    u8 pad44[0x48 - 0x44];
    u8 f48;             /* 0x48 */
    u8 pad49[3];
    u8 f4C;             /* 0x4C */
} Work_02156530;

typedef struct Slot {
    u8 f00;             /* 0x00 */
    u8 f01;             /* 0x01 */
    u16 f02;            /* 0x02 */
} Slot;

typedef struct Seq {
    void *f00;          /* 0x00 */
    u8 pad04[0x10 - 0x04];
    u8 state;           /* 0x10 */
    u8 pad11[3];
    u32 f14;            /* 0x14 */
    u8 pad18[0x4C - 0x18];
    u8 f4C;             /* 0x4C */
} Seq;

typedef struct Pos {
    u32 x;
    u32 y;
    u32 z;
} Pos;

typedef signed short   s16;

typedef struct Work_021568A8 {
    u8 pad[0x28];
    void *f28;
} Work_021568A8;

typedef struct Work_021568E0 {
    u8 pad[0x4C];
    u8 f4c;
} Work_021568E0;

extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern struct BigSub4 *func_0200A750(struct Big *p, u32 index);
extern u16 func_0200A81C(struct Big *p);
extern u8 func_02156934(Work_02156530 *w, u8 idx);
extern u32 func_021FD8F8(char *p, u32 index);
extern u32 func_021FD4F8(struct Ctx *p, u8 key);
extern int func_0215736C(int a0);
extern u32 func_0200A644(struct Big *p, u8 index);
extern u8 func_021572C0(struct Deal *d);
extern u32 func_02005728(u32 range);
extern u32 func_020307B0(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012A30(const struct BigObj *p);
extern void *func_0201210C(const struct Ctx *p);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_02029690(void *a, u32 b, u32 c);
extern void *func_020145CC(void *a);
extern void *func_02029CC0(void *a);
extern u8 *func_020295A4(u8 *p, u32 a);
extern int func_020144DC(int a0, int a1);
extern void *func_02029C64(void *a);
extern void *func_021854B0(void *p, int u, s16 a, const int *s, u16 x);
extern struct Desc *func_02158768(int a0, int a1, int a2, int a3);
extern int func_021589D0(int a0);
extern int func_021FCE28(void *p, u8 i);
void func_02156530(Work_02156530 *w);
int func_02156710(void *evt, Seq *s);
int func_02156770(void *evt, Seq *s);
void func_021567D8(void *evt, Seq *s);
void func_02156824(void *evt, Seq *s);
void func_02156888(void *a0, void *a1, int a2);
u8 func_021568A8(Work_021568A8 *w, u8 n);
u8 func_021568E0(Work_021568E0 *w);
int func_021568E8(int a0, u8 a1);
extern const char d_02172714[];
extern const u16 d_0216FF14[10];
extern const u8 d_0216FF28[7][0x28];
extern const Pos d_0216FEFC;
extern const Pos d_0216FEF0;
extern const Pos d_0216FF08;


/*
 * Byte-correct. Two levers: the spilled locals are declared in the order
 * of their stack slots from the top down (i, lvl, n, q, row, t), and the
 * table row pointer is set in the for-initialiser after j (a separate
 * statement stores it before `j = 0`). Blocker (MATCH): 0x021FD8F8 and
 * 0x021FD4F8 have no func_ label in any overlay listing (ov094, ov132,
 * ov135 and ov186 overlap them).
 *
 * 2026-10-05 (wave D9): the ov132 token on the 0x021FD8F8 and 0x021FD4F8 symbols
 * lines resolves 0x021FD8F8 (matched in ov132_func_021FD8EC.c). 0x021FD4F8 is an
 * unlabelled 50-byte Thumb leaf in ov132; filed as the witness
 * src/matched/ov/ov132_func_021FD4F8.c (EXACT). Still MATCH only until the
 * integrator gives that leaf a shard or label; then this file is EXACT.
 */
void func_02156530(Work_02156530 *w)
{
    u8 order[10];
    u8 *buf;
    Slot *e;
    u32 sum;
    u32 r;
    u16 *pv;
    u8 j;
    u8 v;
    u8 x;
    u8 c;
    u8 i;
    u8 lvl;
    u8 n;
    u32 q;
    const u8 *row;
    u8 t;

    buf = func_02030734(4, 0x28, 1, d_02172714, 0x3F9);
    sum = 0;
    for (i = 0; i < 10; i++) {
        e = (Slot *)func_0200A750(w->f40, i);
        e->f00 = 4;
        e->f01 = 0;
        e->f02 = 0;
    }
    if (w->f14 == 0) {
        sum = func_0200A81C(w->f40) + func_02156934(w, w->f4C);
    } else {
        for (j = 0; j < 4; j++) {
            pv = (u16 *)func_021FD8F8(w->f28, func_021568E8((int)w, j));
            if (func_021FD4F8(w->f28, j) != 0) {
                sum += *pv;
                sum += func_02156934(w, j);
            }
        }
    }
    for (i = 0; i < 10; i++) {
        if (d_0216FF14[i] <= sum) {
            lvl = 10 - i;
            break;
        }
    }
    r = func_0215736C((int)w->f38);
    if (r < 7) {
        n = 0;
        for (j = 0, row = d_0216FF28[r]; j < 0x28; j++) {
            v = row[j];
            if (func_0200A644(w->f40, v) == 0) {
                buf[n] = v;
                n++;
            }
        }
    }
    q = func_021572C0(w->f38);
    for (i = 0; i < 10; i++)
        order[i] = i;
    for (t = 0; t < 10; t++) {
        for (j = 0; j < 10; j++) {
            x = func_02005728(10);
            v = order[j];
            order[j] = order[x];
            order[x] = v;
        }
    }
    for (i = 0; i < lvl; i++) {
        e = (Slot *)func_0200A750(w->f40, order[i]);
        c = func_02156934(w, w->f4C);
        e->f00 = q;
        if ((u8)func_02005728(100) < c && n != 0) {
            x = func_02005728(n);
            e->f01 = 1;
            e->f02 = buf[x];
            for (; x < n - 1; x++)
                buf[x] = buf[x + 1];
            n--;
        }
    }
    func_020307B0(buf);
}


int func_02156710(void *evt, Seq *s)
{
    func_02012A30(func_020120F4(s->f00));
    switch (s->state) {
    case 0:
        func_02012374(evt, func_02029690(s->f00, 0, 0x3C));
        s->state++;
        break;
    case 1:
        func_02012374(evt, func_020145CC(s->f00));
        s->state++;
        break;
    case 2:
        s->state++;
        break;
    case 3:
        func_02012374(evt, func_02029CC0(s->f00));
        s->state++;
        break;
    case 4:
        return 1;
    }
    return 0;
}


int func_02156770(void *evt, Seq *s)
{
    void *x;

    func_02012A30(func_020120F4(s->f00));
    x = func_0201210C(s->f00);
    switch (s->state) {
    case 0:
        s->state++;
        break;
    case 1:
        func_02012374(evt, (struct Evt **)func_020295A4(s->f00, 30));
        s->state++;
        break;
    case 2:
        func_02012374(evt, (struct Evt **)func_020144DC((int)s->f00, (int)x));
        s->state++;
        break;
    case 3:
        func_02012374(evt, func_02029C64(s->f00));
        s->state++;
        break;
    case 4:
        return 1;
    }
    return 0;
}


void func_021567D8(void *evt, Seq *s)
{
    void *x;
    Pos pos;

    x = func_0201210C(s->f00);
    pos = d_0216FEFC;
    pos.x += s->f4C << 17;
    func_02012374(evt, func_021854B0(s->f00, (int)x, 0x4E, (const int *)(&pos), 0));
}


/*
 * The call result goes through a local so both arms share one
 * func_02012374 call (calling it in each arm keeps evt in r6).
 */
void func_02156824(void *evt, Seq *s)
{
    void *x;
    Pos a;
    void *r;
    Pos b;

    x = func_0201210C(s->f00);
    a = d_0216FEF0;
    b = d_0216FF08;
    if (s->f14 == 1)
        r = func_021854B0(s->f00, (int)x, 0x4D, (const int *)(&b), 1);
    else
        r = func_021854B0(s->f00, (int)x, 0x4D, (const int *)(&a), 1);
    func_02012374(evt, r);
}


void func_02156888(void *a0, void *a1, int a2)
{
    void *r4 = func_02158768(((struct Obj17617 *)a1)->f0, a2, 0, 0x15);

    func_021589D0((int)r4);
    func_02012374(a0, r4);
}


/*
 * Counts the slots below n that are occupied: without a link object every
 * slot but 0, otherwise the slots for which func_021FCE28 returns 0.
 * Byte-correct (MATCH*: the listing extent runs over the unlabelled leaf
 * at 0x021568E0). Blocker: 0x021FCE28 has no func_ label in any overlay
 * listing (ov186 has it mid-function, ov094/ov132/ov135 do not start code
 * there), so the call cannot be attested until the co-resident overlay
 * that holds it is labelled.
 */
u8 func_021568A8(Work_021568A8 *w, u8 n)
{
    u8 i;
    u8 cnt;

    cnt = 0;
    for (i = 0; i < n; i++) {
        if (w->f28 == 0) {
            if (i == 0)
                continue;
        } else if (func_021FCE28(w->f28, i) != 0) {
            continue;
        }
        cnt++;
    }
    return cnt;
}


/*
 * Unlabelled leaf between func_021568A8 and func_021568E8: returns the
 * byte at +0x4C.
 */
u8 func_021568E0(Work_021568E0 *w)
{
    return w->f4c;
}




int func_021568E8(int a0, u8 a1)
{
    int a2;
    int a3;

a3 = 0;
loc_021568EA:
a2 = a0 + a3;
a2 = a2 + 0x44;
a2 = ((struct Obj17618 *)((char *)a2))->f0;
    if (a1 != a2) goto loc_021568F8;
loc_021568F4:
a0 = a3 + 0;
    return a0;
loc_021568F8:
a2 = a3 + 1;
a2 = a2 << 0x18;
a3 = (unsigned)a2 >> 0x18;
    if ((unsigned)a3 < (unsigned)4) goto loc_021568EA;
loc_02156902:
a0 = 0;
    return a0;}
