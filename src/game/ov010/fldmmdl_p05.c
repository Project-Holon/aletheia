/*
 * file:     fldmmdl_p05.c
 * unit:     yes
 * function: func_0216C8CC, func_0216C978, func_0216C9CC, func_0216C9F4, func_0216CAA8, func_0216CAD4, func_0216CAF4, func_0216CB48, func_0216CC30
 * address:  0x0216C8CC
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
 *   func_02031330  0x02031330  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_0203A574  0x0203A574  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D594  0x0203D594  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0203D5A0  0x0203D5A0  arm
 *   func_02031348  0x02031348  arm
 *   func_0203A5E4  0x0203A5E4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   id_0000005D    0x0000005D  data  a1
 *   d_021F03C4     0x021F03C4  data  a4 ov093
 *   d_021EFDAC     0x021EFDAC  data  a4 ov026
 *   func_020120F4  0x020120F4  thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   d_02172548     0x02172548  data  ov010  a4
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02161824  0x02161824  thumb  ov010
 *   func_02012374  0x02012374  thumb
 *   func_02029BCC  0x02029BCC  thumb
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AAABC  0x021AAABC  thumb  ov021
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF498  0x021CF498  thumb  ov021
 *   func_020144DC  0x020144DC  thumb
 *   func_02029C00  0x02029C00  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_02029CC0  0x02029CC0  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_021CBD84   0x021CBD84  thumb  ov021
 *   func_02191388  0x02191388  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_021912D8  0x021912D8  thumb
 *   func_021912F8  0x021912F8  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C54  0x02188C54  thumb  ov021
 *   sub_020122C0   0x020122C0  thumb
 *   sub_020124E8   0x020124E8  thumb
 *   func_02012964  0x02012964  thumb
 *   func_0216DEE0  0x0216DEE0  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021B0A40  0x021B0A40  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_021B09D8  0x021B09D8  thumb  ov021
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020071CC  0x020071CC  thumb
 *   func_0200DF58  0x0200DF58  thumb
 *   func_0202435C  0x0202435C  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_021B09EC  0x021B09EC  thumb  ov021
 *   func_0219129C  0x0219129C  thumb  ov021
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0216CC40  0x0216CC40  thumb  ov010
 */
#include "../../matched/include/Obj17769.h"
#include "../../matched/include/Obj07205.h"
#include "../../matched/include/Obj09165.h"

struct Entry;
struct Ctx;
struct IcaAnime;
struct Desc;
struct Obj;
struct Evt;
struct Actor;
struct Big;
struct Sub020071CCCtrl;
struct BigObj;
struct Ent;
struct Q;
struct Buf3FC;
struct RecSlot;
typedef signed int     s32_0216C8CC;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef int            s32_0216CB48;

typedef s32_0216CB48            fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Work {
    void   *owner;      /* 0x00 */
    u32     field04;    /* 0x04 */
    VecFx32 pos;        /* 0x08 */
    u32     field14;    /* 0x14 */
    void   *field18;    /* 0x18 */
} Work;

