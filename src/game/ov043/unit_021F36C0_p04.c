/*
 * file:     unit_021F36C0_p04.c
 * unit:     yes
 * function: func_021F3ECC, func_021F3EEC, func_021F3F38, func_021F3FBC, func_021F3FE8, func_021F4174, func_021F41B8, func_021F4210
 * address:  0x021F3ECC
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F4480  0x021F4480  data  ov043
 *   d_021F4328     0x021F4328  data  ov043
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_02006148  0x02006148  thumb
 *   func_020061F8  0x020061F8  thumb
 *   func_02188C68  0x02188C68  thumb  ov021
 *   func_021A03A4  0x021A03A4  thumb  ov021
 *   func_021A03B8  0x021A03B8  thumb  ov021
 *   func_02188C64  0x02188C64  thumb  ov021
 *   func_021A01FC  0x021A01FC  thumb  ov021
 *   func_0218EC5C  0x0218EC5C  thumb  ov021
 *   func_0218ECC4  0x0218ECC4  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218EC30  0x0218EC30  thumb  ov021
 *   func_0218ECD4  0x0218ECD4  thumb  ov021
 */
#include "../../matched/include/Obj02756.h"
#include "../../matched/include/Obj01223.h"

struct Ctx;
struct Big;
struct Rec94;
typedef unsigned char u8;

typedef struct {
    int x;
    int y;
    int w;
    int h;
    int a;
    int b;
} R;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

extern void  func_021BE700(void *p, int i, u16 j, u16 k, int flag);
extern void func_021BE6CC(int a, int b, int c, int d, int e);
extern void *func_021BE674(void *p, int i, u16 j, u16 k);
extern void func_021BE6B0(unsigned char *p, int v);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188D2C(int *p);
extern int *func_021897BC(char *p, int idx);
extern void *func_02188C58(void *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern int func_021BE6BC(int *p);
extern void func_020061E4(u32 a);
extern int func_02006148(u32 a0);
extern void func_020061F8(int i);
extern u32 func_02188C68(u8 *p);
extern int func_021A03A4(int *p);
extern int func_021A03B8(int *p);
extern u32 func_02188C64(u8 *p);
extern void func_021A01FC(u8 *p, u32 a, u32 b, u32 c);
extern u32 func_0218EC5C(u8 *p);
extern void func_0218ECC4(int p, void *v);
extern void func_0218EC54(u8 *p);
extern void func_0218EC30(int p, int v);
extern void func_0218ECD4(int p, void *v);
int func_021F3ECC(int *p);
int func_021F3EEC(u8 i, int x, int y);
void func_021F3F38(int *a, void *b, int c);
int func_021F3FBC(int *a, int i);
void func_021F3FE8(void *a);
void func_021F4174(void *p);
void func_021F41B8(int a0, int a1, int a2, int a3, u8 *s);
int func_021F4210(u8 *s);
extern R d_021F4480[];
extern int d_021F4328[];

int func_021F3ECC(int *p)
{
    if (p[3] < 0) {
        if (p[2] >= p[1]) {
            return 1;
        }
    } else {
        if (p[2] <= p[1]) {
            return 1;
        }
    }
    return 0;
}


/*
 * Unlabelled leaf called only from func_021F3AC0. Each field gets its own
 * pool word (d_021F4480 + 0/8/4/C). The loads must be written in field
 * order x, y, w, h: loading w before y swaps the index and value registers
 * (17 bytes).
 */
int func_021F3EEC(u8 i, int x, int y)
{
    int x0;
    int y0;
    int w;
    int h;

    x0 = d_021F4480[i].x;
    y0 = d_021F4480[i].y;
    w = d_021F4480[i].w;
    h = d_021F4480[i].h;
    if (x0 <= x && x <= x0 + w - 1 && y0 <= y && y <= y0 + h - 1) {
        return 1;
    }
    return 0;
}


void func_021F3F38(int *a, void *b, int c)
{
    int r4, r6;

    if (a[c]) {
        if (d_021F4328[c]) {
            r4 = 0;
            r6 = 1;
        } else {
            r4 = 1;
            r6 = 0;
        }
    } else {
        if (d_021F4328[c]) {
            r4 = 1;
            r6 = 0;
        } else {
            r4 = 0;
            r6 = 1;
        }
    }
    func_021BE700(b, 0, c, r4, 1);
    func_021BE700(b, 0, c, r6, 0);
    func_021BE6CC((int)b, 0, (u16)c, (u16)r4, 0);
    func_021BE6B0(func_021BE674(b, 0, c, r4), 1);
}


int func_021F3FBC(int *a, int i)
{
    int r;

    if (a[i]) {
        if (d_021F4328[i]) {
            r = 0;
        } else {
            r = 1;
        }
    } else {
        if (d_021F4328[i]) {
            r = 1;
        } else {
            r = 0;
        }
    }
    return r;
}


/*
 * func_02188C64's result is bound to t before the A01FC call: passed inline,
 * the ternary fourth argument is evaluated before the call.
 */
void func_021F3FE8(void *a)
{
    void *s;
    void *r;
    int *w;
    u32 h;
    int *q;
    int flag;
    u32 t;
    int x;
    int y;

    s = func_0201210C((void *)a);
    r = (void *)func_02188D2C(s);
    w = func_021897BC(s, 1);
    h = (u32)func_02188C58(s);
    q = func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(s))), 7);
    if (w[0] != 5) {
        return;
    }
    if (q[6] == 0 && w[1] <= -0x230000) {
        q[6] = 1;
        func_021BE6B0(func_021BE674(r, 0, 6, 0), 0);
        func_020061E4(0x6cd);
        w[1] = -0x230000;
        w[6] = 1;
        ((u16 *)w)[14] = 0;
        ((u16 *)w)[15] = 0;
        w[16] = 1;
    }
    if (w[6] != 0) {
        switch (((u16 *)w)[15]) {
        case 0:
            func_021F41B8((u8)w[0], w[3], 0, (u32)h, (u8 *)(w + 8));
            func_020061E4(0x6cb);
            ((u16 *)w)[15]++;
            break;
        case 1:
            if (func_021F4210((u8 *)(w + 8))) {
                ((u16 *)w)[14]++;
                if (((u16 *)w)[14] >= 100) {
                    w[3] = -0x2000;
                    w[6] = 0;
                    func_020061E4(0x6ca);
                }
            }
            break;
        }
    }
    if (w[15] != 0) {
        flag = 0;
        if (w[3] >= 0) {
            if (w[1] >= -0x2a0000) {
                t = func_02188C68(s);
                flag = 1;
                x = func_021A03A4((int *)t);
                y = func_021A03B8((int *)t);
            }
        } else {
            if (w[1] <= -0x310000) {
                flag = 1;
                x = 0x7fdf;
                y = 9;
            }
        }
        if (flag) {
            t = func_02188C64(s);
            func_021A01FC((u8 *)t, x, y, w[3] == -0x2000 ? 0x20 : 0x10);
            w[15] = 0;
        }
    }
    if (w[16] != 0) {
        if (w[16] == 1) {
            w[16] = 2;
            return;
        }
        if (func_021BE6BC(func_021BE674(r, 0, 6, 0))) {
            func_020061F8(func_02006148(0x6cd));
            w[16] = 0;
        }
    }
}


