/*
 * function: func_0217D1C0
 * address:  0x0217D1C0
 * packet:   pkt_ov018_0217D1C0
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02012138            0x02012138  thumb
 *   func_020120F4            0x020120F4  thumb
 *   func_020120F8            0x020120F8  thumb
 *   func_02012AC8            0x02012AC8  thumb
 *   func_0201283C            0x0201283C  thumb
 *   func_0201058C            0x0201058C  thumb
 *   func_02037174            0x02037174  arm
 *   func_02158344            0x02158344  thumb  ov010
 *   func_0217F008            0x0217F008  thumb  ov018
 *   func_02012B70            0x02012B70  thumb
 *   func_020061E4            0x020061E4  thumb
 *   func_020310C4            0x020310C4  arm
 *   func_0201C4E4            0x0201C4E4  thumb
 *   func_02045770            0x02045770  arm
 *   func_0201C6C4            0x0201C6C4  thumb
 *   func_02045334            0x02045334  arm
 *   func_020257D0            0x020257D0  thumb
 *   func_0217F0FC            0x0217F0FC  thumb  ov018
 *   G2x_SetBlendBrightness_  0x0207D658  arm
 *   func_0217EC7C            0x0217EC7C  thumb  ov018
 *   func_0215841C            0x0215841C  thumb  ov010
 *   func_0203D1C0            0x0203D1C0  arm
 *   func_021746AC            0x021746AC  thumb  ov011
 *   func_02158428            0x02158428  thumb  ov010
 *   func_0201210C            0x0201210C  thumb
 *   func_02188CCC            0x02188CCC  thumb  ov021
 *   func_02034714            0x02034714  arm
 *   str_02183B28             0x02183B28  data  a1
 */
#include "../include/Obj00399.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { u8 a : 7; u8 b : 1; } FlagsF8;

extern char str_02183B28[];

struct Ctx;
unsigned int func_02012138(const struct Ctx *);
struct BigObj;
struct Descriptor;
struct Obj;
struct PrintSys;
struct Tcbl;
void *func_020120F4(const struct Ctx *p);
u8 *func_020120F8(const struct Ctx *p);
struct Rec44;
unsigned short func_02012AC8(const struct Rec44 *);
u32 func_0201283C(const struct BigObj *p);
u32 func_0201058C(void *key);
void func_02037174(void);
int func_02158344(int a0);
void func_0217F008(u8 *w, u8 *p);
u8 func_02012B70(const struct BigObj *p);
void func_020061E4(u32 a);
void func_020310C4(struct Tcbl *p);
u32 func_0201C4E4(struct PrintSys *ps);
void *func_02045770(struct Descriptor *p);
u32 func_0201C6C4(struct PrintSys *p, void *v);
void func_02045334(struct Descriptor *d);
void func_020257D0(struct Obj *o);
int func_0217F0FC(u8 *w);
void G2x_SetBlendBrightness_(volatile u16 *reg, int plane, int brightness);
void func_0217EC7C(u8 *p, u8 *w, int q);
int func_0215841C(void *);
int func_0203D1C0(u8);
int func_021746AC(u8 *p, u8);
u8 func_02158428(u8 *p);
void *func_0201210C(const struct Ctx *p);
u32 func_02188CCC(u8 *p);
void func_02034714(const char *expr, u32 line, const char *file);

#define REG_DB_BLDCNT_SUB (*(volatile u16 *)0x04001050)

void func_0217D1C0(u8 *w, int b)
{
    void *s1;
    void *s2;
    u8 *p;
    int q;
    int i;
    int v;
    void *h;

    s1 = (void *)func_02012138(((struct Obj00399 *)w)->f0);
    s2 = func_020120F4(((struct Obj00399 *)w)->f0);
    p = (u8 *)func_02158344((int)s1);
    q = func_02012AC8((const struct Rec44 *)func_020120F8(((struct Obj00399 *)w)->f0));
    func_0201058C((void *)func_0201283C(s2));
    func_02037174();
    if (p == 0 || (p != 0 && ((FlagsF8 *)(p + 0x8F8))->b == 0)) {
        func_0217F008(w, p);
    }
    if (w[0x11E] < w[0xDA]) {
        if (func_02012B70(s2) == 1) {
            func_020061E4(0x699);
        }
        w[0x11E] = w[0xDA];
    }
    func_020310C4(((struct Obj00399 *)w)->f20);
    func_0201C4E4(((struct Obj00399 *)w)->f28);
    h = ((struct Obj00399 *)w)->f28;
    if (w[0x48] != 0) {
        if (func_0201C6C4(h, func_02045770(((struct Obj00399 *)w)->f44)) == 0) {
            func_02045334(((struct Obj00399 *)w)->f44);
            w[0x48] = 0;
        }
    }
    h = ((struct Obj00399 *)w)->f28;
    if (w[0x50] != 0) {
        if (func_0201C6C4(h, func_02045770(((struct Obj00399 *)w)->f4C)) == 0) {
            func_02045334(((struct Obj00399 *)w)->f4C);
            w[0x50] = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        if (func_0201C6C4(((struct Obj00399 *)w)->f28, *(void **)(w + 0xB4 + i * 4)) == 0) {
            func_020257D0(*(void **)(w + 0xC0 + i * 4));
        }
    }
    if (b == 0) {
        if (func_0217F0FC(w) == 1 || w[0x116] == 1) {
            REG_DB_BLDCNT_SUB = 0;
        } else {
            G2x_SetBlendBrightness_(&REG_DB_BLDCNT_SUB, 0x3F, -8);
            return;
        }
    } else {
        REG_DB_BLDCNT_SUB = 0;
    }
    if (b == 1) {
        func_0217EC7C(p, w, q);
    }
    if (p != 0 && w[0x106] == 1) {
        v = func_0215841C(s2);
        if (func_0203D1C0(v) == 0) {
            w[0x106] = 0;
            return;
        }
        switch (w[0x107]) {
        case 0:
            if (func_021746AC(p, v) == 1) {
                w[0x107]++;
            }
            break;
        case 1:
            if (func_02158428(p) == 1) {
                func_02188CCC(func_0201210C(((struct Obj00399 *)w)->f0));
                ((struct Obj00399 *)w)->f110 = 0x126;
                w[0x112] = 1;
                w[0x106] = 0;
            }
            break;
        default:
            func_02034714(str_02183B28, 0, str_02183B28);
            break;
        }
    }
}
