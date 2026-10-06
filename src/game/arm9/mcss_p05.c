/*
 * file:     mcss_p05.c
 * unit:     yes
 * function: func_020160C4, func_020160CC, func_020160D4, func_0201624C, func_02016374, func_02016380, func_02016394, func_020163B0, func_020163B4, func_020163C4, func_02016630, func_02016880
 * address:  0x020160C4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   data_020A72CC  0x020A72CC  data
 *   func_0201691C  0x0201691C  thumb
 *   func_02016C38  0x02016C38  thumb
 *   func_02021F64  0x02021F64  thumb
 *   func_020056A0  0x020056A0  thumb
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02082A60  0x02082A60  arm
 *   MIi_CpuCopy16  0x02082A60  arm
 *   func_02064CBC  0x02064CBC  arm
 *   func_02016880  0x02016880  thumb
 *   func_02016630  0x02016630  thumb
 *   func_02063A54  0x02063A54  arm
 *   func_02063E54  0x02063E54  arm
 *   sub_020307B0   0x020307B0  arm
 *   sub_02030EAC   0x02030EAC  arm
 */
#include "../../matched/include/Obj15672.h"
#include "../../matched/include/Obj01093.h"
#include "../../matched/include/Obj01612.h"
#include "../../matched/include/Obj06864.h"
#include "../../matched/include/Obj15676.h"
#include "../../matched/include/Obj15677.h"
#include "../../matched/include/Obj15678.h"
#include "../../matched/include/Obj15679.h"
#include "../../matched/include/Obj15680.h"
#include "../../matched/include/Obj15681.h"
#include "../../matched/include/Obj01613.h"
#include "../../matched/include/Obj06865.h"
#include "../../matched/include/Obj11719.h"
#include "../../matched/include/Obj15687.h"
#include "../../matched/include/Obj01018.h"
#include "../../matched/include/Obj00696.h"

struct Obj_0201691C;
struct Obj_0;
struct Obj_02016880;
struct Task;
struct Work;
struct Ctx;
struct ArcFile;
struct Out;
struct Res;
struct Node;
typedef unsigned short u16;

typedef struct {
    char pad[0x28];
    u16 *p28;
} S_0;

typedef unsigned int   u32;

typedef unsigned char  u8;

struct Inner {
    u32 f00;
    u32 f04;
    u32 f08;
    void *f0c;
};

struct Obj_0 {
    u8 pad00[4];
    struct Inner *f04;
    u8 pad08[4];
    void *f0c;
    u8 pad10[0xc];
    u32 f1c;
    void *f20;
    void *f24;
    u32 f28;
};

typedef struct {
    char pad[0x140];
    unsigned int lo : 30;
    unsigned int f : 1;
    unsigned int hi : 1;
} S_1;

typedef struct {
    char pad[0x2c];
    unsigned int b0 : 1;
    unsigned int b1 : 1;
} Obj_0;

struct Obj_020163C4 {
    void *f00;
    void *f04;
    void *f08;
    void *f0c;
    void *f10;
    void *f14;
    u32 f18;
    u32 f1c;
    void *f20;
    void *f24;
    u32 f28;
};

struct Ctx {
    void *f00;
    void *f04;
    void *f08;
    u8 pad0c[8];
    void **f14;
    u8 pad18[0x18];
    u32 f30;
    u32 f34;
    u32 (*f38)(void *, void *, u32);
    u32 f3c;
};

struct Src {
    void *f00;
    void *f04;
    void *f08;
    void *f0c;
    void *f10;
    void *f14;
    void *f18;
    void *f1c;
    u32 f20;
};

struct Obj {
    void *f00;
    void *f04;
    void *f08;
    void *f0c;
    void *f10;
    void *f14;
    u32 f18;
    u32 f1c;
    void *f20;
    void *f24;
    u32 f28;
};

struct Obj_02016880 {
    void *f00;                    /* +0x00 */
    void *f04;                    /* +0x04 */
    u32  f08;                     /* +0x08 */
    u32  f0c;                     /* +0x0c */
    void *f10;                    /* +0x10 */
    void *f14;                    /* +0x14 */
    u32  f18;                     /* +0x18 */
    u32  f1c;                     /* +0x1c */
    struct Obj20_02016880 *f20;   /* +0x20 */
    u32 *f24;                     /* +0x24 */
    u32  f28;                     /* +0x28 */
};

struct Obj20_02016880 {
    u8   pad00[0xc];
    void *f0c;                    /* +0x0c */
};

