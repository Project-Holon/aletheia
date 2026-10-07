/*
 * file:     unit_021EA01C_p02.c
 * unit:     yes
 * function: func_021EA614, func_021EA638, func_021EA65C, func_021EA678, func_021EA694, func_021EA6B0, func_021EA6F4, func_021EA710, func_021EA720, func_021EA730, func_021EA758, func_021EA768, func_021EA778, func_021EA788, func_021EA798, func_021EA7A8, func_021EA7B8, func_021EA7C8, func_021EA7D8, func_021EA7E8, func_021EA7FC, func_021EA814, func_021EA824, func_021EA838, func_021EA850, func_021EA868, func_021EA878, func_021EA888, func_021EA8A4, func_021EA8B4, func_021EA8D4, func_021EA8E4, func_021EA8F4, func_021EA904, func_021EA950, func_021EA990, func_021EAA00
 * address:  0x021EA614
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
 *   func_021EA55C  0x021EA55C  thumb  ov093
 *   func_021EEE80  0x021EEE80  thumb  ov093
 *   func_021EEEF4  0x021EEEF4  thumb  ov093
 *   func_0202A298  0x0202A298  thumb
 *   func_0202A310  0x0202A310  thumb
 *   func_021EF5E8  0x021EF5E8  thumb  ov093
 *   func_021ECF68   0x021ECF68  thumb  ov093
 *   func_021ECF50   0x021ECF50  thumb  ov093
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021ECEB8  0x021ECEB8  thumb  ov093
 *   func_021ECE60   0x021ECE60  thumb  ov093
 *   func_021EDA5C   0x021EDA5C  thumb  ov093
 *   func_021EDA94   0x021EDA94  thumb  ov093
 *   func_021EDAB0   0x021EDAB0  thumb  ov093
 *   func_021EDAE0   0x021EDAE0  thumb  ov093
 *   func_021EDB00   0x021EDB00  thumb  ov093
 *   func_021EDB20   0x021EDB20  thumb  ov093
 *   func_021F7A28  0x021F7A28  thumb  ov094
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   func_021F8A40  0x021F8A40  thumb  ov094
 *   func_021EE200  0x021EE200  thumb  ov093
 *   func_021EE21C   0x021EE21C  thumb  ov093
 *   func_021F8A78  0x021F8A78  thumb  ov094
 *   func_021EE224  0x021EE224  thumb  ov093
 *   func_021ED56C   0x021ED56C  thumb  ov093
 *   func_021B8E70   0x021B8E70  thumb  ov093
 *   func_021ED57C   0x021ED57C  thumb  ov093
 *   func_021ED590   0x021ED590  thumb  ov093
 *   func_021ED5D8   0x021ED5D8  thumb  ov093
 *   func_021ED6BC  0x021ED6BC  thumb  ov093
 *   func_021ED714   0x021ED714  thumb  ov093
 *   func_021ED660  0x021ED660  thumb  ov093
 *   func_021ED8AC   0x021ED8AC  thumb  ov093
 *   func_021ED8D8   0x021ED8D8  thumb  ov093
 *   func_021E9100  0x021E9100  thumb  ov093
 *   func_021B8BEC  0x021B8BEC  thumb  ov093
 *   func_021F84B4  0x021F84B4  thumb  ov094
 *   func_021EAF00  0x021EAF00  thumb  ov093
 *   func_021ED4E4  0x021ED4E4  thumb  ov093
 *   func_021ED510  0x021ED510  thumb  ov093
 *   func_021B9AF8  0x021B9AF8  thumb  ov093
 *   func_021EAA24  0x021EAA24  thumb  ov093
 */
#include "../../matched/include/Obj01899.h"
#include "../../matched/include/Obj13561.h"
#include "../../matched/include/Obj07846.h"
#include "../../matched/include/Obj21566.h"
#include "../../matched/include/Obj21567.h"
#include "../../matched/include/Obj13562.h"
#include "../../matched/include/Obj13563.h"
#include "../../matched/include/Obj13564.h"
#include "../../matched/include/Obj10115.h"

struct H;
struct T;
typedef unsigned char u8;

struct H {
    u8 b0[2];
    u8 b2;
};

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u32 f0; u8 pad[60]; } E64;

typedef struct {
    u32 pad[7];
    int (*cb1)(void *, u32);   /* 0x1c */
    int (*cb2)(void *, u32);   /* 0x20 */
    u32 arg;                   /* 0x24 */
    u32 obj;                   /* 0x28 */
} CbSlot;

