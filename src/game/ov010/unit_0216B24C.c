/*
 * file:     unit_0216B24C.c
 * unit:     yes
 * function: func_0216B24C, func_0216B280, func_0216B2E4, func_0216B340, func_0216B3A8, func_0216B3EC, func_0216B504, func_0216B538, func_0216B578, func_0216B5AC, func_0216B60C, func_0216B63C, func_0216B6DC, func_0216B720, func_0216B7B0, func_0216B7F8, func_0216B81C, func_0216B86C, func_0216B8B8, func_0216B91C, func_0216B970, func_0216B994, func_0216B9D8, func_0216BA08, func_0216BA40, func_0216BA88, func_0216BAE8, func_0216BB18, func_0216BB70, func_0216BB80, func_0216BB90, func_0216BBB4, func_0216BBC4, func_0216BBD4, func_0216BC88, func_0216BCE4, func_0216BD1C, func_0216BD54, func_0216BE20, func_0216BEC0
 * address:  0x0216B24C
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
 *   func_020120F4 0x020120F4 thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02176850  0x02176850  thumb  ov011
 *   func_02176870  0x02176870  thumb  ov011
 *   func_021767A0  0x021767A0  thumb  ov011
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_0216D888  0x0216D888  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_02012374  0x02012374  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_021BE8D4  0x021BE8D4  thumb
 *   func_021665D0  0x021665D0  thumb  ov010
 *   func_02012FA4  0x02012FA4  thumb
 *   func_021854B0  0x021854B0  thumb
 *   func_0219C630  0x0219C630  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0200C224  0x0200C224  thumb
 *   func_0200C22C  0x0200C22C  thumb
 *   func_02027138  0x02027138  thumb
 *   func_0200C32C  0x0200C32C  thumb
 *   func_0200C33C  0x0200C33C  thumb
 *   func_0200E394  0x0200E394  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0200C334  0x0200C334  thumb
 *   func_0200C344  0x0200C344  thumb
 *   func_0200C358  0x0200C358  thumb
 *   func_0203F524  0x0203F524  arm
 *   func_0200C384  0x0200C384  thumb
 *   func_0200E4F8  0x0200E4F8  thumb
 *   func_0200E4B0  0x0200E4B0  thumb
 *   d_0217219C     0x0217219C  data  ov010  a1
 *   d_021721BC     0x021721BC  data  ov010  a1
 *   func_0200E3A0  0x0200E3A0  thumb
 *   func_0200E3E8  0x0200E3E8  thumb
 *   func_02027100  0x02027100  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_021670F8  0x021670F8  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0200C0E8  0x0200C0E8  thumb
 *   func_0200E458 0x0200E458 thumb
 *   func_0200E47C 0x0200E47C thumb
 *   func_0200C34C 0x0200C34C thumb
 *   func_0200C37C  0x0200C37C  thumb
 *   func_020891E0  0x020891E0  arm
 *   d_021723BC 0x021723BC data a1
 *   d_021723BD 0x021723BD data a1
 *   d_021723BE 0x021723BE data a1
 *   d_021723BF 0x021723BF data a1
 *   d_021723C0 0x021723C0 data a1
 *   d_021723C1 0x021723C1 data a1
 *   d_021723C2 0x021723C2 data a1
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021F39B8  0x021F39B8  thumb  ov045
 *   func_021F3AA0  0x021F3AA0  thumb  ov059
 *   func_021F3B68 0x021F3B68 thumb ov059
 *   func_021F3B40 0x021F3B40 thumb ov059
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0202F488  0x0202F488  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0202F630  0x0202F630  thumb
 */
#include "../../matched/include/Obj09327.h"
#include "../../matched/include/Obj05904.h"

struct Ctx;
struct Desc;
struct Obj;
struct Work;
struct ValWork;
struct Evt;
struct Big;
struct Blk34;
struct RTCDate;
struct RTCTime;
struct Obj00020;
struct VecFx32;
struct BigObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { int value; u8 flag; u8 padding[3]; } ValWork;

typedef struct { int x, y, z; } V12_0;

typedef struct Work {
    u16 *result;        /* 0x00 */
    u16 f04;            /* 0x04 */
    u8 pad06[2];
    u8 f08[0x14 - 0x08];/* 0x08 */
    u16 f14;            /* 0x14 */
    u8 f16;             /* 0x16 */
    u8 pad17;
    u16 f18;            /* 0x18 */
    u8 pad1A[2];
    u32 f1c;            /* 0x1C */
    u32 f20;            /* 0x20 */
} Work;

typedef unsigned long long u64;

extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_02082BCC(void *, int, int);
extern void *func_020124E4(struct Obj *p);
extern u32 func_02012138(const struct Ctx *p);
extern int func_02158344(int a0);
extern int func_02176850(u8 *p, u8 value);
extern u32 func_02176870(u8 *p);
extern u8 func_021767A0(void *a, void *b);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188CB4(u8 *p);
extern void *func_021A3074(u8 *p);
extern void *func_0216D888(void *p);
extern void *func_02188C7C(u8 *p);
extern void func_0216D9A0(void *map);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_020061E4(u32 se);
extern void *func_021BE8D4(void *sys, void *proc, u32 a, u32 b);
extern int func_021665D0(int a0, int a1);
extern void func_02012FA4(char *p, unsigned char v);
extern void *func_021854B0(void *sys, void *proc, u32 id, void *pos, u32 flag);
extern int func_0219C630(void *map);
extern void *func_021BE92C(void *sys, void *proc, u32 a, u32 b, u32 c, u32 d, u32 e);
extern u32 *func_0216D9E4(void *c);
extern void *func_0215A5F4(void *p);
extern void *func_0215A5E4(void *a0);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C0F0(void *sys);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u8 func_0200C224(struct Blk34 *p);
extern int func_0200C22C();
extern int func_02027138();
extern u8 func_0200C32C(struct Blk34 *p);
extern int func_0200C33C(struct Blk34 *p, u32 i);
extern void *func_0200E394(void *a0);
extern unsigned int func_02159B10(void *a0, void *a1);
extern void func_0200C334(struct Blk34 *p, u8 v);
extern void func_0200C344(struct Blk34 *p, u8 i, u8 v);
extern void func_0200C358(struct Blk34 *p, u32 i, int v);
extern u64 func_0203F524();
extern void func_0200C384(struct Blk34 *p, u32 lo, u32 hi);
extern int func_0200E4F8(int a0, int a1, int a2);
extern u32 func_0200E4B0(u8 *a0, u32 a1, u32 a2);
extern void *func_0200E3A0(void *a);
extern void func_0200E3E8(u8 *bits, int id, u32 value);
extern void func_02027100(const void *src);
extern void *func_0215A5DC(void *a0);
extern void *func_021670F8(void *p);
extern int func_0215897C();
extern void *func_0200C0E8(void *sys);
extern u16 func_0200E458(const u16 *, int);
extern u32 func_0200E47C(u8 *p, int i);
extern u16 func_0200C34C(struct Blk34 *p, u32 i);
extern unsigned long long func_0200C37C(struct Blk34 *p);
extern void func_020891E0(struct RTCDate *date, struct RTCTime *time, long long sec);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern int func_021F39B8();
extern void func_021F3AA0();
extern void *func_021F3B68(void *, u32);
extern void *func_021F3B40(void *, u32);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern int func_0202F488(int a0, int a1);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_0202F630(u32 a, u32 b);
int func_0216B24C(void *vm, int value, int flag);
int func_0216B280(int a0, int *state, u8 **work);
void func_0216B2E4(V12_0 *src, int kind, V12_0 *dst);
struct Desc *func_0216B340(int a0, int a1, V12_0 *a2, int a3, int a4);
struct Desc *func_0216B3A8(int a0, int a1, int a2);
/* * Seven-state proc of an ov010 field menu: run the list task, then the * chosen entry's screen, writing 0 or 1 to the caller's result word. * Byte-correct first draft. * Blocker (MATCH): the arm9 Thumb callee 0x02012FA4 has no func_ label * and no matched file (seed). * * 2026-10-05: byte-identical; the wildcard is arm9 func_02012FA4 (new matched/arm9 file, EXACT, this lane); needs its shard. */ int func_0216B3EC(void *evt, u32 *state, Work *w);
/* * blocked: listing 52 compiled 50 */ int func_0216B504(int a0, int a1);
/* * blocked: listing 64 compiled 62 */ int func_0216B538(int a0, int a1);
int func_0216B578(int a0, int a1);
int func_0216B5AC(int a0, int a1);
/* * blocked: listing 48 compiled 46 */ int func_0216B60C(int a0, int a1);
int func_0216B63C(int a0, int a1);
int func_0216B6DC(int a0, int a1);
int func_0216B720(int c, int vm);
int func_0216B7B0(int c, int vm);
/* * blocked: listing 36 compiled 34 */ int func_0216B7F8(int a0, int a1);
int func_0216B81C(int c, int vm);
int func_0216B86C(int c, int vm);
int func_0216B8B8(int a0, u16 *a1);
int func_0216B91C(int a0, int a1, u16 *a2);
u32 func_0216B970(const u16 *p, int index);
int func_0216B994(int c, int vm);
int func_0216B9D8(int a0);
int func_0216BA08(void *p);
int func_0216BA40(int c, int vm);
u16 func_0216BA88(int c);
/* * arithmetic: subtract in u32, then interpret the resulting sign bit as * target int before the BPL clamp; this preserves SUB wrapping without bounds. * interface: BB18's old file says void, but this caller loads p into r0 * at 0216BAFC and BB18 forwards entry r0 to 0200C0F0; preserve that input. */ u16 func_0216BAE8(int p);
int func_0216BB18(void *sys);
/* * arithmetic: address and stride are unsigned 32-bit additions, preserving * the original MUL/ADD wrapping for every input bit pattern. */ int func_0216BB70(int index);
int func_0216BB80(int index);
/* * arithmetic: unsigned 32-bit address/stride arithmetic preserves original * MUL/ADD wrapping; each byte load remains ordered before its output store. */ void func_0216BB90(int index, u8 *out);
int func_0216BBB4(int index);
int func_0216BBC4(int index);
int func_0216BBD4(int c, int vm);
int func_0216BC88(int c, int vm);
int func_0216BCE4(void *ctx, void *vm);
int func_0216BD1C(void *ctx, void *vm);
/* * Script command: reads a species and a flag value and two result * variables, maps the event species (243-245, 251, 492, 647-649) to a kind * and, for 647/648, a signature move (548/547, dropped when the flag is 0), * and stores func_0216BE20's answer in the second variable; any other * species stores 0. */ int func_0216BD54(void *ctx, void *work);
int func_0216BE20(int a, int b, int e, int d, u16 *out);
int func_0216BEC0(int c, int vm);
extern u8 d_0217219C[];
extern u8 d_021721BC[];
extern const u8 d_021723BC[];
extern const u8 d_021723BD[];
extern const u8 d_021723BE[], d_021723BF[], d_021723C0[];
extern const u8 d_021723C1[];
extern const u8 d_021723C2[];




