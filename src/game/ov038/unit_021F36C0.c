/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F39B4, func_021F39D8, func_021F3A08, func_021F3A88, func_021F3B3C, func_021F3DFC, func_021F3F40, func_021F407C, func_021F4184, func_021F41B0, func_021F41DC, func_021F4200, func_021F42BC
 * address:  0x021F36C0
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
 *   d_021F464C     0x021F464C  data  a4
 *   d_021F46E8     0x021F46E8  data  a4
 *   d_021F4748     0x021F4748  data  a4
 *   d_021F4694     0x021F4694  data  a4
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_02030344  0x02030344  arm
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_021BE748  0x021BE748  thumb  ov021
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_021BE418 0x021BE418 thumb ov021
 *   func_021BE580 0x021BE580 thumb ov021
 *   func_0201210C 0x0201210C thumb
 *   func_02188CB4 0x02188CB4 thumb
 *   func_021A3050 0x021A3050 thumb ov021
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_0203630C  0x0203630C  arm
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
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
 *   func_021F44C0 0x021F44C0 thumb ov038
 *   func_0200B3A8 0x0200B3A8 thumb
 *   d_021F4628    0x021F4628 data a1
 *   d_021F4632    0x021F4632 data a1
 */
#include "../../matched/include/G_S3A08.h"
#include "../../matched/include/Obj04317.h"
#include "../../matched/include/Obj00488.h"
#include "../../matched/include/Obj00881.h"

struct Ctx;
struct Big;
struct Rec94;
struct Desc;
struct Evt;
struct Obj;
struct S0201235C;
struct Obj00020;
struct VecFx32;
typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    int a;
    int b;
    int c;
} V;

typedef signed int     s32;

typedef unsigned char  u8;


typedef struct {
    int x;
    int y;
    int z;
} V3_021F3B3C;

typedef struct {
    int a;
    int b;
    int c;
} V3_021F3F40;

typedef struct {
    int x, y, z;
} Vec;

typedef signed char s8;

typedef struct {
    u8 pad[0x20];
    int a[10];
    int b[10];
} Work;