extern void func_0201691C(void *a0, struct Obj_0201691C *a1);
extern int func_02016C38(int a0);
extern void *func_02030DA8(void *a0, void *callback, void *ctx, int a3);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern void  func_02021F64(int a, int b, u16 c, int d, u16 e);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void  func_02082A60(int a, int b, int c);
extern void MIi_CpuCopy16(const void *src, void *dest, u32 size);
extern void func_02064CBC(struct Obj_0 *x);
extern void *func_02049FBC(void *a0, void *a1, u32 a2, void *a3, u32 a4);
extern void *func_0204A03C(void *a0, void *a1, u32 a2, void *a3, u32 a4);
extern void *func_0204A0BC(void *a0, void *a1, u32 a2, void *a3, u32 a4);
extern void *func_0204A13C(void *a0, void *a1, u32 a2, void *a3, u32 a4);
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_02063790(u32 *p);
extern void func_020637D4(u32 *p);
extern void sub_02016028(void *p, u32 flag);
extern void func_02016C60(struct Work *a0, struct Task *a1);
extern void func_02016880(void *a0, struct Obj_02016880 *a1);
extern void func_02016630(struct Ctx *a0, u32 idx, const struct Src *a2);
extern void *func_02049FFC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_0204A07C(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_0204A0FC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_0204A17C(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern void *func_02049DF4(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02063A54(struct Res *r, u32 dst, int mode, struct Out *out);
extern void func_02063E54(void *a, u32 b, int c, u32 d);
extern u32 sub_020307B0(void *p);
extern void sub_02030EAC(struct Node *n);
void func_020160C4(char *p, int v);
u16 func_020160CC(S_0 *s);
void func_020160D4(char *a0, char *a1, u16 a2, int a3);
void func_0201624C(u8 *a0, u8 *a1);
void sub_02016374(void *obj);
void sub_02016380(void *o);
void func_02016394(S_1 *s, int f);
void func_020163B0(char *p, int v);
void func_020163B4(Obj_0 *p, int v);
extern char data_020A72CC[];




/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 */
void func_020160C4(char *p, int v)
{
    ((struct Obj15672 *)p)->f174 = v;
}





/*
 * Unlabelled Thumb leaf in the ARM9 module. Reads the halfword behind the pointer at +0x28.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
u16 func_020160CC(S_0 *s)
{
    return *s->p28;
}





/*
 * mcss.c: builds the per-scene fade/transition context.  Three debug
 * allocations out of the heap named by the u16 at +0x14c (masked to
 * 0x7fff and forced into the 0x8000 bank), then a palette blend and a
 * copy, and finally either a task registration (func_0201691C as the
 * callback, through the owner-aware path or the plain one) or, if the
 * caller has already set the "skip" bit at +0x140, an immediate teardown
 * of everything just allocated.  Either way the done bit 0x10000000 is
 * latched into the same word at +0x140.
 *
 * The three heap ids are recomputed rather than cached: each is a fresh
 * `ldr`+lsls/lsrs of the int field at +0x14c, so the field is an `int`
 * truncated at the call, not a u16 member (see func_02016984 in this
 * same file).  The two __LINE__ pool words 0x761 and 0x769 are the
 * consecutive-line idiom: 0x76e is derived from 0x769 with `adds #5`.
 *
 * Closed in the second pass (2026-09-22) from the 12-byte prologue-spill
 * near miss in docs/notes/func_020160D4.c.txt.  The lever is the THIRD
 * PARAMETER'S TYPE: `u16 a2`, not `int a2`.
 *
 * That note's own list had tried `u16` on a3 (which made it worse, 168
 * bytes) and `u32` on a2, but never `u16` on a2.  tools/permuter.py
 * found it as `type:p(a2:int->u16)` on the 306th compile of a
 * `--mode hill --budget 800 --types` run, taking 12 concrete bytes to 0
 * in one mutation.  A 16-bit parameter arrives already narrowed, so the
 * front end spills it BEFORE it touches the literal pool -- which is
 * exactly the `str r2,[sp,#4]` / `ldr r0,[pc,#0x158]` / `str r3,[sp,#8]`
 * order the note recorded and could not reach.  The note's "untried
 * lever" guess (make a2 reach a call earlier) was not needed.
 *
 * This is also a data point for the family: the value at +0x13C that
 * func_020169E8 hands to func_02021F64 as `(u16)` is 16-bit AT THE
 * PARAMETER here, not only at the call.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020160D4.c \
 *       --func func_020160D4 --addr 0x020160D4 --cc 1.1p1 --thumb
 */
void func_020160D4(char *a0, char *a1, u16 a2, int a3)
{
    char *o;

    o = (char *)func_02030734(
            (u16)(((u16)((struct Obj01093 *)a1)->f14C & 0x7fff) | 0x8000),
            0x2c, 1, (const char *)data_020A72CC, 0x761);

    *(char * *)&((struct Obj01612 *)o)->f20 = a0;
    ((struct Obj01612 *)o)->f28 = (((struct Obj06864 *)a0)->f8 != 0);
    *(char * *)&((struct Obj01612 *)o)->f24 = a1;
    *(char * *)&((struct Obj01612 *)o)->fC = a1 + 0xc0;
    ((struct Obj01612 *)o)->f1C = ((struct Obj06864 *)a0)->f34 + (((struct Obj01093 *)a1)->f148 << 5);

    *(char * *)&((struct Obj01612 *)o)->f4 = (char *)func_02030734(
            (u16)(((u16)((struct Obj01093 *)a1)->f14C & 0x7fff) | 0x8000),
            0x10, 0, (const char *)data_020A72CC, 0x769);

    **(int * *)&((struct Obj01612 *)o)->f4 = ((struct Obj01093 *)a1)->fC0;
    ((struct Obj15676 *)(*(char * *)&((struct Obj01612 *)o)->f4))->f4 = 0;
    ((struct Obj15677 *)(*(char * *)&((struct Obj01612 *)o)->f4))->f8 = ((struct Obj01093 *)a1)->fDC;
    ((struct Obj15678 *)(*(char * *)&((struct Obj01612 *)o)->f4))->fC = (int)func_02030734(
            (u16)(((u16)((struct Obj01093 *)a1)->f14C & 0x7fff) | 0x8000),
            ((struct Obj01093 *)a1)->fDC, 0, (const char *)data_020A72CC, 0x76e);

    func_02021F64(((struct Obj01093 *)a1)->fD4,
                  ((struct Obj15679 *)(*(char * *)&((struct Obj01612 *)o)->f4))->fC,
                  (u16)(((struct Obj01093 *)a1)->fDC / 2),
                  a2, (u16)a3);
    func_02082A60(((struct Obj15680 *)(*(char * *)&((struct Obj01612 *)o)->f4))->fC,
                  ((struct Obj01093 *)a1)->fD8, ((struct Obj01093 *)a1)->fDC);

    if (((struct Obj01093 *)a1)->f8 != 0) {
        func_02016C38(((struct Obj01093 *)a1)->f8);
        ((struct Obj01093 *)a1)->f8 = 0;
    }

    if (((u32)(((struct Obj01093 *)a1)->f140 << 0x13) >> 0x1f) == 0) {
        if (((struct Obj06864 *)a0)->f8 != 0) {
            ((struct Obj01093 *)a1)->f8 = (int)func_02030DA8((void *)((struct Obj06864 *)a0)->f8,
                                             func_0201691C, o, 0);
        } else {
            ((struct Obj01093 *)a1)->f8 = (int)func_020056A0(func_0201691C, o, 0);
        }
    } else {
        func_020307B0((void *)(((struct Obj15681 *)(*(char * *)&((struct Obj01612 *)o)->f4))->fC));
        func_020307B0((void *)(*(int *)&((struct Obj01612 *)o)->f4));
        func_020307B0((void *)((int)o));
    }

    *(int *)&((struct Obj01093 *)a1)->f140 |= 0x10000000;
}







void func_0201624C(u8 *a0, u8 *a1)
{
    struct Obj_0 *p;
    u32 flag;
    void *ret;

    flag = 1;
    p = (struct Obj_0 *)func_02030734((u16)(((u16)((struct Obj01613 *)a1)->f14C & 0x7FFF) | 0x8000), 0x2C, 1, data_020A72CC, 1942);
    p->f20 = a0;
    if (((struct Obj06865 *)a0)->f8 == 0) {
        flag = 0;
    }
    p->f28 = flag;
    p->f24 = a1;
    p->f0c = a1 + 0xC0;
    p->f1c = ((struct Obj06865 *)a0)->f34 + (((struct Obj01613 *)a1)->f148 << 5);

    flag = 0;
    p->f04 = (struct Inner *)func_02030734((u16)(((u16)*((u32 *)(a1 + 0x148) + 1) & 0x7FFF) | 0x8000), 0x10, 0, data_020A72CC, 1950);
    p->f04->f00 = ((struct Obj01613 *)a1)->fC0;
    p->f04->f04 = flag;
    p->f04->f08 = ((struct Obj01613 *)a1)->fDC;

    p->f04->f0c = func_02030734((u16)(((u16)*((u32 *)(a1 + 0x148) + 1) & 0x7FFF) | 0x8000), ((struct Obj01613 *)a1)->fDC, 0, data_020A72CC, 1950 + 5);
    MIi_CpuCopy16(((struct Obj01613 *)a1)->fD4, p->f04->f0c, ((struct Obj01613 *)a1)->fDC);

    if (((struct Obj01613 *)a1)->f8 != 0) {
        func_02016C38((int)(((struct Obj01613 *)a1)->f8));
        ((struct Obj01613 *)a1)->f8 = (void *)flag;
    }

    if (((struct Obj06865 *)a0)->f8 != 0) {
        ret = func_02030DA8(((struct Obj06865 *)a0)->f8, func_0201691C, p, 0);
    } else {
        ret = func_020056A0(func_0201691C, p, 0);
    }
    ((struct Obj01613 *)a1)->f8 = ret;

    *(u32 *)(a1 + (5 << 6)) &= 0xEFFFFFFF;
}







/*
 * A single matched function.
 *
 * alias: an argument-adjusting tail call: it shifts the object pointer to
 * a member 0x34 bytes in and hands off to func_02064CBC. See
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/unit_02016374.c \
 *       --func sub_02016374 --addr 0x02016374 --cc 1.1p1 --thumb
 */
void sub_02016374(void *obj)
{
    func_02064CBC((struct Obj_0 *)((u8 *)obj + 0x34));
}








/*
 * Set bit 0 of the word at +0x144: read, clear, set, write back.  The two
 * `movs r1, #1` are the two separate constants of the `& ~1` / `| 1` pair
 * (Thumb has no ORR immediate, so both go through r1).  Entry attested by
 * the pool word 0x02016381 in sub_020173C8's own pool.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02016380.c \
 *       --func sub_02016380 --addr 0x02016380 --cc 1.1p1 --thumb
 */
void sub_02016380(void *o)
{
    u32 v = ((struct Obj11719 *)o)->f144;

    v = v & ~1u;
    v = v | 1u;
    ((struct Obj11719 *)o)->f144 = v;
}







/*
 * Unlabelled Thumb leaf in the ARM9 module. Sets bit 30 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_02016394(S_1 *s, int f)
{
    s->f = f;
}







/*
 * Unlabelled Thumb leaf in the ARM9 module. Stores a word at +0x48.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_020163B0(char *p, int v)
{
    ((struct Obj15687 *)p)->f48 = v;
}





/*
 * Unlabelled Thumb leaf in the ARM9 module. Sets bit 1 of the flag word at +0x2C.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void func_020163B4(Obj_0 *p, int v)
{
    p->b1 = v;
}




/*
 * The mcss.c bind-slot routine (line 0x840).  Closed in wave 15 from 16
 * bytes out by one declaration: the descriptor parameter is
 * const struct Src *.  Without const, the four constructor call sites
 * load a2 for the first argument before the second; with it the image's
 * order (second-argument base first, then the first, then the out
 * pointer copy) comes out.  History: docs/notes/func_020163C4.c.txt.
 */
void func_020163C4(struct Ctx *a0, u32 idx, const struct Src *a2)
{
    u8 *a1 = (u8 *)a0->f14[idx];
    struct Obj_020163C4 *p;
    u32 h;
    u32 flag;
    u32 *q;

    {
        u32 t;
        if (a2->f20 == 1) {
            t = (u16)(((u16)((struct Obj01018 *)a1)->f14C & 0x7FFF) | 0x8000);
        } else {
            t = ((struct Obj01018 *)a1)->f14C;
        }
        h = (u16)t;
    }

    if (a0->f00 != 0 && a0->f04 == a2->f00) {
        func_02016630(a0, idx, a2);
        return;
    }

    *(u32 *)(a1 + (5 << 6)) &= 0xFFFFDFFF;
    func_02063790((u32 *)(a1 + 0x9C));
    func_020637D4((u32 *)(a1 + 0xC0));

    ((struct Obj01018 *)a1)->fC = func_02049FBC(a2->f00, a2->f0c, 0, a1 + 0x10, h);
    ((struct Obj01018 *)a1)->f1C = func_0204A03C(a2->f00, a2->f10, 1, a1 + 0x20, h);
    flag = 1;
    ((struct Obj01018 *)a1)->f14 = func_0204A0BC(a2->f00, a2->f14, 0, a1 + 0x18, h);
    ((struct Obj01018 *)a1)->f24 = func_0204A13C(a2->f00, a2->f18, 0, a1 + 0x28, h);
    sub_02016028(a1, 0);

    q = func_02048F60((u32)a2->f00, (u32)a2->f1c, h);
    *(u32 * *)&((struct Obj01018 *)a1)->f2C = q;
    *(u32 * *)&((struct Obj01018 *)a1)->f30 = (u32 *)((u8 *)q + ((0x30 * q[0] + 0xC) & ~3u));

    p = (struct Obj_020163C4 *)func_02030734((u16)(((u16)*(u32 *)(a1 + (5 << 6) + 0xC) & (0xFFFFDFFFu >> 0x11)) | (flag << 0xF)),
                                    0x2C, 1, data_020A72CC, 0x840);
    p->f20 = a0;
    if (a0->f08 == 0) {
        flag = 0;
    }
    p->f28 = flag;
    p->f08 = a1 + 0x9C;
    p->f0c = a1 + 0xC0;
    p->f18 = a0->f30 + (idx << 0xE);
    p->f1c = a0->f34 + (idx << 5);
    p->f24 = a1;

    p->f10 = func_02049DB4((u32)a2->f00, (u32)a2->f04, 1, (u32)p,
                           (u16)(((u16)((struct Obj01018 *)a1)->f14C & 0x7FFF) | 0x8000));
    p->f14 = func_02049F34((u32)a2->f00, (u32)a2->f08, (u32)(&p->f04),
                           (u16)(((u16)((struct Obj01018 *)a1)->f14C & 0x7FFF) | 0x8000));

    ((struct Obj01018 *)a1)->fD4 = func_02030734(h,
                                          (u32)((struct Src *)p->f04)->f08, 0,
                                          data_020A72CC, 0x858);
    ((struct Obj01018 *)a1)->fD8 = func_02030734(h,
                                          (u32)((struct Src *)p->f04)->f08, 0,
                                          data_020A72CC, 0x858 + 1);
    ((struct Obj01018 *)a1)->fDC = ((struct Src *)p->f04)->f08;
    MIi_CpuCopy16(((struct Src *)p->f04)->f0c, ((struct Obj01018 *)a1)->fD4,
                  (u32)((struct Src *)p->f04)->f08);

    if (a0->f38 != 0) {
        if (a0->f38((void*)a2, p, a0->f3c) == 1) {
            a0->f38 = 0;
            a0->f3c = 0;
        }
    }
    if (((*(u32 *)(a1 + (5 << 6)) << 4) >> 0x1C) != 0) {
        func_02016C60((struct Work *)a1, (struct Task *)p);
    }
    if (a0->f08 != 0) {
        ((struct Obj01018 *)a1)->f0 = func_02030DA8(a0->f08, func_02016880, p, 0);
    } else {
        ((struct Obj01018 *)a1)->f0 = func_020056A0(func_02016880, p, 0);
    }
}



/*
 * The mcss.c rebind routine (line 0x8AB), twin of func_020163C4.  Closed
 * in wave 15 from 21 bytes out by the same declaration: the descriptor
 * parameter is const struct Src *, which fixes the argument load order
 * at every constructor call site.  History:
 * docs/notes/func_02016630.c.txt.
 */
void func_02016630(struct Ctx *a0, u32 idx, const struct Src *a2)
{
    u8 *a1 = (u8 *)a0->f14[idx];
    void *h;
    struct Obj *p;
    u32 flag;
    u32 *q;

    h = a0->f00;
    *(u32 *)(a1 + (5 << 6)) &= 0xFFFFDFFF;
    func_02063790((u32 *)(a1 + 0x9C));
    func_020637D4((u32 *)(a1 + 0xC0));

    ((struct Obj00696 *)a1)->fC = func_02049FFC(h, (u32)(((struct Src *)a2)->f0c), 0,
                                          (u32)((void *)(a1 + 0x10)),
                                          (u16)*(u32 *)(a1 + (5 << 6) + 0xC));
    ((struct Obj00696 *)a1)->f1C = func_0204A07C(h, (u32)a2->f10, 1, (u32)(a1 + 0x20),
                                          (u16)*(u32 *)(a1 + (5 << 6) + 0xC));
    flag = 1;
    ((struct Obj00696 *)a1)->f14 = func_0204A0FC(h, (u32)a2->f14, 0, (u32)(a1 + 0x18),
                                          (u16)*(u32 *)(a1 + (5 << 6) + 0xC));
    ((struct Obj00696 *)a1)->f24 = func_0204A17C(h, (u32)a2->f18, 0, (u32)(a1 + 0x28),
                                          (u16)*(u32 *)(a1 + (5 << 6) + 0xC));
    sub_02016028(a1, 0);

    q = func_02049250(h, (u32)a2->f1c, (u16)*(u32 *)(a1 + (5 << 6) + 0xC));
    *(u32 * *)&((struct Obj00696 *)a1)->f2C = q;
    *(u32 * *)&((struct Obj00696 *)a1)->f30 = (u32 *)((u8 *)q + ((0x30 * q[0] + 0xC) & ~3u));

    p = (struct Obj *)func_02030734((u16)(((u16)*(u32 *)(a1 + (5 << 6) + 0xC) & (0xFFFFDFFFu >> 0x11)) | (flag << 0xF)),
                                    0x2C, 1, data_020A72CC, 0x8AB);
    p->f20 = a0;
    if (a0->f08 == 0) {
        flag = 0;
    }
    p->f28 = flag;
    p->f08 = a1 + 0x9C;
    p->f0c = a1 + 0xC0;
    p->f18 = a0->f30 + (idx << 0xE);
    p->f1c = a0->f34 + (idx << 5);
    p->f24 = a1;

    p->f10 = func_02049DF4(h, (u32)a2->f04, 1, (u32)p,
                           (u16)(((u16)((struct Obj00696 *)a1)->f14C & 0x7FFF) | 0x8000));
    p->f14 = func_02049F78(h, (u32)a2->f08, (u32)(&p->f04),
                           (u16)(((u16)((struct Obj00696 *)a1)->f14C & 0x7FFF) | 0x8000));

    ((struct Obj00696 *)a1)->fD4 = func_02030734((u16)((struct Obj00696 *)a1)->f14C,
                                          (u32)((struct Src *)p->f04)->f08, 0,
                                          data_020A72CC, 0x8C3);
    ((struct Obj00696 *)a1)->fD8 = func_02030734((u16)((struct Obj00696 *)a1)->f14C,
                                          (u32)((struct Src *)p->f04)->f08, 0,
                                          data_020A72CC, 0x8C3 + 1);
    ((struct Obj00696 *)a1)->fDC = ((struct Src *)p->f04)->f08;
    MIi_CpuCopy16(((struct Src *)p->f04)->f0c, ((struct Obj00696 *)a1)->fD4,
                  (u32)((struct Src *)p->f04)->f08);

    if (a0->f38 != 0) {
        if (a0->f38((void *)a2, p, a0->f3c) == 1) {
            a0->f38 = 0;
            a0->f3c = 0;
        }
    }
    if (((*(u32 *)(a1 + (5 << 6)) << 4) >> 0x1C) != 0) {
        func_02016C60((struct Work *)a1, (struct Task *)p);
    }
    if (a0->f08 != 0) {
        ((struct Obj00696 *)a1)->f0 = func_02030DA8(a0->f08, func_02016880, p, 0);
    } else {
        ((struct Obj00696 *)a1)->f0 = func_020056A0(func_02016880, p, 0);
    }
}


void func_02016880(void *a0, struct Obj_02016880 *a1)
{
    if (a1->f28 == 0) {
        u32 v = *(volatile u16 *)0x04000006;

        if (v < 0xc0 || v > 0xc8)
            return;
    }
    if (a1->f10 != 0) {
        func_02063A54(a1->f00, a1->f18, 0, (struct Out *)a1->f08);
        sub_020307B0(a1->f10);
        if (((a1->f24[0x140 / 4] << 4) >> 0x1c) == 0) {
            a1->f10 = 0;
            return;
        }
    }
    if (a1->f24 != 0)
        a1->f24[0x140 / 4] |= 0x2000;
    if (a1->f14 != 0) {
        func_02063E54(a1->f04, a1->f1c, 0, a1->f0c);
        sub_020307B0(a1->f14);
    }
    if (a1->f24 != 0)
        a1->f24[0] = 0;
    if (a1->f20 != 0 && a1->f20->f0c != 0)
        a1->f20->f0c = 0;
    sub_020307B0(a1);
    sub_02030EAC(a0);
}