int func_0216B24C(void *vm, int value, int flag)
{
    int task;
    ValWork *p;
    func_020120F4((const struct Ctx *)vm);
    task = (int)func_020122C0((void *)vm, 0, func_0216B280, 8);
    p = func_020124E8((struct Obj *)task);
    func_02082BCC(p, 0, 8);
    p->value = value;
    p->flag = flag;
    return task;
}





int func_0216B280(int a0, int *state, u8 **work)
{
    int r;
    u16 *p;

    r = func_02158344(func_02012138((const struct Ctx *)func_020124E4((struct Obj *)a0)));
    if (r == 0) {
        p = *(u16 * *)&((struct Obj09327 *)work)->f0;
        if (p != 0)
            *p = 0;
        return 1;
    }
    switch (*state) {
    case 0:
        if (func_02176850((u8 *)r, ((u8 *)work)[4]) == 1)
            (*state)++;
        break;
    case 1:
        if (func_02176870((u8 *)r) == 1)
            (*state)++;
        break;
    case 2:
        p = *(u16 * *)&((struct Obj09327 *)work)->f0;
        if (p != 0)
            *p = 1;
        return 1;
    }
    return 0;
}




/*
 * Copies a 12-byte vector, then overwrites one component per case 0-3
 * (cases 4-9 leave it as copied).
 */
void func_0216B2E4(V12_0 *src, int kind, V12_0 *dst)
{
    *dst = *src;
    switch (kind) {
    case 0:
        dst->z = 0x62 << 14;
        break;
    case 1:
        dst->z = 0x26 << 14;
        break;
    case 2:
        dst->x = 0x6A << 14;
        break;
    case 3:
        dst->x = 0x16 << 14;
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        break;
    }
}



struct Desc *func_0216B340(int a0, int a1, V12_0 *a2, int a3, int a4)
{
    void *h;
    struct Desc *r;
    u8 *p;

    h = func_020120F4((const struct Ctx *)a0);
    r = func_020122C0((void *)a0, 0, (void *)func_0216B3EC, 0x24);
    p = func_020124E8((struct Obj *)r);
    func_02082BCC(p, 0, 0x24);
    *(V12_0 *)(p + 8) = *a2;
    ((struct Obj05904 *)p)->f14 = a3;
    ((struct Obj05904 *)p)->f0 = 0;
    p[0x16] = a4;
    ((struct Obj05904 *)p)->f1C = a1;
    if (func_021767A0((void *)((int)func_02012138((const struct Ctx *)a0)), h) == 4)
        ((struct Obj05904 *)p)->f20 = 1;
    return r;
}





struct Desc *func_0216B3A8(int a0, int a1, int a2)
{
    V12_0 buf;
    void *t;

    t = func_0201210C((void *)a0);
    func_020120F4((const struct Ctx *)a0);
    func_0216B2E4(func_0216D888(func_021A3074(func_02188CB4(t))), a1, &buf);
    return func_0216B340(a0, a1 != 9, &buf, a1, a2);
}