extern int func_02188D2C(int *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern void *func_02030344(u32 heapId);
extern u16 func_02188C84(u8 *p);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern void  func_021BE760(void *p, void *a, int b);
extern V    *func_021BE480(void *p, int i, u16 j);
extern void func_021BE4A4(char *p, int i, int j, int v);
extern void func_021BE4B4(void *p, int i, u16 j, int v);
extern void *func_021BE674(void *p, int i, u16 j, u16 k);
extern void func_021BE6B8(unsigned char *p, int v);
extern void func_021BE6B0(unsigned char *p, int v);
extern void func_021BE700(void *p, int i, u16 j, u16 k, int flag);
extern void func_021BE6CC(void *p, int i, u16 j, u16 k, int v);
extern int func_021BE748(u32 a);
extern int *func_021897BC(char *p, int idx);
extern void func_021897A0(unsigned char *, int);
extern void func_021BE418(unsigned char *, u16);
extern void func_021BE580(void *);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern u16 func_021A3050(u8 *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E4(struct Obj *p);
extern void *func_021A3074(unsigned char *p);
extern int func_0216D454(void *t);
extern int func_0216D3CC(int a0);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern void func_021A3044(u8 *p, void *v);
extern int func_021BE6BC(int *p);
extern int func_021BE6E8(int p, int i, int j, int k);
extern unsigned int func_0203630C(void);
extern void func_020061E4(u32 se);
extern void func_02006210(void);
extern void func_0201235C(struct S0201235C *o, u32 *out);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_021618A0(void *p, int a1, int a2, int a3);
extern int func_02197DA0(u32 a);
extern void func_02197DAC(void *a);
extern int func_02197D3C(void *t, void *p);
extern int func_021F44C0(void *, int *);
extern u8 *func_0200B3A8(struct Rec94 *p, u32 a1);
void func_021F36C0(void *a0);
void func_021F39B4(void *p);
void func_021F39D8(void *p);
int func_021F3A08(int *base, int x, int y, int *o1, int *o2);
int func_021F3A88(int a0, int a1, int a2);
int func_021F3B3C(int a0, int *a1);
int func_021F3DFC(int a0, int *a1);
int func_021F3F40(int a0, int *a1);
int func_021F407C(int a0, int *a1);
void *func_021F4184(void *p, int v);
void *func_021F41B0(void *p, int v);
void *func_021F41DC(void *p, int v);
int func_021F4200(int a0, int *a1);
int func_021F42BC(int a0, int *a1);
extern int d_021F464C;
extern V d_021F46E8[];
extern V d_021F4748[];
extern struct S3A08 d_021F4694[];
extern u32 d_021F45F8[];
extern u32 d_021F4600[];
extern u32 d_021F4608[];
extern u32 d_021F4620[];
extern const s8 d_021F4628[];
extern const u8 d_021F4632[];




void func_021F36C0(void *a0)
{
    void *r5;
    int i;
    int *q;
    int n;
    int j;
    int k;
    int t;
    int m;
    void *b;
    V *e;
    V v;

    r5 = (void *)func_02188D2C(a0);
    q = func_0200B3A4((struct Rec94 *)func_02012EC4((struct Big *)func_020120F4(func_02188C80(a0))), 6);
    func_02030344(0x15);
    func_02189764(a0, 1, func_02188C84(a0), 0x24);
    func_021BE760(r5, &d_021F464C, 0);
    func_02030344(0x15);
    for (i = 0; i < 8; i++) {
        e = func_021BE480(r5, 0, i);
        *e = d_021F46E8[i];
        func_021BE4A4(r5, 0, (u16)i, 1);
        for (j = 0; j < 2; j++) {
            b = func_021BE674(r5, 0, i, j);
            func_021BE6B8(b, 0);
            func_021BE700(r5, 0, i, j, 1);
            func_021BE6B0(b, 1);
            if (q[i] != 0)
                func_021BE6CC(r5, 0, i, j, func_021BE748((u32)b));
        }
    }
    for (i = 0; i < 10; i++) {
        k = i + 8;
        e = func_021BE480(r5, 0, k);
        *e = d_021F4748[i];
        func_021BE4A4(r5, 0, (u16)k, 1);
        for (j = 0; j < 2; j++) {
            b = func_021BE674(r5, 0, k, j);
            func_021BE6B8(b, 0);
            func_021BE700(r5, 0, k, j, 1);
            func_021BE6B0(b, 1);
            if (q[i + 8] != 0)
                func_021BE6CC(r5, 0, k, j, func_021BE748((u32)b));
        }
    }
    for (n = 0; n < 7; n++) {
        t = n + 0x12;
        m = n + 0x19;
        e = func_021BE480(r5, 0, t);
        v = ((V *)d_021F4694)[n];
        *e = v;
        *func_021BE480(r5, 0, m) = v;
        func_021BE4A4(r5, 0, (u16)t, 1);
        func_021BE4A4(r5, 0, (u16)m, 1);
        switch (q[n + 0x12]) {
        case 0:
            func_021BE4B4(r5, 0, m, 1);
            break;
        case 1:
            func_021BE4B4(r5, 0, t, 1);
            break;
        }
    }
    func_021BE4A4(r5, 0, (u16)0x20, 1);
    for (i = 0; i < 2; i++) {
        b = func_021BE674(r5, 0, 0x20, i);
        func_021BE6B8(b, 0);
        func_021BE6B0(b, 1);
    }
    for (i = 0; i < 8; i++) {
        b = func_021BE674(r5, 0, 0x21, i);
        func_021BE6B8(b, 0);
        func_021BE700(r5, 0, 0x21, i, 0);
    }
    for (i = 0; i < 4; i++) {
        b = func_021BE674(r5, 0, 0x22, i);
        func_021BE6B8(b, 0);
    }
    func_021BE4B4(r5, 0, 0x21, 1);
    func_021BE4B4(r5, 0, 0x22, 1);
    func_02030344(0x15);
}



void func_021F39B4(void *p)
{
    int h = func_02188D2C(p);
    func_021897BC(p, 1);
    func_021897A0(p, 1);
    func_021BE418((unsigned char *)h, 0);
}



/*
 * extent: two bytes of alignment padding at 021F3A06.
 */
void func_021F39D8(void *p)
{
    int h = func_02188D2C(p);
    func_021897BC(p, 1);
    func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((void *)func_02188C80(p))), 6);
    func_021BE580((void *)h);
}




