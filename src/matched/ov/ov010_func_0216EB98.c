/*
 * function: func_0216EB98
 * address:  0x0216EB98
 * packet:   pkt_ov010_0216EB98
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
 * blocker:  even byte-correct this caps at MATCH: 0x0202E80C (arm9, Thumb,
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
 *
 * symbols:
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
 *   func_0216EFDC  0x0216EFDC  thumb  ov010
 *   func_0216EFF0  0x0216EFF0  thumb  ov010
 *   func_0216F054  0x0216F054  thumb  ov010
 *   func_0216E680  0x0216E680  thumb  ov010
 *   func_0216F064  0x0216F064  thumb  ov010
 *   func_0216F070  0x0216F070  thumb  ov010
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
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct Info {
    u8 pad00[0x18];
    u16 f18;            /* 0x18 */
} Info;

typedef struct Work {
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
} Work;

extern u8 ov093_id[];
extern u8 ov092_id[];
extern u8 ov230_id[];
extern u8 d_021EFDAC[];
extern u8 d_021B9D94[];
extern u32 g_0214624C;

struct BigObj;
struct Ctx;
struct Evt;
struct Obj;
struct Record;
struct Result;
struct S0201235C;
struct Sub02014444Obj;
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
extern int func_0216EFDC(int *w);
extern void func_0216EFF0(int *p, void *a);
extern int func_0216F054(int a0);
extern int func_0216E680(int a0);
extern int func_0216F064(int a0);
extern int func_0216F070(int a0);
extern int func_0216F07C(int a0);
extern int func_02189A08(unsigned char *p);
extern u32 func_021882DC(void (*a)(void), void (*b)(void), u32 c);
extern u32 func_02188354(void (*a)(void), void (*b)(void), u32 c);
extern u32 func_02188390(void (*a)(void), void (*b)(void), u32 c);
extern void func_021CF498(struct Ctx *c, u32 x, int idx);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);

int func_0216EB98(void *evt, u32 *state, Work *w)
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
