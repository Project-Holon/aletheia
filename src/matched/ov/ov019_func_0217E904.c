/*
 * function: func_0217E904
 * address:  0x0217E904
 * packet:   pkt_ov019_0217E904
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0217F1EC  0x0217F1EC  thumb  ov019
 *   func_0217F210  0x0217F210  thumb  ov019
 *   func_0217F074  0x0217F074  thumb  ov019
 *   func_0217BAF0  0x0217BAF0  thumb  ov019
 *   func_0217FEB8  0x0217FEB8  thumb  ov019
 *   func_0217AE20  0x0217AE20  thumb  ov019
 *   func_02174F34  0x02174F34  thumb  ov012
 *   func_02172D68  0x02172D68  thumb  ov012
 *   func_02172D38  0x02172D38  thumb  ov012
 *   func_02172D50  0x02172D50  thumb  ov012
 *   func_02173408  0x02173408  thumb  ov012
 *   func_02173524  0x02173524  thumb  ov012
 *   func_0217422C  0x0217422C  thumb  ov012
 *   func_02174268  0x02174268  thumb  ov012
 *   func_0217505C  0x0217505C  thumb  ov012
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02012124  0x02012124  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_0203D378  0x0203D378  arm
 *   func_020392B8  0x020392B8  arm
 *   func_02039338  0x02039338  arm
 *   func_0203D1C0  0x0203D1C0  arm
 */

typedef unsigned char u8;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
} Sys;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
} Bits;

int func_0217F1EC(u8 *w);
void func_0217F210(u8 *w, int a, int msg);
void func_0217F074(u8 *w);
void func_0217BAF0(u8 *w, int a, int v);
int func_0217FEB8(u8 *p);
void func_0217AE20(u8 *w);
int func_02174F34(void);
int func_02172D68(u8 *w);
void func_02172D38(u8 *w);
void func_02172D50(u8 *w);
void func_02173408(u8 *w);
void func_02173524(u8 *w, u8 *q);
void func_0217422C(u8 *w, int b, void *c);
int func_02174268(u8 *w);
void func_0217505C(u8 *p, int a);
int func_0200FB24(void);
void func_02012124(int a, int b);
int func_020399A8(void);
void func_02039C68(int a, int b, int c);
int func_02039CB4(int a, int b, int c);
void func_0203D7BC(int a);
int func_0203D378(void);
int func_020392B8(void);
int func_02039338(void);
int func_0203D1C0(u8 i);

int func_0217E904(u8 *w, u8 *obj, int a2, u8 *state)
{
    u8 *p;
    int m;
    int i;

    p = *(u8 **)(w + 0x355C);
    if (*state < 7 && func_0200FB24() != 0 && func_0217F1EC(w) == 1) {
        func_0217BAF0(w, a2, 1);
        *state = 7;
    }
    switch (*state) {
    case 0:
        func_0217BAF0(w, a2, 1);
        if (p[0xde] == 2) {
            if (func_0217F1EC(w) == 1)
                *state = 6;
        } else {
            func_0217F210(w, a2, 0x14c);
            (*state)++;
        }
        break;
    case 1:
        if (func_02174F34() == 1)
            (*state)++;
        break;
    case 2:
        if (func_0217FEB8(p) == 1)
            (*state)++;
        break;
    case 3:
        if (func_0217F1EC(w) == 1)
            (*state)++;
        break;
    case 4:
        func_02039C68(func_020399A8(), 0x13, 0x14);
        (*state)++;
        break;
    case 5:
        if (func_02039CB4(func_020399A8(), 0x13, 0x14) == 1) {
            func_0203D7BC(0);
            (*state)++;
        }
        break;
    case 6:
        if (func_0203D378() == 1) {
            m = p[0x16e];
            if (func_020392B8() <= 1) {
                (*state)++;
                break;
            }
            for (i = 0; i < 5; i++) {
                if (i != func_02039338() && ((1 << i) & m)) {
                    if (func_0203D1C0(i) == 1)
                        break;
                }
            }
            if (i == 5)
                (*state)++;
        } else {
            (*state)++;
        }
        break;
    case 7:
        if (((Bits *)(p + 0xc8))->b1 == 1 && func_02172D68(w) == 1)
            return 0;
        if (func_0200FB24() != 0) {
            func_0217F074(w);
            func_02012124((*(Sys **)w)->fc, 1);
            return 0;
        }
        func_02172D38(w);
        (*state)++;
        break;
    case 8:
        if (func_02172D68(w) == 0)
            (*state)++;
        break;
    case 9:
        p[0xc9] = 1;
        func_02173408(w);
        func_0217AE20(w);
        func_02173524(w, obj + 0x14);
        func_0217422C(w, 0x19, 0);
        (*state)++;
        break;
    case 10:
        if (func_02174268(w) == 0) {
            if (*(u8 **)(w + 0x355C) != 0) {
                func_0217505C(*(u8 **)(w + 0x355C), (*(Sys **)w)->fc);
                *(u8 **)(w + 0x355C) = 0;
            }
            func_02172D50(w);
            (*state)++;
        }
        break;
    case 11:
        if (func_02172D68(w) == 0)
            return 1;
        break;
    }
    return 0;
}
