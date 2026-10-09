/*
 * file:     unit_021F36C0_p02.c
 * unit:     yes
 * function: func_021F3A34, func_021F3CD8, func_021F3D1C, func_021F3D74, func_021F3D98, func_021F3DAC, func_021F3DB8, func_021F3DE4, func_021F3E04, func_021F3E24, func_021F3E70, func_021F404C, func_021F4134, func_021F4158, func_021F4184, func_021F41A8, func_021F4610, func_021F4740, func_021F47D8, func_021F4864, func_021F4894, func_021F48C0, func_021F4928
 * address:  0x021F3A34
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021897BC 0x021897BC thumb
 *   func_02188C80 0x02188C80 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_02012A30 0x02012A30 thumb
 *   func_02011558 0x02011558 thumb
 *   func_02011428 0x02011428 thumb
 *   func_021BE674 0x021BE674 thumb ov021
 *   func_021BE6B0 0x021BE6B0 thumb ov021
 *   func_02028A7C 0x02028A7C thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_02006148 0x02006148 thumb
 *   func_02028B18 0x02028B18 thumb
 *   func_02006138 0x02006138 thumb
 *   func_02072F34 0x02072F34 arm
 *   func_021BE6E8 0x021BE6E8 thumb ov021
 *   func_02028B50 0x02028B50 thumb
 *   func_02006210 0x02006210 thumb
 *   func_02011688 0x02011688 thumb
 *   func_02188CB4 0x02188CB4 thumb ov021
 *   func_021A3044 0x021A3044 thumb ov021
 *   func_021F4A18 0x021F4A18 thumb ov039
 *   d_021F4C38    0x021F4C38 data a4
 *   d_021F4C28    0x021F4C28 data ov039 a1
 *   d_021F4D54    0x021F4D54 data ov039 a4
 *   d_021F4CA0    0x021F4CA0 data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_021897A0 0x021897A0 thumb
 *   func_021BE418 0x021BE418 thumb ov021
 *   func_021BE580 0x021BE580 thumb ov021
 *   func_021F36F0 0x021F36F0 thumb ov039
 *   d_021F4C0C    0x021F4C0C data ov039 a1
 *   func_021BE4C4 0x021BE4C4 thumb ov021
 *   func_02047828 0x02047828 arm
 *   func_0204784C 0x0204784C arm
 *   func_0201210C  0x0201210C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E4 0x020124E4 thumb
 *   func_021BE700 0x021BE700 thumb ov021
 *   func_021BE6CC 0x021BE6CC thumb ov021
 *   func_021BE6BC 0x021BE6BC thumb ov021
 *   func_021A3050 0x021A3050 thumb ov021
 *   func_021A3038 0x021A3038 thumb ov021
 *   func_021F36C0 0x021F36C0 thumb ov039
 *   func_021BE748 0x021BE748 thumb ov021
 *   func_020061F8 0x020061F8 thumb
 *   func_0203630C 0x0203630C arm
 *   func_02047790 0x02047790 arm
 *   func_02047674 0x02047674 arm
 *   func_0207CA00 0x0207CA00 arm
 *   func_0207CBD0 0x0207CBD0 arm
 *   func_02158780 0x02158780 thumb ov010
 *   func_021A3074 0x021A3074 thumb ov021
 *   func_0216DAC8 0x0216DAC8 thumb
 *   func_0216D5E0 0x0216D5E0 thumb
 *   d_021F4C58    0x021F4C58 data ov039 a4
 *   d_021F4CF4    0x021F4CF4 data ov039 a4
 *   func_021587B0 0x021587B0 thumb ov010
 *   func_021BE6B4  0x021BE6B4  thumb  ov021
 *   d_021F4D78 0x021F4D78 data a4
 *   d_021F4BE4 0x021F4BE4 data a2
 *   _ll_mul  0x0209C054  arm
 */
#include "../../matched/include/G_Vec.h"

