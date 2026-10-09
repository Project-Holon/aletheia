/*
 * file:     btl_server_p130.c
 * unit:     yes
 * function: func_021D2030, func_021D20BC, func_021D210C, func_021D215C, func_021D21D4, func_021D2234, func_021D2278, func_021D2320, func_021D2374, func_021D23B8, func_021D2424, func_021D2490, func_021D2510, func_021D2580, func_021D25C4, func_021D2628, func_021D266C, func_021D2700, func_021D2814, func_021D284C, func_021D28AC, func_021D2930, func_021D2990, func_021D299C, func_021D29CC, func_021D2A20
 * address:  0x021D2030
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
 *   func_021CD9E0 0x021CD9E0 thumb ov093
 *   func_021B8590 0x021B8590 thumb ov093
 *   func_021D2000 0x021D2000 thumb ov093
 *   func_021EA0A0 0x021EA0A0 thumb ov093
 *   func_021EA0E4 0x021EA0E4 thumb ov093
 *   func_021B8DC0  0x021B8DC0  thumb  ov093
 *   func_021EA354  0x021EA354  thumb  ov093
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021EA0F4  0x021EA0F4  thumb  ov093
 *   func_021EA120  0x021EA120  thumb  ov093
 *   func_021CD644  0x021CD644  thumb  ov093
 *   func_021EA280  0x021EA280  thumb  ov093
 *   func_021EA2BC  0x021EA2BC  thumb  ov093
 *   func_021EA384  0x021EA384  thumb  ov093
 *   func_021EA3A0  0x021EA3A0  thumb  ov093
 *   func_021EA678  0x021EA678  thumb  ov093
 *   func_021EA710  0x021EA710  thumb  ov093
 *   func_021B8E70  0x021B8E70  thumb  ov093
 *   func_021F81D0  0x021F81D0  thumb  ov094
 *   func_0201BD28  0x0201BD28  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_021EA40C  0x021EA40C  thumb  ov093
 *   func_021EA428  0x021EA428  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D646C  0x021D646C  thumb  ov093
 *   func_021EA438  0x021EA438  thumb  ov093
 *   func_021EA448  0x021EA448  thumb  ov093
 *   func_021EA7C8  0x021EA7C8  thumb  ov093
 *   func_021EA7E8  0x021EA7E8  thumb  ov093
 *   func_021EA7D8  0x021EA7D8  thumb  ov093
 *   func_021EF9C0  0x021EF9C0  thumb  ov093
 *   func_021F7998  0x021F7998  thumb  ov094
 *   d_021EFFAE     0x021EFFAE  data   ov093  a2
 *   func_021EF9C8  0x021EF9C8  thumb  ov093
 *   func_021EA838  0x021EA838  thumb  ov093
 *   func_021EA850  0x021EA850  thumb  ov093
 *   func_021B8DEC  0x021B8DEC  thumb  ov093
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021B9C10  0x021B9C10  thumb  ov093
 *   func_021EA904  0x021EA904  thumb  ov093
 *   func_021EA950  0x021EA950  thumb  ov093
 *   func_021B8BEC 0x021B8BEC thumb ov093
 *   func_021F7E94 0x021F7E94 thumb ov094
 *   func_021F88BC  0x021F88BC  thumb  ov094
 *   func_021F7EA4  0x021F7EA4  thumb  ov094
 *   func_021D6C50  0x021D6C50  thumb  ov093
 *   func_021EA8B4  0x021EA8B4  thumb  ov093
 *   func_021EA8D4  0x021EA8D4  thumb  ov093
 *   func_021D7AD4  0x021D7AD4  thumb  ov093
 *   func_021EA1B8  0x021EA1B8  thumb  ov093
 *   func_021EA1F0  0x021EA1F0  thumb  ov093
 *   func_021F878C  0x021F878C  thumb  ov094
 *   func_021EA8E4 0x021EA8E4 thumb ov093
 *   func_021EA8F4 0x021EA8F4 thumb ov093
 *   func_021D5844  0x021D5844  thumb  ov093
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   d_021EFF88     0x021EFF88  data  ov093  a2
 *   func_021F8204 0x021F8204 thumb ov094
 *   func_021D69B8 0x021D69B8 thumb ov093
 *   func_021F8134 0x021F8134 thumb ov094
 *   func_021F8180 0x021F8180 thumb ov094
 *   func_021D6EA0 0x021D6EA0 thumb ov093
 *   func_021D6BFC 0x021D6BFC thumb ov093
 *   func_021F8150 0x021F8150 thumb ov094
 *   func_02006238 0x02006238 thumb
 *   func_021EA3B8 0x021EA3B8 thumb ov093
 *   func_021EA3D4 0x021EA3D4 thumb ov093
 *   func_021EAF18 0x021EAF18 thumb ov093
 *   func_021EAF50 0x021EAF50 thumb ov093
 *   func_021EA614 0x021EA614 thumb ov093
 *   func_021EA720 0x021EA720 thumb ov093
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005E64 0x02005E64 thumb
 *   func_02005D90 0x02005D90 thumb
 *   func_02005F38 0x02005F38 thumb
 *   func_02005E9C 0x02005E9C thumb
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_021BA238 0x021BA238 thumb ov093
 *   func_021EADA4 0x021EADA4 thumb ov093
 *   func_021EADB4 0x021EADB4 thumb ov093
 *   func_021EADC4 0x021EADC4 thumb ov093
 *   func_021EADD4 0x021EADD4 thumb ov093
 *   func_021EADE4 0x021EADE4 thumb ov093
 *   func_021EADF4 0x021EADF4 thumb ov093
 *   func_021D2CA8 0x021D2CA8 thumb ov093
 *   func_021B9358 0x021B9358 thumb ov093
 *   d_021F3B64 0x021F3B64 data a4
 */
