/*
 * file:     btl_server_p131.c
 * unit:     yes
 * function: func_021D2C7C, func_021D2CA8, func_021D2FD8, func_021D3138, func_021D31A0, func_021D324C, func_021D32E0, func_021D344C, func_021D34B0, func_021D34E8
 * address:  0x021D2C7C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   func_02006254 0x02006254 thumb
 *   func_02005D90   0x02005D90  thumb
 *   func_02005DE4   0x02005DE4  thumb
 *   func_02005E64   0x02005E64  thumb
 *   func_02005E9C   0x02005E9C  thumb
 *   func_02005F38   0x02005F38  thumb
 *   func_02017E1C   0x02017E1C  thumb
 *   func_020181F4   0x020181F4  thumb
 *   func_02018328   0x02018328  thumb
 *   func_021B9934   0x021B9934  thumb ov093
 *   func_021B9AF8   0x021B9AF8  thumb ov093
 *   func_021B9CBC   0x021B9CBC  thumb ov093
 *   func_021D5440   0x021D5440  thumb ov093
 *   func_021D5844   0x021D5844  thumb ov093
 *   func_021D6BFC   0x021D6BFC  thumb ov093
 *   func_021EA614   0x021EA614  thumb ov093
 *   func_021EA638   0x021EA638  thumb ov093
 *   func_021EA710   0x021EA710  thumb ov093
 *   func_021EA720   0x021EA720  thumb ov093
 *   func_021EABC4   0x021EABC4  thumb ov093
 *   func_021EAC54   0x021EAC54  thumb ov093
 *   func_021EAC64   0x021EAC64  thumb ov093
 *   func_021EAC80   0x021EAC80  thumb ov093
 *   func_021EAF18   0x021EAF18  thumb ov093
 *   func_021EAF50   0x021EAF50  thumb ov093
 *   func_021EAF78   0x021EAF78  thumb ov093
 *   g_021F3B64      0x021F3B64  data
 *   func_021B8E70 0x021B8E70 thumb ov093
 *   func_021F7CFC 0x021F7CFC thumb ov094
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 *   func_021B98AC 0x021B98AC thumb ov093
 *   func_021F883C 0x021F883C thumb ov094
 *   d_021EFF80 0x021EFF80 data a2
 *   func_021BA2D4 0x021BA2D4 thumb ov093
 *   func_021F7C0C 0x021F7C0C thumb ov094
 *   func_021B92A0 0x021B92A0 thumb ov093
 *   func_021F7D44  0x021F7D44  thumb  ov094
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021B9C50  0x021B9C50  thumb  ov093
 *   func_021EAA6C  0x021EAA6C  thumb  ov093
 *   func_021EAAD8  0x021EAAD8  thumb  ov093
 *   func_021B9F70  0x021B9F70  thumb  ov093
 *   func_021EA678  0x021EA678  thumb  ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021D66D0  0x021D66D0  thumb  ov093
 *   func_021EA768  0x021EA768  thumb  ov093
 *   func_021EA778  0x021EA778  thumb  ov093
 *   func_021EA7A8  0x021EA7A8  thumb  ov093
 *   func_021EA7B8  0x021EA7B8  thumb  ov093
 *   func_021B9A24 0x021B9A24 thumb ov093
 *   d_021F3B64 0x021F3B64 data a4
 *   func_021D6C2C  0x021D6C2C  thumb  ov093
 *   func_021EA868  0x021EA868  thumb  ov093
 *   func_021EA878  0x021EA878  thumb  ov093
 *   func_021F7998 0x021F7998 thumb ov094
 *   func_021B8590  0x021B8590  thumb  ov093
 *   func_021D3558  0x021D3558  thumb
 *   func_021EA3B8  0x021EA3B8  thumb  ov093
 *   func_021EA3D4  0x021EA3D4  thumb  ov093
 */
#include "../../matched/include/G_StateData.h"