struct Big;
struct Ctx;
struct IcaAnime;
struct SoundSys2;
struct Rec94;
struct BigObj;
struct Obj;
struct Rec;
struct Rec12;
struct Obj00020;
struct Node;
struct AnmCtl;
struct Desc;
struct VecFx32;
typedef signed char s8;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    int x, y, z;
} Vec;

typedef struct {
    u8 pad0[4];
    u8 sel;
    s8 idx;
    u8 mode;
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
    u8 pad0[0x10];
    u8 flag[8];
} Save;

typedef signed int     s32;

typedef struct {
    u16 x;
    u16 z;
} Cell;

typedef struct {
    u8 pad0[8];
    u8 *mdl;
} Res;

typedef short s16;

typedef long long s64;

extern int func_02188D2C(int *p);
extern Work *func_021897BC(void *p, int idx);
extern u32 func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern u32 func_02012A30(const struct BigObj *a);
extern void func_02011558(struct IcaAnime *p);
extern u32 func_02011428(u32 heap, u32 a1, u16 a2, void *a3, u32 a4);
extern void *func_021BE674(char *base, int i, u8 j, u8 k);
extern void func_021BE6B0(unsigned char *p, int v);
extern void func_02028A7C(struct SoundSys2 *s, u32 id);
extern void func_020061E4(u32 a);
extern int func_02006148(u32 a);
extern void func_02028B18(struct SoundSys2 *s, u32 id, u32 who);
extern u32 *func_02006138(int i);
extern void func_02072F34(struct Obj *o, u8 v);
extern int func_021BE6E8(int p, int i, u8 j, u8 k);
extern void func_02028B50(u8 *p, int a0);
extern void func_02006210(void);
extern u32 func_02011688(struct IcaAnime *p, struct Rec12 *dst, u32 idx);
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021A3044(u8 *p, void *v);
extern void func_021F4A18(void *a0, struct Rec *a1);
extern void func_02030EAC(struct Node *n);
extern void func_021897A0(int, int);
extern void func_021BE418(u8 *p, u16 i);
extern void func_021BE580(int);
extern u8 func_021F36F0(u8 *p, int i);
extern void *func_021BE4C4(void *p, u32 i, int delta);
extern u32 func_02047828(struct AnmCtl *c, u32 idx, s32 *frame);
extern u32 func_0204784C(struct AnmCtl *c, u16 idx, s32 *frame);
extern void *func_0201210C(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E4(struct Obj *p);
extern void func_021BE700(void *p, int i, int j, int k, int flag);
extern void func_021BE6CC(int a, int b, int c, int d, int e);
extern int func_021BE6BC(int *p);
extern u16 func_021A3050(u8 *p);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern u8 func_021F36C0(int x, int z);
extern int func_021BE748(u32 a);
extern void func_020061F8(int i);
extern unsigned int func_0203630C(void);
extern int func_02047790(int *p, int i);
extern int func_02047674(int p);
extern void func_0207CA00(const Vec *a, const Vec *b, Vec *out);
extern int func_0207CBD0(const Vec *a);
extern int func_02158780(void *p, u16 b, int c, int d, u16 e);
extern void *func_021A3074(u8 *p);
extern void func_0216DAC8(void *o, u32 v);
extern void func_0216D5E0(void *o, u32 v);
extern int func_021587B0(int a0, int a1, int a2, int a3);
extern u8 func_021BE6B4(u8 *p);
void func_021F3A34(int a0, void *a1);
void func_021F3CD8(int a);
void func_021F3D1C(int a);
void func_021F3D74(u32 a);
u8 func_021F3D98(u8 *p, int i);
unsigned char func_021F3DAC(int i);
int func_021F3DB8(signed char *p, int i);
int func_021F3DE4(void *p, u16 delta, u16 i);
void func_021F3E04(void *p, u8 delta, u16 i, int frame);
int func_021F3E24(void *a, u32 b);
int func_021F3E70(int a0, int *a1);
int func_021F404C(void *a0);
void func_021F4134(void *p, u32 i);
int func_021F4158(u8 *p, int i);
void func_021F4184(u8 *p, u8 i);
int func_021F41A8(void *a0, int *a1);
int func_021F4610(void *a0, int *a1);
void func_021F4740(u32 a, void *b);
void func_021F47D8(void *a, int f, int i);
int func_021F4864(u32 a, u32 b, u8 *out);
int func_021F4894(void *p, int i, u8 j);
void func_021F48C0(u8 *a, int idx, int x, int *out);
void func_021F4928(int *out, int frame, const u32 *data, const u8 *base);
extern u32 d_021F4C38[];
extern s8 d_021F4C28[][2];
extern Vec d_021F4D54;
extern struct Vec d_021F4CA0[];
extern unsigned char d_021F4C0C[];
extern Cell d_021F4C58[];
extern Vec d_021F4CF4;
extern const u32 d_021F4D78[][2];
extern const u16 d_021F4BE4[];






/*
 * note:     spill slots follow reverse declaration order (last declared, lowest
 *           slot): d, v, qr, j2, sr, b, a gives a 8, b 0xc, sr 0x10, j2 0x14, qr 0x18,
 *           v 0x1c, d 0x20. The row pointers qr (q + j) and sr (s + j) and j2 = 2 * j
 *           are named locals so they take their declared places, and `b = v + 1`
 *           keeps v a real variable (with `b = s->cur[j] + 1` a CSE temporary
 *           takes the first slot instead). d_021F4C28 and d_021F4D54 need the ov039 token.
 */
void func_021F3A34(int a0, void *a1)
{
    u8 i;
    int j;
    int h;
    Work *s;
    u32 t;
    Save *q;
    int w;
    int d;
    u8 v;
    u8 *qr;
    int j2;
    s8 *sr;
    u8 b;
    u8 a;
    void *o;
    int snd;
    u8 k;
    Vec pos;
    u8 buf[4];
    u32 tmp2;

    h = func_02188D2C(a1);
    s = func_021897BC(a1, 1);
    t = (u32)func_020120F4((const struct Ctx *)func_02188C80(a1));
    q = (Save *)func_0200B3A4((struct Rec94 *)func_02012EC4((struct Big *)t), 2);
    w = func_02012A30((const struct BigObj *)t);
    for (i = 0; i < 4; i++) {
        j = i;
        if (s->req[j] != 0) {
            qr = (u8 *)q + j;
            d = (u8)((qr[0x10] + 1) % 2);
            j2 = j * 2;
            if (func_021F3DE4((void *)h, (u8)j, (u8)(d + (j2 + 1))) == 0) {
                func_021F47D8((void *)h, d, j);
                tmp2 = qr[0x10];
                s->cur[j] = j2 + tmp2;
                if (s->sel != 0xff && ((u32)s->sel >> 1) == j && s->sel != s->cur[j]) {
                    s->sel = s->cur[j];
                    func_02011558((struct IcaAnime *)s->anim);
                    s->anim = func_02011428(0x8015, 0x6b, d_021F4C38[s->sel], s->f1c, 0x21C0);
                }
                s->req[j] = 0;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        j = i;
        sr = (s8 *)s + j;
        v = s->cur[j];
        b = v + 1;
        a = j;
        o = func_021BE674((char *)h, 0, a, b);
        if (s->timer[j] != 0) {
            if (s->hold != j && --s->timer[j] == 0) {
                func_021BE6B0(o, 0);
                if (s->sel != 0xff && j == ((u32)s->sel >> 1)) {
                    func_02028A7C((struct SoundSys2 *)w, 0x68A);
                    func_020061E4(0x6DB);
                    snd = func_02006148(0x6DB);
                    func_02028B18((struct SoundSys2 *)w, 0x68A, 0x7f);
                    func_02072F34((struct Obj *)func_02006138(snd), 0);
                }
                sr[0x21F0] = -1;
            }
        } else if (func_021F4864(v, func_021BE6E8(h, 0, a, b), buf)) {
            func_021BE6B0(o, 1);
            if (s->sel != 0xff && j == ((u32)s->sel >> 1)) {
                func_02028B50((u8 *)w, 0x68A);
                func_02006210();
            }
            s->timer[j] = 0x5a;
            sr[0x21F0] = d_021F4C28[v][buf[0]];
        }
    }
    if (s->active != 0) {
        pos = d_021F4D54;
        k = s->sel >> 1;
        if (func_02011688((struct IcaAnime *)s->anim, (struct Rec12 *)(&pos), func_021BE6E8(h, 0, k, s->sel + 1) / 4096)) {
            pos.x += d_021F4CA0[k].x;
            pos.y += d_021F4CA0[k].y;
            pos.z += d_021F4CA0[k].z;
            func_021A3044(func_02188CB4((void *)a1), &pos);
        }
    } else {
        func_021F4A18(a1, (struct Rec *)s);
    }
}






void func_021F3CD8(int a)
{
    int r6 = func_02188D2C((int *)a);
    int *r4 = (int *)func_021897BC((void *)a, 1);

    func_02028B50((u8 *)func_02012A30((const struct BigObj *)func_020120F4((const struct Ctx *)func_02188C80((void *)a))), 0x68A);
    func_02030EAC((struct Node *)(*r4));
    func_021897A0(a, 1);
    func_021BE418((u8 *)r6, 0);
}






void func_021F3D1C(int a)
{
    int *r7;
    int r6;
    int i;
    unsigned char *r5;

    r6 = func_02188D2C((int *)a);
    r5 = (unsigned char *)func_021897BC((void *)a, 1);
    r7 = func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((const struct Ctx *)func_02188C80((void *)a))), 2);
    func_021BE580(r6);
    for (i = 0; i < 4; i++)
        r7[i] = func_021F3DE4((void *)r6, (unsigned char)i, (unsigned char)(r5[i + 0x21EC] + 1));
}





void func_021F3D74(u32 a) { struct SoundSys2 *p; p = (struct SoundSys2 *)func_02012A30((const struct BigObj *)func_020120F4((const struct Ctx *)a)); func_02028A7C(p, 0x68a); func_02028B18(p, 0x68a, 0); }




u8 func_021F3D98(u8 *p, int i) { return func_021F36F0(p, func_021F3DAC(i)); }





unsigned char func_021F3DAC(int i)
{
    return d_021F4C0C[i];
}




int func_021F3DB8(signed char *p, int i) { int v; v = *(p + func_021F3DAC(i) + 0x21f0); if (v == -1) return 0; return v == i; }




int func_021F3DE4(void *p, u16 delta, u16 i) { int v = 0; func_02047828((struct AnmCtl *)func_021BE4C4(p, 0, delta), i, &v); return v; }




void func_021F3E04(void *p, u8 delta, u16 i, int frame) { func_0204784C((struct AnmCtl *)func_021BE4C4(p, 0, delta), i, &frame); }





int func_021F3E24(void *a, u32 b)
{
    void *s;
    u8 *p;
    int r;

    s = func_0201210C((void *)a);
    func_02188D2C(s);
    p = (u8 *)(int *)func_021897BC(s, 1);
    func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((void *)func_02188C80(s))), 2);
    if (b >= 4) {
        return 0;
    }
    r = (int)func_020122C0(a, 0, func_021F3E70, 0);
    p[5] = b;
    return r;
}