#include "../../matched/include/Obj06240.h"
#include "../../matched/include/Obj07782.h"
#include "../../matched/include/Obj05206.h"
#include "../../matched/include/Obj05207.h"
#include "../../matched/include/Obj10019.h"
#include "../../matched/include/Obj10021.h"
#include "../../matched/include/Obj07783.h"
#include "../../matched/include/Obj06241.h"
#include "../../matched/include/Obj07784.h"
#include "../../matched/include/Obj04364.h"
#include "../../matched/include/Obj21158.h"
#include "../../matched/include/Obj03693.h"
#include "../../matched/include/Obj13398.h"
#include "../../matched/include/Obj00268.h"

struct S;
struct Unk021D6C50;
struct H;
struct L;
struct Obj;
struct Result;
struct T;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 unk00;
    u8 unk04[0x50];
    void *win;
} Seq_021D2030;

typedef struct {
    u32 unk00;
    u32 unk04;
    u8 unk08[0x4C];
    void *win;            /* 0x54 */
} Seq_021D20BC;

typedef struct {
    u32 unk00;
    u32 unk04;
    u8 unk08[0x4C];
    void *win;            /* 0x54 */
} Seq_021D210C;

typedef struct {
    u8 unk00[0x54];
    void *win;            /* 0x54 */
    u8 unk58[0x134 - 0x58];
    u32 unk134;
} Seq_021D215C;

typedef struct {
    u32 unk00;
    u32 unk04;
    u8 unk08[0x4C];
    void *win;            /* 0x54 */
} Seq_021D21D4;

typedef struct {
    u32 unk00;
    u32 unk04;
} Seq_021D2234;

typedef struct {
    u32 unk00;
    u32 unk04;
    u8 unk08[0x4C];
    void *win;            /* 0x54 */
} Seq;

typedef struct { u16 a; u16 b; } Pair16;

typedef struct { u8 data[0x24]; } MsgParam;

typedef struct {
    void *battle;
    void *party;
    u8 unk008[0x4c];
    void *msgWin;
    MsgParam msg;
    u8 unk07C[0x11e];
    u16 level;
    u8 unk19C[0xa];
    u8 side;
} LearnSeq;

struct StateData { u8 pad0[8]; int counter; u32 remaining; u32 pad10; u8 result[14]; };