/*
 * Seven-state proc of an ov010 field menu: run the list task, then the
 * chosen entry's screen, writing 0 or 1 to the caller's result word.
 * Byte-correct first draft.
 * Blocker (MATCH): the arm9 Thumb callee 0x02012FA4 has no func_ label
 * and no matched file (seed).
 *
 * 2026-10-05: byte-identical; the wildcard is arm9 func_02012FA4 (new matched/arm9 file, EXACT, this lane); needs its shard.
 */
int func_0216B3EC(void *evt, u32 *state, Work *w)
{
    void *sys = func_020124E4(evt);
    void *ctx;
    void *proc;

    func_02012138(sys);
    ctx = func_020120F4(sys);
    proc = func_0201210C(sys);
    switch (*state) {
    case 0:
        func_0216D9A0(func_02188C7C(proc));
        if (w->f20 == 1) {
            *state = 2;
        } else {
            func_02012374(evt, (void *)func_0216B24C(sys, (int)(&w->f18), w->f16));
            (*state)++;
        }
        break;
    case 1:
        if (w->f18 == 0) {
            if (w->result != 0)
                *w->result = 0;
            *state = 6;
        } else {
            (*state)++;
        }
        break;
    case 2:
        if (w->f1c != 0)
            func_020061E4(1369);
        func_02012374(evt, func_021BE8D4(sys, proc, 9, 0));
        (*state)++;
        break;
    case 3:
        w->f04 = func_021665D0((int)sys, w->f16);
        func_02012FA4(ctx, w->f16);
        func_02012374(evt, func_021854B0(sys, proc, w->f04, w->f08, w->f14));
        (*state)++;
        break;
    case 4:
        if (func_0219C630(func_02188C7C(func_0201210C(sys))) == 1)
            break;
        func_02012374(evt, func_021BE92C(sys, proc, 9, 0, 0, 0, 0));
        (*state)++;
        break;
    case 5:
        if (w->result != 0)
            *w->result = 1;
        *state = 6;
        break;
    case 6:
        func_0216D9E4(func_02188C7C(proc));
        return 1;
    }
    return 0;
}






/*
 * blocked:  listing 52 compiled 50
 */
int func_0216B504(int a0, int a1)
{
    int t4;
    int t5;
    void *t6;
    void *p;
    u16 *q;
    void *v0;
    void *v1;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216B510:
a0 = t4 + 0;
    v1 = func_0215A5E4((void *)a0);
loc_0216B516:
    p = func_02012EBC((struct Big *)v1);
loc_0216B51A:
    t6 = func_0200C0F0(p);
loc_0216B51E:
a0 = t5 + 0;
a1 = t4 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0216B528:
    a0 = func_0200C224(t6);
loc_0216B530:
*q = a0;
a0 = 0;
    return a0;}






/*
 * blocked:  listing 64 compiled 62
 */
int func_0216B538(int a0, int a1)
{
    int t4;
    void *t5;
    void *p;
    void *v0;
    void *v1;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216B542:
a0 = t4 + 0;
    v1 = func_0215A5E4((void *)a0);
loc_0216B548:
    p = func_02012EBC((struct Big *)v1);
loc_0216B54C:
    t5 = func_0200C0F0(p);
loc_0216B550:
    a0 = func_0200C224(t5);
loc_0216B556:
t4 = a0 + 0;
    if (t4 < 5) goto loc_0216B560;
loc_0216B55C:
a0 = 0;
    return a0;
loc_0216B560:
a1 = t4 + 1;
    a0 = func_0200C22C(t5, a1);
loc_0216B568:
a0 = t4 + 1;
a0 = a0 << 0x18;
a0 = (unsigned)a0 >> 0x18;
    a0 = func_02027138(a0);
loc_0216B572:
a0 = 0;
    return a0;}






int func_0216B578(int a0, int a1)
{
    int t4;
    int t5;
    void *t6;
    void *p;
    u16 *q;
    void *v0;
    void *v1;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216B584:
a0 = t4 + 0;
    v1 = func_0215A5E4((void *)a0);
loc_0216B58A:
    p = func_02012EBC((struct Big *)v1);
loc_0216B58E:
    t6 = func_0200C0F0(p);
loc_0216B592:
a0 = t5 + 0;
a1 = t4 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0216B59C:
    a0 = func_0200C32C(t6);
loc_0216B5A4:
*q = a0;
a0 = 0;
    return a0;}






int func_0216B5AC(int a0, int a1)
{
    void *h;
    u16 *p0;
    u16 *p1;
    u16 *p2;

    func_0215A5F4((void *)a1);
    h = func_0200C0F0(func_02012EBC((struct Big *)func_0215A5E4((void *)a1)));
    p0 = func_02159AE8((void *)a0, (void *)a1);
    p1 = func_02159AE8((void *)a0, (void *)a1);
    p2 = func_02159AE8((void *)a0, (void *)a1);
    *p0 = func_0200C33C(h, 0);
    *p1 = func_0200C33C(h, 1);
    *p2 = func_0200C33C(h, 2);
    return 0;
}