/*
 * note:     case 1 reads s->idx once into a local (int or s8; u8 differs);
 *           re-reading the field per call reloads it and shifts sys to r6.
 */
int func_021F3E70(int a0, int *a1)
{
    void *sys;
    int h;
    Work *s;
    Save *q;
    u8 a;
    u8 b;
    void *o;
    void *o2;
    int i;

    sys = func_0201210C(func_020124E4((void *)a0));
    h = func_02188D2C(sys);
    s = func_021897BC(sys, 1);
    q = (Save *)func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((const struct Ctx *)func_02188C80(sys))), 2);
    switch (*a1) {
    case 0:
        s->mode = q->flag[s->idx];
        a = s->idx + 4;
        b = s->idx + 8;
        if (s->mode == 0) {
            func_021BE700((void *)h, 0, a, 0, 0);
            func_021BE700((void *)h, 0, b, 0, 0);
            func_021BE700((void *)h, 0, a, 1, 1);
            func_021BE700((void *)h, 0, b, 1, 1);
            func_021BE6B0(func_021BE674((char *)h, 0, a, 1), 0);
            func_021BE6B0(func_021BE674((char *)h, 0, b, 1), 0);
            func_021BE6CC((int)((void *)h), 0, a, 1, 0);
            func_021BE6CC((int)((void *)h), 0, b, 1, 0);
            s->mode = 1;
        } else {
            func_021BE700((void *)h, 0, a, 1, 0);
            func_021BE700((void *)h, 0, b, 1, 0);
            func_021BE700((void *)h, 0, a, 0, 1);
            func_021BE700((void *)h, 0, b, 0, 1);
            func_021BE6B0(func_021BE674((char *)h, 0, a, 0), 0);
            func_021BE6B0(func_021BE674((char *)h, 0, b, 0), 0);
            func_021BE6CC((int)((void *)h), 0, a, 0, 0);
            func_021BE6CC((int)((void *)h), 0, b, 0, 0);
            s->mode = 0;
        }
        func_020061E4(0x689);
        *a1 = *a1 + 1;
        break;
    case 1:
        i = s->idx;
        o = func_021BE674((char *)h, 0, i + 4, s->mode);
        o2 = func_021BE674((char *)h, 0, i + 8, s->mode);
        if (func_021BE6BC(o) && func_021BE6BC(o2)) {
            func_021F4740((u32)sys, (void *)h);
            s->idx = -1;
            return 1;
        }
        break;
    }
    return 0;
}





