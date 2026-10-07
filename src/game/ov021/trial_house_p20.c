/*
 * file:     trial_house_p20.c
 * unit:     yes
 * function: func_021D0C58, func_021D0DB0, func_021D0FE0, func_021D0FE8
 * address:  0x021D0C58
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
 *   func_021576D0  0x021576D0  thumb  ov010
 *   func_021578A0  0x021578A0  thumb  ov010
 *   func_020362DC  0x020362DC  arm
 *   func_02157928  0x02157928  thumb  ov010
 *   func_021578F0  0x021578F0  thumb  ov010
 *   func_02157910  0x02157910  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200E8F8  0x0200E8F8  thumb
 *   func_0200E5E4  0x0200E5E4  thumb
 *   func_0200E5A0  0x0200E5A0  thumb
 *   func_021D1058  0x021D1058  thumb  ov021
 *   func_021D1080  0x021D1080  thumb  ov021
 *   func_0200E608  0x0200E608  thumb
 *   func_02157938  0x02157938  thumb  ov010
 *   func_0203D210  0x0203D210  arm
 *   func_021D09D0  0x021D09D0  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02030734  0x02030734  arm
 *   func_020072CC  0x020072CC  thumb
 *   func_020073D8  0x020073D8  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0200734C  0x0200734C  thumb
 *   func_02008C58  0x02008C58  thumb
 *   func_02008E88  0x02008E88  thumb
 *   func_02008E68  0x02008E68  thumb
 *   d_021DE674     0x021DE674  data  a4
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_021D10A8  0x021D10A8  thumb  ov021
 *   func_021D1164  0x021D1164  thumb  ov021
 *   func_021D11B0  0x021D11B0  thumb  ov021
 */
#include "../../matched/include/Obj20300.h"
#include "../../matched/include/Obj20301.h"
#include "../../matched/include/Obj18371.h"

#define U32(o) (*(u32 *)(w + (o)))
struct Flags;
struct Big;
struct Ctx;
struct Sub02008C20Obj;
struct Sub02007324Ctrl;
struct Desc;
struct Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u8 pad0[0x7c];
    u32 f7c;
    u32 f80;
    u8 *f84;
    u16 *f88;
    int f8c;
} W;

typedef struct {
    u16 species;
    u8 b2;
    u8 b3;
} Mon;

typedef struct {
    u8 valid;
    u8 kind;
    u16 score;
    Mon mons[4];
} Rec;

typedef struct Work {
    void *f00;
    int f04;
    int f08;
    int f0C;
} Work;

