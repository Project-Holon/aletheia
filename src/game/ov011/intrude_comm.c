/*
 * file:     intrude_comm.c
 * unit:     yes
 * function: func_02172BC0, func_02172CB0, func_02172D70, func_021730AC, func_021731C8, func_02173368, func_02173464, func_02173558, func_02173568, func_02173580, func_0217358C, func_02173590, func_021735FC, func_02173638, func_02173644, func_02173654
 * address:  0x02172BC0
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
 *   func_02012944  0x02012944  thumb
 *   func_02158590  0x02158590  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   str_02177000   0x02177000  data  ov011  a1
 *   func_02167518  0x02167518  thumb  ov010
 *   func_0217538C  0x0217538C  thumb  ov011
 *   func_0217576C  0x0217576C  thumb  ov011
 *   func_02161F54  0x02161F54  thumb  ov010
 *   func_020457B0  0x020457B0  arm
 *   func_02012B64  0x02012B64  thumb
 *   func_02012B8C  0x02012B8C  thumb
 *   func_02012B4C  0x02012B4C  thumb
 *   func_02012950  0x02012950  thumb
 *   func_02008494  0x02008494  thumb
 *   func_02012E40  0x02012E40  thumb
 *   func_0203CBAC  0x0203CBAC  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0203D10C  0x0203D10C  arm
 *   func_0203CFF0  0x0203CFF0  arm
 *   d_02177000     0x02177000  data  ov011
 *   d_021768C8     0x021768C8  data  a4
 *   func_020127C4  0x020127C4  thumb
 *   func_02161F74  0x02161F74  thumb  ov010
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02035390  0x02035390  arm
 *   func_020353B0  0x020353B0  arm
 *   func_02173658  0x02173658  thumb  ov011
 *   func_020392B8  0x020392B8  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_02039ACC  0x02039ACC  arm
 *   func_02039338  0x02039338  arm
 *   func_02175710  0x02175710  thumb  ov011
 *   func_02012984  0x02012984  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_020399B8  0x020399B8  arm
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
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_021736EC  0x021736EC  thumb  ov011
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188BE8  0x02188BE8  thumb  ov021
 *   func_02161F68  0x02161F68  thumb  ov010
 *   func_0201281C  0x0201281C  thumb
 *   func_0216754C  0x0216754C  thumb  ov010
 *   func_02175DA8  0x02175DA8  thumb  ov011
 *   func_02175E90  0x02175E90  thumb  ov011
 *   func_02175BCC  0x02175BCC  thumb  ov011
 *   func_02012B58  0x02012B58  thumb
 *   func_02026480  0x02026480  thumb
 *   func_02012124  0x02012124  thumb
 *   func_02026680  0x02026680  thumb
 *   func_02045808  0x02045808  arm
 *   func_0217873C  0x0217873C  thumb  ov014
 *   func_02177494  0x02177494  thumb  ov014
 *   func_02177BFC  0x02177BFC  thumb  ov014
 *   func_02158570  0x02158570  thumb  ov010
 *   func_02165C34  0x02165C34  thumb  ov010
 *   func_02165D08  0x02165D08  thumb  ov010
 *   func_02165C50  0x02165C50  thumb  ov010
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_0217C11C  0x0217C11C  thumb  ov018
 *   func_02167794  0x02167794  thumb  ov010
 *   func_021676E4  0x021676E4  thumb  ov010
 *   func_021677E4  0x021677E4  thumb  ov010
 *   func_02167848  0x02167848  thumb  ov010
 *   func_02174F54  0x02174F54  thumb  ov011
 *   func_02167688 0x02167688 thumb ov010
 *   func_0217963C  0x0217963C  thumb  ov014
 *   func_02039414  0x02039414  arm
 *   func_0217778C  0x0217778C  thumb  ov014
 */
#include "../../matched/include/Obj19161.h"
#include "../../matched/include/Obj19162.h"

