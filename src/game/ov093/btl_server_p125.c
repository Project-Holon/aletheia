/*
 * file:     btl_server_p125.c
 * unit:     yes
 * function: func_021D0B6C, func_021D0BB0, func_021D0C78, func_021D0CC4, func_021D0D38,func_021D0D44, func_021D0D50, func_021D0E7C, func_021D102C, func_021D1058
 * address:  0x021D0B6C
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
 *   func_021D8394  0x021D8394  thumb  ov093
 *   func_021B9B94 0x021B9B94 thumb ov093
 *   func_021B99C0 0x021B99C0 thumb ov093
 *   func_021B8E28 0x021B8E28 thumb ov093
 *   func_021B9C00 0x021B9C00 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021EEC20  0x021EEC20  thumb  ov093
 *   func_021B8DE4  0x021B8DE4  thumb  ov093
 *   func_021EAF18  0x021EAF18  thumb  ov093
 *   func_021EABC4  0x021EABC4  thumb  ov093
 *   func_021EAC54  0x021EAC54  thumb  ov093
 *   func_021CE1B0 0x021CE1B0 thumb ov093
 *   func_021D0980 0x021D0980 thumb ov093
 *   func_021CFD50 0x021CFD50 thumb ov093
 *   func_021D09E0 0x021D09E0 thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021D83C4 0x021D83C4 thumb ov093
 *   func_021D8434 0x021D8434 thumb ov093
 *   func_021D0B10 0x021D0B10 thumb ov093
 *   func_021E9A78 0x021E9A78 thumb ov093
 *   func_021CE068 0x021CE068 thumb ov093
 *   func_021CE08C 0x021CE08C thumb ov093
 *   func_021E9B14 0x021E9B14 thumb ov093
 *   func_021E9B20 0x021E9B20 thumb ov093
 *   func_021CE0E0 0x021CE0E0 thumb ov093
 *   func_021B86C0 0x021B86C0 thumb ov093
 *   func_021EA7FC 0x021EA7FC thumb ov093
 *   func_021EA814 0x021EA814 thumb ov093
 *   func_021B9AB0  0x021B9AB0  thumb  ov093
 *   func_021D83FC  0x021D83FC  thumb  ov093
 */
#include "../../matched/include/Obj13365.h"
#include "../../matched/include/Obj03198.h"
#include "../../matched/include/Obj09995.h"
#include "../../matched/include/Obj05202.h"
#include "../../matched/include/Obj01236.h"
#include "../../matched/include/Obj00819.h"
#include "../../matched/include/Obj13368.h"
#include "../../matched/include/Obj13369.h"

struct Q1;
struct S2;
struct L;
struct G;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    void *battle;         /* 0x00 */
    u8 unk04[0x50];
    void *msgWin;         /* 0x54 */
    u8 msg[0x14E];        /* 0x58 */
    u8 unk1A6;            /* 0x1A6 */
} BattleSeq;

typedef struct { u8 pad[0x1B3]; volatile u8 count; } CountField;

extern void func_021D8394(void *dst, u8 a, u8 b);
extern u8 func_021B9B94(struct Q1 *p);
extern u8 func_021B99C0(void *, int);
extern void func_021B8E28(u8 *, u8, u8 *, u8 *);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int func_021D5B68(void *);
extern int func_021EEC20(int, int *);
extern u8 func_021B8DE4(char *p, int i);
extern void func_021EAF18(struct L *p, int kind, int id);
extern void func_021EABC4(u8 *a, u32 x, u32 y, u32 z);
extern int func_021EAC54(void *win, int *out);
extern u8 func_021D0980(u8 *,u8 *);
extern u8 *func_021CFD50(struct G *g, int k);
extern void func_021D09E0(u8 *p, u8 *order, u8 count, void *target);
extern u32 func_021B8588(void **);
extern void func_021D83C4(u32 *p);
extern void func_021D8434(u32 *p);
extern int func_021CE1B0(u8 *,int *);
extern void func_021D0B10(u8 *p, u32 a, u32 b, void *q, void *out);
extern void func_021E9A78(char *p, const u8 *q, int x, int y, u8 *r);
extern void func_021CE068(u8 *);
extern int func_021CE08C(u8 *);
extern void func_021E9B14(unsigned int *p);
extern int func_021E9B20(u8 *p);
extern void func_021CE0E0(u8 *p);
extern u8 func_021B86C0(u8 **p);
extern void func_021EA7FC(char *p);
extern int func_021EA814(u32 *p);
extern int func_021B9AB0(int k);
extern void func_021D83FC(u32 *p, u32 sub);
void func_021D0B6C(u8 *g, u8 *s);
void func_021D0BB0(u8 *p);
u8 func_021D0C78(BattleSeq *s, u8 *out);
int func_021D0CC4(BattleSeq *s, int *state);
int func_021D0D38(u8 *p, int *state);
int func_021D0D44(u8 *p, int *state);
int func_021D0D50(u8 *p);
int func_021D0E74(u8 *p,int *state);
int func_021D0E7C(u8 *p, int *state, u8 param);
int func_021D102C(char *p);
int func_021D1058(u8 *s, void *q);