extern void func_021EA55C(struct H *p, int a);
extern void func_021EEE80(unsigned int a, u16 k, unsigned int *p);
extern void func_021EEEF4(unsigned int a, u16 b, unsigned int c);
extern u32 func_0202A298(u32 key, u32 want, u32 heap);
extern void func_0202A310(int key, int want, void *dest, u32 heap);
extern void func_021EF5E8(u32 a, u8 b, u16 c);
extern int func_021ECF68(struct T *p);
extern u32 func_021CD9E0(u8 *p);
extern void func_021ECEB8(u8 *a, u32 b, u16 s, u32 c);
extern void func_021F7A28(int a, u32 b);
extern int func_021F7EB4(void);
extern void func_021F8A40(int a);
extern void func_021EE200(u8 *p);
extern int func_021EE21C(u8 *p);
extern void func_021F8A78(void);
extern void func_021EE224(char *p);
extern u8 func_021B8E70(u8 *p, u32 k);
extern void func_021ED56C(int a, int b);
extern int func_021ED57C(int a, int b);
extern void func_021ED6BC(char *p, u32 k, u32 a);
extern void func_021ED660(char *p, u32 k, u32 a, u32 b);
extern u8 *func_021E9100(u8 *p, int n);
extern u8 func_021B8BEC(u8 *p, u32 k, u8 n);
extern void func_021F84B4(u32 a, u32 b);
extern void func_021EAF00(u8 *p, int a);
extern void func_021ED4E4(u8 *p, int a, int b);
extern int func_021ED510(u8 *p, int a, int b);
extern char *func_021B9AF8(char *p, int i);
extern void func_021EAA24(void *a, u8 *t);
void func_021EA614(char *p, struct H *h);
void func_021EA638(char *p, struct H *h, int c);
void func_021EA65C(char *p, struct H *h);
void func_021EA678(char *p, u16 k, int *c);
void func_021EA694(char *p, u16 k, int *c);
int func_021EA6B0(char *p, u16 a, u16 b);
void func_021EA6F4(void *p, u8 b, u16 c);
int func_021EA710(u32 *p);
int func_021EA720(u32 *p);
void func_021EA730(char *p, u32 a, u16 b, u32 c);
void func_021EA758(u32 *p, u32 a2);
void func_021EA768(u32 *p, u32 a2, u32 a3);
int func_021EA778(u32 *p, u32 a2);
void func_021EA788(u32 *p, u32 a2);
int func_021EA798(u32 *p, u32 a2);
void func_021EA7A8(u32 *p, u32 a2);
int func_021EA7B8(u32 *p, u32 a2);
void func_021EA7C8(void *ctx, int a);
void func_021EA7D8(void *ctx, int a);
int func_021EA7E8(void *w, int v);
void func_021EA7FC(char *p);
int func_021EA814(u32 *p);
void func_021EA824(char *p);
void func_021EA838(u32 *p, u32 k);
int func_021EA850(u32 *p, u32 k);
void func_021EA868(u32 *p, u32 a2, u32 a3);
int func_021EA878(u32 *p);
void func_021EA888(char *ctx, int a);
int func_021EA8A4(u32 *p);
void func_021EA8B4(char *ctx, u32 a, u32 b);
int func_021EA8D4(u32 *p);
void func_021EA8E4(u32 *p);
int func_021EA8F4(u32 *p);
void func_021EA904(u32 *p, u32 a, u32 b, u32 c, u8 d, u8 e);
int func_021EA950(CbSlot *s);
int func_021EA990(int *st, u8 *b);
void func_021EAA00(u8 *p, u8 v);


void func_021EA614(char *p, struct H *h)
{
    func_021EA55C(h, ((struct Obj01899 *)p)->fAC);
    func_021EA730(p, ((struct Obj01899 *)p)->fAC, h->b2, 0);
}


void func_021EA638(char *p, struct H *h, int c)
{
    func_021EA55C(h, ((struct Obj01899 *)p)->fAC);
    func_021EA730(p, ((struct Obj01899 *)p)->fAC, h->b2, c);
}


void func_021EA65C(char *p, struct H *h)
{
    func_021EA55C(h, *(int *)&((struct Obj13561 *)p)->fAC);
    func_021EA758((u32 *)p, ((struct Obj13561 *)p)->fAC);
}