int func_021F3A08(int *base, int x, int y, int *o1, int *o2)
{
    int f;
    int ax;
    int bz;
    int i;
    struct S3A08 *e;

    for (i = 0; i < 7; i++) {
        e = &d_021F4694[i];
        ax = e->a / 0x10000;
        bz = e->c / 0x10000;
        f = 0;
        if (ax == x && bz == y) {
            *o2 = 1;
            f = 1;
        } else if (ax - 1 == x && bz == y) {
            *o2 = 0;
            f = 1;
        } else if (ax + 1 == x && bz == y) {
            *o2 = 0;
            f = 1;
        }
        if (f != 0) {
            *o1 = *(int *)((char *)base + i * 4 + 0x48);
            return i;
        }
    }
    *o2 = 0;
    *o1 = 0;
    return 7;
}




int func_021F3A88(int a0, int a1, int a2)
{
    int o1;
    int o2;
    int r6; /* int-typed on purpose: pointer local changes codegen */
    int r7;
    unsigned char *r4;

    r6 = (int)func_0201210C((void *)a0);
    r4 = (unsigned char *)func_021897BC((char *)((void *)r6), 1);
    r6 = (int)func_02188CB4((void *)r6);
    r7 = (int)func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((const struct Ctx *)(int)func_02188C80(func_0201210C((void *)a0)))), 6);
    r6 = func_021A3050((u8 *)r6);
    if (r6 != 0 && r6 != 1)
        return 0;
    r7 = func_021F3A08((int *)r7, a1, a2, &o1, &o2);
    if (r7 < 7) {
        if (o2 != 0) {
            if (o1 == 1)
                func_020122C0((void *)a0, 0, func_021F3B3C, 0);
            else
                func_020122C0((void *)a0, 0, func_021F407C, 0);
        } else {
            func_020122C0((void *)a0, 0, func_021F3F40, 0);
        }
    } else {
        return 0;
    }
    r4[5] = 0;
    r4[7] = 0;
    r4[6] = r6;
    r4[3] = r7;
    ((struct Obj04317 *)r4)->f14 = 0;
    ((struct Obj04317 *)r4)->f18 = 0;
    ((struct Obj04317 *)r4)->f1C = 0;
}




/*
 * note:     u8 k and u8 j locals as in ov038_func_021F3F40.  Case 1 keeps the pressed
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
    u8 k;
    void *e;
    void *t;
    V3_021F3B3C *src;
    int mask;
    int dir;
    u32 d;
    V3_021F3B3C v;

    w = func_020124E4((struct Obj *)a0);
    sys = func_0201210C(w);
    h = func_02188D2C(sys);
    s = (u8 *)func_021897BC(sys, 1);
    q = func_02188CB4(sys);
    func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(sys))), 6);
    k = 0;
    c = s[3] + 0x19;
    if (s[6] == 1)
        k++;
    e = func_021BE674((char *)h, 0, 0x22, k);
    switch (*a1) {
    case 0:
        t = func_021A3074((void *)q);
        if (func_0216D454(t) != 0 && func_0216D3CC((int)t) != 0) {
            ((struct Obj00488 *)s)->f1C = 1;
            func_021A3038(q, (struct VecFx32 *)(s + 8));
            func_021BE4B4((char *)h, 0, c, 1);
            func_021BE4B4((char *)h, 0, 0x22, 0);
            src = (V3_021F3B3C *)func_021BE480((char *)h, 0, c);
            *(V3_021F3B3C *)func_021BE480((char *)h, 0, 0x22) = *src;
            func_021BE700((void *)h, 0, 0x22, k, 1);
            func_021BE6CC((void *)h, 0, 0x22, k, 0);
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
                func_021BE6CC((void *)h, 0, 0x22, k, d << 12);
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
 * note:     same u8 k spelling as ov038_func_021F3F40 (k++ on a u8 local;
 *           the 0x021BE6xx callees take u16 parameters).
 */
