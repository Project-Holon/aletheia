/*
 * function: func_021743A4
 * address:  0x021743A4
 * packet:   pkt_ov012_021743A4
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stage machine on *state (20 states), same family as func_021742BC.
 * Pooled small words 0x16/0x17/0x89 are linker overlay ids
 * (ov022/ov023/ov137).
 *
 * symbols:
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02183C3C  0x02183C3C  thumb  ov022
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_02012944  0x02012944  thumb
 *   func_02183B60  0x02183B60  thumb  ov022
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_02173E1C  0x02173E1C  thumb  ov012
 *   func_02183F84  0x02183F84  thumb  ov022
 *   func_02173EC8  0x02173EC8  thumb  ov012
 *   func_0218401C  0x0218401C  thumb  ov022
 *   func_021841A0  0x021841A0  thumb  ov022
 *   func_02173F90  0x02173F90  thumb  ov012
 *   func_0218402C  0x0218402C  thumb  ov022
 *   func_02174084  0x02174084  thumb  ov012
 *   func_021840AC  0x021840AC  thumb  ov022
 *   func_021736E0  0x021736E0  thumb  ov012
 *   func_0203D1E8  0x0203D1E8  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   func_02012984  0x02012984  thumb
 *   func_02029DF4  0x02029DF4  thumb
 *   func_02005DA4  0x02005DA4  thumb
 *   func_02005E50  0x02005E50  thumb
 *   func_02183BE0  0x02183BE0  thumb  ov022
 *   func_020145CC  0x020145CC  thumb
 *   ov022_id       0x00000016  data   a1
 *   ov023_id       0x00000017  data   a1
 *   ov137_id       0x00000089  data   a1
 *   d_02186B30     0x02186B30  data   ov023  a4
 *   d_021E1A2C     0x021E1A2C  data   ov137  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Save {
    u8  pad0[8];
    u32 f8;
} Save;

typedef struct Req {
    void *f0;
    u8    pad4[0x10];
    int   f14;
} Req;

typedef struct Sub {
    u8   pad0[8];
    Req *f8;
} Sub;

typedef struct Local {
    u8    f0;
    u8    pad1[0x59];
    u8    lo5A : 1;
    u8    flag5A : 1;
    u8    hi5A : 6;
    u8    pad5B[5];
} Local;

typedef struct Self {
    Save *f0;
    u8    pad4[0x282c];
    Local l;
    u8    pad2890[0xc98];
    void *f3528;
    u8    pad352C[0x1c];
    Sub   f3548;
} Self;

extern int   func_0200FB24(void);
extern void  func_02183C3C(void *p, Self *self);
extern void *func_021BE8D4(u32 a0, u32 a1, int a2, int a3);
extern void *func_021BE92C(u32 a0, u32 a1, int a2, int a3, int a4, int a5, int a6);
extern void  func_02012374(void *obj, void *out);
extern void *func_020144DC(u32 a0, u32 a1);
extern void  func_02034AC4(u32 id);
extern void  func_02034A5C(u32 id);
extern u32   func_02012944(u32 a);
extern void *func_02183B60(Self *self, int a, int b, u32 c);
extern u32   func_020399A8(void);
extern void  func_02039C68(u32 a0, int a1, int a2);
extern int   func_02039CB4(u32 a0, int a1, int a2);
extern int   func_02173E1C(void);
extern int   func_02183F84(void *p);
extern int   func_02173EC8(void);
extern int   func_0218401C(void *p);
extern int   func_021841A0(void *p);
extern int   func_02173F90(u8 a, u32 b);
extern int   func_0218402C(void *p);
extern int   func_02174084(u8 a, u32 b);
extern void  func_021840AC(void *p);
extern void  func_021736E0(u8 a);
extern void  func_0203D1E8(u32 a0, int a1);
extern void  func_0203D7BC(int a0);
extern void  func_020120B4(u32 a0, void *a1, void *a2, void *a3);
extern int   func_020120F0(u32 a0);
extern u32   func_02012984(u32 a);
extern int   func_02029DF4(u32 a, int b, u32 c);
extern void  func_02005DA4(u16 a, int b, int c, int d);
extern int   func_02005E50(void);
extern void  func_02183BE0(void *p);
extern void *func_020145CC(u32 a0);

extern char ov022_id[];
extern char ov023_id[];
extern char ov137_id[];
extern u8 d_02186B30[];
extern u8 d_021E1A2C[];

int func_021743A4(u32 a0, Self *self, u32 a2, u32 a3, void *obj, u32 a5, u8 *state)
{
    Sub *sub = &self->f3548;
    Local *l = &self->l;
    Req *r;
    int v;

    if (func_0200FB24() != 0 && *state > 2 && *state <= 13)
        *state = 16;
    if (self->f3528 != 0)
        func_02183C3C(self->f3528, self);

    switch (*state) {
    case 0:
        func_02012374(obj, func_021BE8D4(a0, a2, 0, 0));
        (*state)++;
        break;
    case 1:
        func_02012374(obj, func_020144DC(a0, a2));
        (*state)++;
        break;
    case 2:
        func_02034AC4((u32)ov022_id);
        self->f3528 = func_02183B60(self, 3, 5, func_02012944(self->f0->f8));
        if (l->flag5A == 1)
            *state = 5;
        else
            (*state)++;
        break;
    case 3:
        func_02039C68(func_020399A8(), 9, 0x14);
        (*state)++;
        break;
    case 4:
        if (func_02039CB4(func_020399A8(), 9, 0x14) == 1)
            *state = 7;
        break;
    case 5:
        if (func_02173E1C() == 1)
            (*state)++;
        break;
    case 6:
        if (func_02183F84(self->f3528) == 1)
            *state = 7;
        break;
    case 7:
        if (func_02173EC8() == 1)
            (*state)++;
        break;
    case 8:
        if (func_0218401C(self->f3528) == 1)
            (*state)++;
        break;
    case 9:
        v = func_021841A0(self->f3528);
        if (func_02173F90(v, func_02012944(self->f0->f8)) == 1)
            (*state)++;
        break;
    case 10:
        if (func_0218402C(self->f3528) == 1)
            (*state)++;
        break;
    case 11:
        if (l->flag5A == 1) {
            v = func_021841A0(self->f3528);
            if (func_02174084(v, func_02012944(self->f0->f8)) == 1) {
                func_021840AC(self->f3528);
                *state = 13;
            }
        } else {
            func_021736E0(l->f0);
            func_02039C68(func_020399A8(), 10, 0x14);
            *state = 12;
        }
        break;
    case 12:
        if (func_02039CB4(func_020399A8(), 10, 0x14) == 1) {
            func_0203D1E8(func_020399A8(), 1);
            *state = 13;
        }
        break;
    case 13:
        func_0203D7BC(0);
        if (l->f0 == 3) {
            r = sub->f8;
            r->f0 = self->f3528;
            func_020120B4(a0, ov023_id, d_02186B30, r);
        } else {
            r = sub->f8;
            r->f0 = self->f3528;
            func_020120B4(a0, ov137_id, d_021E1A2C, r);
        }
        (*state)++;
        break;
    case 14:
        if (func_020120F0(a0) != 0)
            break;
        if (l->f0 == 0x19) {
            if (sub->f8->f14 == 1) {
                func_02005DA4(func_02029DF4(self->f0->f8, 0x1a6, func_02012984(self->f0->f8)), 0xffff, 6, 0x3c);
                *state = 15;
            } else {
                *state = 16;
            }
        } else {
            *state = 16;
        }
        break;
    case 15:
        if (func_02005E50() == 0)
            *state = 16;
        break;
    case 16:
        if (self->f3528 != 0) {
            func_02183BE0(self->f3528);
            self->f3528 = 0;
            func_02034A5C((u32)ov022_id);
        }
        *state = 17;
        break;
    case 17:
        func_02012374(obj, func_020145CC(a0));
        (*state)++;
        break;
    case 18:
        func_02012374(obj, func_021BE92C(a0, a2, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 19:
    default:
        return 1;
    }
    return 0;
}