struct BigObj;
struct Rec44;
struct Sub24;
struct U16Vec;
struct Req;
struct Comm;
struct Sub;
struct Entry;
struct Ctx;
struct Link;
struct SaveBlock;
struct O;
struct Work_1;
struct Ent;
struct Obj_1;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u8 kind;
    u8 a : 4;
    u8 b : 4;
    u8 c : 1;
    u8 d : 5;
    u8 e : 2;
} Hdr;

typedef signed short   s16;

typedef struct Param {
    void *field00;
    void *field04;
    u8    pad08[6];
    u8    field0e;
} Param;

typedef struct Work {
    u32   field000;
    void *field004;
    void *field008;
    u8    pad00c[0x8a - 0x0c];
    u8    pad08a : 6;       /* 0x08A */
    u8    mode : 2;
    u8    kind : 6;         /* 0x08B */
    u8    flag08b : 1;
    u8    pad08c[0x8f8 - 0x8c];
    u8    field8f8;         /* 0x8F8 */
    u8    pad8f9;
    u8    field8fa;         /* 0x8FA */
    u8    field8fb;         /* 0x8FB */
    u8    pad8fc;
    u8    step;             /* 0x8FD */
    u8    pad8fe[3];
    u8    field901;
    u8    field902;
    u8    pad903[0x90a - 0x903];
    u16   idle;             /* 0x90A */
    u8    pad90c[2];
    s16   timer;            /* 0x90E */
    u8    pad910[0x928 - 0x910];
    void *field928[2];
    u8    pad930[0x93f - 0x930];
    u8    bit0 : 1;         /* 0x93F */
    u8    quit : 1;
    u8    bit2 : 1;
    u8    bit3 : 1;
    u8    bit4 : 1;
    u8    bit5 : 1;
    u8    lock : 1;
    u32   stamp : 31;       /* 0x940 */
    u32   warned : 1;
    u8    pad944[0x94c - 0x944];
} Work;

typedef struct {
    u32 w[28];
} T70;

typedef int            s32;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} Bits;

typedef struct Rec {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 f3_0 : 1;
    u8 f3_1 : 1;
    u8 f3_rest : 6;
    u32 id;
    u32 w8;
    u32 lo : 17;
    u32 mon : 10;
    u32 hi : 5;
} Rec;

typedef struct Obj_0 {
    u8 pad0[0x925];
    u8 count;
    u8 f926;
    u8 pad927;
    u32 a928[2];
    u32 ids[2];
    u8 b938[2];
    u8 b93a[2];
    u8 pad93c[3];
    u8 f93f_0 : 1;
    u8 f93f_1 : 1;
    u8 f93f_rest : 6;
} Obj_0;

typedef struct Head {
    u32 f0;
    u32 w[4];
} Head;

typedef struct Entry {
    Head h;
    u16 f14;
    u16 a : 3;
    u16 b : 6;
    u16 f18;
    u8 pad1a;
    u8 pad1b : 7;
    u8 hi : 1;
} Entry;

typedef struct Obj_1 {
    u8 pad0[8];
    int f8;
    u8 padc[0x80];
    Entry ents[3];
    u8 pad[0x8fb - 0x8c - 3 * 0x1c];
    u8 mask;
} Obj_1;

typedef struct { void *sys; void *obj; } Work_1;

