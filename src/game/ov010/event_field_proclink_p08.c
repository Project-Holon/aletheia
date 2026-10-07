/*
 * file:     event_field_proclink_p08.c
 * unit:     yes
 * function: func_0215F52C, func_0215F608, func_0215F630, func_0215F64C, func_0215F6E8, func_0215F734, func_0215F8A8, func_0215F900
 * address:  0x0215F52C
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
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_020056EC  0x020056EC  thumb
 *   func_02159F80 0x02159F80 thumb ov010
 *   func_02012914 0x02012914 thumb
 *   func_02023F60  0x02023F60  thumb
 *   func_02012444  0x02012444  thumb
 *   d_021B9EC0     0x021B9EC0  data  a4
 *   ov_id_00CD     0x000000CD  data  a1
 *   func_0215FA1C  0x0215FA1C  thumb  ov010
 *   func_02012374  0x02012374  thumb
 *   func_02158780  0x02158780  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012ED0  0x02012ED0  thumb
 *   func_0201213C  0x0201213C  thumb
 *   func_021666A4  0x021666A4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012138  0x02012138  thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   func_02012158  0x02012158  thumb
 *   func_02014554  0x02014554  thumb
 *   func_02005E30  0x02005E30  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02026454  0x02026454  thumb
 *   func_021BE8D4  0x021BE8D4  thumb
 *   func_0215F9C4  0x0215F9C4  thumb  ov010
 *   func_0215F9DC  0x0215F9DC  thumb  ov010
 *   func_0215F9EC  0x0215F9EC  thumb  ov010
 *   func_02158A20  0x02158A20  thumb  ov010
 *   func_02161B90  0x02161B90  thumb  ov010
 *   ov180_id       0x000000B4  data
 *   ov181_id       0x000000B5  data
 *   ov205_id       0x000000CD  data
 *   ov182_id       0x000000B6  data
 *   d_021B800C     0x021B800C  data  ov180
 *   d_021BAB24     0x021BAB24  data  ov181
 *   d_021B9E54     0x021B9E54  data  ov205
 *   d_021B9BA0     0x021B9BA0  data  ov182
 *   func_0215E580  0x0215E580  thumb  ov010
 *   func_0215F920  0x0215F920  thumb  ov010
 *   func_0215F948  0x0215F948  thumb  ov010
 *   func_02012934   0x02012934  thumb
 *   func_02012FCC   0x02012FCC  thumb
 */
#include "../../matched/include/Obj17706.h"
#include "../../matched/include/Obj04132.h"
#include "../../matched/include/Obj04883.h"

struct BigObj;
struct Evt;
struct Obj;
struct Ctx;
struct Desc;
struct Big;
struct Comm;
struct IcaAnime;
struct Work;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef enum { FALSE = 0, TRUE = 1 } BOOL;

typedef struct Work {
    void *sys;          /* 0x00 */
    void *f04;          /* 0x04 */
    u32 f08;            /* 0x08 */
    u8 pad0C[0x14 - 0x0C];
    u8 f14[8];          /* 0x14 */
    u8 f1c[0x28 - 0x1C];/* 0x1C */
    u8 f28[8];          /* 0x28 */
    u8 f30[4];          /* 0x30 */
    u32 step;           /* 0x34 */
    u32 seq[16];        /* 0x38 */
    int timer;          /* 0x78 */
} Work;

extern void *func_0215A5F4(void *p);
extern u16 *func_02159AE8(void *c, void *vm);
extern u32 func_020056EC(u32 n);
extern int func_02159F80(void);
extern u16 func_02012914(const struct BigObj *p);
extern void func_02023F60(u32 a0, u32 a1, u32 mask);
extern void func_02012444(struct Obj *obj, u32 a1, u32 a2, u32 a3);
extern int func_0215FA1C();
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_02158780(void *p, u16 b, int c, int d, u16 e);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void *func_020120F4(const struct Ctx *p);
u8 *func_02012944(void *p);
u8 *func_02012ED0(struct Big *p);
void func_0201213C(struct Ctx *p, u32 v);
void func_021666A4(int a0);
extern void *func_02012EBC(struct Big *p);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02012138(const struct Ctx *p);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 func_020120F0(const struct Ctx *p);
extern void func_02012158(char *p, unsigned int v);
extern int func_02014554(int a0, int a1);
extern void func_02005E30(u32 v);
extern void func_02026400(struct Comm *p);
extern u32 func_02026454(void *obj);
extern void *func_021BE8D4(void *sys, void *proc, u32 a, u32 b);
extern int func_0215F9C4(void);
extern void func_0215F9DC(Work *w, u32 *i);
extern int func_0215F9EC(int a0);
extern void func_02158A20(int a, int v);
extern void *func_02161B90(void *p, void *a1, int kind, int sub, int flag);
void func_0215E580(void *a);
int func_0215F920(int a0);
void func_0215F948(u8 *p);
extern void *func_02012934(const struct BigObj *p);
extern int func_02012FCC(int p0);
int func_0215F52C(void *c, void *vm);
int func_0215F608(int a0, int a1, int a2, int a3);
BOOL func_0215F630(void *p);
int func_0215F64C(int a0, int *st, int *a2);
void *func_0215F6E8(void *p);
int func_0215F734(void *evt, u32 *i, Work *w);
void *func_0215F8A8(void *p, int a1);
void func_0215F900(void *a0);
extern u8 d_021B9EC0[];
extern u8 ov_id_00CD[];
extern u8 ov180_id[];
extern u8 ov181_id[];
extern u8 ov205_id[];
extern u8 ov182_id[];
extern u8 d_021B800C[];
extern u8 d_021BAB24[];
extern u8 d_021B9E54[];
extern u8 d_021B9BA0[];