/*
 * note:     func_021BE674's third parameter is u8 here (the caller truncates
 *           the int local before the bl); the 0x02188D2C result bound to a
 *           named local keeps `k` computed before that call.
 */
int func_021F404C(void *a0)
{
    void *sys;
    void *p;
    u8 *s;
    void *x;
    Vec v;
    u8 n;
    int c;
    u8 k;
    int h;

    sys = func_0201210C(a0);
    p = func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((const struct Ctx *)func_02188C80(sys))), 2);
    s = (u8 *)func_021897BC(sys, 1);
    x = func_02188CB4(sys);
    if (func_021A3050(x)) {
        return 0;
    }
    func_021A3038(x, (struct VecFx32 *)&v);
    n = func_021F36C0(v.x / 0x10000, v.z / 0x10000);
    if (n == 0xff) {
        return 0;
    }
    if (func_021F3DB8((signed char *)s, n)) {
        c = func_021F3DAC(n);
        s[4] = func_021F3D98(s, n);
        k = s[4] + 1;
        h = func_02188D2C(sys);
        func_021BE6B0(func_021BE674((char *)h, 0, c, k), 1);
        s[7] = c;
        if (func_021F4158(p, c)) {
            return (int)func_020122C0(a0, 0, func_021F4610, 0);
        }
        return (int)func_020122C0(a0, 0, func_021F41A8, 0);
    }
    return 0;
}



