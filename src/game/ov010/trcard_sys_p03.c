/*
 * file:     trcard_sys_p03.c
 * unit:     yes
 * function: func_0216E910, func_0216E95C, func_0216EAB0, func_0216EB98, func_0216EDFC, func_0216EE20, func_0216EE40, func_0216EE7C, func_0216EF84, func_0216EFA8, func_0216EFCC, func_0216EFDC, func_0216EFF0, func_0216F02C, func_0216F054, func_0216F064, func_0216F070
 * address:  0x0216E910
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
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AAABC  0x021AAABC  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02013090  0x02013090  thumb
 *   func_0201A920  0x0201A920  thumb
 *   func_020173EC  0x020173EC  thumb
 *   func_02030734  0x02030734  arm
 *   func_0201756C  0x0201756C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_021AA304  0x021AA304  thumb  ov021
 *   func_020135C0  0x020135C0  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_021CF5D8  0x021CF5D8  thumb
 *   d_02172B54     0x02172B54  data
 *   func_02012FD8  0x02012FD8  thumb
 *   func_0216E818  0x0216E818  thumb  ov010
 *   sub_0200E740   0x0200E740  thumb
 *   sub_020124E8   0x020124E8  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   sub_0200E788   0x0200E788  thumb
 *   sub_0200E74C   0x0200E74C  thumb
 *   sub_0200E7B4   0x0200E7B4  thumb
 *   sub_0200E7A4   0x0200E7A4  thumb
 *   func_02017588  0x02017588  thumb
 *   sub_0200E76C   0x0200E76C  thumb
 *   sub_0200E780   0x0200E780  thumb
 *   sub_0200E7AC   0x0200E7AC  thumb
 *   func_020178D8  0x020178D8  thumb
 *   func_02017FA8  0x02017FA8  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012374  0x02012374  thumb
 *   func_0201235C  0x0201235C  thumb
 *   func_02012444  0x02012444  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_02012F20  0x02012F20  thumb
 *   func_02012F50  0x02012F50  thumb
 *   func_0201447C  0x0201447C  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_02029B28  0x02029B28  thumb
 *   func_02029BCC  0x02029BCC  thumb
 *   func_02029C00  0x02029C00  thumb
 *   func_02029CC0  0x02029CC0  thumb
 *   func_0202E79C  0x0202E79C  thumb
 *   func_0202E80C  0x0202E80C  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_02011D34  0x02011D34  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0215F6E8  0x0215F6E8  thumb  ov010
 *   func_02168D30  0x02168D30  thumb  ov010
 *   func_0216E680  0x0216E680  thumb  ov010
 *   func_0216F07C  0x0216F07C  thumb  ov010
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021882DC  0x021882DC  arm  ov230d
 *   func_02188354  0x02188354  arm  ov230d
 *   func_02188390  0x02188390  arm  ov230d
 *   func_021CF498  0x021CF498  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   ov093_id       0x0000005D  data
 *   ov092_id       0x0000005C  data
 *   ov230_id       0x000000E6  data
 *   d_021EFDAC     0x021EFDAC  data  ov093
 *   d_021B9D94     0x021B9D94  data  ov092
 *   g_0214624C     0x0214624C  data
 *   func_0202A230   0x0202A230  thumb
 *   func_0202A3FC   0x0202A3FC  thumb
 *   d_021725C0     0x021725C0  data
 *   func_0201313C  0x0201313C  thumb
 *   func_0216505C  0x0216505C  thumb  ov010
 *   func_02165078  0x02165078  thumb  ov010
 *   func_021653F4  0x021653F4  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   func_0201AB18  0x0201AB18  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_021654AC  0x021654AC  thumb  ov010
 *   func_02165424  0x02165424  thumb  ov010
 *   func_02165468  0x02165468  thumb  ov010
 *   func_021654F0  0x021654F0  thumb  ov010
 *   func_02045808  0x02045808  arm
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   d_021725D8  0x021725D8  data  ov010  a1
 *   d_021725B8     0x021725B8  data
 *   func_02012A4C 0x02012A4C thumb
 *   func_0215E5B0 0x0215E5B0 thumb ov010
 *   func_020127A4 0x020127A4 thumb
 *   func_02012AC8 0x02012AC8 thumb
 *   func_0202C83C 0x0202C83C thumb
 *   func_02082A7C 0x02082A7C arm
 *   func_020130B4  0x020130B4  thumb
 *   func_0203F0A8  0x0203F0A8  arm
 */
