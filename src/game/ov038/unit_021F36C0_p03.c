/*
 * file:     unit_021F36C0_p03.c
 * unit:     yes
 * function: func_021F3B3C, func_021F3DFC
 * address:  0x021F3B3C
 * region:   ov038
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_0203630C  0x0203630C  arm
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_0201235C  0x0201235C  thumb
 *   func_02197DA0  0x02197DA0  thumb  ov021
 *   func_02197DAC  0x02197DAC  thumb  ov021
 *   func_021618A0  0x021618A0  thumb  ov010
 *   func_02012374  0x02012374  thumb
 *   func_02006210  0x02006210  thumb
 *   func_021BE6E8  0x021BE6E8  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_02197D3C  0x02197D3C  thumb  ov021
 *   d_021F45F8     0x021F45F8  data  a4
 *   d_021F4600     0x021F4600  data  a4
 *   d_021F4608     0x021F4608  data  a4
 *   d_021F4620     0x021F4620  data  a4
 */
#include "../../matched/include/Obj00488.h"
#include "../../matched/include/Obj00881.h"

struct Big;
struct Ctx;
struct Desc;
struct Evt;
struct Obj;
struct S0201235C;
struct Obj00020;
struct Rec94;
struct VecFx32;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef enum { K_0 } KType;

typedef struct {
    int x;
    int y;
    int z;
} V3;

typedef signed int     s32;

extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188D2C(int *p);
extern int *func_021897BC(char *p, int idx);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void *func_021A3074(unsigned char *p);
extern int func_0216D454(void *t);
extern int func_0216D3CC(int a0);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern void func_021A3044(u8 *p, void *v);
extern void func_021BE4B4(char *p, int i, int j, int v);
extern V3 *func_021BE480(int p, int i, int j);
extern void func_021BE700(void *p, int i, int j, int k, int flag);
extern void func_021BE6CC(int p, int i, int j, int k, int flag);
extern void func_021BE6B0(unsigned char *p, int v);
extern int func_021BE6BC(int *p);
extern int func_021BE6E8(int p, int i, int j, int k);
extern unsigned int func_0203630C(void);
extern void func_020061E4(u32 se);
extern void func_02006210(void);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void func_0201235C(struct S0201235C *o, u32 *out);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_021618A0(void *p, int a1, int a2, int a3);
extern int func_02197DA0(u32 a);
extern void func_02197DAC(void *a);
extern int func_02197D3C(void *t, void *p);
int func_021F3B3C(int a0, int *a1);
int func_021F3DFC(int a0, int *a1);
extern u32 d_021F45F8[];
extern u32 d_021F4600[];
extern u32 d_021F4608[];
extern u32 d_021F4620[];


/*
 * note:     enum-k spelling as ov038_func_021F3F40.  Case 1 keeps the pressed
 *           path in the if body (the release path, a task swap to
 *           func_021F3DFC, is the else) so case 0's two failed tests reuse
 *           its `b` to the shared tail; d = (u32)s[5] >> 1 gives the plain lsrs.
 */