extern unsigned int func_02031330(void *p);
extern int func_02034AC4(s32_0216C8CC handle);
extern void func_0203A574(u32 a, u32 b, u32 c, u32 d);
extern struct Entry *func_020399A8(void);
extern void func_0203D594(int, int);
extern u32 func_0200FB24(void);
extern int func_0203D5A0(int, int);
extern void func_02031348(int, int, char *, int);
extern void func_0203A5E4(u32 key);
extern void func_02034A5C(s32_0216C8CC handle);
extern void *func_020120F4(const struct Ctx *p);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 func_020120F0(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_02161824(void *a, void *b);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_02029BCC(void *a, u32 b);
extern u32 func_02188CE8(u8 *p);
extern void func_021AAABC(int);
extern int func_02189A08(unsigned char *p);
extern void func_021CF498(struct Ctx *c, u32 x, int idx);
extern int func_020144DC(int, int);
extern void *func_02029C00(void *a);
extern void *func_020145CC(void *a0);
extern void *func_02029CC0(void *a);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void *func_021CBD84(void *a);
extern int func_02191388();
extern u32 func_020362DC(void);
extern int func_021912D8();
extern int func_021912F8();
extern int func_02045808();
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188C54(u8 *p);
extern struct Desc *sub_020122C0(void *owner, void *a, void *b, u32 size);
extern void *sub_020124E8(struct Obj *p);
extern u32 func_02012964(const struct BigObj *p);
extern void *func_0216DEE0(void *a0);
extern void *func_0216DE94(void *map, u32 id);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern int func_021B0A40(u32 a, struct Q *q);
extern void *func_02188C58(void *p);
extern u32 func_0218EC2C(u8 *p);
extern void  func_021B09D8(VecFx32 *pos, VecFx32 *out, void *a, void *b, void *c);
extern void *func_02012EBC(struct Big *p);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern struct Buf3FC *func_0200DF58(struct RecSlot *p, u32 heap);
extern void *func_0202435C(void *slots, unsigned int heap);
extern u32 func_020307B0(void *p);
extern void func_021B09EC(int sel, int *a, int *b);
extern struct Ent *func_0219129C(u8 *base, int idx, u32 c, u32 d, u32 f, u32 g);
extern void *func_0215A5DC(void *a0);
extern int func_0216CC40();
int func_0216C8CC(int a, int *st, int *o, int *x);
int func_0216C978(int a, int *st, int *o);
void *func_0216C9CC(void *a,void *b,void *c);
int func_0216C9F4(int a, int *st, int *o);
void *func_0216CAA8(void *a,void *b,void *c,void *d);
void func_0216CAD4(void *a0, void *a1, void *a2);
int func_0216CAF4(int a0, int a1, int a2);
void *func_0216CB48(void *owner, int idx, u8 arg);
int func_0216CC30(int a0, int a1);
extern char id_0000005D[];
extern char d_021F03C4[];
extern char d_021EFDAC[];
extern char d_02172548[];


/*
 * blockers: d_021F03C4 and d_021EFDAC data pointers outside ov010 window; no witness
 * (tried ov006/008/011/187/199/ov010 hints)
 *
 * 2026-10-05: data hints now carry an overlay token that has a witness; EXACT.
 */
int func_0216C8CC(int a, int *st, int *o, int *x)
{
    int r = func_02031330((void *)x[0]);
    switch (*st) {
    case 0:
        func_02034AC4((s32_0216C8CC)id_0000005D);
        func_0203A574(0x100, (u32)d_021F03C4, 9, 0);
        func_0203D594((int)func_020399A8(), 0xc8);
        *st = 1;
        break;
    case 1:
        if (func_0200FB24() != 0) {
            *st = 4;
            break;
        }
        if (func_0203D5A0((int)func_020399A8(), 0xc8) == 0)
            break;
        *st = 2;
        break;
    case 2:
        func_02031348(x[0], ~0, d_021EFDAC, o[1]);
        *st = 3;
        break;
    case 3:
        if (r == 1)
            break;
        *st = 4;
        break;
    case 4:
        func_0203A5E4(0x100);
        func_02034A5C((s32_0216C8CC)id_0000005D);
        *st = 5;
        break;
    case 5:
        return 1;
    }
    return 0;
}


int func_0216C978(int a, int *st, int *o)
{
    int x = o[0];
    int *t;
    switch (*st) {
    case 0:
        t = o + 3;
        o[3] = (int)func_020120F4((const struct Ctx *)x);
        t[1] = o[1];
        t[2] = o[2];
        func_020120B4((struct IcaAnime *)x, ~0, d_02172548, t);
        (*st)++;
        break;
    case 1:
        if (func_020120F0((const struct Ctx *)x) == 0)
            return 1;
        break;
    }
    return 0;
}

void *func_0216C9CC(void *a,void *b,void *c) {
    void *t; void **p;
    t=func_020122C0(a,0,(void *)func_0216C978,0x3c); p=func_020124E8(t);
    p[0]=a; p[1]=b; p[2]=c; return t;
}


int func_0216C9F4(int a, int *st, int *o)
{
    int x = o[0];
    int y = o[1];
    switch (*st) {
    case 0:
        func_02012374((struct Evt *)a, func_02161824((void *)x, (void *)y));
        (*st)++;
        break;
    case 1:
        func_02012374((struct Evt *)a, func_02029BCC((void *)x, *(unsigned short *)(o[2] + 0x18)));
        (*st)++;
        break;
    case 2:
        func_021AAABC(func_02188CE8((u8 *)y));
        func_021CF498((struct Ctx *)func_02189A08((unsigned char *)o[1]), a, 9);
        (*st)++;
        break;
    case 3:
        func_02012374((struct Evt *)a, (struct Evt **)func_020144DC(x, y));
        (*st)++;
        break;
    case 4:
        func_02012374((struct Evt *)a, func_0216C9CC((void *)x, (void *)o[2], (void *)o[3]));
        (*st)++;
        break;
    case 5:
        func_02012374((struct Evt *)a, func_02029C00((void *)x));
        (*st)++;
        break;
    case 6:
        func_02012374((struct Evt *)a, func_020145CC((void *)x));
        (*st)++;
        break;
    case 7:
        func_02012374((struct Evt *)a, func_02029CC0((void *)x));
        (*st)++;
        break;
    case 8:
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE92C((void *)x, y, 0, 0, 1, 0, 0));
        (*st)++;
        break;
    case 9:
        return 1;
    default:
        return 1;
    }
    return 0;
}

void *func_0216CAA8(void *a,void *b,void *c,void *d) {
    void *t; void **p;
    t=func_020122C0(a,0,(void *)func_0216C9F4,0x10); p=func_020124E8(t);
    p[0]=a; p[2]=c; p[3]=d; p[1]=b; return t;
}