extern u32 func_02026478(void *obj);
extern u8 *func_02012944(void *p);
extern int   func_02158590(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02167518(int a, void *b, u16 heap, int c);
extern void func_0217538C(u8 *p, int a);
extern void func_0217576C(u8 *p);
extern int func_02161F54(int a0);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02012B64(struct BigObj *p, u32 v);
extern void func_02012B8C(struct BigObj *p, u32 v);
extern void func_02012B4C(struct BigObj *p, u8 v);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern void  func_02008494(void *a, void *b);
extern u8 func_02012E40(const u8 *o);
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern u32 func_020307B0(void *p);
extern int func_0203D10C(int a0);
extern void func_0203CFF0(void *p);
extern u8 *func_020127C4(void *p);
extern void func_02161F74(int a0, int a1, int a2);
extern u32 func_0200FB24(void);
extern void func_02026400(struct Comm *p);
extern u32   func_02035390(void);
extern int func_020353B0(void);
extern void func_02173658(u8 *o);
extern int   func_020392B8(void);
extern void func_0203D7BC(u8 a0);
extern int func_02039ACC(void);
extern u16 func_02039338(void);
extern void func_02175710(u8 *o, u32 v);
extern u8 func_02012984(const struct BigObj *p);
extern struct Entry *func_020399A8(void);
extern u32 func_020399B8(u8 *p);
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
extern int func_0203CEAC(int a0);
extern int   func_0203D1B4(void);
extern int func_021736EC(char *p);
extern void func_02039C68(struct Link *p, u32 a, u32 b);
extern u32 func_02039CB4(struct Link *p, u32 a, u32 b);
extern int func_0203CDBC(void);
extern void func_0200FBA0(void);
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern u32 func_02013D5C(u32 id);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188BE8(void *a);
extern void func_02161F68(void *p);
extern void func_0201281C(u8 *obj);
extern void func_0216754C(int a, struct O *o);
extern int func_02175DA8(u8 *p);
extern int func_02175E90(void *p, u8 *q);
extern u8 *func_02175BCC(u8 *p);
extern u8 func_02012B58(const struct BigObj *p);
extern void func_02026480(void *obj, u32 value);
extern void func_02012124(struct Ctx *p, u32 v);
extern void func_02026680(u8 *p);
extern void func_02045808(struct U16Vec *vec);
extern int func_0217873C(u8 *p);
extern int func_02177494(u8 *obj, u32 flags);
extern Rec *func_02177BFC(void *, u8 *);
extern int func_02158570(u16);
extern void func_02165C34(struct Rec *r, void *buf);
extern u8 func_02165D08(struct Rec *r);
extern u8 func_02165C50(u32 *);
extern u16 func_02188C9C(u8 *p);
extern int func_0217C11C(u32 value);
extern void func_02167794(struct Work_1 *w);
extern void func_021676E4(struct Work_1 *w);
extern int func_021677E4(void *p, int i);
extern void func_02167848(char *a0, int a1, char *a2);
extern void func_02174F54(u8 *p, int idx, const struct Ent *src, int arg);
extern void func_02167688(struct Work_1 *w);
extern void func_0217963C(u32 v);
extern u32 func_02039414(void);
extern void func_0217778C(void);
Work *func_02172BC0(void *unused, Param *p);
int func_02172CB0(int *a, Param *b, Work *c);
void func_02172D70(int *state, Param *p, Work *w);
int func_021730AC(int *state, Param *p, Work *w);
int func_021731C8(int a0, void **o, u8 *s);
void func_02173368(void *a0, Obj_0 *s);
void func_02173464(u8 *a0, Obj_1 *p, int a2);
void func_02173558(int a, char *p);
void func_02173568(u8 *w);
void func_02173580(u8 *w);
u8 *func_0217358C(u8 *p);
void func_02173590(int a, Hdr *p, int c);
int func_021735FC(int a, Hdr *p);
extern char  str_02177000[];
extern char d_02177000[];
extern const T70 d_021768C8;


Work *func_02172BC0(void *unused, Param *p)
{
    void *sv;
    void *bag;
    u32 mode;
    Work *w;
    int i;
    u8 j;

    sv = (void *)func_02026478(p->field04);
    bag = func_02012944(sv);
    mode = 3;
    if (p->field0e == 1 && func_02158590(sv) == 0) {
        mode = 2;
    }
    w = func_02030734(5, sizeof(Work), 1, str_02177000, 0x9a);
    w->field000 = (u32)p->field00;
    w->field004 = p->field04;
    w->step = 1;
    w->field008 = func_02167518(3, p->field00, 5, 0);
    w->field902 = 1;
    w->field901 = 1;
    func_0217538C((u8 *)w, 4);
    func_0217576C((u8 *)w + 0x1ac);
    func_02173590((int)sv, (Hdr *)((u8 *)w + 0xc), mode);
    func_02161F54((int)((u8 *)w + 0x35c));
    for (i = 0; i < 2; i++) {
        w->field928[i] = func_020457B0(8, 5);
    }
    func_02012B64(sv, 0);
    func_02012B8C(sv, 0);
    func_02012B4C(sv, 1);
    for (j = 0; j < 3; j++) {
        func_02008494(bag, func_02012950(sv, j));
    }
    return w;
}







/*
 * recoup 2026-10-05: the old draft (196 B, c as u8* with c[0x8fd]) failed on register
 * colours and a second pool load of 0x8fd. Typed parameters closed it to 192 B, all bytes equal:
 * b as a struct with the byte at 0x0E, c as a struct with the step byte at 0x8FD (written
 * c->step = 3 / 4 in each arm, no local v), callee types from matched twins (func_02026478 and
 * func_02030734 return u32, func_02012E40 takes const u8 *). The only open item is the pool
 * word func_02173568: the leaf is filed at src/matched/ov/ov011_func_02173568.c (EXACT);
 * the integrator needs a shard for it, then this file is EXACT.
 */
int func_02172CB0(int *a, Param *b, Work *c)
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
void func_02172D70(int *state, Param *p, Work *w)
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
    func_021735FC((int)sv, (Hdr *)((u8 *)w + 0xc));
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







int func_021730AC(int *state, Param *p, Work *w)
{
    if (func_02012E40((const u8 *)func_02026478(p->field04)) == 1) {
        return 0;
    }
    if (w->quit == 1 || func_0200FB24() != 0) {
        w->field8f8 |= 0x40;
        func_0203CEAC((int)func_02173580);
        return 1;
    }
    switch (*state) {
    case 0:
        w->step = 9;
        if (func_0203D1B4() <= 1) {
            *state = 4;
        } else if (func_021736EC((char *)w) == 1) {
            (*state)++;
        }
        break;
    case 1:
        w->timer = 0;
        func_02039C68((struct Link *)func_020399A8(), 0x14, 2);
        (*state)++;
        break;
    case 2:
        w->timer++;
        if (func_02039CB4((struct Link *)func_020399A8(), 0x14, 2) == 1 || w->timer > 300) {
            func_0203D7BC(0);
            (*state)++;
        }
        break;
    case 3:
        w->timer++;
        if (func_0203D378() == 1) {
            if (func_0203D1B4() <= 1 || w->timer > 300) {
                (*state)++;
            }
        } else {
            (*state)++;
        }
        break;
    case 4:
        w->field8f8 |= 0x40;
        func_0203CEAC((int)func_02173580);
        return 1;
    }
    return 0;
}







/*
 * 2026-10-05 (D8 lane19): re-verified, MATCH; unresolved relocations are arm9 0x02026680 and ov010 0x02161F68 (leaf witnesses in the note). Needs label seeds. Source is byte-correct; no C change possible.
 *
 * Byte-correct (416/416), 29 of 31 relocations resolved. The two
 * unresolved sites are leaves whose only caller image-wide is this
 * function (tu --suggest-split: not cuttable):
 *   +0076 func_02161F68 (ov010, unlabelled 12-byte memset stub)
 *   +0168 func_02026680 (arm9, unlabelled; Ilias's)
 * Because an arm9 leaf is among the blockers, the ov010 leaf is not filed.
 * Levers from the DIFF note (wave 82): the `b` to the next instruction at
 * +0x136 is the shared func_02012B4C(h, 1) call written in both arms of the
 * func_02012B70(h) == 0 test (cross-jumped, see
 * docs/idioms/an-if-else-storing-to-one-target-keeps-the-empty-else-branch-to-next.md);
 * the register permutation disappeared once every callee took its matched
 * prototype (h a u32 cast at each call, me a u8, o a void ** parameter).
 *
 *   0x02026680 arm9 thumb, verified EXACT with
 *     `one --thumb --lang c99` (no --region):
 *     typedef unsigned char u8;
 *     typedef struct { u8 b0 : 1; u8 rest : 7; u8 pad[0xb]; } E;
 *     void func_02026680(u8 *p)
 *     {
 *         int i;
 *         for (i = 0; i < 6; i++) {
 *             ((E *)(p + 0x3f))[i].b0 = 0;
 *         }
 *         p[0x85] = 0;
 *         p[0x84] = 0;
 *     }
 *   0x02161F68 ov010 thumb (overlay leaf, not filed while the arm9 leaf
 *     blocks), verified EXACT with `one --thumb --region ov010 --lang c99`:
 */
int func_021731C8(int a0, void **o, u8 *s)
{
    void *ctx;
    int ok;
    u32 h;
    u8 *pt;
    u8 me;
    int i;

    ctx = o[1];
    h = func_02026478(ctx);
    ok = 0;
    if (func_02012E40((const u8 *)h) == 1) {
        return ok;
    }
    if (s[0x8fd] == 10 || func_0203CDBC() == 1) {
        if (func_02012B70((struct BigObj *)h) == 0) {
            func_0200FBA0();
            ok = 1;
        } else if (func_02013D5C(func_02012AC8(func_020127A4((struct SaveBlock *)h))) == 1
                   && func_02012114(o[0]) == 1
                   && func_02188BE8(func_0201210C(o[0])) == 1) {
            ok = 1;
        }
    }
    if (ok == 1) {
        func_02161F68(s + 0x35c);
        func_0201281C((u8 *)h);
        func_0216754C((int)o[0], *(struct O **)(s + 8));
        if (((Bits *)(s + 0x93f))->b1 == 1 || func_0200FB24() != 0) {
            func_02026480(ctx, 5);
        } else if (func_02175DA8(s + 0x1ac) == 1) {
            if (((Bits *)(s + 0x904))->b0 == 1) {
                func_02026480(ctx, 4);
            } else if (func_02175E90(s, s + 0x1ac) == 1) {
                func_02026480(ctx, 2);
            } else {
                pt = func_02175BCC(s + 0x1ac);
                me = func_02012B58((struct BigObj *)h);
                for (i = 0; i < 3; i++) {
                    if (pt[0x34 + i] != 4 && me != pt[0x34 + i]) {
                        break;
                    }
                }
                if (i < 3) {
                    func_02026480(ctx, 3);
                } else {
                    func_02026480(ctx, 4);
                }
            }
        } else if (s[0x8fb] > 1) {
            func_02026480(ctx, 1);
        }
        if (func_02012B70((struct BigObj *)h) == 0) {
            func_02012B64((struct BigObj *)h, 0);
            func_02012B8C((struct BigObj *)h, 0);
            func_02012B4C((struct BigObj *)h, 1);
        } else {
            func_02012B4C((struct BigObj *)h, 1);
        }
        if ((((Bits *)(s + 0x93f))->b1 == 1 || func_0200FB24() != 0) && func_02012B70((struct BigObj *)h) == 1) {
            func_02012124(o[0], 1);
        }
        func_02026680(ctx);
        for (i = 0; i < 2; i++) {
            func_02045808(*(struct U16Vec **)(s + 0x928 + i * 4));
        }
        func_020307B0(s);
        func_020307B0(o);
        return 1;
    }
    return 0;
}







/*
 * Addresses are Black-image addresses.
 */
void func_02173368(void *a0, Obj_0 *s)
{
    u8 kind;
    Rec *rec;
    int i;

    if (s->count >= 2) {
        return;
    }
    if (func_0203D1B4() > 1) {
        return;
    }
    if (s->f93f_1 == 1) {
        return;
    }
    if (func_0200FB24() != 0) {
        return;
    }
    if (func_0217873C(a0) == 0) {
        return;
    }
    if (func_02177494(a0, ~0x10) == 0) {
        return;
    }
    rec = func_02177BFC(a0, &kind);
    if (kind != 3) {
        return;
    }
    if (rec->f3_1) {
        return;
    }
    for (i = 0; i < s->count; i++) {
        if (rec->id == s->ids[i]) {
            return;
        }
    }
    if ((int)func_02013D5C((u16)rec->mon) == 1) {
        return;
    }
    if (func_02158570(rec->mon) == 0) {
        return;
    }
    func_02165C34((struct Rec *)(&rec->w8), (void *)s->a928[s->count]);
    s->b938[s->count] = func_02165D08((struct Rec *)(&rec->w8));
    s->b93a[s->count] = func_02165C50(&rec->w8);
    s->ids[s->count] = rec->id;
    s->f926 = 0;
    s->count++;
}






void func_02173464(u8 *a0, Obj_1 *p, int a2)
{
    int h;
    int me;
    int i;
    Head tmp;

    if (p == 0) {
        return;
    }
    h = func_02026478((void *)(((struct Obj19161 *)a0)->f4));
    me = func_02012B58((const struct BigObj *)h);
    if (func_02012B70((const struct BigObj *)h) == 0) {
        if (func_0217C11C(func_02188C9C((u8 *)a2)) == 1) {
            func_021676E4((struct Work_1 *)p->f8);
        } else {
            func_02167794((struct Work_1 *)p->f8);
        }
    } else {
        func_021676E4((struct Work_1 *)p->f8);
    }
    for (i = 0; i < 3; i++) {
        if (i != me && func_021677E4((void *)p->f8, i) == 1) {
            p->ents[i].h.f0 = p->ents[i].hi;
            tmp = p->ents[i].h;
            tmp.f0 = 1;
            func_02167848((char *)p->f8, i, (char *)(&tmp));
        }
    }
    for (i = 0; i < 3; i++) {
        if (i != me && (p->mask & (1 << i))) {
            int hi = p->ents[i].hi;
            func_02174F54((u8 *)p, i, (const struct Ent *)(&p->ents[i]), 0);
            p->ents[i].hi = hi;
        }
    }
}





/*
 * Extent contains followers 02173568, already-filed 02173580, and 0217358C;
 * the lead stays separate to preserve the existing follower file.
 */
void func_02173558(int a, char *p)
{
    if (p != 0)
        func_02167688((struct Work_1 *)(*(Work_1 * *)&((struct Obj19162 *)p)->f8));
}






void func_02173568(u8 *w)
{
    w[0x8fd] = 2;
    func_0217963C((u32)func_02173368);
}




/*
 * Callback leaf: sets the state byte at 0x8FD to 10.  It saves nothing, so
 * disasm.py left it as .word data; its only reference is the function
 * pointer func_021730AC hands to func_0203CEAC, which is why it is filed
 * here, to give that pool word a matched witness.
 */
void func_02173580(u8 *w)
{
    w[0x8fd] = 10;
}



u8 *func_0217358C(u8 *p) { return p + 12; }




void func_02173590(int a, Hdr *p, int c)
{
    p->kind = 2;
    p->a = func_0203D1B4();
    if (c != -1)
        p->b = c;
    p->c = func_02039414();
    p->d = 1;
    func_02008494(func_02012944((void *)a), (char *)p + 8);
}




int func_021735FC(int a, Hdr *p)
{
    if (p->a != func_0203D1B4() || p->c != func_02039414()) {
        func_02173590(a, p, -1);
        func_0217778C();
        return 1;
    }
    return 0;
}


int func_02173638(int a, int b)
{
    if (a == b)
        return 1;
    return 0;
}


void func_02173644(int a, int b, u8 *p)
{
    p[0x93F] |= 2;
}


void func_02173654(void)
{
}