struct H;
struct L;
struct QJ;
struct Unk021D6C2C;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u8 data[0x24];
} MsgParam;

typedef struct {
    void *battle;       /* 0x000 */
    void *party;        /* 0x004 */
    u8 unk008[0x4C];
    void *msgWin;       /* 0x054 */
    MsgParam msg;       /* 0x058 */
    u8 unk07C[0x11E];
    u16 level;          /* 0x19A */
    u8 unk19C[0xA];
    u8 side;            /* 0x1A6 */
} LearnSeq;

extern void func_020061E4(unsigned int);
extern int func_02006254(unsigned int);
extern u8 func_021D5440(u8 *p);
extern void *func_021D5844(void *mon);
extern u16 func_02018328(void *p, u32 *idx, u32 heap);
extern u8 *func_021B9934(char *p, int i);
extern void func_021D6BFC(u8 *p);
extern void func_021EAF18(struct L *p, int kind, int id);
extern void func_021EAF50(struct L *p, u32 val);
extern void func_021EAF78(u8 *p, u8 v);
extern void func_021EA614(char *p, struct H *h);
extern void func_021EA638(char *p, struct H *h, int c);
extern int func_021EA720(u32 *p);
extern int func_021EA710(u32 *p);
extern void func_02005DE4(void *p);
extern int func_02005E64(void);
extern void func_02005D90(int a, int b);
extern int func_02005F38(void);
extern int func_02005E9C(void);
extern void func_021EABC4(u8 *a, u32 x, u32 y, u32 z);
extern int func_021EAC54(void *win, int *sel);
extern char *func_021B9AF8(char *p, int i);
extern int func_021B9CBC(u8 *p, int v);
extern void func_021EAC64(u8 *p, u8 a, int c);
extern int func_021EAC80(u8 *p, u8 *out);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_020181F4(void *p, u16 move, u32 slot);
extern u8 func_021B8E70(u8 *, u32);
extern void func_021F7CFC(u32, u16, u8, int, int);
extern int func_021F7EB4(void);
extern u8 *func_021B98AC(char *const *q, u8 b);
extern void func_021F883C(u32);
extern void func_021BA2D4(u32 p, u32 *q);
extern void func_021F7C0C(void);
extern void func_021B92A0(u8 *p);
extern void func_021F7D44(int a, u16 b);
extern char *func_021B9AEC(char *p, int i);
extern void func_021B9C50(u8 **p, int k, u8 **o1, u8 **o2);
extern void func_021EAA6C(u32 a, int b, int c);
extern int func_021EAAD8(u32 a);
extern int func_021B9F70(u8 *p, int i);
extern void func_021EA678(char *p, u16 k, int *c);
extern int func_021B8D8C(void *p, void *a, u32 b);
extern u32 func_021CD9E0(u8 *p);
extern void func_021D66D0(struct QJ *p, u32 v);
extern void func_021EA768(u32 *p, u32 a2, u32 a3);
extern int func_021EA778(u32 *p, u32 a2);
extern void func_021EA7A8(u32 *p, u32 a2);
extern int func_021EA7B8(u32 *p, u32 a2);
extern int func_021B9A24(u32, u32);
extern void func_021D6C2C(struct Unk021D6C2C *p);
extern void func_021EA868(u32 *p, u32 a2, u32 a3);
extern int func_021EA878(u32 *p);
extern void func_021F7998(unsigned int);
extern unsigned int func_021B8590(unsigned char *p);
extern int func_021D3558(u16 v);
extern void func_021EA3B8(char *ctx, int a, int b);
extern int func_021EA3D4(u32 a);
int func_021D2C7C(int n);
int func_021D2CA8(LearnSeq *s, int *state, void *mon);
int func_021D2FD8(u32 *a, int *b, const u32 *c);
int func_021D3138(u32 *a, int *b, u32 *c);
int func_021D31A0(u32 *a, int *b, u32 *c);
int func_021D324C(u32 *a, int *b, u32 *c);
int func_021D32E0(u32 *a, int *b, u32 *c);
int func_021D344C(u32 *a, int *b, u32 *c);
int func_021D34B0(char *p, int *state, unsigned int *q);
int func_021D34E8(u32 *a, int *b, u32 *c);
extern struct StateData g_021F3B64;
extern const u16 d_021EFF80[];
extern u32 d_021F3B64[];