/*
 * unblocked: func_021CBD84 (ov021, unlabelled leaf) was matched bottom-up
 *   and filed as pkt_021CBD84; the `ov021` token then resolves the site as
 *   `matched, overlay`.
 *
 * The record's far field (0x7CC) and the arm9 probe result are the last
 * two arguments of the four-argument overlay call.
 */
void func_0216CAD4(void *a0, void *a1, void *a2)
{
    int v = (int)func_021CBD84(a0);

    func_0216CAA8(a1, a2, (void *)(((struct Obj17769 *)a0)->f7CC), (void *)v);
}


int func_0216CAF4(int a0, int a1, int a2)
{
    int t4;
    int t5;

t5 = a1 + 0;
a0 = ((struct Obj09165 *)((char *)t5))->f0;
t4 = a2 + 0;
    if (a0 == 0) goto loc_0216CB0A;
loc_0216CB00:
    if (a0 == 1) goto loc_0216CB1C;
loc_0216CB04:
    if (a0 == 2) goto loc_0216CB2E;
loc_0216CB08:
    goto loc_0216CB42;
loc_0216CB0A:
a0 = ((struct Obj07205 *)t4)->f14;
    a0 = func_02191388(a0);
loc_0216CB10:
    if (a0 != 1) goto loc_0216CB42;
loc_0216CB14:
a0 = ((struct Obj09165 *)((char *)t5))->f0;
a0 = a0 + 1;
((struct Obj09165 *)((char *)t5))->f0 = a0;
    goto loc_0216CB42;
loc_0216CB1C:
    a0 = func_020362DC();
loc_0216CB20:
a1 = 3;
    if ((a0 & a1) == 0) goto loc_0216CB42;
loc_0216CB26:
a0 = ((struct Obj07205 *)t4)->f14;
    a0 = func_021912D8(a0);
loc_0216CB2C:
    goto loc_0216CB14;
loc_0216CB2E:
a0 = ((struct Obj07205 *)t4)->f14;
    a0 = func_021912F8(a0);
loc_0216CB34:
    if (a0 != 1) goto loc_0216CB42;
loc_0216CB38:
a0 = ((struct Obj07205 *)t4)->f18;
    a0 = func_02045808(a0);
loc_0216CB3E:
a0 = 1;
    return a0;
loc_0216CB42:
a0 = 0;
    return a0;}


/*
 * The third parameter is u8: with it declared int the body is byte-identical
 * except that the w->owner store and the next call's argument move swap
 * places (4 bytes); the u8 spill to [sp,#8] changes nothing visible but the
 * schedule.  Found by tools/permuter.py --types.  The call to arm9
 * 0x0202435C (an unlabelled two-slot wrapper) is attested by its shard.
 *
 * evidence: 0x0202435C is an unlabelled ARM9 thunk ("ldr r3, =func_02024368; movs r2, #2; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov069 0x021BA21A, ov093 0x021D1894, ov010 0x02168138), so the call
 * attests as `label`.
 */
void *func_0216CB48(void *owner, int idx, u8 arg)
{
    void *sys;
    void *anm;
    void *ctx;
    void *task;
    Work *w;
    void *mdl;
    void *m2;
    void *cam;
    VecFx32 ofs;
    s32_0216CB48 b;
    s32_0216CB48 c;
    u8 *tbl;

    sys = func_020120F4(owner);
    anm = func_0201210C(owner);
    ctx = (void *)func_02188C54(anm);
    task = sub_020122C0(owner, 0, func_0216CAF4, sizeof(Work));
    w = sub_020124E8(task);
    w->owner = owner;
    mdl = (void *)func_02012964(sys);
    m2 = func_0216DEE0(mdl);
    func_0216D88C(func_0216DE94(mdl, arg), &w->pos);
    mdl = (void *)func_021B0A40((u32)m2, (struct Q *)(&w->pos));
    cam = func_02188C58(anm);
    func_021B09D8(&w->pos, &ofs, (void *)func_0218EC2C(cam), cam, mdl);
    w->pos.x += ofs.x;
    w->pos.y += ofs.y;
    w->pos.z += ofs.z;
    tbl = (u8 *)func_0200DF58(func_020071CC(func_02012EBC(sys), 0x3b), 4);
    w->field18 = func_0202435C(tbl + idx * 0x22 + 0x18, 4);
    func_020307B0(tbl);
    func_021B09EC((int)mdl, &b, &c);
    w->field14 = (u32)func_0219129C(ctx, b, (u32)(&w->pos), (u32)w->field18, 0, c);
    return task;
}


int func_0216CC30(int a0, int a1)
{
    void *v0;

a0 = a1 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0216CC38:
    a0 = func_0216CC40(v0);
loc_0216CC3C:
a0 = 0;
    return a0;}
