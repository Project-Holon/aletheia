/*
 * function: func_021F41A8
 * address:  0x021F41A8
 * packet:   pkt_ov039_021F41A8
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     2026-10-05 final push G2L1: closed. Case 5 stored s->hold before movs r1,#1 only when
 *           func_021BE674 takes (char *, int, u8 j, u8 k), as the matched caller ov039 021F404C declares
 *           it (earlier drafts used unsigned int j, int k; with u8 parameters the call site is
 *           the same but the pair order in case 5 follows the original). The func_021F3DE4 call keeps
 *           (u8)(s->sel + 1) for its u16 parameter.
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
extern void *func_021BE674(char *base, int i, u8 j, u8 k);
extern void func_021BE6B0(unsigned char *p, int v);
extern int func_021BE6BC(int *p);
extern void *func_021BE4C4(void *p, u32 i, int delta);
extern int func_021BE748(u32 a);
extern void func_021F3E04(void *p, u8 delta, u16 i, int frame);
extern int func_021F3DE4(void *p, u16 delta, u16 i);
extern void func_021F48C0(u8 *a, int idx, int x, int *out);
extern void *func_02011428(u32 heap, u32 a1, u32 a2, u32 a3, u32 a4);
extern void func_02011558(struct IcaAnime *p);
extern void func_020061E4(u32 a);
extern void func_020061F8(int i);
extern u32 *func_02006138(int i);
extern void func_02006210(void);
extern void func_02028A7C(struct SoundSys2 *s, u32 id);
extern void func_02028B18(struct SoundSys2 *s, u32 id, u32 who);
extern void func_02028B50(u8 *p, int a0);
extern void func_02072F34(struct Obj *o, u8 v);
extern unsigned int func_0203630C(void);
extern int func_02047790(int *p, int i);
extern int func_02047674(int p);
extern void func_0207CA00(const Vec *a, const Vec *b, Vec *out);
extern int func_0207CBD0(const Vec *a);
extern int func_02158780(void *p, int b, int c, int d, u16 e);
extern void *func_02188CB4(u8 *p);
extern void *func_021A3074(u8 *p);
extern void func_021A3044(u8 *p, void *v);
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
        s->anim = (u32)func_02011428(0x8015, 0x6b, (u16)d_021F4C38[s->sel], (u32)s->f1c, 0x21C0);
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
        func_021BE6B0(func_021BE674((char *)h, 0, j, s->sel + 1), 0);
        s->timer[c] = 0;
        s->slot[c] = -1;
        s->hold = -1;
        func_02028A7C((struct SoundSys2 *)w, 0x68A);
        func_020061E4(0x6DB);
        func_02072F34((struct Obj *)func_02006138(snd), 0);
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
        p = func_021BE674((char *)h, 0, j, s->sel + 1);
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
        func_021BE6B0(func_021BE674((char *)h, 0, j, s->sel + 1), 0);
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
    n = func_021BE748((u32)func_021BE674((char *)h, 0, j, k));
    f = func_021F3DE4((void *)h, j, k);
    f2 = f + 0x1000;
    if (f2 >= n) {
        f2 = 0;
    }
    r = (Res *)func_02047674(func_02047790(q, (u16)k));
    vol = 0;
    func_021F48C0(r->mdl, 0, f, (int *)(&a));
    func_021F48C0(r->mdl, 0, f2, (int *)(&b));
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
    func_02072F34((struct Obj *)func_02006138(snd), vol);
    return 0;
}