/*
 * blocked:  listing 48 compiled 46
 */
int func_0216B60C(int a0, int a1)
{
    int t4;
    int t5;
    void *t6;
    u16 *q;
    void *v0;
    void *v1;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216B618:
a0 = t4 + 0;
    v1 = func_0215A5E4((void *)a0);
loc_0216B61E:
    t6 = func_02012EBC((struct Big *)v1);
loc_0216B622:
a0 = t5 + 0;
a1 = t4 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0216B62C:
    a0 = func_0216BB18(t6);
loc_0216B634:
*q = a0;
a0 = 0;
    return a0;}





int func_0216B63C(int a0, int a1)
{
    void *h;
    u16 s[3];
    int i;
    void *w;
    int k;
    int z;
    u64 t;

    func_0215A5F4((void *)a1);
    w = func_02012EBC((struct Big *)func_0215A5E4((void *)a1));
    h = func_0200C0F0(w);
    func_0200E394(w);
    k = func_02159B10((void *)a0, (void *)a1);
    s[0] = func_02159B10((void *)a0, (void *)a1);
    s[1] = func_02159B10((void *)a0, (void *)a1);
    s[2] = func_02159B10((void *)a0, (void *)a1);
    func_0200C334(h, k);
    z = 0;
    for (i = 0; i < 3; i++) {
        func_0200C344(h, i, s[i]);
        func_0200C358(h, (u8)i, z);
    }
    t = func_0203F524();
    func_0200C384(h, (u32)t, (u32)(t >> 32));
    return z;
}





int func_0216B6DC(int a0, int a1)
{
    void *w;
    void *h;
    int i;

    func_0215A5F4((void *)a1);
    w = func_02012EBC((struct Big *)func_0215A5E4((void *)a1));
    h = func_0200C0F0(w);
    func_0200E394(w);
    func_0200C334(h, 0);
    for (i = 0; i < 3; i++)
        func_0200C344(h, (u8)i, 0xFF);
    return 0;
}





int func_0216B720(int c, int vm)
{
    int i;
    int r5;
    void *r6;
    int best;
    u16 *dst;
    int out;
    int n;

    func_0215A5F4((void *)vm);
    r6 = func_0200E394(func_02012EBC((struct Big *)func_0215A5E4((void *)vm)));
    r5 = func_02159B10((void *)c, (void *)vm);
    dst = func_02159AE8((void *)c, (void *)vm);
    n = d_0217219C[r5];
    best = -1;
    for (i = 0; i < n; i++) {
        int a = func_0200E4F8((int)r6, r5, i + 1);
        int b = func_0200E4B0(r6, r5, i + 1);
        int s = a + b;
        if (best < s) {
            best = s;
            out = d_021721BC[r5 * 17 + i];
        }
    }
    *dst = out;
    return 0;
}





int func_0216B7B0(int c, int vm)
{
    void *r6;
    int a;
    int b;

    func_0215A5F4((void *)vm);
    r6 = func_0200E3A0(func_0200E394(func_02012EBC((struct Big *)func_0215A5E4((void *)vm))));
    a = func_02159B10((void *)c, (void *)vm);
    b = func_02159B10((void *)c, (void *)vm);
    func_0200E3E8(r6, (u8)a, b);
    func_02027100(r6);
    return 0;
}





/*
 * blocked:  listing 36 compiled 34
 */
int func_0216B7F8(int a0, int a1)
{    int t5;
    void *p;
    void *v0;
    void *v1;

t5 = a1 + 0;
a0 = t5 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216B802:
a0 = t5 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0216B80A:
    p = func_021670F8(v1);
loc_0216B80E:
    a0 = func_0215897C(v0, p);
loc_0216B816:
a0 = 1;
    return a0;}





int func_0216B81C(int c, int vm)
{
    void *r6;
    void *t;
    int r5;
    u16 *r4;

    r6 = func_02012EBC((struct Big *)func_0215A5E4((void *)vm));
    t = func_0200C0E8(r6);
    r5 = (u8)func_02159B10((void *)c, (void *)vm);
    r4 = func_02159AE8((void *)c, (void *)vm);
    if (r5 == func_0200C32C(t)) {
        func_0216B8B8((int)r6, r4);
    } else {
        func_0216B91C((int)r6, r5, r4);
    }
    return 0;
}