int func_021F3B3C(int a0, int *a1)
{
    void *w;
    void *sys;
    int h;
    u8 *s;
    void *q;
    u8 c;
    KType k;
    void *e;
    void *t;
    V3 *src;
    int mask;
    int dir;
    u32 d;
    V3 v;

    w = func_020124E4((struct Obj *)a0);
    sys = func_0201210C(w);
    h = func_02188D2C(sys);
    s = (u8 *)func_021897BC(sys, 1);
    q = func_02188CB4(sys);
    func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(sys))), 6);
    k = 0;
    c = s[3] + 0x19;
    if (s[6] == 1)
        k = (u8)(k + 1);
    e = func_021BE674((char *)h, 0, 0x22, k);
    switch (*a1) {
    case 0:
        t = func_021A3074((void *)q);
        if (func_0216D454(t) != 0 && func_0216D3CC((int)t) != 0) {
            ((struct Obj00488 *)s)->f1C = 1;
            func_021A3038(q, (struct VecFx32 *)(s + 8));
            func_021BE4B4((char *)h, 0, c, 1);
            func_021BE4B4((char *)h, 0, 0x22, 0);
            src = func_021BE480(h, 0, c);
            *func_021BE480(h, 0, 0x22) = *src;
            func_021BE700((void *)h, 0, 0x22, k, 1);
            func_021BE6CC(h, 0, 0x22, k, 0);
            func_021BE6B0(e, 1);
            ((struct Obj00488 *)s)->f20 = 0;
            *a1 = *a1 + 1;
        }
        break;
    case 1:
        if (s[6] == 0) {
            mask = 0x40;
            dir = -1;
        } else {
            mask = 0x80;
            dir = 1;
        }
        if ((func_0203630C() & mask) != 0) {
            s[7]++;
            if (s[7] >= 2) {
                s[7] = 0;
                s[5]++;
                func_021A3038(q, (struct VecFx32 *)&v);
                v.z += dir << 12;
                func_021A3044(q, &v);
                d = (u32)s[5] >> 1;
                if (((struct Obj00488 *)s)->f20 == 0 && d != 0) {
                    func_020061E4(0x6C2);
                    ((struct Obj00488 *)s)->f20 = 1;
                }
                func_021BE6CC(h, 0, 0x22, k, d << 12);
                if (s[5] >= 0x20)
                    *a1 = *a1 + 1;
            }
        } else {
            func_0201235C((struct S0201235C *)a0, (u32 *)func_020122C0(w, 0, func_021F3DFC, 0));
            return 0;
        }
        break;
    case 2:
        if (((struct Obj00488 *)s)->f14 != 0) {
            if (func_02197DA0(((struct Obj00488 *)s)->f14) == 1) {
                func_02197DAC((void *)(((struct Obj00488 *)s)->f14));
                ((struct Obj00488 *)s)->f14 = 0;
                ((struct Obj00488 *)s)->f18 = 1;
                *a1 = *a1 + 1;
            }
        } else {
            ((struct Obj00488 *)s)->f18 = 1;
            *a1 = *a1 + 1;
        }
        if (((struct Obj00488 *)s)->f18 != 0) {
            func_021BE6B0(e, 0);
            func_02012374((struct Evt *)a0, func_021618A0(w, (int)sys, 0xff, (int)(s[6] == 0 ? d_021F4608 : d_021F4600)));
            func_02006210();
            func_020061E4(0x6C3);
        }
        break;
    case 3:
        func_021BE6E8(h, 0, 0x22, k);
        if (func_021BE6BC(e)) {
            func_021BE700((void *)h, 0, 0x22, k, 0);
            func_021BE4B4((char *)h, 0, 0x22, 1);
            func_021BE4B4((char *)h, 0, c, 0);
            return 1;
        }
        break;
    }
    if (((struct Obj00488 *)s)->f1C != 0 && ((struct Obj00488 *)s)->f18 == 0) {
        t = func_021A3074((void *)q);
        if (((struct Obj00488 *)s)->f14 == 0) {
            ((struct Obj00488 *)s)->f14 = func_02197D3C(t, s[6] == 0 ? d_021F4620 : d_021F45F8);
        } else if (func_02197DA0(((struct Obj00488 *)s)->f14) == 1) {
            func_02197DAC((void *)(((struct Obj00488 *)s)->f14));
            ((struct Obj00488 *)s)->f14 = 0;
        }
    }
    return 0;
}


/*
 * note:     same enum-k spelling as ov038_func_021F3F40 (k = (u8)(k + 1)
 *           on an enum local, int fourth parameter on the 0x021BE6xx calls).
 */
int func_021F3DFC(int a0, int *a1)
{
    void *sys;
    int h;
    u8 *s;
    void *q;
    u8 c;
    KType k;
    int done;
    int d;
    V3 v;

    sys = func_0201210C(func_020124E4((void *)a0));
    h = func_02188D2C(sys);
    s = (u8 *)func_021897BC(sys, 1);
    q = func_02188CB4(sys);
    k = 0;
    c = s[3] + 0x19;
    if (s[6] == 1)
        k = (u8)(k + 1);
    switch (*a1) {
    case 0:
        func_02006210();
        *a1 = *a1 + 1;
    case 1:
        if (((struct Obj00881 *)s)->f14 != 0) {
            if (func_02197DA0(((struct Obj00881 *)s)->f14) == 1) {
                func_02197DAC((void *)(((struct Obj00881 *)s)->f14));
                ((struct Obj00881 *)s)->f14 = 0;
                s[5] = 0;
                *a1 = *a1 + 1;
            }
        } else {
            s[5] = 0;
            *a1 = *a1 + 1;
        }
        if (*a1 == 2)
            ((struct Obj00881 *)s)->f20 = 0;
        break;
    case 2:
        func_021A3038(q, (struct VecFx32 *)&v);
        done = 0;
        s[5]++;
        if (s[6] == 0) {
            v.z += s[5] << 12;
            if (v.z >= ((struct Obj00881 *)s)->f10) {
                v.z = ((struct Obj00881 *)s)->f10;
                done = 1;
            }
            d = (((struct Obj00881 *)s)->f10 - v.z) / 2;
        } else {
            v.z += -s[5] << 12;
            if (v.z <= ((struct Obj00881 *)s)->f10) {
                v.z = ((struct Obj00881 *)s)->f10;
                done = 1;
            }
            d = (v.z - ((struct Obj00881 *)s)->f10) / 2;
        }
        if (((struct Obj00881 *)s)->f20 == 0 && d != 0) {
            func_020061E4(0x6C4);
            ((struct Obj00881 *)s)->f20 = 1;
        }
        func_021BE6CC(h, 0, 0x22, k, d);
        func_021A3044(q, &v);
        if (done) {
            func_021BE700((void *)h, 0, 0x22, k, 0);
            func_021BE4B4((char *)h, 0, 0x22, 1);
            func_021BE4B4((char *)h, 0, c, 0);
            return 1;
        }
        break;
    }
    return 0;
}
