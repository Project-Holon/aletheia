/*
 * file:     btl_server_p130.c
 * unit:     yes
 * function: func_021D1C40, func_021D1CAC, func_021D1CF4, func_021D1DF4, func_021D1E6C, func_021D1EB4, func_021D1F10, func_021D1F58, func_021D1FB4, func_021D2000
 * address:  0x021D1C40
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
 *   func_021B8588  0x021B8588  thumb  ov093
 *   func_021B86C0  0x021B86C0  thumb  ov093
 *   func_021CDEE8  0x021CDEE8  thumb  ov093
 *   func_021B9F70  0x021B9F70  thumb  ov093
 *   func_021B8E70  0x021B8E70  thumb  ov093
 *   func_021EA458  0x021EA458  thumb  ov093
 *   func_021EA478  0x021EA478  thumb  ov093
 *   func_021B9920 0x021B9920 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021B8CE8 0x021B8CE8 thumb ov093
 *   func_021EAF18 0x021EAF18 thumb ov093
 *   func_021EAF50 0x021EAF50 thumb ov093
 *   func_021EA614 0x021EA614 thumb ov093
 *   func_021EA710 0x021EA710 thumb ov093
 *   func_021B8BEC 0x021B8BEC thumb ov093
 *   func_021EA488 0x021EA488 thumb ov093
 *   func_021EA4C4 0x021EA4C4 thumb ov093
 *   func_021CDECC 0x021CDECC thumb ov093
 *   func_021B9064  0x021B9064  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D5C44  0x021D5C44  thumb  ov093
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021EA678  0x021EA678  thumb  ov093
 *   func_021EA720  0x021EA720  thumb  ov093
 *   func_020061E4  0x020061E4  thumb
 *   func_021EA694  0x021EA694  thumb  ov093
 *   func_021EA6F4  0x021EA6F4  thumb  ov093
 *   func_021B98AC  0x021B98AC  thumb  ov093
 *   func_021D80A8  0x021D80A8  thumb  ov093
 *   func_0201BD28  0x0201BD28  thumb
 */
#include "../../matched/include/Obj01691.h"
#include "../../matched/include/Obj21146.h"

struct S;
struct L;
struct H;
struct Rat;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    void *battle;         /* 0x00 */
    u8 unk04[0x50];
    void *msgWin;         /* 0x54 */
    u8 msg[0x14E];        /* 0x58 */
    u8 unk1A6;            /* 0x1A6 */
} BattleSeq_021D1C40;

typedef struct {
    void *battle;         /* 0x00 */
    void *unk04;          /* 0x04 */
    u8 unk08[0x4C];
    void *msgWin;         /* 0x54 */
    u8 msg[0x14E];        /* 0x58 */
    u8 unk1A6;            /* 0x1A6 */
} BattleSeq_021D1DF4;

typedef struct {
    u8 unk00[0x54];
    void *win;            /* 0x54 */
} Seq;

extern u32 func_021B8588(void **p);
extern u8 func_021B86C0(u8 **p);
extern u32 func_021CDEE8(u8 *p);
extern int func_021B9F70(u8 *p, int i);
extern u8 func_021B8E70(u8 *p, u32 k);
extern void func_021EA458(char *ctx, u16 a, u16 b);
extern int func_021EA478(u32 *p);
extern u8 *func_021B9920(void *p, u32 i, u8 j);
extern u8 func_021D5440(u8 *p);
extern int func_021B8CE8(int a, int b, int c);
extern void func_021EAF18(struct L *p, int kind, int id);
extern void func_021EAF50(struct L *p, u32 val);
extern void func_021EA614(char *p, struct H *h);
extern int func_021EA710(u32 *p);
extern u8 func_021B8BEC(u8 *, u32, u8);
extern void func_021EA488(struct S *s, u8 a, u8 b, u8 c);
extern int func_021EA4C4(struct S *s);
extern void func_021CDECC(u8 *p);
extern u32 func_021B9064(u8 *p, int k, int x);
extern int func_021D5B68(void *p);
extern int func_021D5C44(struct Rat *p);
extern u32 func_021CD9E0(u8 *p);
extern void func_021EA678(char *p, u16 k, int *c);
extern int func_021EA720(u32 *p);
extern void func_020061E4(unsigned int arg);
extern void func_021EA694(char *p, u16 k, int *c);
extern void func_021EA6F4(void *p, u8 b, u16 c);
extern u8 *func_021B98AC(char *const *q, u8 b);
extern int func_021D80A8(void *p);
extern u32 func_0201BD28(u32 v, u32 n);
int func_021D1C40(BattleSeq_021D1C40 *s, u32 x, int *out);
int func_021D1CAC(BattleSeq_021D1C40 *s, int *state, int *pp);
int func_021D1CF4(u8 *p, int *state, const u32 *params);
int func_021D1DF4(BattleSeq_021D1DF4 *s);
int func_021D1E6C(Seq *s, int *state, u32 *a);
int func_021D1EB4(Seq *s, int *state, u32 *a);
int func_021D1F10(Seq *s, int *state, u32 *a);
int func_021D1F58(Seq *s, int *state, u32 *a);
int func_021D1FB4(Seq *s, int *state, u32 *a);
u32 func_021D2000(u32 *p, u32 k, u8 b);