int func_021F3DFC(int a0, int *a1)
{
    void *sys;
    int h;
    u8 *s;
    void *q;
    u8 c;
    u8 k;
    int done;
    int d;
    V3_021F3B3C v;

    sys = func_0201210C(func_020124E4((void *)a0));
    h = func_02188D2C(sys);
    s = (u8 *)func_021897BC(sys, 1);
    q = func_02188CB4(sys);
    k = 0;
    c = s[3] + 0x19;
    if (s[6] == 1)
        k++;
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
        func_021BE6CC((void *)h, 0, 0x22, k, d);
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





/*
 * note:     k and j (0x021BE674/0x021BE700/0x021BE6CC arguments) are u8 locals,
 *           so the u16 parameters add no narrowing at the call; k++ keeps the
 *           unfolded increment of the stored value.
 */
int func_021F3F40(int a0, int *a1)
{
    void *sys;
    int h;
    u8 *s;
    int *p;
    u8 c;
    u8 j;
    u8 k;
    void *e;
    V3_021F3F40 *src;

    sys = func_0201210C(func_020124E4((void *)a0));
    h = func_02188D2C(sys);
    s = (u8 *)func_021897BC(sys, 1);
    func_02188CB4(sys);
    p = func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(sys))), 6);
    if (*(int *)((char *)p + s[3] * 4 + 0x48) == 0) {
        c = s[3] + 0x12;
        j = 0x21;
    } else {
        c = s[3] + 0x19;
        j = 0x22;
    }
    k = 2;
    if (s[6] == 1)
        k++;
    e = func_021BE674((char *)h, 0, j, k);
    switch (*a1) {
    case 0:
        func_021BE4B4((char *)h, 0, c, 1);
        func_021BE4B4((char *)h, 0, j, 0);
        src = (V3_021F3F40 *)func_021BE480((char *)h, 0, c);
        *(V3_021F3F40 *)func_021BE480((char *)h, 0, j) = *src;
        func_021BE700((void *)h, 0, j, k, 1);
        func_021BE6B0(e, 0);
        func_021BE6CC((void *)h, 0, j, k, 0);
        func_020061E4(0x6C5);
        *a1 = *a1 + 1;
        break;
    case 1:
        if (func_021BE6BC(e)) {
            func_021BE700((void *)h, 0, j, k, 0);
            func_021BE4B4((char *)h, 0, j, 1);
            func_021BE4B4((char *)h, 0, c, 0);
            return 1;
        }
        break;
    }
    return 0;
}






/*
 * note:     `k++` on the u8 local keeps the increment of the stored zero
 *           (adds; lsls; lsrs); `k = k + 1` folds it to `movs #1` and swaps
 *           a1/sys between r5 and r6.
 */
int func_021F407C(int a0, int *a1)
{
    void *sys;
    char *h;
    u8 *s;
    u8 c;
    u8 k;
    void *o;
    Vec *v;

    sys = func_0201210C(func_020124E4((void *)a0));
    h = (char *)func_02188D2C(sys);
    s = (u8 *)func_021897BC((char *)sys, 1);
    func_02188CB4(sys);
    k = 0;
    c = s[3] + 0x12;
    if (s[6] == 1) {
        k++;
    }
    o = func_021BE674(h, 0, 0x21, k);
    switch (*a1) {
    case 0:
        func_021BE4B4(h, 0, c, 1);
        func_021BE4B4(h, 0, 0x21, 0);
        v = (Vec *)func_021BE480(h, 0, c);
        *(Vec *)func_021BE480(h, 0, 0x21) = *v;
        func_021BE700(h, 0, 0x21, k, 1);
        func_021BE6B0(o, 0);
        func_021BE6CC((void *)h, 0, 0x21, k, 0);
        func_020061E4(0x6C5);
        *a1 = *a1 + 1;
        break;
    case 1:
        if (func_021BE6BC(o)) {
            func_021BE700(h, 0, 0x21, k, 0);
            func_021BE4B4(h, 0, 0x21, 1);
            func_021BE4B4(h, 0, c, 0);
            return 1;
        }
        break;
    }
    return 0;
}





void *func_021F4184(void *p, int v)
{
    unsigned char *s = (unsigned char *)(u8 *)func_021897BC((char *)func_0201210C(p), 1);
    if (v >= 8) return 0;
    s[0] = v;
    return func_020122C0(p, 0, func_021F4200, 0);
}




void *func_021F41B0(void *p, int v)
{
    unsigned char *s = (unsigned char *)func_021897BC((char *)func_0201210C(p), 1);
    if (v >= 10) return 0;
    s[1] = v;
    return func_020122C0(p, 0, func_021F42BC, 0);
}




void *func_021F41DC(void *p, int v)
{
    unsigned char *s = (unsigned char *)func_021897BC((char *)func_0201210C(p), 1);
    s[2] = v;
    return func_020122C0(p, 0, func_021F44C0, 0);
}



/*
 * note:     the case-0 byte must be held in a u8 (or u16) local: an int local
 *           swaps the 0x0201210C result and the 0x021897BC pointer between r4
 *           and r5.  func_020124E4/func_0201210C are argless as in the twin
 *           ov045_func_021F39B8.  func_021BE700/func_021BE674 take their
 *           fourth argument as u16 (the caller truncates it before the bl).
 *           func_021BE674's third parameter must be `int` here, as for
 *           func_021BE700: its own file's `unsigned int j` brings the r4/r5
 *           swap back even with the u8 local.
 */