void func_021D0B6C(u8 *g, u8 *s)
{
    u8 i;

    for (i = 0; i < s[6]; i++)
        func_021D8394(g + 0x124 + i * 4, s[i + 3], s[i]);
    *(u8 * *)&((struct Obj13365 *)g)->fD8 = g + 0x124;
    ((struct Obj13365 *)g)->fDC = s[6] << 2;
}



void func_021D0BB0(u8 *p)
{
    u8 pair[2];
    u8 start;
    u8 count;
    u32 n;
    u32 i;
    u32 j;
    count = 0;
    n = func_021B9B94(((struct Obj03198 *)p)->f118);
    start = func_021B99C0(((struct Obj03198 *)p)->f0, p[0x1a6]);
    for (i = 0; i < p[0x1b3]; i++) {
        func_021B8E28(*(u8 * *)&((struct Obj03198 *)p)->f0, p[0x1b5 + i], &pair[1], &pair[0]);
        for (j = start; j < n; j++) {
            if (!func_021D5B68(func_021B9C00(((struct Obj03198 *)p)->f118, (u8)j))) {
                func_021D8394(p + 0x124 + count++ * 4, pair[0], j);
                start = j + 1;
                break;
            }
        }
    }
    ((struct Obj03198 *)p)->fD8 = p + 0x124;
    ((struct Obj03198 *)p)->fDC = count * 4;
}




u8 func_021D0C78(BattleSeq *s, u8 *out)
{
    int arr;
    u8 n;
    u32 i;
    u32 cnt;

    n = func_021EEC20(((struct Obj09995 *)s)->f50, &arr);
    i = 0;
    cnt = 0;
    for (; i < n; i++) {
        if (s->unk1A6 == func_021B8DE4(s->battle, ((u8 *)arr)[i])) {
            out[cnt] = ((u8 *)arr)[i];
            cnt++;
        }
    }
    return cnt;
}




int func_021D0CC4(BattleSeq *s, int *state)
{
    int t;
    u8 *q;
    u8 f;

    switch (*state) {
    case 0:
        func_021EAF18((struct L *)s->msg, 3, 5);
        func_021EAF18((struct L *)((u8 *)s + 0x7c), 3, 1);
        func_021EABC4(s->msgWin, (u32)s->msg, (u32)((u8 *)s + 0x7c), 0);
        (*state)++;
        break;
    case 1:
        if (func_021EAC54(s->msgWin, &t)) {
            f = 0;
            if (t != 0)
                f = 1;
            q = (u8 *)s + 0x1ac;
            *q = f;
            *(u8 * *)&((struct Obj05202 *)s)->fD8 = q;
            ((struct Obj05202 *)s)->fDC = 1;
            return 1;
        }
        break;
    }
    return 0;
}


int func_021D0D38(u8 *p, int *state)
{
    return func_021D0E7C(p, state, 2);
}


int func_021D0D44(u8 *p, int *state)
{
    return func_021D0E7C(p, state, 1);
}



/*
 * lever: separate order[6] then pair[2] stack arrays keep the order base
 * at sp+6 and the index in the ldrb register offset; one buffer or a
 * struct member array reassociates this into a base+index and immediate 2.
 * follower: 021D0E74 is an eight-byte tail-call stub to func_021CE1B0;
 * included in this complete 300-byte unit after parent ownership audit.
 */
int func_021D0D50(u8 *p)
{
    u8 order[6];
    u8 pair[2];
    u8 count;
    u8 n;
    u8 i;
    u8 *target;
    int result;
    p[0x1b3] = func_021D0C78((BattleSeq *)p, p+0x1b5);
    if (p[0x1b3]) {
        n = func_021D0980(p,order);
        if (n) {
            count = p[0x1b3];
            target = func_021CFD50((struct G *)p,p[0x1b5]);
            if (target) func_021D09E0(p,order,n,target);
            if (count > n) {
                if (func_021B8588(*(void ** *)&((struct Obj01236 *)p)->f0) == 3) {
                    result = func_021D1058(p,p+0x124);
                    if (result) {
                        *(int *)&((struct Obj01236 *)p)->fDC = result;
                        ((struct Obj01236 *)p)->fD8 = p+0x124;
                        return 1;
                    }
                }
                count = n;
            }
            for (i=0;i<count;i++) {
                func_021B8E28(*(u8 * *)&((struct Obj01236 *)p)->f0,p[0x1b5+i],pair,pair+1);
                func_021D8394(p+0x124+i*4,pair[1],order[i]);
            }
            ((struct Obj01236 *)p)->fD8 = p+0x124;
            ((struct Obj01236 *)p)->fDC = count*4;
        } else {
            if (func_021D102C((char *)p)) {
                result = func_021D1058(p,p+0x124);
                if (result) {
                    *(int *)&((struct Obj01236 *)p)->fDC = result;
                    ((struct Obj01236 *)p)->fD8 = p+0x124;
                    return 1;
                }
            }
            func_021D83C4((u32 *)(p+0x124));
            ((struct Obj01236 *)p)->fD8 = p+0x124;
            ((struct Obj01236 *)p)->fDC = 4;
        }
    } else {
        func_021D8434((u32 *)(p+0x124));
        ((struct Obj01236 *)p)->fD8 = p+0x124;
        ((struct Obj01236 *)p)->fDC = 4;
    }
    return 1;
}