/*
 * Draws six distinct values from 0..0x33 (random pick among the ones not
 * yet taken) and writes each plus 0x37 to six script-variable slots.
 *
 * Keys: the work locals live in a nested block opened after the six
 * func_02159AE8 calls, so `u16 buf[6] = {0}` is emitted there (at function
 * scope the initializer lands above the calls) and its stores go through
 * the same `add r4, sp, #0x18` the search loops index. `u16 n = 0x34`
 * declared before buf schedules `movs r7, #0x34` ahead of the zero stores.
 * EXACT* only for the 2-byte pad after the function (218 of 220).
 */
int func_0215F52C(void *c, void *vm)
{
    u16 *p0, *p1, *p2, *p3, *p4, *p5;

    func_0215A5F4(vm);
    p0 = func_02159AE8(c, vm);
    p1 = func_02159AE8(c, vm);
    p2 = func_02159AE8(c, vm);
    p3 = func_02159AE8(c, vm);
    p4 = func_02159AE8(c, vm);
    p5 = func_02159AE8(c, vm);
    {
        u16 n = 0x34;
        u16 buf[6] = {0};
        int i, v, j;
        s16 r;

        for (i = 0; i < 6; i++) {
            r = func_020056EC(n);
            for (v = 0; v < 0x34; v++) {
                for (j = 0; j < i; j++) {
                    if (buf[j] == v)
                        break;
                }
                if (j == i) {
                    if (--r < 0) {
                        buf[i] = v;
                        break;
                    }
                }
            }
            n--;
        }
        *p0 = buf[0] + 0x37;
        *p1 = buf[1] + 0x37;
        *p2 = buf[2] + 0x37;
        *p3 = buf[3] + 0x37;
        *p4 = buf[4] + 0x37;
        *p5 = buf[5] + 0x37;
    }
    return 0;
}




int func_0215F608(int a0, int a1, int a2, int a3)
{
    int t4;
    int t5;

t5 = 0;
loc_0215F60C:
a3 = t5 << 3;
t4 = a0 + a3;
a3 = *(u16 *)((char *)a0 + a3);
    if (a1 != a3) goto loc_0215F622;
loc_0215F616:
a3 = ((struct Obj17706 *)t4)->f2;
    if (a2 != a3) goto loc_0215F622;
loc_0215F61C:
a0 = t5 + 0;
    return a0;
loc_0215F622:
t5 = t5 + 1;
    if (t5 < 0x6b) goto loc_0215F60C;
loc_0215F628:
a0 = 0;
    return a0;}

BOOL func_0215F630(void *p) { int a = func_02159F80(); if(a == func_02012914(p)) return FALSE; else return TRUE; }


