/*
 * function: func_021823A8
 * address:  0x021823A8
 * packet:   pkt_ov018_021823A8
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201EF40  0x0201EF40  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201235C  0x0201235C  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0217405C  0x0217405C  thumb  ov011
 *   func_02173B9C  0x02173B9C  thumb  ov011
 *   func_021753B8  0x021753B8  thumb  ov011
 *   func_02175514  0x02175514  thumb  ov011
 *   func_02175CF4  0x02175CF4  thumb  ov011
 *   func_0217CA84  0x0217CA84  thumb  ov018
 *   func_0217F3C4  0x0217F3C4  thumb  ov018
 *   func_0217F40C  0x0217F40C  thumb  ov018
 *   func_0217F420  0x0217F420  thumb  ov018
 *   func_0217FE38  0x0217FE38  thumb  ov018
 *   func_021804F8  0x021804F8  thumb  ov018
 *   d_021839E0     0x021839E0  data  a2
 *
 * lever: func_021804F8 reads the live r1 as its second argument.
 * The f9C comparison value is forwarded unchanged on the taken arm.
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Outer {
    u8   pad00[0x10];
    void *p10;
    u8   pad14[0x42 - 0x14];
    u8   b42;
    u8   pad43[0x58 - 0x43];
    u16  h58[2];
    u8   pad5C[0x78 - 0x5C];
    u8   f78[0x98 - 0x78];
    int  f98;
    int  f9C;
    int  fA0;
} Outer;

extern const u16 d_021839E0[5][5];

extern void *func_020124E4(void *);
extern void *func_02012138(void *);
extern void *func_020120F4(void *);
extern void *func_02012944(void *);
extern void  func_0201F02C(void *, int, void *);
extern void  func_0201EF40(void *, int, u32);
extern void  func_0201EFA4(void *, u32, u32, u32, u32, u32);
extern void  func_0201235C(void *, void *);
extern u32   func_020362DC(void);
extern u8   *func_02158344(void *);
extern int   func_0217405C(u8 *, u8 *);
extern int   func_02173B9C(u8, u8);
extern void  func_021753B8(u8 *);
extern int   func_02175514(u8 *);
extern int   func_02175CF4(u8 *, u8 *);
extern void *func_0217CA84(void *, int);
extern void  func_0217F3C4(u8 *, int);
extern int   func_0217F40C(u8 *);
extern int   func_0217F420();
extern void  func_0217FE38(u8 *, Outer *);
extern void *func_021804F8(void *, int);

int func_021823A8(void *a, int *state, Outer *c)
{
    void *sub;
    u8 *v;
    u16 *h;

    sub = func_020124E4(a);
    v = func_02158344(func_02012138(sub));
    if (v == 0 && *state <= 4) {
        if (func_0217F40C((u8 *)c + 0x10) == 0) {
            return 0;
        }
        if (*state < 9) {
            func_0217F3C4((u8 *)c + 0x10, 4);
            *state = 9;
            c->f98 = 1;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        func_0201F02C(c->p10, 0, c->f78);
        h = c->h58;
        func_0201EF40(c->p10, 1, h[0]);
        func_0201EFA4(c->p10, 2, h[1], 5, 0, 1);
        func_0201F02C(c->p10, 3, func_02012944(func_020120F4(sub)));
        func_0217F3C4((u8 *)c + 0x10, d_021839E0[0][c->b42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C((u8 *)c + 0x10) == 1) {
            switch (func_02175514(v)) {
            case 7:
                *state = 2;
                break;
            case 3:
            case 8:
                *state = 5;
                break;
            case 9:
                *state = 6;
                break;
            case 10:
                *state = 7;
                break;
            default:
                if ((func_020362DC() & 2) && func_02173B9C(v[0x154], v[0x158]) == 1) {
                    func_021753B8(v);
                    c->fA0 = 1;
                    *state = 8;
                }
                break;
            }
        }
        break;
    case 2:
        func_0217F3C4((u8 *)c + 0x10, d_021839E0[4][c->b42]);
        (*state)++;
        break;
    case 3:
        if (func_0217405C(v, v + 0x1AC) == 1) {
            (*state)++;
        }
        break;
    case 4:
        if (func_02175CF4(v, v + 0x1AC) != 0) {
            c->f9C = 1;
            *state = 9;
        }
        break;
    case 5:
        func_0217F3C4((u8 *)c + 0x10, d_021839E0[1][c->b42]);
        *state = 9;
        break;
    case 6:
        func_0217F3C4((u8 *)c + 0x10, d_021839E0[2][c->b42]);
        *state = 9;
        break;
    case 7:
        func_0217F3C4((u8 *)c + 0x10, d_021839E0[3][c->b42]);
        *state = 9;
        break;
    case 8:
        *state = 11;
        break;
    case 9:
        if (func_0217F40C((u8 *)c + 0x10) == 1) {
            *state = 10;
        }
        break;
    case 10:
        if (func_0217F420() == 1) {
            *state = 11;
        }
        break;
    case 11:
        func_0217FE38(v, c);
        if (c->f9C == 1) {
            func_0201235C(a, func_021804F8(sub, c->f9C));
            return 0;
        }
        if (c->fA0 == 0) {
            func_0201235C(a, func_0217CA84(sub, 2));
            return 0;
        }
        func_0201235C(a, func_0217CA84(sub, 0));
        return 0;
    }
    return 0;
}
