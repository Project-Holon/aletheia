/*
 * file:     intrude_comm_p01.c
 * unit:     yes
 * function: func_02172CB0, func_02172D70
 * address:  0x02172CB0
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_02012E40  0x02012E40  thumb
 *   func_02030734  0x02030734  arm
 *   func_02158590  0x02158590  thumb  ov010
 *   func_0203CBAC  0x0203CBAC  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0203D10C  0x0203D10C  arm
 *   func_0203CFF0  0x0203CFF0  arm
 *   func_02173568  0x02173568  thumb  ov011
 *   d_02177000     0x02177000  data  ov011
 *   d_021768C8     0x021768C8  data  a4
 *   func_020127C4  0x020127C4  thumb
 *   func_02161F74  0x02161F74  thumb  ov010
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02035390  0x02035390  arm
 *   func_020353B0  0x020353B0  arm
 *   func_021735FC  0x021735FC  thumb  ov011
 *   func_02173658  0x02173658  thumb  ov011
 *   func_020392B8  0x020392B8  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_02039ACC  0x02039ACC  arm
 *   func_02039338  0x02039338  arm
 *   func_02012B64  0x02012B64  thumb
 *   func_02012950  0x02012950  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008494  0x02008494  thumb
 *   func_02175710  0x02175710  thumb  ov011
 *   func_02012984  0x02012984  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_020399B8  0x020399B8  arm
 *   func_02161F54  0x02161F54  thumb  ov010
 *   func_02174E3C  0x02174E3C  thumb  ov011
 *   func_02174EAC  0x02174EAC  thumb  ov011
 *   func_02173828  0x02173828  thumb  ov011
 *   func_0203F4FC  0x0203F4FC  arm
 *   func_02012B70  0x02012B70  thumb
 *   func_02012114  0x02012114  thumb
 *   func_02174978  0x02174978  thumb  ov011
 *   func_02175EB8  0x02175EB8  thumb  ov011
 *   func_0203D378  0x0203D378  arm
 *   func_02175B14  0x02175B14  thumb  ov011
 *   func_021739E0  0x021739E0  thumb  ov011
 *   func_02175ED8  0x02175ED8  thumb  ov011
 *   func_02175628  0x02175628  thumb  ov011
 */
struct Req;
struct BigObj;
struct Comm;
struct Rec44;
struct Sub;
struct Sub24;
struct Entry;
struct Ctx;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct {
    u32 w[28];
} T70;

typedef struct Param_02172CB0 {
    void *field00;
    void *field04;
    u8 pad08[6];
    u8 field0e;
} Param_02172CB0;

typedef struct Work_02172CB0 {
    u8 pad[0x8fd];
    u8 step;
} Work_02172CB0;

typedef unsigned short u16;

typedef signed short   s16;

typedef int            s32;

typedef struct Param_02172D70 {
    void *field00;
    void *field04;
} Param_02172D70;

typedef struct Work_02172D70 {
    u32   field000;
    void *field004;         /* 0x004 */
    u8    pad008[0x8a - 0x8];
    u8    pad08a : 6;       /* 0x08A */
    u8    mode : 2;
    u8    kind : 6;         /* 0x08B */
    u8    flag08b : 1;
    u8    pad08c[0x8fa - 0x8c];
    u8    field8fa;         /* 0x8FA */
    u8    field8fb;         /* 0x8FB */
    u8    pad8fc;
    u8    step;             /* 0x8FD */
    u8    pad8fe[0x90a - 0x8fe];
    u16   idle;             /* 0x90A */
    u8    pad90c[2];
    s16   timer;            /* 0x90E */
    u8    pad910[0x93f - 0x910];
    u8    bit0 : 1;         /* 0x93F */
    u8    quit : 1;
    u8    bit2 : 1;
    u8    bit3 : 1;
    u8    bit4 : 1;
    u8    bit5 : 1;
    u8    lock : 1;
    u32   stamp : 31;       /* 0x940 */
    u32   warned : 1;
} Work_02172D70;

extern u32 func_02026478(void *obj);
extern u8 func_02012E40(const u8 *o);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02158590(void *p);
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern u32 func_020307B0(void *p);
extern int func_0203D10C(int a0);
extern void func_0203CFF0(void *p);
extern void func_02173568(u8 *w);
extern u8 *func_020127C4(void *p);
extern void func_02161F74(int a0, int a1, int a2);
extern u32 func_0200FB24(void);
extern void func_02026400(struct Comm *p);
extern u32   func_02035390(void);
extern int func_020353B0(void);
extern void  func_021735FC(void *sv, void *p);
extern void func_02173658(u8 *o);
extern int   func_020392B8(void);
extern void func_0203D7BC(u8 a0);
extern int func_02039ACC(void);
extern u16 func_02039338(void);
extern void  func_02012B64(void *sv, u32 a);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern u8 *func_02012944(void *p);
extern void  func_02008494(void *a, void *b);
extern void func_02175710(u8 *o, u32 v);
extern u8 func_02012984(const struct BigObj *p);
extern struct Entry *func_020399A8(void);
extern u32 func_020399B8(u8 *p);
extern int func_02161F54(int a0);
extern void func_02174E3C(u8 *p);
extern void func_02174EAC(u8 *p, int idx, u8 *q);
extern int func_02173828(char *p);
extern u32 func_0203F4FC(void);
extern int func_02012B70(const struct BigObj *p);
extern u32   func_02012114(const struct Ctx *p);
extern void func_02174978(u8 *s);
extern int   func_02175EB8(void *p);
extern u32 func_0203D378(void);
extern int func_02175B14(u8 *p);
extern int   func_021739E0(void);
extern int func_02175ED8(struct Sub *s);
extern int   func_02175628(void);
int func_02172CB0(int *a, Param_02172CB0 *b, Work_02172CB0 *c);
void func_02172D70(int *state, Param_02172D70 *p, Work_02172D70 *w);
extern char d_02177000[];
extern const T70 d_021768C8;