int func_021F4200(int a0, int *a1)
{
    void *sys;
    int h;
    u8 *s;
    int *p;
    unsigned int t;
    unsigned short *q;
    int i;
    u8 c;

    sys = func_0201210C(func_020124E4((void *)a0));
    h = func_02188D2C(sys);
    s = (u8 *)func_021897BC(sys, 1);
    t = (unsigned int)func_02012EC4(func_020120F4((const struct Ctx *)func_02188C80(sys)));
    p = func_0200B3A4((struct Rec94 *)t, 6);
    q = (short unsigned int *)func_0200B3A8((struct Rec94 *)t, 6);
    switch (*a1) {
    case 0:
        c = *s;
        for (i = 0; i < 2; i++) {
            func_021BE700((void *)h, 0, c, (u16)i, 1);
            func_021BE6B0(func_021BE674((char *)h, 0, c, i), 0);
        }
        *a1 = *a1 + 1;
        break;
    case 1:
        if (func_021BE6BC(func_021BE674((char *)h, 0, *s, 0))) {
            p[*s] = 1;
            q[*s] = 1;
            return 1;
        }
        break;
    }
    return 0;
}



/*
 * note:     the work block's two int arrays are struct fields (index*4 then
 *           [#0x20]/[#0x48]); the flag test is `if (n != -1) { if (a[n])
 *           f = 1; } else f = 1;`, whose cross-jumped else arm gives the
 *           `beq SET ... beq SKIP; b SET` shape (an `||` or else-if does not).
 */
int func_021F42BC(int a0, int *a1)
{
    void *sys;
    int h;
    u8 *s;
    Work *p;
    int i;
    int f;
    u8 c;
    u8 m;
    s8 n;
    Vec *v;

    sys = func_0201210C(func_020124E4((void *)a0));
    h = func_02188D2C(sys);
    s = (u8 *)func_021897BC((char *)sys, 1);
    p = (Work *)func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((const struct Ctx *)func_02188C80(sys))), 6);
    switch (*a1) {
    case 0:
        c = s[1] + 8;
        for (i = 0; i < 2; i++) {
            func_021BE700((void *)h, 0, c, (u16)i, 1);
            func_021BE6B0(func_021BE674((char *)h, 0, c, i), 0);
        }
        *a1 = *a1 + 1;
        break;
    case 1:
        f = 0;
        if (func_021BE6BC(func_021BE674((char *)h, 0, (u8)(s[1] + 8), 0))) {
            p->a[s[1]] = 1;
            n = d_021F4628[s[1]];
            if (n != -1) {
                if (p->a[n] != 0) {
                    f = 1;
                }
            } else {
                f = 1;
            }
            if (f) {
                m = d_021F4632[s[1]];
                if (p->b[m] == 0) {
                    s[4] = m;
                    c = m + 0x12;
                    func_021BE4B4((char *)h, 0, (u16)c, 1);
                    func_021BE4B4((char *)h, 0, (u16)0x21, 0);
                    v = (Vec *)func_021BE480((char *)h, 0, c);
                    *(Vec *)func_021BE480((char *)h, 0, 0x21) = *v;
                    for (i = 0; i < 4; i++) {
                        c = i + 4;
                        func_021BE700((void *)h, 0, 0x21, (u16)c, 1);
                        func_021BE6B0(func_021BE674((char *)h, 0, 0x21, c), 0);
                        func_021BE6CC((void *)h, 0, 0x21, c, 0);
                    }
                    func_020061E4(0x6C8);
                    *a1 = *a1 + 1;
                    break;
                }
                return 1;
            }
            return 1;
        }
        break;
    case 2:
        if (func_021BE6BC(func_021BE674((char *)h, 0, 0x21, 4))) {
            for (i = 0; i < 4; i++) {
                func_021BE700((void *)h, 0, 0x21, (u16)((u8)(i + 4)), 0);
            }
            p->b[s[4]] = 1;
            m = s[4];
            func_021BE4B4((char *)h, 0, (u16)(m + 0x12), 1);
            func_021BE4B4((char *)h, 0, (u16)(m + 0x19), 0);
            func_021BE4B4((char *)h, 0, (u16)0x21, 1);
            func_020061E4(0x6DC);
            return 1;
        }
        break;
    }
    return 0;
}