int func_021D0E74(u8 *p,int *state)
{
    return func_021CE1B0(p,state);
}



/*
 * lever: the state-0 fallbacks and single-mon path set state 4, not 6;
 * duplicating the state-4 assignment inside both fallback arms preserves
 * the late cross-jump of D8/DC stores. Factoring it outside adds 12 bytes.
 * volatile: count at 021D0EB2 is reread at 021D0EB6 and 021D0ECC.
 */
int func_021D0E7C(u8 *p, int *state, u8 param)
{
    u8 order[6];
    u8 pair[2];
    u32 n;
    u32 count;
    int mode;
    void *mon;
    switch (*state) {
    case 0:
        ((CountField *)p)->count = func_021D0C78((BattleSeq *)p, p + 0x1B5);
        if (((CountField *)p)->count != 0) {
            n = func_021D0980(p, order);
            if (n != 0) {
                count = ((CountField *)p)->count;
                if (count > n) count = n;
                if (func_021D102C((char *)p) != 0) {
                    mon = func_021B9C00(((struct Obj00819 *)p)->f118, 0);
                    if (n == 1 && func_021D5B68(mon) != 0) {
                        func_021D8394(p + 0x124, 0, order[0]);
                        *(u8 * *)&((struct Obj00819 *)p)->fD8 = p + 0x124;
                        ((struct Obj00819 *)p)->fDC = 4;
                        *state = 4;
                        break;
                    }
                }
                func_021B8E28(*(u8 * *)&((struct Obj00819 *)p)->f0, p[0x1B5], &pair[1], &pair[0]);
                func_021D0B10(p, param, count, p + 0x184, p + 0x190);
                func_021E9A78(((struct Obj00819 *)p)->f54, p + 0x184, pair[0], 0, p + 0x190);
                func_021CE068(p);
                *state = 1;
            } else {
                if (func_021D102C((char *)p) != 0 && (mode = func_021D1058(p, p + 0x124)) != 0) {
                    ((struct Obj00819 *)p)->fDC = mode;
                    *(u8 * *)&((struct Obj00819 *)p)->fD8 = p + 0x124;
                    *state = 4;
                } else {
                    func_021D83C4((u32 *)(p + 0x124));
                    *(u8 * *)&((struct Obj00819 *)p)->fD8 = p + 0x124;
                    ((struct Obj00819 *)p)->fDC = 4;
                    *state = 4;
                }
            }
        } else {
            func_021D8434((u32 *)(p + 0x124));
            *(u8 * *)&((struct Obj00819 *)p)->fD8 = p + 0x124;
            ((struct Obj00819 *)p)->fDC = 4;
            *state = 4;
        }
        break;
    case 1:
        if (func_021CE08C(p) != 0) {
            func_021E9B14(((struct Obj00819 *)p)->f54);
            *state = 2;
        } else if (func_021E9B20(((struct Obj00819 *)p)->f54) != 0) {
            func_021D0B6C(p, p + 0x190);
            *state = 3;
        }
        break;
    case 2:
        if (func_021E9B20(((struct Obj00819 *)p)->f54) != 0) {
            func_021D0BB0(p);
            *state = 3;
        }
        break;
    case 3:
        func_021CE0E0(p);
        *state = 4;
        break;
    case 4:
        if (func_021B86C0(((struct Obj00819 *)p)->f0) != 0) {
            p[0x1A9] = 1;
            func_021EA7FC(((struct Obj00819 *)p)->f54);
            *state = 5;
        } else {
            *state = 6;
        }
        break;
    case 5:
        if (func_021EA814(((struct Obj00819 *)p)->f54) != 0) {
            *state = 6;
        }
        break;
    case 6:
        return 1;
    }
    return 0;
}



/*
 * extent: compiled 42 bytes followed by two zero alignment bytes.
 */
int func_021D102C(char *p)
{
    if (func_021B8588(((struct Obj13368 *)p)->f0) == 3 && func_021D5B68(func_021B9C00(((struct Obj13368 *)p)->f118, 0)) != 0) return 1;
    return 0;
}




int func_021D1058(u8 *s, void *q)
{
    int k;

    k = 2;
    if (func_021D5B68(func_021B9C00(((struct Obj13369 *)s)->f118, (u8)func_021B9AB0(2))) == 0) {
        func_021D83FC(q, k);
        return 4;
    }
    k = 3;
    if (func_021D5B68(func_021B9C00(((struct Obj13369 *)s)->f118, (u8)func_021B9AB0(3))) == 0) {
        func_021D83FC(q, k);
        return 4;
    }
    return 0;
}