/*
 * recoup 2026-10-05: the old draft (196 B, c as u8* with c[0x8fd]) failed on register
 * colours and a second pool load of 0x8fd. Typed parameters closed it to 192 B, all bytes equal:
 * b as a struct with the byte at 0x0E, c as a struct with the step byte at 0x8FD (written
 * c->step = 3 / 4 in each arm, no local v), callee types from matched twins (func_02026478 and
 * func_02030734 return u32, func_02012E40 takes const u8 *). The only open item is the pool
 * word func_02173568: the leaf is filed at src/matched/ov/ov011_func_02173568.c (EXACT);
 * the integrator needs a shard for it, then this file is EXACT.
 */
int func_02172CB0(int *a, Param_02172CB0 *b, Work_02172CB0 *c)
{
    u8 *h;
    T70 *p;

    h = (u8 *)func_02026478(b->field04);
    if (func_02012E40(h) == 1)
        return 0;
    switch (*a) {
    case 0:
        p = (T70 *)func_02030734(0x8005, 0x70, 0, d_02177000, 0xcf);
        *p = d_021768C8;
        if (b->field0e == 1) {
            if (func_02158590(h) == 0)
                *((u8 *)p + 0x60) = 2;
        }
        func_0203CBAC((struct Req *)p, (u32)func_02173568, (u32)c);
        func_020307B0(p);
        *a = *a + 1;
        break;
    case 1:
        if (c->step >= 2) {
            if (b->field0e == 1) {
                func_0203D10C(0);
                c->step = 3;
            } else {
                func_0203CFF0((u8 *)b + 8);
                c->step = 4;
            }
            return 1;
        }
        break;
    }
    return 0;
}


/*
 * evidence: 0x02008494 is an unlabelled ARM9 thunk ("ldr r3, =func_02082D44; movs r2, #0x20; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov018 0x0217FDEC, ov021 0x021CD548, ov088 0x021BC32A and more), so the call
 * attests as `label`.
 */
void func_02172D70(int *state, Param_02172D70 *p, Work_02172D70 *w)
{
    void *sv;
    void *mon;
    s32 base;
    s32 now;

    sv = (void *)func_02026478(p->field04);
    if (w != 0 && w->step >= 7) {
        func_02161F74((int)((u8 *)w + 0x35c), (int)func_020127C4(sv), w->field8fb);
    }
    if (func_0200FB24() != 0 || w->quit == 1) {
        if (w->lock) {
            return;
        }
        w->step = 11;
        w->quit = 1;
        func_02026400(w->field004);
        return;
    }
    if (func_02035390() == 1 && func_020353B0() == 1 && w->lock == 0) {
        func_02026400(w->field004);
        return;
    }
    if (w->step == 7 && w->field8fa == 1) {
        func_02026400(w->field004);
        return;
    }
    func_021735FC(sv, (u8 *)w + 0xc);
    func_02173658((u8 *)w);
    switch (*state) {
    case 0:
        if (func_020392B8() > 1 && w->step < 5) {
            w->step = 5;
            func_0203D7BC(1);
        }
        if (w->step == 5) {
            if (func_02039ACC() == 1) {
                func_02012B64(sv, func_02039338());
                mon = func_02012950(sv, func_02039338());
                func_02008494(func_02012944(sv), mon);
                func_02175710((u8 *)w, func_02039338());
                w->kind = 0x15;
                w->mode = func_02012984(sv);
                if (func_02158590(sv) == 0) {
                    w->flag08b = 1;
                }
                func_0203D7BC(1);
                (*state)++;
            }
        } else if (w->step == 4) {
            w->timer++;
            if (w->timer > 600) {
                w->timer = 0;
                func_02026400(w->field004);
                return;
            }
        }
        break;
    case 1:
        if (func_020399B8((u8 *)((u32)func_020399A8())) == 1) {
            w->step = 6;
            (*state)++;
        }
        break;
    case 2:
        func_02161F54((int)((u8 *)w + 0x35c));
        func_02174E3C((u8 *)w);
        func_02174EAC((u8 *)w, func_02039338(), (u8 *)w + 0x160);
        (*state)++;
        break;
    case 3:
        if (func_02173828((char *)w) == 1) {
            w->step = 7;
            w->stamp = func_0203F4FC();
            (*state)++;
        }
        break;
    case 4:
        if (func_02012B70(sv) == 0 && w->mode != func_02012984(sv)
            && func_02012114(p->field00) == 1) {
            func_02026400(w->field004);
            return;
        }
        func_02174978((u8 *)w);
        if (func_02175EB8((u8 *)w + 0x1ac) == 1) {
            func_02026400(w->field004);
            return;
        }
        if (func_0203D378() == 1 && func_02175B14((u8 *)w + 0x1ac) == 0) {
            base = w->stamp;
            now = func_0203F4FC();
            if (now < base) {
                now += 86399;
            }
            now -= base;
            if (now >= 180) {
                func_02026400(w->field004);
                return;
            }
            if (now > 170 && w->warned == 0 && func_021739E0() == 1) {
                w->warned = 1;
            }
        } else if (w->lock == 0 && func_0203D378() == 1
                   && func_02175ED8((struct Sub *)((u8 *)w + 0x1ac)) == 1) {
            func_02026400(w->field004);
        } else {
            w->warned = 0;
        }
        if (func_02175628() == 0) {
            w->idle++;
            if (w->idle > 180) {
                func_02026400(w->field004);
                return;
            }
        } else {
            w->idle = 0;
        }
        break;
    }
}