void func_021F4134(void *p, u32 i) { func_021F4184((u8 *)func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((void *)func_02188C80((void *)((u32)func_0201210C(p))))), 2), i); }



int func_021F4158(u8 *p, int i) { int zero = 0; int valid = 0; if (i == 1) { valid = 1; i = zero; } else if (i == 2) { valid = 1; i = 1; } if (valid && *(u16 *)(p + i * 2 + 0x14) == 0) return 1; return 0; }



void func_021F4184(u8 *p, u8 i) { int zero = 0; int valid = 0; if (i == 1) { valid = 1; i = zero; } else if (i == 2) { valid = 1; i = 1; } if (valid) *(u16 *)(p + i * 2 + 0x14) = 1; }




/*
 * note:     2026-10-05 final push G2L1: closed. Case 5 stored s->hold before movs r1,#1 only when
 *           func_021BE674 takes (char *, int, u8 j, u8 k), as the matched caller ov039 021F404C declares
 *           it (earlier drafts used unsigned int j, int k; with u8 parameters the call site is
 *           the same but the pair order in case 5 follows the original). The func_021F3DE4 call keeps
 *           (u8)(s->sel + 1) for its u16 parameter.
 */
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
    func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((const struct Ctx *)func_02188C80(sys))), 2);
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





int func_021F4610(void *a0, int *a1)
{
    void *sys;
    int h;
    Work *s;
    int c;
    u8 j;
    void *o;

    sys = func_0201210C(func_020124E4(a0));
    h = func_02188D2C(sys);
    s = func_021897BC(sys, 1);
    c = (u8)(s->sel >> 1);
    j = c;
    o = func_021BE674((char *)h, 0, j, 0);
    func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((const struct Ctx *)func_02188C80(sys))), 2);
    switch (*a1) {
    case 0:
        func_02158780(a0, 0xF, 0, 0, 0x8015);
        *a1 = *a1 + 1;
        break;
    case 1:
        func_021F3E04((void *)h, j, 0, 0);
        func_021BE6B0(o, 0);
        func_020061E4(0x687);
        *a1 = *a1 + 1;
        break;
    case 2:
        if (func_021F3DE4((void *)h, j, 0) < 0xF000) {
            break;
        }
        func_021BE6B0(o, 1);
        func_02158780(a0, 7, 0, 0, 0x8015);
        *a1 = *a1 + 1;
        break;
    case 3:
        func_021BE6B0(o, 0);
        func_020061E4(0x687);
        *a1 = *a1 + 1;
        break;
    case 4:
        if (func_021BE6BC(o) == 0) {
            break;
        }
        func_021BE6B0(o, 1);
        func_021BE6B0(func_021BE674((char *)h, 0, j, (u8)(s->sel + 1)), 0);
        s->timer[c] = 0;
        s->slot[c] = -1;
        s->sel = 0xff;
        func_021587B0((int)a0, 8, 0, 0x8015);
        *a1 = *a1 + 1;
        break;
    case 5:
        return 1;
    }
    return 0;
}