int func_0216B86C(int c, int vm)
{
    u16 *dst;
    void *r6;
    void *r7;
    int r5;
    u8 k;

    r6 = func_02012EBC((struct Big *)func_0215A5E4((void *)vm));
    r7 = func_0200C0E8(r6);
    dst = func_02159AE8((void *)c, (void *)vm);
    k = func_0216BB70(func_0200C32C(r7));
    if (k != 0) {
        if (k == 1) {
            r5 = func_0216BAE8((int)r6);
        }
    } else {
        r5 = func_0216BA88((int)r6);
    }
    *dst = r5;
    return 0;
}





int func_0216B8B8(int a0, u16 *a1)
{
    u16 *t4;
    int t5;
    void *t6;
    int t7;
    void *p;

t5 = a0 + 0;
t4 = a1 + 0;
    t6 = func_0200E394((void *)a0);
loc_0216B8C2:
a0 = t5 + 0;
    p = func_0200C0E8((void *)a0);
loc_0216B8CA:
    a0 = func_0200C32C(p);
loc_0216B8CE:
t7 = a0 + 0;
    a0 = func_0216BB70(a0);
loc_0216B8D4:
a0 = a0 << 0x18;
a0 = (unsigned)a0 >> 0x18;
    if (a0 != 0) goto loc_0216B8F2;
loc_0216B8DA:
    a0 = func_0216B994((int)t6, t7);
loc_0216B8E2:
    if (a0 == 0) goto loc_0216B8EC;
loc_0216B8E6:
a0 = 1;
*t4 = a0;
    return a0;
loc_0216B8EC:
a0 = 2;
*t4 = a0;
    return a0;
loc_0216B8F2:
    if (a0 != 1) goto loc_0216B91A;
loc_0216B8F6:
a0 = t5 + 0;
    a0 = func_0216B9D8(a0);
loc_0216B8FC:
    if (a0 == 0) goto loc_0216B916;
loc_0216B900:
a0 = t5 + 0;
    a0 = func_0216BA08((void *)a0);
loc_0216B906:
    if (a0 == 0) goto loc_0216B910;
loc_0216B90A:
a0 = 1;
*t4 = a0;
    return a0;
loc_0216B910:
a0 = 4;
*t4 = a0;
    return a0;
loc_0216B916:
a0 = 3;
*t4 = a0;
loc_0216B91A:
    return a0;}





int func_0216B91C(int a0, int a1, u16 *a2)
{
    u16 *t4;
    int t5;
    void *t6;
    int t7;

t7 = a0 + 0;
t5 = a1 + 0;
t4 = a2 + 0;
    t6 = func_0200E394((void *)a0);
loc_0216B928:
a0 = t7 + 0;
    func_0200C0E8((void *)a0);
loc_0216B930:
a0 = t5 + 0;
    a0 = func_0216BB70(a0);
loc_0216B936:
a0 = a0 << 0x18;
a0 = (unsigned)a0 >> 0x18;
    if (a0 != 0) goto loc_0216B954;
loc_0216B93C:
a1 = t5 + 0;
    a0 = func_0216B994((int)t6, a1);
loc_0216B944:
    if (a0 == 0) goto loc_0216B94E;
loc_0216B948:
a0 = 1;
*t4 = a0;
    return a0;
loc_0216B94E:
a0 = 2;
*t4 = a0;
    return a0;
loc_0216B954:
    if (a0 != 1) goto loc_0216B96E;
loc_0216B958:
a1 = t5 + 0;
    a0 = func_0216BA40((int)t6, a1);
loc_0216B960:
    if (a0 == 0) goto loc_0216B96A;
loc_0216B964:
a0 = 1;
*t4 = a0;
    return a0;
loc_0216B96A:
a0 = 3;
*t4 = a0;
loc_0216B96E:
    return a0;}



u32 func_0216B970(const u16 *p, int index)
{
    u32 x = func_0200E458(p, index);
    x += func_0200E47C((u8 *)p, index);
    if (x > 999999) x = 999999;
    return x;
}




int func_0216B994(int c, int vm)
{
    int i;
    u8 buf[4];
    int n;
    u32 lim;

    func_0216BB90(vm, buf);
    n = (u8)func_0216BB80(vm);
    lim = func_0216BBB4(vm);
    for (i = 0; i < n; i++) {
        if (func_0216B970((const u16 *)c, buf[i]) < lim) {
            return 0;
        }
    }
    return 1;
}




int func_0216B9D8(int a0)
{
    int t4;
    int t5;
    void *p;

t4 = a0 + 0;
    func_0200E394((void *)a0);
loc_0216B9E0:
a0 = t4 + 0;
    p = func_0200C0E8((void *)a0);
loc_0216B9E6:
    a0 = func_0200C32C(p);
loc_0216B9EA:
t5 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0216BB18((void *)a0);
loc_0216B9F2:
t4 = a0 + 0;
a0 = t5 << 0x18;
a0 = (unsigned)a0 >> 0x18;
    a0 = func_0216BBC4(a0);
loc_0216B9FC:
    if (a0 > t4) goto loc_0216BA04;
loc_0216BA00:
a0 = 1;
    return a0;
loc_0216BA04:
a0 = 0;
    return a0;}



