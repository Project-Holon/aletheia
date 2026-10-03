/*
 * function: func_0218261C
 * address:  0x0218261C
 * packet:   pkt_ov018_0218261C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012F08  0x02012F08  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_020127B8  0x020127B8  thumb
 *   func_0200C274  0x0200C274  thumb
 *   func_0200C29C  0x0200C29C  thumb
 *   func_02007E3C  0x02007E3C  thumb
 *   func_02007E50  0x02007E50  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201EF40  0x0201EF40  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02173AE0  0x02173AE0  thumb  ov011
 *   func_021763D8  0x021763D8  thumb  ov011
 *   func_0217F3C4  0x0217F3C4  thumb  ov018
 *   func_0217F40C  0x0217F40C  thumb  ov018
 *   func_0217F420  0x0217F420  thumb  ov018
 *   func_0217F4C4  0x0217F4C4  thumb  ov018
 *   func_0217F4D8  0x0217F4D8  thumb  ov018
 *   func_0217F508  0x0217F508  thumb  ov018
 *   func_0217FE38  0x0217FE38  thumb  ov018
 *   d_021839A4     0x021839A4  data  a2
 *
 * EXACT*: the listing extent runs into two unlabelled 8-byte Thumb
 * followers at 0x021828A8 and 0x021828B0 (ldr r3,[pc,#0]; bx r3 thunks
 * to 0x0218236D and 0x021825F9).
 *
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
} Outer;

extern const u16 d_021839A4[6][5];

struct BigObj;
struct Blk34;
struct Ctx;
struct Obj;
struct WordSet;
extern void *func_020124E4(struct Obj *p);
extern void *func_02012138(void *);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern void *func_02012F08(int *p);
extern void *func_0201292C(const struct BigObj *p);
extern void *func_020127B8(void *);
extern u32 func_0200C274(struct Blk34 *p);
extern u32 func_0200C29C(struct Blk34 *p, u32 v);
extern u32 func_02007E3C(u8 *base, u16 id, u16 qty, u16 d);
extern u32 func_02007E50(u8 *base, u16 id, u16 qty, u16 d);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u8   *func_02158344(void *);
extern int   func_02173AE0(u8 *, u8, int, u8);
extern void func_021763D8(u8 *p, u32 key);
extern void  func_0217F3C4(u8 *, int);
extern int   func_0217F40C(u8 *);
extern int   func_0217F420();
extern void  func_0217F4C4(u8 *);
extern void  func_0217F4D8(u8 *, void *);
extern int   func_0217F508(u8 *);
extern void  func_0217FE38(u8 *, Outer *);

int func_0218261C(void *a, int *state, Outer *c)
{
    void *sub;
    void *x;
    u8 *v;
    u16 *h;
    void *t;
    int flag;
    int r;

    sub = func_020124E4(a);
    x = func_020120F4(sub);
    t = func_02012138(sub);
    h = c->h58;
    v = func_02158344(t);
    if (v == 0) {
        if (func_0217F40C((u8 *)c + 0x10) == 0) {
            return 0;
        }
        if (*state < 8 && *state != 2 && *state != 3) {
            func_0217F3C4((u8 *)c + 0x10, 4);
            *state = 8;
            c->f98 = 1;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        func_0201F02C(c->p10, 0, c->f78);
        func_0201EF40(c->p10, 1, h[0]);
        func_0201EFA4(c->p10, 2, h[1], 5, 0, 1);
        func_0201F02C(c->p10, 3, func_02012944(func_020120F4(sub)));
        func_0217F3C4((u8 *)c + 0x10, d_021839A4[0][c->b42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C((u8 *)c + 0x10) == 1) {
            func_0217F3C4((u8 *)c + 0x10, d_021839A4[1][c->b42]);
            (*state)++;
        }
        break;
    case 2:
        if (func_0217F40C((u8 *)c + 0x10) == 1) {
            func_0217F4D8((u8 *)c + 0x10, sub);
            (*state)++;
        }
        break;
    case 3:
        r = func_0217F508((u8 *)c + 0x10);
        flag = 0;
        switch (r) {
        case 0:
            func_0217F4C4((u8 *)c + 0x10);
            if (h[1] > func_0200C274(func_02012F08(x))) {
                flag = 1;
                *state = 5;
            } else if (func_02007E3C(func_0201292C(x), h[0], 1, 0x15) == 0) {
                flag = 1;
                *state = 6;
            } else {
                *state = 4;
            }
            break;
        case 1:
            func_0217F4C4((u8 *)c + 0x10);
            flag = 1;
            *state = 7;
            break;
        }
        if (flag == 1) {
            func_021763D8(func_020127B8(x), 3);
        }
        break;
    case 4:
        if (func_02173AE0(v, v[0x154], 7, v[0x158]) == 1) {
            func_0200C29C(func_02012F08(x), h[1]);
            func_02007E50(func_0201292C(x), h[0], 1, 0x15);
            func_0217F3C4((u8 *)c + 0x10, d_021839A4[5][c->b42]);
            *state = 8;
        }
        break;
    case 5:
        if (func_02173AE0(v, v[0x154], 9, v[0x158]) == 1) {
            func_0217F3C4((u8 *)c + 0x10, d_021839A4[3][c->b42]);
            *state = 8;
        }
        break;
    case 6:
        if (func_02173AE0(v, v[0x154], 10, v[0x158]) == 1) {
            func_0217F3C4((u8 *)c + 0x10, d_021839A4[4][c->b42]);
            *state = 8;
        }
        break;
    case 7:
        if (func_02173AE0(v, v[0x154], 8, v[0x158]) == 1) {
            func_0217F3C4((u8 *)c + 0x10, d_021839A4[2][c->b42]);
            *state = 8;
        }
        break;
    case 8:
        if (func_0217F40C((u8 *)c + 0x10) == 1) {
            *state = 9;
        }
        break;
    case 9:
        if (func_0217F420() == 1) {
            *state = 10;
        }
        break;
    case 10:
        func_0217FE38(v, c);
        return 1;
    }
    return 0;
}
