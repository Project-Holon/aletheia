/*
 * function: func_0217F6A0
 * address:  0x0217F6A0
 * packet:   pkt_ov018_0217F6A0
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02012B80  0x02012B80  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_021757A8  0x021757A8  thumb  ov011
 *   func_0217BF1C  0x0217BF1C  thumb  ov018
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_021907A8  0x021907A8  thumb  ov021
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_0215841C  0x0215841C  thumb  ov010
 *   func_02190740  0x02190740  thumb  ov021
 *   func_020457B0  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_021583EC  0x021583EC  thumb  ov010
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02190758  0x02190758  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_02173D2C  0x02173D2C  thumb  ov011
 *   func_02175FB4  0x02175FB4  thumb  ov011
 *   func_02173C6C  0x02173C6C  thumb  ov011
 *   func_0217BF28  0x0217BF28  thumb  ov018
 *   func_0219077C  0x0219077C  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02190728  0x02190728  thumb  ov021
 *   func_02045C04  0x02045C04  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int f0;
    int f4;
    int f8;
    u16 *fC;
} Ctx;

void *func_020124E4(void *a0);
void *func_020120F4(void *a0);
struct Ctx;
u32 func_02012138(const struct Ctx *p);
struct Ctx;
void *func_0201210C(const struct Ctx *p);
u8 *func_02158344(int a0);
int func_0200FB24(void);
u8 func_02012B80(void *a0);
u8 func_02012B58(void *a0);
void func_021757A8(void *p);
void func_0217BF1C(void *p);
void *func_02188C54(u8 *a0);
int func_021904B0(int a0, int a1);
int func_021907A8(void *a0, int a1);
int func_0201EC64(int a0);
void func_020061E4(int a0);
int func_0215841C(void *p);
void func_02190740(int a0, int a1, int a2, int a3);
int func_020457B0(int a0, int a1);
int func_02045EC0(int a0, int a1);
int func_021583EC(void *a0, int a1);
void func_0201F02C(int a0, int a1, int a2);
void func_0201F250(int a0, int a1, int a2);
void func_02190758(int a0, int a1, int a2, int a3);
void func_02045808(int a0);
int func_0203D1B4(void);
int func_02173D2C(u8 *w, int a1);
int func_02175FB4(void *p);
int func_02173C6C(u8 *w, int a1);
int func_0217BF28(void *p);
int func_0219077C(int a0);
u32 func_020362DC(void);
void func_0201ED04(int a0);
void func_02190728(int a0);
void func_02045C04(int a0);

int func_0217F6A0(void *a0, int *state, Ctx *c)
{
    void *h;
    void *s;
    u32 k;
    u8 *w;
    void *t;
    int flag;

    h = func_020124E4(a0);
    s = func_020120F4(h);
    k = func_02012138(h);
    t = func_0201210C(h);
    flag = 0;
    w = func_02158344(k);
    if (w == 0 && *state > 0 && *state < 5) {
        *state = 5;
    }
    switch (*state) {
    case 0: {
        void *g;
        int a;
        int b;

        if (func_0200FB24() != 0 || (w == 0 && func_02012B80(s) != func_02012B58(s))) {
            *state = 7;
            break;
        }
        if (w != 0) {
            func_021757A8(w + 0x1AC);
            func_0217BF1C(w + 0x914);
        }
        g = func_02188C54(t);
        c->f0 = func_021904B0((int)g, 0x2D);
        c->f4 = func_021907A8(g, c->f0);
        c->f8 = func_0201EC64(4);
        func_020061E4(0x547);
        if (w == 0 || func_0215841C(s) == func_02012B58(s)) {
            func_02190740(c->f4, 0, 0, 0x49);
            flag = 1;
        } else {
            a = func_020457B0(0x100, 0x15);
            b = func_02045EC0(c->f0, 0x4A);
            func_0201F02C(c->f8, 0, func_021583EC(s, func_0215841C(s)));
            func_0201F250(c->f8, a, b);
            func_02190758(c->f4, 0, 0, a);
            func_02045808(b);
            func_02045808(a);
        }
        if (func_0203D1B4() <= 1) {
            if (flag == 0) {
                *c->fC = 0;
            } else {
                *c->fC = 1;
            }
            *state = 5;
            break;
        }
        (*state)++;
    }
    case 1:
        if (func_02173D2C(w, func_0215841C(s)) == 1) {
            (*state)++;
        }
        break;
    case 2:
        if (func_02175FB4(w + 0x1AC + func_0215841C(s) * 0x28) == 1) {
            (*state)++;
        }
        break;
    case 3:
        if (func_02173C6C(w, func_0215841C(s)) == 1) {
            (*state)++;
        }
        break;
    case 4:
        if (func_0217BF28(w + 0x914) == 1) {
            *c->fC = 1;
            *state = 5;
        }
        break;
    case 5:
        if (func_0219077C(c->f4) == 1) {
            (*state)++;
        }
        break;
    case 6:
        if (func_020362DC() & 0xF3) {
            func_0201ED04(c->f8);
            func_02190728(c->f4);
            func_02045C04(c->f0);
            (*state)++;
        }
        break;
    case 7:
        return 1;
    }
    return 0;
}