/*
 * former blocker: ABS32 0x000000CD (ov_id_00CD) has no witness outside the function (literal pool word only)
 *
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */
int func_0215F64C(int a0, int *st, int *a2)
{
    switch (*st) {
    case 0:
        func_02023F60(-16, 0x37, 1);
        func_02023F60(-16, 0x3f, 2);
        func_02012444((struct Obj *)a0, (u32)ov_id_00CD, (u32)d_021B9EC0, (u32)a2);
        (*st)++;
        break;
    case 1:
        func_02023F60(0, 0x3f, 3);
        func_02012374((struct Evt *)a0, (struct Evt **)func_0215FA1C(a2[0]));
        (*st)++;
        break;
    case 2:
        if (a2[1] == 0) {
            func_02158780((void *)a0, 3, 0, 0, 0x15);
        } else {
            func_02158780((void *)a0, 0x7d1, 0, 0, 0x15);
        }
        (*st)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}


/*
 * Allocator with callback, then two accessor stores and two teardown calls.
 */
void *func_0215F6E8(void *p)
{
    int r4 = (int)func_020120F4(p);
    void *r7 = func_020122C0(p, 0, func_0215F64C, 0xc);
    int *r6 = func_020124E8(r7);

    r6[0] = (int)p;
    r6[1] = (int)func_0215F630((void *)r4);
    r6[2] = (int)func_02012944((void *)r4);
    func_021666A4((int)func_02012ED0((struct Big *)r4));
    func_0201213C(p, 0);
    return r7;
}


/*
 * Step machine of an ov010 sub-sequence: the step comes from w->seq[*i]
 * through func_0215F9DC, loading ov180/ov181 as procs and ov205/ov182 as
 * tasks. Byte-correct first draft.
 * Former blocker (MATCH): ov205_id and ov182_id reach r1 of func_02012444, which
 * is not in match.py's OVERLAY_ID_CONSUMERS; d_021B9BA0 then fails its
 * ov182 hint for want of that overlay_id site. Same blocker as
 * func_0215FA54.
 *
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */
int func_0215F734(void *evt, u32 *i, Work *w)
{
    void *sys = w->sys;
    void *save;
    void *proc;

    func_02012EBC(w->f04);
    proc = func_0201210C(w->sys);
    save = (void *)func_02012138(w->sys);
    switch (w->step) {
    case 0:
        if (w->f08 == 1)
            func_0215F9EC((int)w);
        func_02005E30(30);
        func_0215F9DC(w, i);
        break;
    case 1:
        func_02012374(evt, func_021BE8D4(sys, proc, 0, 0));
        func_0215F9DC(w, i);
        break;
    case 2:
        if (func_02026454(save))
            func_02026400(save);
        func_0215F9DC(w, i);
        break;
    case 3:
        if (func_02026454(save) == 0)
            func_0215F9DC(w, i);
        break;
    case 4:
        func_02012374(evt, (void *)func_02014554((int)sys, (int)proc));
        func_0215F9DC(w, i);
        break;
    case 5:
        func_020120B4(sys, (u32)ov180_id, d_021B800C, w->f1c);
        func_0215F9DC(w, i);
        break;
    case 6:
        if (func_020120F0(sys) == 0)
            func_0215F9DC(w, i);
        break;
    case 7:
        func_020120B4(sys, (u32)ov181_id, d_021BAB24, w->f28);
        func_0215F9DC(w, i);
        break;
    case 8:
        if (func_020120F0(sys) == 0)
            func_0215F9DC(w, i);
        break;
    case 9:
        func_02012374(evt, func_02161B90(sys, evt, func_0215F9C4(), 0, 0));
        func_0215F9DC(w, i);
        break;
    case 10:
        func_02158A20((int)sys, 4);
        func_0215F9DC(w, i);
        break;
    case 11:
        func_02012444(evt, (u32)ov205_id, (u32)d_021B9E54, (u32)w->f14);
        func_0215F9DC(w, i);
        break;
    case 12:
        if (w->timer > 60) {
            w->timer = 0;
            func_0215F9DC(w, i);
        }
        w->timer++;
        break;
    case 13:
        func_02012444(evt, (u32)ov182_id, (u32)d_021B9BA0, (u32)w->f30);
        func_02012158(sys, 0);
        func_0215F9DC(w, i);
        break;
    case 14:
        return 1;
    case 15:
        return 0;
    }
    return 0;
}


/*
 * Allocator with callback, three sub-init calls over the new node.
 */
void *func_0215F8A8(void *p, int a1)
{
    int r7 = (int)func_020120F4(p);
    void *r0v = func_020122C0(p, 0, func_0215F734, 0x7C);
    char *r4 = func_020124E8(r0v);

    ((struct Obj04132 *)r4)->f0 = (int)p;
    ((struct Obj04132 *)r4)->f4 = r7;
    ((struct Obj04132 *)r4)->f8 = a1;
    ((struct Obj04132 *)r4)->f10 = (int)func_02012944((void *)r7);
    ((struct Obj04132 *)r4)->f78 = 0;
    ((struct Obj04132 *)r4)->f14 = (int)p;
    ((struct Obj04132 *)r4)->f18 = a1;
    func_0215E580((void *)r7);
    func_0215F900(r4);
    func_0215F920((int)r4);
    func_0215F948((u8 *)r4);
    return r0v;
}


/*
 * Three arm9 size reads on the record's handle, cached at three fields.
 */
void func_0215F900(void *a0)
{
    char *p = (char *)a0;

    ((struct Obj04883 *)p)->f1C = func_02012934(((struct Obj04883 *)p)->f4);
    ((struct Obj04883 *)p)->f20 = (int)func_02012944(((struct Obj04883 *)p)->f4);
    ((struct Obj04883 *)p)->f24 = func_02012FCC((int)(((struct Obj04883 *)p)->f4));
}