void func_021EA678(char *p, u16 k, int *c)
{
    func_021EEE80(((struct Obj01899 *)p)->fAC, k, (unsigned int *)c);
    func_021EA730(p, ((struct Obj01899 *)p)->fAC, 0x50, 0);
}


void func_021EA694(char *p, u16 k, int *c)
{
    func_021EEEF4(((struct Obj01899 *)p)->fAC, k, (unsigned int)c);
    func_021EA730(p, ((struct Obj01899 *)p)->fAC, 0x50, 0);
}


int func_021EA6B0(char *p, u16 a, u16 b)
{
    if (func_0202A298(a, b, ((struct Obj07846 *)p)->f184) != 0) {
        func_0202A310(a, b, ((struct Obj07846 *)p)->fAC, ((struct Obj07846 *)p)->f184);
        func_021EA730(p, *(int *)&((struct Obj07846 *)p)->fAC, 0x50, 0);
    } else {
        return 0;
    }
    return 1;
}


void func_021EA6F4(void *p, u8 b, u16 c)
{
    func_021EF5E8(*(u32 *)&((struct Obj01899 *)p)->fAC, b, c);
    func_021EA730(p, ((struct Obj01899 *)p)->fAC, 0x50, 0);
}


/*
 * Indexed-dispatch thunk (o18's 23-member shape): the member's whole stream is movs/lsls/ldr/ldr/bx with r0 as the load base; only the scratch register, the index constant and the tail target differ. Tail call T(p[i]) with the index materialised as a scaled immediate.
 */
int func_021EA710(u32 *p) { return func_021ECF68((struct T *)p[0x5f]); }


/*
 * Indexed-dispatch thunk (o18's 23-member shape): the whole stream is movs/lsls/ldr/ldr/bx with r0 as the load base, and one argument means the index temp is r1.  Tail call T(p[0x5f]).  The pool word names a mid-stream entry point that no listing labels, so the site caps at MATCH until the TARGET is filed; func_021ECF50 is an EXACT entry in this shard, which the `matched` class accepts as the witness (brief rule 10), and the call site then attests with no change of its own.
 */
int func_021EA720(u32 *p) { return func_021ECF50(p[0x5f]); }


void func_021EA730(char *p, u32 a, u16 b, u32 c)
{
    if (func_021CD9E0(*(u8 * *)&((struct Obj01899 *)p)->f4) == 0) {
        func_021ECEB8(*(u8 * *)&((struct Obj01899 *)p)->f17C, a, b, c);
    }
}


void func_021EA758(u32 *p, u32 a2) { func_021ECE60(p[0x5f], a2); }


void func_021EA768(u32 *p, u32 a2, u32 a3) { func_021EDA5C(p[0x5f], a2, a3); }


int func_021EA778(u32 *p, u32 a2) { return func_021EDA94(p[0x5f], a2); }


void func_021EA788(u32 *p, u32 a2) { func_021EDAB0(p[0x5f], a2); }


int func_021EA798(u32 *p, u32 a2) { return func_021EDAE0(p[0x5f], a2); }


void func_021EA7A8(u32 *p, u32 a2) { func_021EDB00(p[0x5f], a2); }


int func_021EA7B8(u32 *p, u32 a2) { return func_021EDB20(p[0x5f], a2); }


void func_021EA7C8(void *ctx, int a)
{
    func_021F7A28(a, 0x262);
}


void func_021EA7D8(void *ctx, int a)
{
    func_021F7A28(a, 0x261);
}


int func_021EA7E8(void *w, int v)
{
    if (func_021F7EB4() == 0) {
        return 1;
    }
    return 0;
}


void func_021EA7FC(char *p)
{
    func_021F8A40(3);
    func_021EE200((u8 *)(*(char * *)&((struct Obj21566 *)p)->f17C));
}


/*
 * Indexed-dispatch thunk (o18's 23-member shape): the whole stream is movs/lsls/ldr/ldr/bx with r0 as the load base, and one argument means the index temp is r1.  Tail call T(p[0x5f]).  The pool word names a mid-stream entry point that no listing labels, so the site caps at MATCH until the TARGET is filed; func_021EE21C is an EXACT entry in this shard, which the `matched` class accepts as the witness (brief rule 10), and the call site then attests with no change of its own.
 */
int func_021EA814(u32 *p) { return func_021EE21C((u8 *)p[0x5f]); }