#include "../../matched/include/Obj00020.h"
#include "../../matched/include/Obj12059.h"
#include "../../matched/include/Obj19144.h"
#include "../../matched/include/Obj12060.h"

struct Work;
struct Desc;
struct Obj;
struct Ctx;
struct Party;
struct PartyMon;
struct Info;
struct BigObj;
struct Evt;
struct Record;
struct Result;
struct S0201235C;
struct Sub02014444Obj;
struct U16Vec;
struct Sub02008C20Obj;
struct Rec44;
struct SaveBlock;
struct BattleEndCtx;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned long long u64;

typedef struct Loc {
    u32 f00;            /* 0x00 */
    u32 f04;            /* 0x04 */
    u8 pad08[8];
} Loc;

typedef struct Holder {
    u8 pad00[0x18];
    u8 f18[4];          /* 0x18 */
} Holder;

typedef struct Work_0216E95C {
    u8 pad00[8];
    Holder *f08;        /* 0x08 */
    u8 pad0C[0x14 - 0x0C];
    u32 f14;            /* 0x14 */
    u8 pad18[0x24 - 0x18];
    u32 f24;            /* 0x24 */
} Work_0216E95C;

typedef u32 (*TaskFn)(void *task, u32 *state, Work_0216E95C *work);

typedef signed int s32;

typedef struct Info {
    u8 pad00[0x18];
    u16 f18;            /* 0x18 */
} Info;

typedef struct Work_0216EB98 {
    void *sys;          /* 0x00 */
    void *f04;          /* 0x04 */
    Info *f08;          /* 0x08 */
    void *f0c;          /* 0x0C */
    Info *f10;          /* 0x10 */
    u32 f14;            /* 0x14 */
    u32 f18;            /* 0x18 */
    u32 f1c;            /* 0x1C */
    u8 pad20[4];
    void *f24;          /* 0x24 */
} Work_0216EB98;

typedef void (*IdHandler)(u16 id);

typedef struct BattleEnd {
    u32 mode;           /* 0x00 */
    u8 pad04[0x48];
    u32 *result;        /* 0x4C */
    u8 pad50[0x3C];
    u32 outcome;        /* 0x8C */
} BattleEnd;

typedef struct BattleEndCtx {
    u32 f00;
    void *sys;          /* 0x04 */
    BattleEnd *st;      /* 0x08 */
} BattleEndCtx;

extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern u32 func_02188CE8(u8 *p);
extern void func_021AAABC(int s);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02013090(u32 heap);
extern void *func_0201A920(u16 heap);
extern u32 func_020173EC(void);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern void func_0201756C(void *mon, u16 species, u16 level, u64 id);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void func_021AA304(struct Info *out, void *a1, void *a2);
extern void func_020135C0(void *bs, void *ctx, void *p1, void *p2, Loc *loc, u32 heap);
extern u32 func_020307B0(void *p);
extern void func_021CF5D8(u16 species, u32 a, u32 b, u32 c, u32 *d, void *e);
extern void *func_02012FD8(void **p);
extern int func_0216E818(int a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern u32   sub_0200E740(const void *obj, u32 idx);
extern void *sub_020124E8(struct Obj *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32   func_02017E1C(void *p, u32 id, u32 v);
extern u32   sub_0200E788(const void *obj, u32 a, u32 b);
extern u32   sub_0200E74C(const void *obj, u32 idx);
extern u32   sub_0200E7B4(const void *obj, u32 idx);
extern u32   sub_0200E7A4(const void *obj, u32 idx);
extern void  func_02017588(void *p, u16 species, u32 level, u64 id, u32 pow, u64 rnd);
extern u32   sub_0200E76C(const void *obj, u32 idx);
extern u8    sub_0200E780(const void *obj, u32 idx);
extern void *sub_0200E7AC(void *obj, u32 idx);
extern void func_020178D8(void *p, u32 a);
extern u32   func_02017FA8(void *p);
extern void *func_0201210C(const struct Ctx *p);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_0201235C(struct S0201235C *o, u32 *out);
extern void func_02012444(struct Obj *obj, u32 a1, u32 a2, u32 a3);
extern void *func_02012B38(const struct BigObj *p);
extern int func_02012F20(int p0);
extern void *func_02012F50(void *base);
extern u8 func_0201447C(struct Sub02014444Obj *o, u8 v);
extern int func_020144DC(int a0, int a1);
extern void *func_020145CC(void *sys);
extern void *func_02029B28(void *a, u16 b);
extern void *func_02029BCC(void *a, u32 b);
extern void *func_02029C00(void *a);
extern void *func_02029CC0(void *a);
extern void func_0202E79C(u8 *p);
extern void func_0202E80C(u32 *p);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
extern void *func_020056A0(void (*callback)(void *, void *), void *work, u32 key);
extern void func_02011D34(void);
extern void *func_0215F6E8(void *sys);
extern void func_02168D30(struct Record *r, struct Result *s);
extern int func_0216E680(int a0);
extern int func_0216F07C(int a0);
extern int func_02189A08(unsigned char *p);
extern u32 func_021882DC(void (*a)(void), void (*b)(void), u32 c);
extern u32 func_02188354(void (*a)(void), void (*b)(void), u32 c);
extern u32 func_02188390(void (*a)(void), void (*b)(void), u32 c);
extern void func_021CF498(struct Ctx *c, u32 x, int idx);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern u32 func_0202A230(void *a, u32 idx);
extern u8 func_0202A3FC(u32 key);
extern void *func_0201313C(void *p, int i);
extern int func_0216505C(int a0);
extern int func_02165078(int a0);
extern void func_021653F4(u16 species);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AB18(void *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_021654AC(void *name);
extern void func_02165424(void *name);
extern void func_02165468(void *name);
extern void func_021654F0(void *name);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02012F2C(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern void func_02012A4C(struct BigObj *p, u32 v);
extern void func_0215E5B0(void *a0, struct Work *w);
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern int func_0202C83C(int,int);
extern void func_02082A7C(int,void *,int);
extern int func_020130B4(int a0);
extern u32 func_0203F0A8(void);
int func_0216E910(void *a0, void *a1, void *a2);
void *func_0216E95C(void *sys, u32 arg, u32 heap);
void *func_0216EAB0(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 idx);
int func_0216EB98(void *evt, u32 *state, Work_0216EB98 *w);
int func_0216EDFC(void *a0);
void func_0216EE20(u16 id, int col);
void func_0216EE40(void *p, int which);
void func_0216EE7C(BattleEndCtx *c);
int func_0216EF84(int a0);
int func_0216EFA8(int a, int b);
u8 func_0216EFCC(int i);
int func_0216EFDC(int *w);
void func_0216EFF0(int *p,void *a);
void func_0216F02C(void **p,void *a,void *b);
int func_0216F054(int a0);
int func_0216F064(int a0);
int func_0216F070(int a0);
extern const char d_02172B54[];
extern u8 ov093_id[];
extern u8 ov092_id[];
extern u8 ov230_id[];
extern u8 d_021EFDAC[];
extern u8 d_021B9D94[];
extern u32 g_0214624C;
extern const IdHandler d_021725C0[][2];
extern u8 d_021725D8[][5];
extern u8 d_021725B8[];


int func_0216E910(void *a0, void *a1, void *a2)
{
    int h;
    int *t;

    h = (int)func_020122C0((void *)a0, 0, func_0216EB98, 0x28);
    t = func_020124E8((struct Obj *)h);
    func_0216F02C((void **)t, (void *)a0, (void *)a2);
    t[5] = 0;
    t[7] = 1;
    t[6] = 1;
    t[9] = 9;
    *(u16 *)((char *)t[2] + 0x18) = 0x46b;
    func_021AAABC(func_02188CE8((u8 *)a1));
    return h;
}


/*
 * Set up the scripted catching-tutorial battle (Minccino Lv7 against
 * Patrat Lv2) and push func_0216EB98 as its task. First draft.
 */
void *func_0216E95C(void *sys, u32 arg, u32 heap)
{
    Loc loc;
    u16 h;
    void *ctx;
    void *bs;
    void *party1;
    void *party2;
    void *mon;
    void *task;
    Work_0216E95C *w;

    h = (heap & 0x7FFF) | 0x8000;
    ctx = func_020120F4(sys);
    bs = func_02013090(heap);
    party1 = func_0201A920(h);
    party2 = func_0201A920(h);
    mon = func_02030734(h, func_020173EC(), 1, d_02172B54, 0x1DA);
    func_0201756C(mon, 572, 7, 0);
    func_02017E40(mon, 0x36, 1);
    func_02017E40(mon, 0x37, 45);
    func_02017E40(mon, 0x38, 0);
    func_02017E40(mon, 0x39, 0);
    func_0201A98C(party1, mon);
    func_0201756C(mon, 504, 2, 0);
    func_02017E40(mon, 0x36, 33);
    func_02017E40(mon, 0x37, 43);
    func_02017E40(mon, 0x38, 0);
    func_02017E40(mon, 0x39, 0);
    func_0201A98C(party2, mon);
    func_021AA304((struct Info *)(&loc), ctx, (void *)arg);
    loc.f04 = 5;
    loc.f00 = 0;
    func_020135C0(bs, ctx, party1, party2, &loc, heap);
    func_020307B0(mon);
    func_020307B0(party2);
    func_020307B0(party1);
    task = func_020122C0(sys, 0, func_0216EB98, 0x28);
    w = func_020124E8(task);
    func_0216F02C((void **)w, sys, bs);
    w->f14 = 1;
    func_021CF5D8(504, 5, 0, arg, &w->f24, w->f08->f18);
    w->f24 = 0;
    return task;
}


/*
 * Every concrete byte matches; the one wildcard is the bl to 0x02012FD8, an
 * unlabelled 12-byte arm9 Thumb leaf (ldr r0,[r0]; tail call
 * func_020071CC(r0, 0x43)) with no label, no shard and so no witness.
 * as `void *func_02012FD8(void **p) { return func_020071CC(*p, 0x43); }`
 * (symbols: func_020071CC 0x020071CC thumb), which is outside an overlay
 * lane's write set; once it has a shard this file should verify EXACT.
 *
 * The level argument to func_02017588 is passed untruncated here, so its
 * extern takes u32 level rather than the u16 other callers declare.
 */
void *func_0216EAB0(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 idx)
{
    void *data;
    void *task;
    void *mon;
    u32 old;
    u32 species;
    u32 level;
    u32 id;
    u32 rnd;

    data = func_02012FD8(func_020120F4(a0));
    task = (void *)func_0216E818((int)a0, a1, a2, a3, a4, a5, a6);
    if (sub_0200E740(data, idx) != 0) {
        mon = func_0201AB28(*(void **)(*(u8 **)((u8 *)sub_020124E8(task) + 8) + 0x28), 0);
        old = func_02017E1C(mon, 5, 0);
        species = sub_0200E788(data, idx, 0x15);
        level = sub_0200E74C(data, idx);
        id = sub_0200E7B4(data, idx);
        rnd = sub_0200E7A4(data, idx);
        func_02017588(mon, species, level, id, -1, rnd);
        if (sub_0200E76C(data, idx) != 0) {
            func_02017E40(mon, 10, sub_0200E780(data, idx));
        }
        func_02017E40(mon, 0x74, (u32)sub_0200E7AC(data, idx));
        func_020178D8(mon, (u16)old);
        func_02017FA8(mon);
    }
    return task;
}


/*
 * lever:    case 1's argument-less `bl func_02189A08` takes proc (the
 *           func_0201210C result) as its hidden r0 argument: the matched
 *           ov021 definition is int func_02189A08(unsigned char *p). That
 *           keeps proc in r0 through the dispatch, the index in r1 and the
 *           r2 copy of proc for cases 2 and 10 (457 -> 2 bytes). The ov230
 *           probe calls resolve with the `ov230d` token, prototypes copied
 *           from the matched twin src/matched/arm9/func_02011D9C.c.
 * residue:  case 7 zeroes its spilled `ok` (sp+0xC) through r2 in the image
 *           (`movs r2,#0; str r2,[sp,#0xc]` at 0x0216ECCC), r0 in the compile.
 *           No change from ok as u32, u8, enum, function-scope, passed as the
 *           seed, or with start/end locals ahead of it; permuter 300 found
 *           nothing (baseline agrees, DIFF 2/612).
 *           unlabelled: `ldr r1,[r0]; str r1,[r0,#8]; movs r1,#0; str
 *           r1,[r0]; bx lr`, verified C not filed: arm9 is Ilias's);
 *           0x0216EFDC (ov010 unlabelled tail-call leaf, not filed while an
 *           arm9 leaf blocks); ov093_id/ov092_id pooled ids passed to
 *           func_02012444, which is not in OVERLAY_ID_CONSUMERS;
 *           d_021EFDAC/d_021B9D94 (proc data of ov093/ov092) unwitnessed.
 * prototype conflicts (parked, matched callees not edited):
 *           func_0216F054 (ov010 0x0216F054, src/matched/ov/func_0216F054.c)
 *           is defined int(int a0, int a1) but a1 is overwritten before any
 *           read (`ldr r1,[r0,#0x20]` at 0x0216F054); the three call sites
 *           here set only r0 (`adds r0, r5, #0; bl`). func_02012F20 (arm9,
 *           src/matched/arm9/func_02012F20.c) is defined int(int p0..p3) and
 *           reads only p0; both sites here set only r0 (`ldr r0,[sp,#0x10];
 *           bl`). The C below declares both with one parameter.
 * runs:     4 iteration + checks (2 + 2 + 1) + permuter 300; one cleanup run.
 * checks:   1 every callee re-derived from its matched definition: func_02189A08 takes the live proc in r0 (fixed), F054/2F20 definitions over-declare (conflict above); 2 twin func_02011D9C gives the ov230d probe tokens and prototypes (resolved 3 sites), u32 start local no change; 3 ok as u32 / enum no change; 4 u8 flag idiom (a-narrow-flag-local-is-spilled) no change, zero-register idioms read; 5 idioms re-listed, nothing new applies
 * note:     2026-10-05 wave P19 lane 6 recoup: byte-correct (612/612, 0 bytes off).
 *           Lever: case 7 writes ok in both arms (`if (probe == ~f) ok = 1; else ok = 0;`
 *           with `int ok;` uninitialised), which moves the spilled zero to r2 (was r0,
 *           2 bytes). Tried before it: six per-function pragmas (lifetimes 14 B, the rest
 *           2 B), function-scope ok, ok as the probe seed or a separate zero local, probe
 *           result in a local (3 B), ternary sum (258 B). Data words resolve with
 *           `data ov093` / `data ov092` tokens. Leaf witnesses filed:
 *           src/matched/arm9/func_0202E80C.c and src/matched/ov/ov010_func_0216EFDC.c (both
 *           EXACT c99 and c); the three unresolved call sites resolve once the integrator
 *           refreshes the manifest. Callee arity conflicts (matched definitions
 *           over-declare, callers pass less): func_0216F054 and func_02012F20.
 */
int func_0216EB98(void *evt, u32 *state, Work_0216EB98 *w)
{
    void *sys = w->sys;
    void *p04 = w->f04;
    void *proc = func_0201210C(sys);
    u32 sum = 0x013A1AB5;

    switch (*state) {
    case 0:
        func_02012374(evt, func_02029BCC(sys, w->f08->f18));
        (*state)++;
        break;
    case 1:
        func_021CF498((void *)func_02189A08(proc), (u32)evt, (int)w->f24);
        (*state)++;
        break;
    case 2:
        func_02012374(evt, (void *)func_020144DC((int)sys, (int)proc));
        (*state)++;
        break;
    case 3:
        func_0201447C(func_02012B38(p04), 1);
        func_0202E79C((u8 *)func_02012F20((int)p04));
        func_02012444(evt, (u32)ov093_id, (u32)d_021EFDAC, (u32)w->f08);
        (*state)++;
        break;
    case 4:
        w->f10 = w->f08;
        w->f0c = p04;
        func_02012444(evt, (u32)ov092_id, (u32)d_021B9D94, (u32)&w->f0c);
        (*state)++;
        break;
    case 5:
        func_02034AC4((s32)ov230_id);
        func_0201447C(func_02012B38(p04), 0);
        func_0202E80C((void *)func_02012F20((int)p04));
        (*state)++;
        break;
    case 6: {
        int ok = 0;

        if (func_021882DC((void (*)(void))func_0216E680, (void (*)(void))func_0216F064, 0) == ~(u32)func_0216F064)
            ok = 1;
        sum += ok ? 0 : 0x3D1;
        func_0216EFF0((int *)w, p04);
        if (w->f1c != 0)
            func_02168D30(*(void **)func_02012F50(p04), (struct Result *)w->f08);
        (*state)++;
        ok = 0;
        if (func_02188354((void (*)(void))func_0216E680, (void (*)(void))func_0216F070, 0) == ~(u32)func_0216F070)
            ok = 1;
        sum += ok ? 0 : 0x5D1;
        break;
    }
    case 7: {
        int ok;

        if (func_02188390((void (*)(void))func_0216E680, (void (*)(void))func_0216F07C, 0) == ~(u32)func_0216F07C)
            ok = 1;
        else
            ok = 0;
        sum += ok * 0x9D;
        if (w->f18 == 0 && func_0216EFDC((int *)w) == 1)
            func_02012374(evt, func_02029B28(sys, 0x1E));
        else
            func_02012374(evt, func_02029C00(sys));
        func_02034A5C((s32)ov230_id);
        (*state)++;
        break;
    }
    case 8:
        if (w->f18 == 0 && func_0216EFDC((int *)w) == 1) {
            if (w->f14 == 1) {
                func_0216F054((int)w);
                return 1;
            }
            func_0216F054((int)w);
            func_0201235C(evt, func_0215F6E8(sys));
            return 0;
        }
        func_02012374(evt, func_020145CC(sys));
        (*state)++;
        break;
    case 9:
        func_02012374(evt, func_02029CC0(sys));
        (*state)++;
        break;
    case 10:
        if (w->f14 == 0)
            func_02012374(evt, (void *)func_021BE92C(sys, (int)proc, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 11:
        func_0216F054((int)w);
        return 1;
    }
    if (sum % 0x1933 != 0) {
        func_020056A0((void (*)(void *, void *))func_02011D34, 0, 0x7F);
        g_0214624C++;
    }
    return 0;
}


/*
 * Mode word out of the overlay call decides between zero, one and two;
 * two of the modes are refused outright.
 */
int func_0216EDFC(void *a0)
{
    int r = 1;
    int v;

    v = func_0202A3FC(func_0202A230(a0, 1));

    if (v == 0xC || v == 9)
        return 0;
    if (v != 2)
        r = 2;

    return r;
}


/*
 * Dispatches through the two-column handler table d_021725C0, row chosen
 * by func_0216EDFC's classification of `id`.
 */
void func_0216EE20(u16 id, int col)
{
    d_021725C0[func_0216EDFC((void *)id)][col](id);
}


/*
 * Reports the species of the first party member to one of three
 * notifiers.
 *
 * MATCH, first draft (2026-09-28 tree_ov010_4): the one wildcard is arm9
 * 0x0201313C, an unlabelled Thumb leaf (`lsls r1, #2; adds r0, r1;
 * ldr r0, [r0, #0x24]; bx lr`) inside the listing's ARM data run.
 *
 * 2026-10-05: byte-identical; the wildcard is arm9 func_0201313C (matched file exists, no shard yet); integrator shard resolves it.
 */
void func_0216EE40(void *p, int which)
{
    u16 species;

    species = func_02017E1C(func_0201AB28(func_0201313C(p, 1), 0), 5, 0);
    switch (which) {
    case 0:
        func_0216505C(species);
        break;
    case 1:
        func_02165078(species);
        break;
    case 2:
        func_021653F4(species);
        break;
    }
}


/*
 * After a battle: unless the outcome is 0 or 2, reports the lead party
 * member's state (fainted, at half HP or less, a move out of PP, a status
 * condition) by name, then reports the species depending on the mode and
 * outcome.
 */
void func_0216EE7C(BattleEndCtx *c)
{
    BattleEnd *st;
    void *party;
    void *mon;
    void *name;
    u16 hp;
    u16 maxHp;
    int i;

    st = c->st;
    party = func_02012934(c->sys);
    mon = func_0201AB28(party, func_0201AB18(party));
    if (st->outcome != 0 && st->outcome != 2) {
        name = func_020457B0(12, 0x8004);
        func_02017E1C(mon, 0x73, (u32)name);
        hp = func_02017E1C(mon, 0xA0, 0);
        maxHp = func_02017E1C(mon, 0xA1, 0);
        if (hp == 0)
            func_021654AC(name);
        else if (hp * 2 <= maxHp)
            func_02165424(name);
        for (i = 0; i < 4; i++) {
            if (func_02017E1C(mon, 0x36 + i, 0) != 0 && func_02017E1C(mon, 0x3A + i, 0) == 0) {
                func_02165468(name);
                break;
            }
        }
        if (func_02017E1C(mon, 0x9D, 0) != 0)
            func_021654F0(name);
        func_02045808(name);
    }
    switch (st->mode) {
    case 0:
        if (st->outcome == 3)
            func_0216EE40(st, 2);
        else if (st->outcome == 1)
            func_0216EE40(st, 1);
        break;
    case 1:
        if (st->outcome == 1)
            func_0216EE20(*st->result, 1);
        break;
    }
}


int func_0216EF84(int a0)
{
    int a1;
    int t4;
    void *p;

t4 = *(int *)&((struct Obj00020 *)a0)->f8;
a0 = ((struct Obj00020 *)((char *)a0))->f0;
    p = func_020120F4((const struct Ctx *)a0);
loc_0216EF8E:
    a0 = (int)func_02012F2C(p);
loc_0216EF92:
a1 = ((struct Obj12059 *)((char *)t4))->f0;
    if (a1 != 0) goto loc_0216EFA6;
loc_0216EF98:
t4 = t4 + 0x8c;
a1 = ((struct Obj12059 *)((char *)t4))->f0;
    if (a1 != 4) goto loc_0216EFA6;
loc_0216EFA0:
a1 = 0x4f;
    a0 = func_02008DF0((struct Sub02008C20Obj *)a0, a1);
loc_0216EFA6:
    return a0;}


int func_0216EFA8(int a, int b)
{
    if (b == 4)
        return 0;
    if (d_021725D8[a][b] == 0)
        return 1;
    return 0;
}


/*
 * Unlabelled leaf, blocker of ov021 func_021B50D0: byte table lookup, 0xFF maps to 1.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
u8 func_0216EFCC(int i)
{
    u8 v = d_021725B8[i];

    if (v == 0xff) {
        v = 1;
    }
    return v;
}


/*
 * note:     2026-10-05 wave P19 lane 6: tiny unlabelled tail-call leaf filed as
 *           the witness for the calls in ov010 func_0216EB98. Reads the info
 *           block at w[2] and tail-calls func_0216EFA8(info[0x8c / 4], info[0]).
 */
int func_0216EFDC(int *w)
{
    int *q = (int *)w[2];
    return func_0216EFA8(q[0x8c / 4], q[0]);
}

/*
 * func_0202C83C's body consumes only r0/r1, forwarding those to
 * func_0202C794; original supplies no new r2/r3. Legacy trailing
 * arguments are omitted. func_02012AC8 consumes the preceding result.
 */
void func_0216EFF0(int *p,void *a) {
    func_02012A4C(a,((struct Obj19144 *)(*(char * *)&((struct Obj00020 *)p)->f8))->f8C);
    func_0215E5B0(a,(void *)p[2]);
    func_0216EE7C((struct BattleEndCtx *)p);
    func_0216EF84((int)p);
    func_0202C83C(p[0],func_02012AC8(func_020127A4(a)));
}

void func_0216F02C(void **p,void *a,void *b) { int zero=0; func_02082A7C(0,p,40); p[0]=a; p[1]=func_020120F4(a); p[2]=b; p[5]=(void *)zero; p[6]=(void *)zero; p[7]=(void *)zero; }


int func_0216F054(int a0)
{
    int a1;

a1 = ((struct Obj12060 *)a0)->f20;
    if (a1 != 0) goto loc_0216F062;
loc_0216F05C:
a0 = ((struct Obj12060 *)a0)->f8;
    a0 = func_020130B4(a0);
loc_0216F062:
    return a0;}


int func_0216F064(int a0)
{

    a0 = func_0203F0A8();
loc_0216F06A:
    a0 = func_0203F0A8();
loc_0216F06E:
    return a0;}


int func_0216F070(int a0)
{

    a0 = func_0203F0A8();
loc_0216F076:
    a0 = func_0203F0A8();
loc_0216F07A:
    return a0;}