int func_0216BA08(void *p)
{
    void *q;
    int i, n;
    q = func_0200C0E8(p);
    n = (u8)func_0216BB80(func_0200C32C(q));
    for (i = 0; i < n; i++) {
        if (func_0200C34C(q, (u8)i) == 0) return 0;
    }
    return 1;
}




int func_0216BA40(int c, int vm)
{
    int i;
    u8 buf[4];
    int n;

    func_0216BB90(vm, buf);
    n = (u8)func_0216BB80(vm);
    func_0216BBB4(vm);
    for (i = 0; i < n; i++) {
        if (func_0216B970((const u16 *)c, buf[i]) < 999999) {
            return 0;
        }
    }
    return 1;
}




u16 func_0216BA88(int c)
{
    int i;
    u8 buf[4];
    int n;
    u32 lim;
    u32 best;
    void *r7;
    int r4;

    r7 = func_0200E394((void *)c);
    r4 = func_0200C32C(func_0200C0E8((void *)c));
    lim = func_0216BBB4(r4);
    n = (u8)func_0216BB80(r4);
    func_0216BB90(r4, buf);
    best = 1009998;
    for (i = 0; i < n; i++) {
        u32 v = func_0216B970(r7, buf[i]);
        if (v < best) {
            best = v;
        }
    }
    return lim - best;
}



/*
 * arithmetic: subtract in u32, then interpret the resulting sign bit as
 * target int before the BPL clamp; this preserves SUB wrapping without bounds.
 * interface: BB18's old file says void, but this caller loads p into r0
 * at 0216BAFC and BB18 forwards entry r0 to 0200C0F0; preserve that input.
 */
u16 func_0216BAE8(int p)
{
    int index, elapsed, x;
    func_0200E394((void *)p);
    index = func_0200C32C(func_0200C0E8((void *)p));
    elapsed = func_0216BB18((void *)p);
    x = (int)((u32)func_0216BBC4((u8)index) - (u32)elapsed);
    if (x < 0) x = 0;
    return (u16)x;
}




int func_0216BB18(void *sys)
{
    u32 a[7];
    void *r4;
    u64 t;

    r4 = func_0200C0F0(sys);
    if (func_0200C32C(r4) == 0) {
        return 0;
    }
    t = func_0200C37C(r4);
    func_020891E0((struct RTCDate *)(a + 3), (struct RTCTime *)a, func_0203F524() - t);
    if (a[3] != 0 || a[4] > 1 || a[5] > 1) {
        return 24;
    }
    return (u16)a[0];
}



/*
 * arithmetic: address and stride are unsigned 32-bit additions, preserving
 * the original MUL/ADD wrapping for every input bit pattern.
 */
int func_0216BB70(int index)
{
    return *(const u8 *)((u32)d_021723BC + (u32)index * 7u);
}



int func_0216BB80(int index)
{
    return *(const u8 *)((u32)d_021723BD + (u32)index * 7u);
}



/*
 * arithmetic: unsigned 32-bit address/stride arithmetic preserves original
 * MUL/ADD wrapping; each byte load remains ordered before its output store.
 */
void func_0216BB90(int index, u8 *out)
{
    out[0] = *(const u8 *)((u32)d_021723BE + (u32)index * 7u);
    out[1] = *(const u8 *)((u32)d_021723BF + (u32)index * 7u);
    out[2] = *(const u8 *)((u32)d_021723C0 + (u32)index * 7u);
}



int func_0216BBB4(int index)
{
    return *(const u8 *)((u32)d_021723C1 + (u32)index * 7u);
}



int func_0216BBC4(int index)
{
    return *(const u8 *)((u32)d_021723C2 + (u32)index * 7u);
}




int func_0216BBD4(int c, int vm)
{
    void *ws;
    void *p8;
    void *p10;
    int a1;
    int a2;
    int a3;
    int a4;
    int a5;
    int a6;
    int buf[3];
    int vec[3];
    int *x;
    int *y;
    int r;

    ws = func_0215A5F4((void *)vm);
    p8 = func_0215A5DC((void *)vm);
    p10 = func_0201210C((void *)p8);
    a1 = func_02159B10((void *)c, (void *)vm);
    a2 = func_02159B10((void *)c, (void *)vm);
    a3 = func_02159B10((void *)c, (void *)vm);
    a4 = func_02159B10((void *)c, (void *)vm);
    a5 = func_02159B10((void *)c, (void *)vm);
    a6 = func_02159B10((void *)c, (void *)vm);
    func_021A3038(func_02188CB4((void *)p10), (struct VecFx32 *)buf);
    vec[0] = (a2 << 16) + 0x8000;
    vec[1] = a3 << 15;
    vec[2] = (a4 << 16) + 0x8000;
    if (a1 == 0) {
        x = buf;
        y = vec;
    } else {
        x = vec;
        y = buf;
    }
    r = func_021F39B8(p8, a1, x, y, a5 << 15, a6);
    if (r == 0) {
        return 1;
    }
    func_0215897C(ws, (void *)r);
    return 1;
}