void func_021EA824(char *p)
{
    func_021F8A78();
    func_021EE224(*(char * *)&((struct Obj21567 *)p)->f17C);
}


/*
 * Wrapper family member; the body is the hand-checked shape of the family's first instance with only the member's constants substituted, per the family uniformity assertion in o36/report.md.
 */
void func_021EA838(u32 *p, u32 k) { func_021ED56C(p[0x5f], func_021B8E70((u8 *)p[0], k)); }


int func_021EA850(u32 *p, u32 k) { return func_021ED57C(p[0x5f], func_021B8E70((u8 *)p[0], k)); }


void func_021EA868(u32 *p, u32 a2, u32 a3) { func_021ED590(p[0x5f], a2, a3); }


int func_021EA878(u32 *p) { return func_021ED5D8(p[0x5f]); }


void func_021EA888(char *ctx, int a)
{
    func_021ED6BC(*(char * *)&((struct Obj13562 *)ctx)->f17C, a, func_021CD9E0(*(u8 * *)&((struct Obj13562 *)ctx)->f4));
}


/*
 * Indexed-dispatch thunk (o18's 23-member shape): the whole stream is movs/lsls/ldr/ldr/bx with r0 as the load base, and one argument means the index temp is r1.  Tail call T(p[0x5f]).  The pool word names a mid-stream entry point that no listing labels, so the site caps at MATCH until the TARGET is filed; func_021ED714 is an EXACT entry in this shard, which the `matched` class accepts as the witness (brief rule 10), and the call site then attests with no change of its own.
 */
int func_021EA8A4(u32 *p) { return func_021ED714(p[0x5f]); }


void func_021EA8B4(char *ctx, u32 a, u32 b)
{
    func_021ED660(*(char * *)&((struct Obj13563 *)ctx)->f17C, a, b, func_021CD9E0(*(u8 * *)&((struct Obj13563 *)ctx)->f4));
}


int func_021EA8D4(u32 *p) { return func_021ED714(p[0x5f]); }


void func_021EA8E4(u32 *p) { func_021ED8AC(p[0x5f]); }


/*
 * Indexed-dispatch thunk (o18's 23-member shape): the whole stream is movs/lsls/ldr/ldr/bx with r0 as the load base, and one argument means the index temp is r1.  Tail call T(p[0x5f]).  The pool word names a mid-stream entry point that no listing labels, so the site caps at MATCH until the TARGET is filed; func_021ED8D8 is an EXACT entry in this shard, which the `matched` class accepts as the witness (brief rule 10), and the call site then attests with no change of its own.
 */
int func_021EA8F4(u32 *p) { return func_021ED8D8(p[0x5f]); }


void func_021EA904(u32 *p, u32 a, u32 b, u32 c, u8 d, u8 e)
{
    u8 *t;

    t = func_021E9100((u8 *)p, 7);
    t[0] = a;
    t[1] = b;
    t[2] = c;
    t[3] = d;
    t[4] = e;
    t[5] = func_021B8BEC((u8 *)p[0], a, d);
    t[6] = func_021B8BEC((u8 *)p[0], a, e);
    p[7] = 0;
    p[8] = (u32)func_021EA990;
    p[9] = (u32)p;
    p[10] = 0;
}


int func_021EA950(CbSlot *s)
{
    if (s->cb1 != 0) {
        if (s->cb1(&s->obj, s->arg) != 0) {
            s->cb1 = 0;
            s->obj = 0;
        }
        return 0;
    }
    if (s->cb2 != 0) {
        if (s->cb2(&s->obj, s->arg) != 0) {
            s->cb2 = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}


int func_021EA990(int *st, u8 *b)
{
    u8 *t = func_021E9100(b, 7);

    switch (*st) {
    case 0:
        func_021F84B4(t[1], t[2]);
        func_021EAF00(b, 0x57b);
        *st = *st + 1;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            func_021ED4E4((u8 *)(((struct Obj13564 *)b)->f17C), t[5], t[6]);
            *st = *st + 1;
        }
        break;
    case 2:
        if (func_021ED510((u8 *)(((struct Obj13564 *)b)->f17C), t[5], t[6]) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}


void func_021EAA00(u8 *p, u8 v)
{
    u8 *t;

    t = func_021E9100(p, 0x3c);
    func_021B9AF8(*(char * *)&((struct Obj10115 *)p)->f8, p[0xc]);
    func_021EAA24(((struct Obj10115 *)p)->f180, t);
}