int func_021D1C40(BattleSeq_021D1C40 *s, u32 x, int *out)
{
    u32 v;

    if (x == s->unk1A6) {
        *out = 0;
        if (func_021B8588(s->battle) == 0 && func_021B86C0(s->battle) == 0) {
            v = func_021CDEE8((u8 *)s);
            if (v >= 0x4b)
                return 0x1d;
            if (v > 0x32)
                return 0x1c;
            if (v > 0x19)
                return 0x1b;
            if (v != 0)
                return 0x1a;
            return 0x19;
        }
        return 0x1a;
    }
    *out = 1;
    if (func_021B9F70(s->battle, x) != 0)
        return 0x1e;
    return 0x1f;
}






int func_021D1CAC(BattleSeq_021D1C40 *s, int *state, int *pp)
{
    switch (*state) {
    case 0:
        func_021EA458(s->msgWin, func_021B8E70(s->battle, (u8)pp[0]), (u16)pp[1]);
        (*state)++;
        break;
    case 1:
        if (func_021EA478(s->msgWin) != 0)
            return 1;
        break;
    }
    return 0;
}




static inline void message(u8 *p, int code, u32 value, u32 id)
{
    func_021EAF18((struct L *)(p + 0x58), 1, code);
    func_021EAF50((struct L *)(p + 0x58), value);
    func_021EAF50((struct L *)(p + 0x58), id);
    func_021EA614(((struct Obj21146 *)p)->f54, (struct H *)(p + 0x58));
}




/*
 * lever: append-id and send are written in every message arm; the inline
 * helper includes that tail. Factoring it outside the conditional merges
 * the initialisation call too early and loses 16 bytes.
 */
int func_021D1CF4(u8 *p, int *state, const u32 *params)
{
    u8 a = params[0];
    u8 b = params[1];
    u8 flag = params[3];
    u8 id;
    switch (*state) {
    case 0:
        if (flag != 0) {
            id = func_021D5440(func_021B9920(((struct Obj01691 *)p)->f4, a, b));
            if (func_021B8CE8((int)(((struct Obj01691 *)p)->f0), p[0x1A6], a) == 0) {
                if (p[0x1A6] == a) {
                    func_021EAF18((struct L *)(p + 0x58), 1, func_021D1DF4((BattleSeq_021D1DF4 *)p));
                    func_021EAF50((struct L *)(p + 0x58), id);
                    func_021EA614(((struct Obj01691 *)p)->f54, (struct H *)(p + 0x58));
                } else {
                    message(p, 0x11, a, id);
                }
            } else if (func_021B9F70(((struct Obj01691 *)p)->f0, a) != 0) {
                message(p, 0xE, a, id);
            } else {
                message(p, 0x11, a, id);
            }
        }
        (*state)++;
        break;
    case 1:
        if (func_021EA710(((struct Obj01691 *)p)->f54) != 0) {
            func_021EA488(((struct Obj01691 *)p)->f54, func_021B8BEC(*(u8 * *)&((struct Obj01691 *)p)->f0, a, b), a, b);
            (*state)++;
        }
        break;
    case 2:
        if (func_021EA4C4(((struct Obj01691 *)p)->f54) != 0) {
            func_021CDECC(p);
            return 1;
        }
        break;
    }
    return 0;
}




int func_021D1DF4(BattleSeq_021D1DF4 *s)
{
    u8 *m;
    u8 t;
    int v;

    if (func_021B8588(s->battle) == 0) {
        t = func_021B9064(s->battle, s->unk1A6, 0);
        m = func_021B9920(s->unk04, t, 0);
        if (func_021D5B68(m) != 0)
            return 0xb;
        v = func_021D5C44((struct Rat *)m);
        if (v >= 0x4d800)
            return 0xb;
        if (v >= 0x37000)
            return 0x15;
        if (v >= 0x20800)
            return 0x16;
        if (v >= 0xa000)
            return 0x17;
        return 0x18;
    }
    return 0xb;
}




int func_021D1E6C(Seq *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (func_021CD9E0((u8 *)s)) {
            return 1;
        }
        func_021EA678(s->win, a[0], (int *)(a + 1));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA710(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}




int func_021D1EB4(Seq *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (func_021CD9E0((u8 *)s)) {
            return 1;
        }
        func_021EA678(s->win, a[0], (int *)(a + 2));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA720(s->win)) {
            func_020061E4(a[1]);
        }
        if (func_021EA710(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}




int func_021D1F10(Seq *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (func_021CD9E0((u8 *)s)) {
            return 1;
        }
        func_021EA694(s->win, a[0], (int *)(a + 1));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA710(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}




int func_021D1F58(Seq *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (func_021CD9E0((u8 *)s)) {
            return 1;
        }
        func_021EA694(s->win, a[0], (int *)(a + 2));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA720(s->win)) {
            func_020061E4(a[1]);
        }
        if (func_021EA710(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}



int func_021D1FB4(Seq *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (func_021CD9E0((u8 *)s)) {
            return 1;
        }
        func_021EA6F4(s->win, a[0], a[1]);
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA710(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}



/*
 * Unlabelled leaf (filed for the blocker of func_021D2030, lane S15).
 */
u32 func_021D2000(u32 *p, u32 k, u8 b)
{
    u8 *r;

    if (k != 0xAE) {
        return func_0201BD28(k, 0x1B);
    }
    r = func_021B98AC((char *const *)p[1], b);
    if (r) {
        return func_021D80A8(r);
    }
    return func_0201BD28(k, 0x1B);
}
