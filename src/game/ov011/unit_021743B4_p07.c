/*
 * file:     unit_021743B4_p07.c
 * unit:     yes
 * function: func_02175184, func_021751A8, func_021751D4, func_02175274, func_021752DC, func_02175368
 * address:  0x02175184
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02026478 0x02026478 thumb
 *   func_02012B58 0x02012B58 thumb
 *   func_02175144  0x02175144  thumb ov011
 *   func_02013D5C  0x02013D5C  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_0216786C  0x0216786C  thumb ov010
 *   func_02012FB0  0x02012FB0  thumb
 *   sub_02082BCC  0x02082BCC  arm
 */
#include "../../matched/include/Obj02670.h"
#include "../../matched/include/Obj07330.h"
#include "../../matched/include/Obj12425.h"
#include "../../matched/include/Obj19182.h"
#include "../../matched/include/Obj09349.h"

struct BigObj;
struct Ent;
struct Report;
struct SaveBlock;
struct Work;
struct Rec44;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct Ent {
    int f0;
    int f4;
    u8 pad8[0xc];
    u16 f14;
    u16 a : 3;
    u16 rest : 13;
} Ent;

typedef struct C12 {
    int w[3];
} C12;

typedef struct Hd {
    u8 pad[0x14];
    u16 f14;
    u16 lo : 3;
    u16 x : 6;
    u16 mid : 6;
    u16 top : 1;
} Hd;

extern u32 func_02026478(void *obj);
extern u8 func_02012B58(const struct BigObj *p);
int func_02175144(u16 v, u8 *out);
u32 func_02013D5C(u32 id);
void *func_020127A4(struct SaveBlock *p);
u16 func_02012AC8(const struct Rec44 *p);
int func_0216786C(struct Work *w, struct Report *out);
u8 func_02012FB0(int a);
extern void sub_02082BCC(void *p, int c, unsigned int n);
int func_02175184(u8 *a, u8 *b);
int func_021751A8(u8 *p, int index);
void func_021751D4(u8 *p, u16 a, int b, Ent *c);
void func_02175274(u8 *p, int arg);
int func_021752DC(u8 *p);
void func_02175368(char *p);

int func_02175184(u8 *a, u8 *b)
{
    if (((struct Obj02670 *)a)->f0 == ((struct Obj02670 *)b)->f0) return 0;
    if (a[2] != b[2] && a[3] == b[3]) return 1;
    return 2;
}

int func_021751A8(u8 *p, int index)
{
    int value;
    if (index >= p[0x902]) return 0;
    value = index - func_02012B58((const struct BigObj *)func_02026478((void *)(((struct Obj07330 *)p)->f4)));
    if (value < 0) value += p[0x902];
    return value;
}


void func_021751D4(u8 *p, u16 a, int b, Ent *c)
{
    u8 x[4];
    u8 y[4];
    int r;
    int w;
    int k;
    int n;

    func_02175144(a, x);
    func_02175144(c->f14, y);
    r = func_02175184(x, y);
    switch (r) {
    case 1:
        break;
    case 2:
        break;
    case 0:
        if (func_02013D5C(a) != 0) {
            w = c->f4 % 0x400000;
            k = func_021751A8(p, c->a);
            n = p[0x902];
            if (k == n - 1 && w > 0x200000 && b < 0x200000) {
                c->f4 = w - 0x400000;
            } else if (k == 0 && w < 0x200000 && b > (n << 22) - 0x200000) {
                c->f4 = w + (n << 22);
            } else {
                c->f4 = w + (k << 22);
            }
        }
        break;
    }
}


void func_02175274(u8 *p, int arg)
{
    u8 *arr;
    u8 *h;
    int n;
    int i;
    u8 *e;

    n = func_02012B58((const struct BigObj *)func_02026478((void *)(((struct Obj12425 *)p)->f4)));
    h = p + 0x70;
    i = 0;
    arr = p + 0x8C;
    for (; i < 3; i++) {
        if ((p[0x8FB] & (1 << i)) && i != n) {
            e = arr + i * 0x1C;
            *(C12 *)(e + 4) = *(C12 *)(p + 0xE4 + i * 0x14);
            func_021751D4(p, ((struct Obj19182 *)h)->f14, arg, (struct Ent *)e);
        }
    }
}


int func_021752DC(u8 *p)
{
    int ctx;
    int v;
    int r;
    int k;
    Hd *h;

    ctx = func_02026478((void *)(((struct Obj09349 *)p)->f4));
    v = func_02012AC8(func_020127A4((struct SaveBlock *)ctx));
    h = (Hd *)(p + 0x70);
    r = func_0216786C((struct Work *)(((struct Obj09349 *)p)->f8), (struct Report *)h);
    if (h->f14 != v) {
        h->f14 = v;
        r = 1;
    }
    if (h->x != func_02012FB0(ctx)) {
        h->x = func_02012FB0(ctx);
        r = 1;
    }
    k = (*(volatile u16 *)0x02FFFFA8 & 0x8000) >> 15;
    if (h->top != k) {
        h->top = k;
        r = 1;
    }
    return r;
}


/*
 * Unlabelled Thumb leaf, seeded so that ov018 func_0217FE38 has a witness:
 * clears the four bytes at +0x15C through sub_02082BCC (fill, n bytes).
 *
 * Addresses are Black-image addresses.
 */
void func_02175368(char *p)
{
    sub_02082BCC(p + 0x15C, 0, 4);
}