extern u32 func_021CD9E0(u8 *p);
extern unsigned int func_021B8590(unsigned char *p);
extern u32 func_021D2000(Seq_021D2030 *s, u32 k, u32 b);
extern void func_021EA0A0(u32 *p, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u8 s7);
extern int func_021EA0E4(u32 *p);
extern unsigned char func_021B8DC0(unsigned char *p, void *a, unsigned int b);
extern void func_021EA354(void *ctx, int a, int b);
extern int func_021F7EB4(void);
extern int func_021B8D8C(void *p, void *a, u32 b);
extern void func_021EA0F4(struct S *s, u32 a, u32 b, u32 c);
extern int func_021EA120(struct S *s);
extern u8 func_021CD644(u8 *p);
extern void func_021EA280(char *ctx, u32 n, int b, const u8 *c, u16 e);
extern int func_021EA2BC(char *ctx);
extern void func_021EA384(char *ctx, int a);
extern int func_021EA3A0(u32 *p);
extern void func_021EA678(char *p, u16 k, int *c);
extern int func_021EA710(u32 *p);
extern u8 func_021B8E70(u8 *p, u32 k);
extern void func_021F81D0(u32 a, u32 b);
extern u32 func_0201BD28(u16 id, u32 field);
extern void func_020061E4(unsigned int arg);
extern void func_021EA40C(char *ctx, int a);
extern int func_021EA428(u32 *p);
extern u8 *func_021B9934(char *p, int i);
extern void func_021D646C(void *p);
extern void func_021EA438(u32 *p, u32 a2);
extern int func_021EA448(u32 *p);
extern void func_021EA7C8(void *ctx, int a);
extern int func_021EA7E8(void *w, int v);
extern void func_021EA7D8(void *ctx, int a);
extern int *func_021EF9C0(int *p, int a, int b);
extern void func_021F7998(u32 a);
extern void func_021EF9C8(int *p);
extern void func_021EA838(u32 *p, u32 k);
extern int func_021EA850(u32 *p, u32 k);
extern int func_021B8DEC(void *p, u32 k);
extern char *func_021B9AEC(char *p, int i);
extern void func_021B9C10(u32 *p, int a, int b);
extern void func_021EA904(void *w, u32 a, u32 b, u32 c, int d, int e);
extern int func_021EA950(void *w);
extern u8 func_021B8BEC(u8 *, u32, u8);
extern void func_021F7E94(int a);
extern void func_021F88BC(int v);
extern void func_021F7EA4(u32 v);
extern int func_021D6C50(struct Unk021D6C50 *a, struct Unk021D6C50 *b);
extern void func_021EA8B4(char *ctx, u32 a, u32 b);
extern int func_021EA8D4(u32 *p);
extern int func_021D7AD4(int a);
extern void func_021EA1B8(struct S *s, u32 a, int b, int c);
extern int func_021EA1F0(struct S *s);
void func_021F878C(u32 a);
extern void func_021EA8E4(u32 *p);
extern int func_021EA8F4(u32 *p);
extern void *func_021D5844(void *m);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_02017E40(void *p, u32 id, u32 v);
extern int func_021F8204(int);
extern int func_021D69B8(struct Obj *p, u32 *remaining, struct Result *r);
extern void func_021F8134(int, u32);
extern int func_021F8180(void);
extern void func_021D6EA0(void *);
extern void func_021D6BFC(u8 *p);
extern void func_021F8150(int, void *);
extern int func_02006238(void);
extern void func_021EA3B8(char *ctx, int a, int b);
extern int func_021EA3D4(void *);
extern void func_021EAF18(struct L *p, int kind, int id);
extern void func_021EAF50(struct L *p, u32 val);
extern void func_021EA614(char *p, struct H *h);
extern int func_021EA720(u32 *p);
extern void func_02005DE4(void *);
extern int func_02005E64(void);
extern void func_02005D90(u32, u32);
extern int func_02005F38(void);
extern int func_02005E9C(void);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_021BA238(char *p, void *m);
extern void func_021EADA4(u8 *, int, struct T *);
extern int func_021EADB4(u8 *);
extern void func_021EADC4(u8 *);
extern int func_021EADD4(u8 *);
extern void func_021EADE4(u8 *);
extern int func_021EADF4(u8 *);
extern int func_021D2CA8(LearnSeq *, int *, void *);
extern void func_021B9358(char *p, int i);
int func_021D2030(Seq_021D2030 *s, int *state, const u32 *a);
int func_021D20BC(Seq_021D20BC *s, int *state, u32 *a);
int func_021D210C(Seq_021D210C *s, int *state, u32 *a);
int func_021D215C(Seq_021D215C *s, int *state, u32 *a);
int func_021D21D4(Seq_021D21D4 *s, int *state, u32 *a);
int func_021D2234(Seq_021D2234 *s, int *state, u32 *a);
int func_021D2278(Seq *s, int *state, u32 *a);
int func_021D2320(u8 *p, int *st, u32 *c);
int func_021D2374(u8 *p, int *st, u32 *c);
int func_021D23B8(u8 *p, int *st, u32 *c);
int func_021D2424(u8 *p, int *st, u32 *c);
int func_021D2490(u8 *p, int *st, u32 *c);
int func_021D2510(u8 *p, int *st, u32 *c);
int func_021D2580(u8 *p, int *st, u32 *c);
int func_021D25C4(u8 *p, int *st, u32 *c);
int func_021D2628(u8 *p, int *st, u32 *c);
int func_021D266C(u8 *p, int *st, u32 *c);
int func_021D2700(u32 *p, int *st, u32 *c);
int func_021D2814(char *p, int *state, unsigned int *q);
int func_021D284C(u8 *p, int *st, u32 *c);
int func_021D28AC(u8 *p, int *st, u32 *c);
int func_021D2930(u32 *a, int *b, u32 *c);
int func_021D2990(int a, int b, int *c);
int func_021D299C(char *p, int *state);
int func_021D29CC(u32 *a, int b, u32 *c);
int func_021D2A20(u8 *p, int *state, u32 *args);
extern Pair16 d_021EFFAE[5];
extern u16 d_021EFF88[];
extern struct StateData d_021F3B64;