extern void *func_021576D0(u8 *p);
extern int func_021578A0(u32 *p);
extern u32 func_020362DC(void);
extern void func_02157928(u8 *p);
extern int func_021578F0(void *p);
extern int func_02157910(u8 *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200E8F8(void *sys);
extern u16 func_0200E5E4(void *p);
extern int func_0200E5A0(void *a0);
extern u8 func_021D1058(struct Flags *p, u32 n);
extern void func_021D1080(struct Flags *p, u32 n);
extern void func_0200E608(void *sys, void *dst, u32 heap);
extern int func_02157938(void *a0);
extern u32 func_0203D210(void);
extern void func_021D09D0(int a, char *out);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern void *func_02030734(u32 heap, u32 size, int flag, const char *file, u16 line);
extern int func_020072CC(u32 sv, u32 id, u32 heap, void *buf, u32 size);
extern u8 *func_020073D8(u32 sv, u32 id, u32 v);
extern void func_02082D44(void *src, void *dst, u32 n);
extern u32 func_020307B0(void *p);
extern void func_0200734C(struct Sub02007324Ctrl *sv, u32 id);
extern struct Sub02008C20Obj *func_02008C58(void *sys);
extern void func_02008E88(struct Sub02008C20Obj *obj, u32 value);
extern void func_02008E68(struct Sub02008C20Obj *obj, u32 value);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_021D10A8(u32 a, u32 *b, u32 *c);
extern void *func_021D1164(u32 heap, u32 v);
extern void func_021D11B0(u32 *p);
int func_021D0C58(u32 unused, u32 *state, W *w);
void func_021D0DB0(u32 a, u8 *w, u16 *outRank, u16 *outScore);
int func_021D0FE0(int x, int *p);
void *func_021D0FE8(void *a, int unused, int c);
extern int d_021DE674;


/*
 * Callee witnesses filed in wave A1 (witness lane).
 *
 * Addresses are Black-image addresses.
 */
int func_021D0C58(u32 unused, u32 *state, W *w)
{
    u32 x;
    u32 h, sv;
    u8 *rec;
    int n, ok, r;

    x = w->f80;
    switch (*state) {
    case 0:
        w->f7c = (u32)func_021576D0((u8 *)w);
        if (func_021578A0((u32 *)w->f7c) == 0) {
            *w->f88 = 0;
            *state = 4;
        } else {
            *state = 1;
        }
        break;
    case 1:
        if (func_020362DC() == 2) {
            *w->f88 = 3;
            *state = 4;
            break;
        }
        func_02157928((u8 *)w->f7c);
        if (++w->f8c > 120) {
            *state = 2;
        }
        break;
    case 2:
        if (func_020362DC() == 2) {
            *w->f88 = 3;
            *state = 4;
            break;
        }
        func_02157928((u8 *)w->f7c);
        if (func_021578F0((void *)w->f7c)) {
            *state = 3;
        } else {
            *w->f88 = 0;
            *state = 4;
        }
        break;
    case 3:
        if (func_020362DC() == 2) {
            *w->f88 = 3;
            *state = 4;
            break;
        }
        func_02157928((u8 *)w->f7c);
        if (func_02157910((u8 *)w->f7c) == 0) {
            break;
        }
        h = (u32)func_020120F4((const struct Ctx *)x);
        rec = func_0200E8F8(func_02012EBC((struct Big *)h));
        sv = ((struct Obj20300 *)(w->f84))->f14C;
        n = func_0200E5E4((void *)sv);
        ok = func_0200E5A0((void *)sv);
        r = func_021D1058((struct Flags *)rec, n);
        if (ok != 0 && (r == 0 || n == 0)) {
            func_021D1080((struct Flags *)rec, n);
            func_0200E608((void *)h, (void *)(((struct Obj20301 *)(w->f84))->f14C), 0x8004);
            *w->f88 = 1;
        } else if (r != 0) {
            *w->f88 = 2;
        } else {
            *w->f88 = 0;
        }
        *state = 4;
        break;
    case 4:
        func_02157938((void *)w->f7c);
        *state = 5;
        break;
    case 5:
        if (func_0203D210()) {
            *state = 6;
        }
        break;
    case 6:
        func_021D09D0(x, (char *)w->f84);
        return 1;
    }
    return 0;
}


/*
 * The listing extent (568 B) runs over the unlabelled 8-byte follower leaf
 * at 0x021D0FE0 (return *(u32 *)(r1 + 0x150)); the function is 560 B.
 * s is u32 with (int) casts on the clamp (signed clamp, unsigned rank
 * ladder); that and the h, s, rec, rank declaration order give the
 * stack slots.
 *
 * Addresses are Black-image addresses.
 */
void func_021D0DB0(u32 a, u8 *w, u16 *outRank, u16 *outScore)
{
    u16 *st;
    u32 h;
    u32 s;
    u8 *rec;
    u32 rank;
    Rec *e;
    int i;
    Mon *m;
    void *mon;
    u32 h2;
    void *buf;
    void *x;

    st = (u16 *)(w + 0x134);
    s = 0;
    s += st[7] * 1000;
    s += st[8] * 80;
    s += st[1] * 5;
    s += st[3];
    s += st[5] * 5;
    s += st[6] * 2;
    s += st[11] * 15;
    s -= st[0] * 10;
    s -= st[2] * 10;
    s -= st[4] * 2;
    s -= st[9] * 80;
    s -= 500 - st[10];
    if ((int)s < 0) {
        s = 0;
    } else if ((int)s > 9999) {
        s = 9999;
    }

    if (s >= 6000) {
        rank = 6;
    } else if (s >= 5000) {
        rank = 5;
    } else if (s >= 4000) {
        rank = 4;
    } else if (s >= 3000) {
        rank = 3;
    } else if (s >= 2000) {
        rank = 2;
    } else if (s >= 1000) {
        rank = 1;
    } else {
        rank = 0;
    }
    *outRank = rank;
    *outScore = s;

    h = (u32)func_02012EBC(func_020120F4((const struct Ctx *)a));
    rec = func_0200E8F8((void *)h);
    e = (Rec *)(rec + (u8)(U32(0x150) != 0) * 20);
    e->valid = 1;
    if (U32(0x124) == 3) {
        e->kind = 0;
    } else if (U32(0x124) == 4) {
        e->kind = 1;
    } else {
        e->kind = 0;
    }
    e->score = s;
    func_02082BCC(e->mons, 0, 0x10);
    for (i = 0; i < (int)U32(0x124); i++) {
        m = &e->mons[i];
        mon = func_0201AB28((void *)U32(0x128), i);
        m->species = func_02017E1C(mon, 5, 0);
        m->b2 = func_02017E1C(mon, 0x6f, 0);
        m->b3 = func_02017E1C(mon, 0x6e, 0);
    }

    if (U32(0x150) != 0) {
        h2 = (u32)func_02012EBC(func_020120F4((const struct Ctx *)a));
        buf = func_02030734(0x8004, 0x8004 >> 3, 1, (const char *)&d_021DE674, 0x277);
        if (func_020072CC(h2, 5, 0x8004, buf, 0x8004 >> 3) == 1) {
            func_02082D44(func_020073D8(h2, 5, 0) + 0x5a0, rec += 0x38, 0x22);
        }
        func_020307B0(buf);
        func_0200734C((struct Sub02007324Ctrl *)h2, 5);
    }

    x = func_02008C58((void *)h);
    func_02008E88(x, s);
    func_02008E68(x, (u8)rank);
}


/*
 * Unlabelled ov021 leaf hidden in a word run: returns the word at +0x150 of
 * its pointer argument (the second argument register).  Matched to supply the
 * `matched` witness for the pending ov010 caller func_0216A6B4.
 */
int func_021D0FE0(int x, int *p)
{
    return ((struct Obj18371 *)p)->f150;
}


void *func_021D0FE8(void *a, int unused, int c)
{
    void *task;
    Work *w;
    int v;

    task = func_020122C0(a, 0, func_021D10A8, 0x10);
    w = func_020124E8(task);
    w->f00 = a;
    w->f04 = 0;
    w->f08 = c;
    v = (int)func_021D1164(0x8015, (u32)func_0201210C(a));
    w->f0C = v;
    func_021D11B0((u32 *)v);
    return task;
}