int func_021D2C7C(int n)
{
    switch (n) {
    case 3:
        func_020061E4(0x56b);
        break;
    case 5:
        if (func_02006254(0x56b) != 0) return 1;
        break;
    }
    return 0;
}



int func_021D2CA8(LearnSeq *s, int *state, void *mon)
{
    int idx = func_021D5440(mon);

    switch (*state) {
    case 0:
        g_021F3B64.iter = 0;
        g_021F3B64.move = 0;
        *state = 1;
    case 1:
        g_021F3B64.move = func_02018328(func_021D5844(mon), &g_021F3B64.iter, s->level);
        if (g_021F3B64.move == 0)
            return 1;
        if (g_021F3B64.move == 0xFFFE)
            break;
        if (g_021F3B64.move & 0x8000) {
            g_021F3B64.move &= 0x7FFF;
            *state = 5;
        } else {
            *state = 2;
        }
        break;
    case 2: {
        void *p = func_021B9934(s->party, idx);
        func_021D5844(p);
        func_021D6BFC(p);
        func_021EAF18((struct L *)(&s->msg), 5, 3);
        func_021EAF50((struct L *)(&s->msg), idx);
        func_021EAF50((struct L *)(&s->msg), g_021F3B64.move);
        func_021EA614(s->msgWin, (struct H *)(&s->msg));
        *state = 3;
    }
    case 3:
        if (func_021EA720(s->msgWin)) {
            func_02005DE4((void *)1);
            func_02005E64();
            func_02005D90(0x515, 0xFFFF);
        }
        if (func_021EA710(s->msgWin))
            *state = 4;
        break;
    case 4:
        if (func_02005F38() == 0) {
            func_02005E9C();
            func_02005DE4(0);
            *state = 1;
        }
        break;
    case 5:
        func_021EAF18((struct L *)(&s->msg), 5, 4);
        func_021EAF50((struct L *)(&s->msg), idx);
        func_021EAF50((struct L *)(&s->msg), g_021F3B64.move);
        func_021EAF78((u8 *)(&s->msg), 255);
        func_021EA614(s->msgWin, (struct H *)(&s->msg));
        *state = 6;
    case 6:
        if (func_021EA720(s->msgWin)) {
            MsgParam yes, no;
            func_021EAF18((struct L *)(&yes), 6, 2);
            func_021EAF18((struct L *)(&no), 6, 3);
            func_021EABC4(s->msgWin, (u32)(&yes), (u32)(&no), 1);
        }
        if (func_021EA710(s->msgWin))
            *state = 7;
        break;
    case 7: {
        int sel;
        if (func_021EAC54(s->msgWin, &sel)) {
            if (sel == 0) {
                func_021EAC64(s->msgWin, func_021B9CBC((u8 *)func_021B9AF8(s->party, s->side), idx), g_021F3B64.move);
                *state = 8;
            } else {
                *state = 10;
            }
        }
        break;
    }
    case 8: {
        u8 slot;
        void *pp;
        u16 old;
        if (func_021EAC80(s->msgWin, &slot) == 0)
            break;
        if (slot == 4) {
            *state = 5;
            break;
        }
        pp = func_021D5844(func_021B9934(s->party, idx));
        old = func_02017E1C(pp, slot + 54, 0);
        func_020181F4(pp, g_021F3B64.move, slot);
        func_021EAF18((struct L *)(&s->msg), 5, 5);
        func_021EAF50((struct L *)(&s->msg), idx);
        func_021EAF50((struct L *)(&s->msg), old);
        func_021EA638(s->msgWin, (struct H *)(&s->msg), (int)((void (*)(void))func_021D2C7C));
        *state = 9;
        break;
    }
    case 9:
        if (func_021EA710(s->msgWin))
            *state = 2;
        break;
    case 10:
        func_021EAF18((struct L *)(&s->msg), 5, 7);
        func_021EAF50((struct L *)(&s->msg), idx);
        func_021EAF50((struct L *)(&s->msg), g_021F3B64.move);
        func_021EAF78((u8 *)(&s->msg), 255);
        func_021EA614(s->msgWin, (struct H *)(&s->msg));
        *state = 11;
        break;
    case 11:
        if (func_021EA720(s->msgWin)) {
            MsgParam yes, no;
            func_021EAF18((struct L *)(&yes), 6, 4);
            func_021EAF50((struct L *)(&yes), g_021F3B64.move);
            func_021EAF18((struct L *)(&no), 6, 5);
            func_021EAF50((struct L *)(&no), g_021F3B64.move);
            func_021EABC4(s->msgWin, (u32)(&yes), (u32)(&no), 1);
        }
        if (func_021EA710(s->msgWin))
            *state = 12;
        break;
    case 12: {
        int sel;
        if (func_021EAC54(s->msgWin, &sel)) {
            if (sel == 0) {
                func_021EAF18((struct L *)(&s->msg), 5, 8);
                func_021EAF50((struct L *)(&s->msg), idx);
                func_021EAF50((struct L *)(&s->msg), g_021F3B64.move);
                func_021EA614(s->msgWin, (struct H *)(&s->msg));
                *state = 13;
            } else {
                *state = 5;
            }
        }
        break;
    }
    case 13:
        if (func_021EA710(s->msgWin))
            *state = 1;
        break;
    }
    return 0;
}