/*
 * lever: word locals with casts at the four descriptor loads, t2 before v
 * in declaration order, and a named nested-call result keep v in r7 and
 * t1/t2 in the original spill slots. The u8 b in the callee's own source
 * is widened here: the original caller has no second truncation after v.
 */
int func_021D2030(Seq_021D2030 *s, int *state, const u32 *a)
{
    u32 t2;
    u32 v;
    u32 t1;
    u32 t3;
    u32 result;
    switch (*state) {
    case 0:
        if (func_021CD9E0((u8 *)s)) {
            return 1;
        }
        if (func_021B8590((unsigned char *)s->unk00)) {
            v = (u8)a[0];
            t1 = (u8)a[1];
            t2 = (u16)a[2];
            t3 = (u8)a[3];
            result = func_021D2000(s, t2, v);
            func_021EA0A0(s->win, v, t1, t2, result, t3, 0);
            *state = *state + 1;
        } else {
            return 1;
        }
        break;
    case 1:
        if (func_021EA0E4(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}






int func_021D20BC(Seq_021D20BC *s, int *state, u32 *a)
{
    u32 t;

    switch (*state) {
    case 0:
        t = (u32)func_021B8DC0((unsigned char *)s->unk00, (void *)s->unk04, (u8)a[0]);
        func_021EA354(s->win, t, a[1] != 0);
        *state = *state + 1;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            return 1;
        }
        return 0;
    }
    return 0;
}






int func_021D210C(Seq_021D210C *s, int *state, u32 *a)
{
    int t;

    switch (*state) {
    case 0:
        t = func_021B8D8C((void *)s->unk00, (void *)s->unk04, (u8)a[0]);
        func_021EA0F4(s->win, (u16)a[2], t, (u8)a[1]);
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA120(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}






int func_021D215C(Seq_021D215C *s, int *state, u32 *a)
{
    u8 buf[8];
    u8 i;
    u16 n;
    u32 p1;
    u16 p2;

    switch (*state) {
    case 0:
        n = a[0];
        p1 = a[1];
        p2 = a[2];
        for (i = 0; i < n; i++) {
            buf[i] = func_021CD644((u8 *)s->unk134);
        }
        func_021EA280(s->win, n, p1, buf, p2);
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA2BC(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}






int func_021D21D4(Seq_021D21D4 *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        func_021EA384(s->win, func_021B8D8C((void *)s->unk00, (void *)s->unk04, (u8)a[0]));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA3A0(s->win)) {
            func_021EA678(s->win, 0x61, (int *)a);
            *state = *state + 1;
        }
        break;
    case 2:
        if (func_021EA710(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}






int func_021D2234(Seq_021D2234 *s, int *state, u32 *a)
{
    int t;

    switch (*state) {
    case 0:
        t = func_021B8D8C((void *)s->unk00, (void *)s->unk04, (u8)a[0]);
        func_021F81D0(a[1], func_021B8E70((u8 *)s->unk00, t));
        *state = *state + 1;
        break;
    case 1:
        return 1;
    }
    return 0;
}





int func_021D2278(Seq *s, int *state, u32 *a)
{
    int t;

    switch (*state) {
    case 0:
        if (func_021CD9E0((u8 *)s) == 0) {
            t = func_021B8D8C((void *)s->unk00, (void *)s->unk04, (u8)a[0]);
            func_021EA0A0(s->win, t, t, 1, func_0201BD28(1, 0x1B), 0, 0);
        }
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA0E4(s->win)) {
            t = func_021B8D8C((void *)s->unk00, (void *)s->unk04, (u8)a[0]);
            if (func_021CD9E0((u8 *)s) == 0) {
                func_020061E4(0x564);
            }
            func_021EA0F4(s->win, 1, t, 1);
            *state = *state + 1;
        }
        break;
    case 2:
        if (func_021EA120(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}





int func_021D2320(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0:
        func_021EA40C(((struct Obj06240 *)p)->f54, func_021B8D8C(((struct Obj06240 *)p)->f0, ((struct Obj06240 *)p)->f4, (u8)(*c)));
        (*st)++;
        break;
    case 1:
        if (func_021EA428(((struct Obj06240 *)p)->f54)) {
            func_021D646C(func_021B9934(((struct Obj06240 *)p)->f4, (u8)(*c)));
            return 1;
        }
        break;
    }
    return 0;
}





int func_021D2374(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0:
        func_021EA438(((struct Obj07782 *)p)->f54, func_021B8D8C(((struct Obj07782 *)p)->f0, ((struct Obj07782 *)p)->f4, (u8)(*c)));
        (*st)++;
        break;
    case 1:
        if (func_021EA448(((struct Obj07782 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}





int func_021D23B8(u8 *p, int *st, u32 *c)
{
    u32 t = func_021B8E70(((struct Obj05206 *)p)->f0, func_021B8D8C(((struct Obj05206 *)p)->f0, ((struct Obj05206 *)p)->f4, (u8)(*c)));

    switch (*st) {
    case 0:
        if (func_021CD9E0(p))
            return 1;
        if (!func_021B8590(((struct Obj05206 *)p)->f0))
            return 1;
        func_021EA7C8(((struct Obj05206 *)p)->f54, t);
        (*st)++;
        break;
    case 1:
        if (func_021EA7E8(((struct Obj05206 *)p)->f54, t))
            return 1;
        break;
    }
    return 0;
}





int func_021D2424(u8 *p, int *st, u32 *c)
{
    u32 t = func_021B8E70(((struct Obj05207 *)p)->f0, func_021B8D8C(((struct Obj05207 *)p)->f0, ((struct Obj05207 *)p)->f4, (u8)(*c)));

    switch (*st) {
    case 0:
        if (func_021CD9E0(p))
            return 1;
        if (!func_021B8590(((struct Obj05207 *)p)->f0))
            return 1;
        func_021EA7D8(((struct Obj05207 *)p)->f54, t);
        (*st)++;
        break;
    case 1:
        if (func_021EA7E8(((struct Obj05207 *)p)->f54, t))
            return 1;
        break;
    }
    return 0;
}





int func_021D2490(u8 *p, int *st, u32 *c)
{
    u8 id = c[0];

    switch (*st) {
    case 0:
        func_021EF9C0(((struct Obj10019 *)p)->f34, (u8)id, (u16)c[1]);
        if (func_021CD9E0(p))
            return 1;
        if (id < 5)
            func_021F7998(d_021EFFAE[id].b);
        (*st)++;
        break;
    case 1:
        if (!func_021F7EB4()) {
            func_021EA678(((struct Obj10019 *)p)->f54, d_021EFFAE[id].a, 0);
            (*st)++;
        }
        break;
    case 2:
        if (func_021EA710(((struct Obj10019 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}





int func_021D2510(u8 *p, int *st, u32 *c)
{
    u16 v;

    switch (*st) {
    case 0:
        switch ((u8)c[0]) {
        case 1:
            v = 0x59;
            break;
        case 2:
            v = 0x5a;
            break;
        case 4:
            v = 0x5b;
            break;
        case 3:
            v = 0x5c;
            break;
        default:
            return 1;
        }
        func_021EA678(((struct Obj10021 *)p)->f54, v, 0);
        (*st)++;
        break;
    case 1:
        if (func_021EA710(((struct Obj10021 *)p)->f54)) {
            func_021EF9C8(((struct Obj10021 *)p)->f34);
            return 1;
        }
        break;
    }
    return 0;
}





int func_021D2580(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0:
        func_021EA384(((struct Obj07783 *)p)->f54, func_021B8D8C(((struct Obj07783 *)p)->f0, ((struct Obj07783 *)p)->f4, (u8)(*c)));
        (*st)++;
        break;
    case 1:
        if (func_021EA3A0(((struct Obj07783 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}





int func_021D25C4(u8 *p, int *st, u32 *c)
{
    int t = func_021B8D8C(((struct Obj06241 *)p)->f0, ((struct Obj06241 *)p)->f4, (u8)(*c));

    switch (*st) {
    case 0:
        if (func_021CD9E0(p))
            return 1;
        if (!func_021B8590(((struct Obj06241 *)p)->f0))
            return 1;
        func_021EA838(((struct Obj06241 *)p)->f54, t);
        (*st)++;
        break;
    case 1:
        if (func_021EA850(((struct Obj06241 *)p)->f54, t))
            return 1;
        break;
    }
    return 0;
}





int func_021D2628(u8 *p, int *st, u32 *c)
{
    u8 id = *c;

    switch (*st) {
    case 0:
        func_021EA384(((struct Obj07784 *)p)->f54, func_021B8D8C(((struct Obj07784 *)p)->f0, ((struct Obj07784 *)p)->f4, id));
        (*st)++;
        break;
    case 1:
        if (func_021EA3A0(((struct Obj07784 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}





int func_021D266C(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0: {
        u8 a = c[0];
        u32 b = (u8)c[1];
        u32 d = (u8)c[2];
        int x = func_021B8DEC(((struct Obj04364 *)p)->f0, b);
        int y = func_021B8DEC(((struct Obj04364 *)p)->f0, d);
        u32 m = func_021B8E70(((struct Obj04364 *)p)->f0, b);
        u32 n = func_021B8E70(((struct Obj04364 *)p)->f0, d);
        func_021B9C10((u32 *)func_021B9AEC(((struct Obj04364 *)p)->f4, a), x, y);
        func_021EA904(((struct Obj04364 *)p)->f54, a, m, n, x, y);
        (*st)++;
        break;
    }
    case 1:
        if (func_021EA950(((struct Obj04364 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}




int func_021D2700(u32 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0:
        func_021F7998(0x281);
        (*st)++;
        break;
    case 1:
        if (!func_021F7EB4()) {
            u8 a = c[0], b = c[1];
            u32 x, y, v, w;
            x = func_021B8BEC((u8 *)p[0], a, b);
            y = func_021B8BEC((u8 *)p[0], a, 1);
            v = func_021B8E70((u8 *)p[0], x);
            w = func_021B8E70((u8 *)p[0], y);
            func_021B9C10((u32 *)func_021B9AEC((char *)p[1], a), b, 1);
            func_021EA904((u32 *)p[21], a, v, w, b, 1);
            (*st)++;
        }
        break;
    case 2:
        if (func_021EA950((void *)p[21])) {
            u8 a = c[2], b = c[3];
            u32 x, y, v, w;
            x = func_021B8BEC((u8 *)p[0], a, b);
            y = func_021B8BEC((u8 *)p[0], a, 1);
            v = func_021B8E70((u8 *)p[0], x);
            w = func_021B8E70((u8 *)p[0], y);
            func_021B9C10((u32 *)func_021B9AEC((char *)p[1], a), b, 1);
            func_021EA904((u32 *)p[21], a, v, w, b, 1);
            (*st)++;
        }
        break;
    case 3:
        if (func_021EA950((void *)p[21])) return 1;
        break;
    }
    return 0;
}




/*
 * evidence: Thumb 01 49 02 4b 18 47 c0 46; pools 0x26e and 0x021F7A29. No ARM9/SDK blocker work.
 * note 2026-10-05 (D8 lane16): re-verified MATCH. Callee 0x021F7E94 is an ov094 Thumb tail stub (pool 0x26E, 0x021F7A29); other overlay, not filed. Integrator: seed label.
 */
int func_021D2814(char *p, int *state, unsigned int *q)
{
    switch (*state) {
    case 0:
        func_021F7E94((u8)func_021B8E70(*(void **)p, (u8)q[0]));
        (*state)++;
        break;
    case 1:
        if (func_021F7EB4() == 0) return 1;
        break;
    }
    return 0;
}





int func_021D284C(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0: {
        u32 t = func_021B8E70(((struct Obj21158 *)p)->f0, (u8)(*c));
        if (func_021CD9E0(p))
            func_021F88BC(1);
        func_021F7EA4(t);
        (*st)++;
        break;
    }
    case 1:
        if (!func_021F7EB4()) {
            if (func_021CD9E0(p))
                func_021F88BC(0);
            return 1;
        }
        break;
    }
    return 0;
}





int func_021D28AC(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0: {
        u8 *a = func_021B9934(*(char * *)&((struct Obj03693 *)p)->f4, (u8)c[0]);
        u8 *b = func_021B9934(*(char * *)&((struct Obj03693 *)p)->f4, (u8)c[1]);
        int d = (int)func_021B8DC0(((struct Obj03693 *)p)->f0, ((struct Obj03693 *)p)->f4, (u8)c[0]);
        int e = (int)func_021B8DC0(((struct Obj03693 *)p)->f0, ((struct Obj03693 *)p)->f4, (u8)c[1]);
        func_021D6C50((struct Unk021D6C50 *)a, (struct Unk021D6C50 *)b);
        func_021EA8B4(((struct Obj03693 *)p)->f54, d, e);
        (*st)++;
        break;
    }
    case 1:
        if (func_021EA8D4(((struct Obj03693 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}




int func_021D2930(u32 *a, int *b, u32 *c)
{
    int t;

    switch (*b) {
    case 0:
        if (func_021CD9E0((u8 *)a) == 0) {
            t = func_021B8D8C((void *)a[0], (void *)a[1], (u8)c[0]);
            func_021EA1B8((struct S *)a[0x15], (u16)c[2], t, func_021D7AD4(c[1]));
            (*b)++;
            break;
        }
        return 1;
    case 1:
        if (func_021EA1F0((struct S *)a[0x15]) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}




int func_021D2990(int a, int b, int *c)
{
    func_021F878C(*c);
    return 1;
}



int func_021D299C(char *p, int *state)
{
    switch (*state) {
    case 0:
        func_021EA8E4(((struct Obj13398 *)p)->f54);
        (*state)++;
        break;
    case 1:
        if (func_021EA8F4(((struct Obj13398 *)p)->f54) != 0) return 1;
        break;
    }
    return 0;
}



int func_021D29CC(u32 *a, int b, u32 *c)
{
    void *m;
    u32 i;
    int k;
    u32 v;

    m = func_021D5844(func_021B9934((char *)a[1], (u8)c[0]));
    for (i = 0; i < 6; i++) {
        if (d_021EFF88[i + 1] != 0) {
            k = d_021EFF88[i];
            v = c[i + 1] + func_02017E1C(m, k, 0);
            if (v > 0xff) {
                v = 0xff;
            }
            func_02017E40(m, k, v);
        }
    }
    return 1;
}


/*
 * evidence: 43/43 relocations resolved after parent-coordinated overlay
 * leaf witnesses; all ARM9 calls resolve without new ARM9 files.
 * lever: int id loaded via (u8) cast fixes spill slots; widening the
 * func_021B8DC0 third extern parameter removes absent call truncation.
 * StateData fields keep counter updates on one global base.
 */
int func_021D2A20(u8 *p, int *state, u32 *args)
{
    void *obj;
    int id;
    int index;
    int enabled;
    u32 remaining;
    id = (u8)args[0];
    obj = func_021B9934(*(char * *)&((struct Obj00268 *)p)->f4, id);
    index = func_021B8DC0(((struct Obj00268 *)p)->f0, ((struct Obj00268 *)p)->f4, id);
    enabled = 0;
    if (index != 0xff && func_021F8204(index)) enabled = 1;
    switch (*state) {
    case 0:
        d_021F3B64.remaining = args[1];
        d_021F3B64.counter = 0;
        *state = 1;
    case 1:
        if (d_021F3B64.remaining) {
            remaining = d_021F3B64.remaining;
            if (func_021D69B8(obj, &remaining, (struct Result *)d_021F3B64.result)) {
                *state = 3;
            } else {
                if (enabled) {
                    func_021F8134(index, d_021F3B64.remaining);
                    *state = 2;
                } else *state = 13;
                remaining = 0;
            }
            d_021F3B64.remaining = remaining;
        } else *state = 13;
        break;
    case 2:
        if (!func_021F8180()) *state = 13;
        break;
    case 3:
        func_021D6EA0(obj);
        func_021D6BFC(obj);
        if (enabled) {
            func_021F8150(index, obj);
            *state = 4;
        } else *state = 6;
        break;
    case 4:
        if (!func_021F8180() && !func_02006238()) {
            func_021EA3B8(((struct Obj00268 *)p)->f54, index, 0x25d);
            *state = 5;
        }
        break;
    case 5:
        if (func_021EA3D4(((struct Obj00268 *)p)->f54)) *state = 6;
        break;
    case 6:
        func_021EAF18((struct L *)(p + 0x58), 1, 0x3c);
        func_021EAF50((struct L *)(p + 0x58), (int)id);
        func_021EAF50((struct L *)(p + 0x58), (int)d_021F3B64.result[0]);
        func_021EA614(((struct Obj00268 *)p)->f54, (struct H *)(p + 0x58));
        *state = 7;
        break;
    case 7:
        if (func_021EA720(((struct Obj00268 *)p)->f54)) {
            func_02005DE4((void *)1);
            func_02005E64();
            func_02005D90(0x515, 0xffff);
        }
        if (func_021EA710(((struct Obj00268 *)p)->f54) && !func_02005F38()) {
            func_02005E9C();
            func_02005DE4(0);
            d_021F3B64.counter = 0;
            *state = 8;
        }
        break;
    case 8:
        d_021F3B64.counter++;
        if ((func_020362DC() & 3) || func_02035C60() || d_021F3B64.counter > 80) {
            d_021F3B64.counter = 0;
            func_021BA238(((struct Obj00268 *)p)->f0, obj);
            func_021EADA4(*(u8 * *)&((struct Obj00268 *)p)->f54, (int)obj, (struct T *)d_021F3B64.result);
            *state = 9;
        }
        break;
    case 9:
        if (func_021EADB4(((struct Obj00268 *)p)->f54) && ((func_020362DC() & 3) || func_02035C60())) {
            func_021EADC4(((struct Obj00268 *)p)->f54);
            *state = 10;
        }
        break;
    case 10:
        if (func_021EADD4(((struct Obj00268 *)p)->f54) && ((func_020362DC() & 3) || func_02035C60())) {
            func_021EADE4(((struct Obj00268 *)p)->f54);
            *state = 11;
        }
        break;
    case 11:
        if (func_021EADF4(((struct Obj00268 *)p)->f54)) {
            d_021F3B64.counter = 0;
            *state = 12;
        }
        break;
    case 12:
        if (func_021D2CA8((LearnSeq *)p, &d_021F3B64.counter, obj)) *state = 1;
        break;
    case 13:
        func_021B9358(((struct Obj00268 *)p)->f0, id);
        return 1;
    }
    return 0;
}