void func_021F4174(void *p)
{
    func_021BE700(p, 0, 7, 0, 1);
    func_021BE700(p, 0, 7, 1, 0);
    func_021BE6CC((int)p, 0, 7, 0, 0);
    p = func_021BE674(p, 0, 7, 0);
    func_021BE6B0(p, 1);
}


void func_021F41B8(int a0, int a1, int a2, int a3, u8 *s)
{
    s[0] = 0;
    s[1] = 0;
    ((struct Obj02756 *)s)->f8 = a3;
    ((struct Obj02756 *)s)->fC = func_0218EC5C((u8 *)a3);
    func_0218ECC4(a3, s + 0x10);
    if (a2) {
        ((struct Obj02756 *)s)->f4 = 0x1000;
        s[2] = 2;
    } else {
        if (a0 == 5) {
            ((struct Obj02756 *)s)->f4 = 0x4000;
        } else {
            ((struct Obj02756 *)s)->f4 = 0x2000;
        }
        s[2] = 4;
    }
    if (a1 < 0) {
        ((struct Obj02756 *)s)->f4 *= -1;
    }
}


int func_021F4210(u8 *s)
{
    int v[3];

    switch (s[0]) {
    case 0:
        func_0218EC54((u8 *)(((struct Obj01223 *)s)->f8));
        s[0]++;
    case 1:
        if (s[3] % 2 == 0) {
            func_0218ECC4(((struct Obj01223 *)s)->f8, v);
            v[1] = v[1] + ((struct Obj01223 *)s)->f4;
            func_0218ECD4(((struct Obj01223 *)s)->f8, v);
            ((struct Obj01223 *)s)->f4 *= -1;
            s[1]++;
            if (s[1] >= s[2] * 2) {
                if (((struct Obj01223 *)s)->fC) {
                    func_0218EC30(((struct Obj01223 *)s)->f8, ((struct Obj01223 *)s)->fC);
                }
                func_0218ECD4(((struct Obj01223 *)s)->f8, s + 0x10);
                return 1;
            }
        }
        s[3] = (s[3] + 1) % 2;
    }
    return 0;
}