void func_021F4740(u32 a, void *b)
{
    s8 *p;
    u8 *q;
    u8 *arr;
    u8 v;
    s8 i;

    p = (s8 *)(int *)func_021897BC((char *)a, 1);
    q = (u8 *)func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((void *)func_02188C80((void *)a))), 2);
    i = p[5];
    if (i == -1) {
        return;
    }
    arr = q + 0x10;
    v = arr[i];
    arr[i] = (v + 1) % 2;
    if (func_021F4894(b, (u8)i, *((u8 *)p + p[5] + 0x21EC)) != 0) {
        func_021F47D8(b, v, (u8)p[5]);
        i = p[5];
        *((u8 *)p + i + 0x21EC) = i * 2 + *(u8 *)(q + i + 0x10);
    } else {
        u8 *r = (u8 *)p + 0x21E8;

        i = p[5];
        if (r[i] != 0) {
            r[i] = 0;
        } else {
            r[i] = 1;
        }
    }
}






void func_021F47D8(void *a, int f, int i)
{
    u8 r7;
    u8 r6;
    u8 r4;
    u8 v;
    int d;

    if (f == 0) {
        r7 = i * 2 + 1;
        r6 = r7 + 1;
    } else {
        r6 = i * 2 + 1;
        r7 = r6 + 1;
    }
    r4 = i;
    d = func_021F3DE4(a, r4, r7);
    func_021BE700(a, 0, r4, r7, 0);
    func_021BE700(a, 0, r4, r6, 1);
    func_021F3E04(a, r4, r6, d);
    v = func_021BE6B4(func_021BE674(a, 0, r4, r7));
    func_021BE6B0(func_021BE674(a, 0, r4, r6), v);
}