/*
 * lever: const on the read-only descriptor schedules c[1] before the
 * stack-argument store in the first arm.
 */
int func_021D2FD8(u32 *a, int *b, const u32 *c)
{
    switch (*b) {
    case 0:
        func_021F7CFC(func_021B8E70((u8 *)a[0], (u8)c[0]), (u16)c[5], (u8)c[1], c[2], c[4]);
        (*b)++;
        break;
    case 1:
        if (!func_021F7EB4()) {
            if (c[2]) {
                u8 *p = func_021B98AC((char *const *)a[1], (u8)c[0]);
                func_021EAF18((struct L *)((u8 *)a + 0x58), 1, 0x41);
                func_021EAF50((struct L *)((u8 *)a + 0x58), func_021D5440(p));
                func_021F883C(0x518);
            } else {
                int msg;
                if (c[1] < 4) msg = d_021EFF80[c[1]];
                else msg = 0x3d;
                func_021EAF18((struct L *)((u8 *)a + 0x58), 1, msg);
            }
            func_021EA614((char *)a[21], (struct H *)((u8 *)a + 0x58));
            (*b)++;
        }
        break;
    case 2:
        if (func_021EA710((u32 *)a[21])) {
            if (c[2]) {
                func_021BA2D4((u32)((void *)a[0]), (u32 *)func_021B98AC((char *const *)a[1], (u8)c[0]));
                (*b)++;
            } else return 1;
        }
        break;
    case 3:
        if (!func_02005F38()) {
            func_021F7C0C();
            func_02005D90(0x47c, 0xffff);
            func_021B92A0((u8 *)a[0]);
            if (c[3]) {
                u8 *p = func_021B98AC((char *const *)a[1], (u8)c[0]);
                func_021EAF18((struct L *)((u8 *)a + 0x58), 1, 0x42);
                func_021EAF50((struct L *)((u8 *)a + 0x58), func_021D5440(p));
                func_021EA614((char *)a[21], (struct H *)((u8 *)a + 0x58));
                (*b)++;
            } else return 1;
        }
        break;
    case 4:
        if (func_021EA710((u32 *)a[21])) (*b)++;
        break;
    default:
        return 1;
    }
    return 0;
}



