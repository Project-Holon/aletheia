/*
 * function: func_021F41A8
 * address:  0x021F41A8
 * packet:   pkt_ov039_021F41A8
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * note:     2026-10-04 wave D3 lane 04: complete draft, same size (1128 bytes); the only
 *           residue is two swapped instructions in case 5 (+01B2): the original stores
 *           s->hold = c (strb r6,[r4,#7]) right after the func_021BE674 call and then sets
 *           r1 = 1; the draft sets r1 = 1 first. Tried: the store before the call (it lands
 *           before the call), a comma expression inside the argument, a fresh u8 * local
 *           for the call result. Levers that closed other residues here: q declared before j
 *           (stack slots 8/0xc), f2 declared before k (r4/r5), u8 vol, a u8 index local in
 *           case 6, the range test written (u8)(s->sel + 0xFE) <= 3.
 *           2026-10-05 wave D4 lane 12: still the same 4 bytes. Tried: hold as u8 instead of s8
 *           (worse, recolours r4/r6 from +0x86). The store and the movs r1,#1 are independent;
 *           the original keeps source order there. Also tried a static inline helper that
 *           does the 674 call and the store and returns p (same 4 bytes).
 *           2026-10-05 wave D5 lane 13: still 4 bytes. Tried: the store as a comma
 *           expression on either argument of func_021BE6B0 (same 4), the whole call nested
 *           with the comma on the second argument (20), s->hold = j (688), u8/u32/short as
 *           the func_021BE6B0 second parameter (same 4).
 *           2026-10-05 wave D6 lane 15: still 4 bytes. Tried: volatile s8 hold (same 4),
 *           the 1 held in a local n set after the store (same 4), c as u32 (same 4), c as u8 (882),
 *           c as s8 (1024). The scheduler always puts movs r1,#1 above the strb.
 *           2026-10-05 wave D7 lane 13: still 4 bytes. Tried: n = 1 set before the
 *           func_021BE674 call and passed as the argument (same 4), the store through a raw
 *           `*(s8 *)((u8 *)s + 7) = c` (same 4), the whole case-5 pair as one nested call with
 *           the comma on the second argument and p assigned in the first (20). Callee heads
 *           read no extra argument registers. The residue is only the order of two independent
 *           instructions after the bl; no source shape tried so far moves it.
 *           2026-10-05 wave D8 lane 02: still 4 bytes. Checked: no branch targets the movs r1,#1
 *           at +01B4 (021F435C), so the strb and the movs are in one scheduled block; the residue
 *           is the scheduler tie-break only. Tried: func_021BE6B0 unprototyped (K&R call), same 4.
 *           2026-10-05 wave D9 lane 15: still 4 bytes. Tried: s->hold = s->sel >> 1 (689, the shift is not
 *           CSE'd with c), s->hold = j (688). No source form tried so far moves the strb above the movs.
 *
 *           2026-10-05 wave D9r lane 17: still 4 bytes. Fresh reading: both the strb and the movs r1,#1 feed
 *           only the bl, so a list scheduler with equal heights keeps IR order; ours must see the 1 before the
 *           store. Tried: sel/hold as u32 bitfields (sel:8, pad:16, signed hold:8) to change the store node:
 *           1092 (read-modify-write stores). No new source form found; left DIFF.
 *           2026-10-05 wave D9r lane 31: still 4 bytes. Tried: a static inline Pick(s, p, c) that does
 *           `s->hold = c; func_021BE6B0(p, 1);` (c as int and as s8 parameter): same 4, movs r1,#1 still above
 *           the strb. Left DIFF.
 *           2026-10-05 wave D9r lane 37: still 4 bytes. Tried: the store as `((u8 *)s)[7] = c` (the
 *           matched caller ov039 021F404C writes s[7] = c on a u8 pointer): same 4; a label (and a goto to
 *           it) between the store and the call, to test a block split: same 4 (mwcc merges the blocks).
 *           Searched matched code for a twin with the same case-5 sequence (as ov177 021E5A30 closed from
 *           its ov068 twin): ov039 021F4610 and 021F3A34 are siblings, but neither has this pair. Left DIFF.
 *           2026-10-05 wave D9r lane 60: still 4 bytes. Reduced the residue to a 10-line test function
 *           (call; s->hold = c; leaf(p, 1)): mwcc puts the argument setup above an independent register
 *           strb in every form tried: a literal, a register argument, an enum or s8 or const callee
 *           parameter, a function-pointer call, p typed u8 *, the callee returning u64, a pointer local
 *           to the field, the store to a global. A computed value (c + 1) puts the store first only
 *           because r1 is the temp. Full-function tries: a separate local for the 021A3074 result (same
 *           4), k = s->sel + 1 assigned in case 5 and passed (same 4), the store before a nested
 *           leaf(674(...), 1) (20). No real source form found; left DIFF.
 *           2026-10-05 wave D9r lane 91: still 4 bytes. Checked callee prototypes against the matched
 *           definitions: func_021BE674 and func_021BE6B0 agree with ov021 (void *, void). func_021F3DE4 is
 *           really (void *, u8, u16); with that prototype the call site needs (u8)(s->sel + 1) (the
 *           original truncates to 8 bits), now used here; same 4 bytes. func_021BE4C4 returning int:
 *           same 4. New reading: mwcc never moves an independent store above the argument setup when
 *           the store and the call are in one block (micro tests: __restrict s, stack object, global,
 *           (u8)/(s8)/& 0xFF value, int-returning callee: all movs first). A game-wide scan found
 *           store-before-argument only with a register dependence (ov091 021B62A2 base r1, ov021
 *           021AD040 adds r1,r0) or when the call sits in a cross-jumped join block (matched ov135
 *           021F9FF0: m->cur = r; f(m->cursor, 6) in an else arm). Case 5 has no branch into
 *           +01B4/+01B6, so the original block structure here is still unexplained. Left DIFF.
 * symbols:
 *   func_020124E4 0x020124E4 thumb
 *   func_0201210C 0x0201210C thumb
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021897BC 0x021897BC thumb
 *   func_02188C80 0x02188C80 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_02012A30 0x02012A30 thumb
 *   func_02006148 0x02006148 thumb
 *   func_021BE674 0x021BE674 thumb ov021
 *   func_021BE6B0 0x021BE6B0 thumb ov021
 *   func_021BE6BC 0x021BE6BC thumb ov021
 *   func_021BE4C4 0x021BE4C4 thumb ov021
 *   func_021BE748 0x021BE748 thumb ov021
 *   func_021F3E04 0x021F3E04 thumb ov039
 *   func_021F3DE4 0x021F3DE4 thumb ov039
 *   func_021F48C0 0x021F48C0 thumb ov039
 *   func_02011428 0x02011428 thumb
 *   func_02011558 0x02011558 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_020061F8 0x020061F8 thumb
 *   func_02006138 0x02006138 thumb
 *   func_02006210 0x02006210 thumb
 *   func_02028A7C 0x02028A7C thumb
 *   func_02028B18 0x02028B18 thumb
 *   func_02028B50 0x02028B50 thumb
 *   func_02072F34 0x02072F34 arm
 *   func_0203630C 0x0203630C arm
 *   func_02047790 0x02047790 arm
 *   func_02047674 0x02047674 arm
 *   func_0207CA00 0x0207CA00 arm
 *   func_0207CBD0 0x0207CBD0 arm
 *   func_02158780 0x02158780 thumb ov010
 *   func_02188CB4 0x02188CB4 thumb ov021
 *   func_021A3074 0x021A3074 thumb ov021
 *   func_021A3044 0x021A3044 thumb ov021
 *   func_0216DAC8 0x0216DAC8 thumb
 *   func_0216D5E0 0x0216D5E0 thumb
 *   d_021F4C38    0x021F4C38 data a4
 *   d_021F4C58    0x021F4C58 data ov039 a4
 *   d_021F4CF4    0x021F4CF4 data ov039 a4
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int x, y, z;
} Vec;

typedef struct {
    u16 x;
    u16 z;
} Cell;

typedef struct {
    u8 pad0[4];
    u8 sel;
    u8 pad5[2];
    s8 hold;
    int timer[4];
    u32 anim;
    u8 f1c[0x21E4 - 0x1C];
    int active;
    u8 req[4];
    u8 cur[4];
    s8 slot[4];
} Work;

typedef struct {
    u8 pad0[8];
    u8 *mdl;
} Res;

struct Ctx;
struct Obj;
struct Big;
struct BigObj;
struct IcaAnime;
struct SoundSys2;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188D2C(int *p);
extern Work *func_021897BC(void *p, int idx);
extern u32 func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern void *func_0200B3A4(unsigned int, unsigned int);
extern u32 func_02012A30(const struct BigObj *a);
extern int func_02006148(u32 a);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void func_021BE6B0(unsigned char *p, int v);
extern int func_021BE6BC(int *p);
extern void *func_021BE4C4(void *p, u32 i, int delta);
extern int func_021BE748(void *p);
extern void func_021F3E04(void *p, u8 delta, u16 i, int frame);
extern int func_021F3DE4(void *p, u8 delta, u16 i);
extern void func_021F48C0(u8 *a, int idx, int x, Vec *out);
extern u32 func_02011428(u32 heap, u32 a1, u16 a2, void *a3, u32 a4);
extern void func_02011558(struct IcaAnime *p);
extern void func_020061E4(u32 a);
extern void func_020061F8(int i);
extern u32 *func_02006138(int i);
extern void func_02006210(void);
extern void func_02028A7C(struct SoundSys2 *s, u32 id);
extern void func_02028B18(struct SoundSys2 *s, u32 id, u32 who);
extern void func_02028B50(u8 *p, int a0);
extern void func_02072F34(void *o, u8 v);
extern unsigned int func_0203630C(void);
extern void *func_02047790(void *h, u16 i);
extern Res *func_02047674(void *p);
extern void func_0207CA00(const Vec *a, const Vec *b, Vec *out);
extern int func_0207CBD0(const Vec *a);
extern int func_02158780(void *p, int b, int c, int d, u16 e);
extern void *func_02188CB4(u8 *p);
extern void *func_021A3074(u8 *p);
extern void func_021A3044(void *q, Vec *v);
extern void func_0216DAC8(void *o, u32 v);
extern void func_0216D5E0(void *o, u32 v);

extern u32 d_021F4C38[];
extern Cell d_021F4C58[];
extern Vec d_021F4CF4;

int func_021F41A8(void *a0, int *a1)
{
    void *sys;
    int h;
    Work *s;
    u32 w;
    int snd;
    int c;
    void *q;
    u8 j;
    void *o;
    void *p;
    void *m;
    Res *r;
    int f2;
    u8 k;
    int f;
    int n;
    int d;
    u8 vol;
    Vec t;
    Vec a;
    Vec b;
    Vec e;

    sys = func_0201210C(func_020124E4(a0));
    h = func_02188D2C(sys);
    s = func_021897BC(sys, 1);
    w = func_02012A30((const struct BigObj *)func_020120F4((const struct Ctx *)func_02188C80(sys)));
    snd = func_02006148(0x6DB);
    c = (u8)(s->sel >> 1);
    j = c;
    o = func_021BE674((char *)h, 0, j, 0);
    func_0200B3A4((unsigned int)func_02012EC4(func_020120F4((const struct Ctx *)func_02188C80(sys))), 2);
    switch (*a1) {
    case 0:
        s->anim = func_02011428(0x8015, 0x6b, d_021F4C38[s->sel], s->f1c, 0x21C0);
        func_021F3E04((void *)h, j, 0, 0);
        func_021BE6B0(o, 0);
        func_020061E4(0x687);
        *a1 = *a1 + 1;
        break;
    case 1:
        if (func_021F3DE4((void *)h, j, 0) < 0xF000) {
            break;
        }
        func_021BE6B0(o, 1);
        func_02158780(a0, 0xD, 0, 0, 0x8015);
        *a1 = *a1 + 1;
        break;
    case 2:
        func_021BE6B0(o, 0);
        func_020061E4(0x687);
        *a1 = *a1 + 1;
        break;
    case 3:
        if (func_021BE6BC(o) == 0) {
            break;
        }
        func_0216DAC8(func_021A3074(func_02188CB4(sys)), 1);
        func_021BE6B0(o, 1);
        func_021BE6B0(func_021BE674((char *)h, 0, j, (u8)(s->sel + 1)), 0);
        s->timer[c] = 0;
        s->slot[c] = -1;
        s->hold = -1;
        func_02028A7C((struct SoundSys2 *)w, 0x68A);
        func_020061E4(0x6DB);
        func_02072F34(func_02006138(snd), 0);
        func_02028B18((struct SoundSys2 *)w, 0x68A, 0x7f);
        s->active = 1;
        *a1 = *a1 + 1;
        break;
    case 4:
        if (s->slot[c] == -1) {
            break;
        }
        if (func_0203630C() & 0x80) {
            *a1 = *a1 + 1;
        }
        break;
    case 5:
        p = func_021BE674((char *)h, 0, j, (u8)(s->sel + 1));
        s->hold = c;
        func_021BE6B0(p, 1);
        func_021F3E04((void *)h, j, 0, 0);
        func_021BE6B0(o, 0);
        func_020061E4(0x687);
        p = func_021A3074(func_02188CB4(sys));
        func_0216D5E0(p, 1);
        func_0216DAC8(p, 0);
        *a1 = *a1 + 1;
        break;
    case 6:
        if (func_021F3DE4((void *)h, j, 0) < 0xF000) {
            break;
        }
        func_021BE6B0(o, 1);
        m = func_02188CB4(sys);
        t = d_021F4CF4;
        k = s->slot[c];
        t.x = (d_021F4C58[k].x << 16) + 0x8000;
        t.z = ((d_021F4C58[k].z - 2) << 16) + 0x8000;
        func_021A3044(m, &t);
        s->active = 0;
        *a1 = *a1 + 1;
        break;
    case 7:
        func_02158780(a0, 0xE, 0, 0, 0x8015);
        *a1 = *a1 + 1;
        break;
    case 8:
        func_021BE6B0(o, 0);
        func_020061E4(0x687);
        *a1 = *a1 + 1;
        break;
    case 9:
        if (func_021BE6BC(o) == 0) {
            break;
        }
        func_021BE6B0(o, 1);
        func_021BE6B0(func_021BE674((char *)h, 0, j, (u8)(s->sel + 1)), 0);
        s->timer[c] = 0;
        s->slot[c] = -1;
        func_02011558((struct IcaAnime *)s->anim);
        s->hold = -1;
        s->sel = 0xff;
        func_02028A7C((struct SoundSys2 *)w, 0x68A);
        func_02028B18((struct SoundSys2 *)w, 0x68A, 0);
        func_020061F8(snd);
        return 1;
    }
    if ((u8)(s->sel + 0xFE) <= 3) {
        f = func_021F3DE4((void *)h, j, (u8)(s->sel + 1));
        switch (s->sel) {
        case 2:
            if (f == 0xBF000) {
                func_02028B50((u8 *)w, 0x68A);
                func_02006210();
                func_020061E4(0x68B);
            } else if (f == 0xEB000) {
                func_02028B50((u8 *)w, 0x68A);
                func_02006210();
            } else if (f == 0xFF000) {
                func_020061E4(0x68C);
            }
            break;
        case 3:
            if (f == 0x108000) {
                func_02028B50((u8 *)w, 0x68A);
                func_02006210();
                func_020061E4(0x68B);
            } else if (f == 0x131000) {
                func_02028B50((u8 *)w, 0x68A);
                func_02006210();
            } else if (f == 0x148000) {
                func_020061E4(0x68C);
            }
            break;
        case 4:
            if (f == 0xB1000) {
                func_02028B50((u8 *)w, 0x68A);
                func_02006210();
                func_020061E4(0x6D2);
            }
            break;
        case 5:
            if (f == 0xB6000) {
                func_02028B50((u8 *)w, 0x68A);
                func_02006210();
                func_020061E4(0x6D2);
            }
            break;
        }
    }
    q = func_021BE4C4((void *)h, 0, j);
    k = s->sel + 1;
    n = func_021BE748(func_021BE674((char *)h, 0, j, k));
    f = func_021F3DE4((void *)h, j, k);
    f2 = f + 0x1000;
    if (f2 >= n) {
        f2 = 0;
    }
    r = func_02047674(func_02047790(q, k));
    vol = 0;
    func_021F48C0(r->mdl, 0, f, &a);
    func_021F48C0(r->mdl, 0, f2, &b);
    func_0207CA00(&a, &b, &e);
    d = func_0207CBD0(&e);
    if (d >= 0x20000) {
        vol = 0x7f;
    } else if (d >= 0x18000) {
        vol = 0x5a;
    } else if (d >= 0x10000) {
        vol = 0x3c;
    } else if (d >= 0x8000) {
        vol = 0x1e;
    }
    func_02072F34(func_02006138(snd), vol);
    return 0;
}