int func_021F4864(u32 a, u32 b, u8 *out) { u8 i; for (i = 0; i < 2; i++) { if (d_021F4D78[a][i] == b) { *out = i; return 1; } } return 0; }




int func_021F4894(void *p, int i, u8 j) { if (func_021F3DE4(p, (u8)i, j + 1) <= (int)(d_021F4BE4[i] << 12)) return 1; return 0; }





void func_021F48C0(u8 *a, int idx, int x, int *out)
{
    u16 off;
    u32 flags;
    u8 *p;
    int c;
    int b;
    int d;

    off = *(u16 *)(a + idx * 2 + 0x14);
    flags = *(u32 *)(a + off);
    p = a + off + 4;
    if (flags & 6) {
        return;
    }
    if (!(flags & 8)) {
        func_021F4928(&c, x, (const u32 *)p, a);
        p += 8;
        out[0] = c;
    }
    if (!(flags & 0x10)) {
        func_021F4928(&b, x, (const u32 *)p, a);
        p += 8;
        out[1] = b;
    }
    if (flags & 0x20) {
        return;
    }
    func_021F4928(&d, x, (const u32 *)p, a);
    out[2] = d;
}





/*
 * An animation-curve sampler (step-1/2/4 keys, fx16 or fx32 array).  The
 * 1:3 weight's own idx_sub variable puts idx in r2 on every path; the fx16
 * 1:3 sum needs v = v + (v << 1) as its own statement or the second load
 * is hoisted; the interpolation reads spelled *(p + idx) / *(p + idx + 1)
 * share p + idx after the first load, where p[idx] / p[idx + 1] recomputes
 * (idx + 1) * 2 and a pointer local p + idx hoists the add above the load.
 */
void func_021F4928(int *out, int frame, const u32 *data, const u8 *base)
{
    const u8 *arr;
    u32 f;
    u32 info;
    u32 last;
    u32 idx;

    f = frame >> 12;
    arr = base + data[1];
    info = data[0];
    if (!(info & 0xC0000000)) {
        idx = f;
        goto plain;
    }
    last = (info & 0x1FFF0000) >> 16;
    if (info & 0x40000000) {
        if (f & 1) {
            if (f > last) {
                idx = (last >> 1) + 1;
                goto plain;
            } else {
                idx = f >> 1;
                goto interp2;
            }
        } else {
            idx = f >> 1;
            goto plain;
        }
    } else {
        if (f & 3) {
            if (f > last) {
                idx = (last >> 2) + (f & 3);
                goto plain;
            }
            if (f & 1) {
                int v;
                u32 idx_sub;
                if (f & 2) {
                    idx_sub = f >> 2;
                    idx = idx_sub + 1;
                } else {
                    idx = f >> 2;
                    idx_sub = idx + 1;
                }
                if (info & 0x20000000) {
                    const s16 *p16 = (const s16 *)arr;
                    v = p16[idx];
                    v = v + (v << 1);
                    *out = (v + p16[idx_sub]) >> 2;
                } else {
                    const int *p32 = (const int *)arr;
                    v = p32[idx];
                    *out = (int)(((s64)v * 3 + (s64)p32[idx_sub]) >> 2);
                }
                return;
            } else {
                idx = f >> 2;
                goto interp2;
            }
        } else {
            idx = f >> 2;
            goto plain;
        }
    }
interp2:
    if (info & 0x20000000) {
        const s16 *p16 = (const s16 *)arr;
        *out = (*(p16 + idx) + *(p16 + idx + 1)) >> 1;
    } else {
        const int *p32 = (const int *)arr;
        *out = (*(p32 + idx) >> 1) + (*(p32 + idx + 1) >> 1);
    }
    return;
plain:
    if (info & 0x20000000) {
        *out = ((const s16 *)arr)[idx];
    } else {
        *out = ((const int *)arr)[idx];
    }
}