int func_021D3138(u32 *a, int *b, u32 *c)
{
    switch (*b) {
    case 0:
        func_021F7D44(func_021B8E70((u8 *)a[0], (u8)c[0]), (u16)c[1]);
        (*b)++;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            func_021EAF18((struct L *)((u8 *)a + 0x58), 1, 0x43);
            func_021EA614((char *)a[0x15], (struct H *)((u8 *)a + 0x58));
            (*b)++;
        }
        break;
    case 2:
        if (func_021EA710((u32 *)a[0x15]) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}



static inline u16 sel(u32 u, u32 k)
{
    if (u == 3) {
        return (k != 0) ? 0x26 : 0x27;
    }
    return (k != 0) ? 0x28 : 0x29;
}



/*
 * Levers: the 0x26..0x29 selection is a `static inline u16` helper returning nested
 * ternaries; inlined, its result stays in r0 and each arm branches (the inner join of the
 * u == 3 arm is the unthreaded `b` hop). Written in the caller (ternary, if/else, nested
 * ternary, call in each arm) it is if-converted into r1, and a plain `static` helper is
 * not inlined. `u` is `int` (permuter: u32 put c[1] first into r7 in case 0).
 */
int func_021D31A0(u32 *a, int *b, u32 *c)
{
    u32 v;
    int u;
    u8 k;
    char *p;

    switch (*b) {
    case 0:
        u = (u8)c[0];
        v = (u8)c[1];
        p = func_021B9AEC((char *)a[1], u);
        func_021B9C50((u8 **)p, v, 0, 0);
        func_021EAA6C(a[0x15], u, v);
        (*b)++;
        break;
    case 1:
        if (func_021EAAD8(a[0x15]) != 0) {
            u = (u8)c[1];
            if (u == 1) {
                return 1;
            }
            k = func_021B9F70((u8 *)a[0], (u8)c[0]);
            func_021EA678((char *)a[0x15], sel(u, k), (int *)c);
            (*b)++;
        }
        break;
    case 2:
        if (func_021EA710((u32 *)a[0x15]) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}



int func_021D324C(u32 *a, int *b, u32 *c)
{
    u32 u;
    int s;

    u = (u8)c[0];
    s = func_021B8D8C((void *)a[0], (void *)a[1], u);
    switch (*b) {
    case 0:
        if (func_021CD9E0((u8 *)a) != 0) {
            func_021D66D0((struct QJ *)func_021B9934((char *)a[1], u), c[1]);
            return 1;
        }
        func_021EA768((u32 *)a[0x15], s, 0);
        (*b)++;
        break;
    case 1:
        if (func_021EA778((u32 *)a[0x15], s) != 0) {
            func_021D66D0((struct QJ *)func_021B9934((char *)a[1], u), c[1]);
            func_021EA7A8((u32 *)a[0x15], s);
            (*b)++;
        }
        break;
    case 2:
        if (func_021EA7B8((u32 *)a[0x15], s) != 0) {
            (*b)++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}


/*
 * pass 6 2026-10-06 P6L08: EXACT (364 B), also EXACT under -lang c99. The closing change is u16 x, y
 * with func_021D66D0 declared (void *, u16), non-const a, and source order u, v, x, y. The callee
 * (func_021D66D0.c, strh to a u16 field) also matches EXACT with a u16 parameter, so the prototype is
 * consistent. Why it closes (scheduler trace, scratchpad wD9r/p6_P6L08): the word spill of the narrow
 * variable x uses the unknown-memory alias set (AO1), not a fresh spill alias object. With non-const a,
 * the pointee of a is in that set, so `str x, [sp]` gets a memory edge to the a[1] load and the load
 * waits after it, as in the original. With const a, the pointee of a is not in the set (22 B).
 * Earlier passes (wave75 to pass 6 P6L04) stayed at 13 B with u32 locals.
 */
int func_021D32E0(u32 *a, int *b, u32 *c)
{
    u32 u, v;
    u16 x, y;
    int s, t;
    u8 *p, *q;
    u = (u8)c[0];
    v = (u8)c[1];
    x = (u16)c[2];
    y = (u16)c[3];
    s = func_021B8D8C((void *)a[0], (void *)a[1], u);
    t = func_021B8D8C((void *)a[0], (void *)a[1], v);
    p = func_021B9934((char *)a[1], u);
    q = func_021B9934((char *)a[1], v);
    switch (*b) {
    case 0:
        if (func_021CD9E0((u8 *)a)) {
            func_021D66D0((struct QJ *)p, x);
            func_021D66D0((struct QJ *)q, y);
            return 1;
        }
        if (func_021B9A24(u, v)) {
            func_021D66D0((struct QJ *)p, x);
            func_021D66D0((struct QJ *)q, y);
            return 1;
        }
        func_021EA768((u32 *)((int)a[21]), s, 0);
        d_021F3B64[1] = 8;
        (*b)++;
        break;
    case 1:
        func_021EA778((u32 *)a[21], s);
        if (d_021F3B64[1]) d_021F3B64[1]--;
        else {
            func_021EA768((u32 *)a[21], t, 0);
            (*b)++;
        }
        break;
    case 2: {
        u8 r, z;
        r = func_021EA778((u32 *)a[21], s);
        z = func_021EA778((u32 *)a[21], t);
        if (r && z) (*b)++;
        break;
    }
    case 3:
        func_021D66D0((struct QJ *)p, x);
        func_021D66D0((struct QJ *)q, y);
        d_021F3B64[1] = 0;
        (*b)++;
        break;
    case 4:
        d_021F3B64[1]++;
        if (d_021F3B64[1] > 8) {
            func_021EA7A8((u32 *)a[21], s);
            (*b)++;
        }
        break;
    case 5:
        if (func_021EA7B8((u32 *)a[21], s)) {
            func_021EA7A8((u32 *)a[21], t);
            (*b)++;
        }
        break;
    case 6:
        if (func_021EA7B8((u32 *)a[21], t)) (*b)++;
        break;
    default:
        return 1;
    }
    return 0;
}



int func_021D344C(u32 *a, int *b, u32 *c)
{
    u32 u;
    int s;
    u8 *m;
    int f;

    switch (*b) {
    case 0:
        u = (u8)c[0];
        s = func_021B8D8C((void *)a[0], (void *)a[1], u);
        m = func_021B9934((char *)a[1], u);
        f = func_021CD9E0((u8 *)a);
        func_021D6C2C((struct Unk021D6C2C *)m);
        func_021EA868((u32 *)a[0x15], s, f);
        (*b)++;
        break;
    case 1:
        if (func_021EA878((u32 *)a[0x15]) != 0) {
            (*b)++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}


/*
 * extent: compiled 54 bytes followed by two zero alignment bytes.
 */
int func_021D34B0(char *p, int *state, unsigned int *q)
{
    if (*state == 0) {
        if (func_021CD9E0((u8 *)p) != 0) return 1;
        func_021F7998(q[0]);
        (*state)++;
    } else {
        if (func_021F7EB4() == 0) return 1;
    }
    return 0;
}



int func_021D34E8(u32 *a, int *b, u32 *c)
{
    u8 k;

    k = func_021B8E70((u8 *)a[0], (u8)c[0]);
    if (*b == 0) {
        if (func_021CD9E0((u8 *)a) != 0) {
            return 1;
        }
        if (func_021B8590((unsigned char *)a[0]) == 0) {
            if (func_021D3558((u16)c[1]) != 0) {
                return 1;
            }
        }
        func_021EA3B8((char *)a[0x15], k, (u16)c[1]);
        (*b)++;
    } else {
        if (func_021EA3D4(a[0x15]) != 0) {
            return 1;
        }
    }
    return 0;
}