int func_0216BC88(int c, int vm)
{
    void *p;
    int a1;
    int a2;
    int a3;
    int a4;
    int vec[3];

    p = func_0215A5DC((void *)vm);
    a1 = func_02159B10((void *)c, (void *)vm);
    a2 = func_02159B10((void *)c, (void *)vm);
    a3 = func_02159B10((void *)c, (void *)vm);
    a4 = func_02159B10((void *)c, (void *)vm);
    vec[0] = (a2 << 16) + 0x8000;
    vec[1] = a3 << 15;
    vec[2] = (a4 << 16) + 0x8000;
    func_021F3AA0(p, a1, vec);
    return 0;
}



int func_0216BCE4(void *ctx, void *vm)
{
    void *ws, *p, *task;
    ws = func_0215A5F4(vm);
    p = func_0215A5DC(vm);
    task = func_021F3B68(p, func_02159B10(ctx, vm));
    if (task == 0) return 1;
    func_0215897C(ws, task);
    return 1;
}



int func_0216BD1C(void *ctx, void *vm)
{
    void *ws, *p, *task;
    ws = func_0215A5F4(vm);
    p = func_0215A5DC(vm);
    task = func_021F3B40(p, func_02159B10(ctx, vm));
    if (task == 0) return 1;
    func_0215897C(ws, task);
    return 1;
}




/*
 * Script command: reads a species and a flag value and two result
 * variables, maps the event species (243-245, 251, 492, 647-649) to a kind
 * and, for 647/648, a signature move (548/547, dropped when the flag is 0),
 * and stores func_0216BE20's answer in the second variable; any other
 * species stores 0.
 */
int func_0216BD54(void *ctx, void *work)
{
    void *s = func_02012934(func_0215A5E4(work));
    int species = func_02159B10(ctx, work);
    unsigned int flag = func_02159B10(ctx, work);
    u16 *out = func_02159AE8(ctx, work);
    u16 *res = func_02159AE8(ctx, work);
    int kind;
    int move;

    switch (species) {
    case 647:
        kind = 4;
        move = 548;
        break;
    case 648:
        kind = 5;
        move = 547;
        break;
    case 251:
        kind = 0;
        move = 0;
        break;
    case 243:
    case 244:
    case 245:
        kind = 2;
        move = 0;
        break;
    case 649:
        kind = 6;
        move = 0;
        break;
    case 492:
        kind = 7;
        move = 0;
        break;
    default:
        *res = 0;
        return 0;
    }
    if (flag == 0) {
        move = 0;
    }
    *res = func_0216BE20((int)s, species, move, kind, out);
    return 0;
}




int func_0216BE20(int a, int b, int e, int d, u16 *out)
{
    int found;
    int n;
    int i;
    void *obj;

    n = func_0201AA18((void *)a);
    found = 0;
    *out = 0;
    for (i = 0; i < n; i++) {
        obj = func_0201AB28((void *)a, i);
        if (func_0202F488((int)obj, d) == 0) {
            continue;
        }
        if (b != func_02017E1C(obj, 5, 0)) {
            continue;
        }
        if (e != 0) {
            if (e == func_02017E1C(obj, 0x36, 0)
                || e == func_02017E1C(obj, 0x37, 0)
                || e == func_02017E1C(obj, 0x38, 0)
                || e == func_02017E1C(obj, 0x39, 0)) {
                continue;
            }
        }
        found = 1;
        *out = i;
        break;
    }
    return found;
}




int func_0216BEC0(int c, int vm)
{
    void *r7;
    int k;
    int m;
    int t;
    void *obj;

    r7 = func_02012934(func_0215A5E4((void *)vm));
    k = func_02159B10((void *)c, (void *)vm);
    m = func_02159B10((void *)c, (void *)vm);
    switch (k) {
    case 0xFB:
        t = 0;
        break;
    case 0xF3:
    case 0xF4:
    case 0xF5:
        t = 2;
        break;
    case 0xF6:
    case 0xF7:
    case 0xF8:
    case 0xF9:
    case 0xFA:
    default:
        return 0;
    }
    obj = func_0201AB28((void *)r7, m);
    if (func_0202F488((int)obj, t) == 0) {
        return 0;
    }
    func_0202F630((u32)obj, t);
    return 0;
}
