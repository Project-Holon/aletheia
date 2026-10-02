/*
 * function: func_0217D5B8
 * address:  0x0217D5B8
 * packet:   pkt_ov019_0217D5B8
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0217BB04  0x0217BB04  thumb  ov019
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0217F1EC  0x0217F1EC  thumb  ov019
 *   func_02030734  0x02030734  arm
 *   func_02012934  0x02012934  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_0217422C  0x0217422C  thumb  ov012
 *   func_02174268  0x02174268  thumb  ov012
 *   func_020307B0  0x020307B0  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0217B8E4  0x0217B8E4  thumb  ov019
 *   func_02172D50  0x02172D50  thumb  ov012
 *   func_02172D68  0x02172D68  thumb  ov012
 *   func_02173D38  0x02173D38  thumb  ov012
 *   func_0217EE10  0x0217EE10  thumb  ov019
 *   func_0217EDEC  0x0217EDEC  thumb  ov019
 *   func_0217EE1C  0x0217EE1C  thumb  ov019
 *   func_0217EDF8  0x0217EDF8  thumb  ov019
 *   func_0217F210  0x0217F210  thumb  ov019
 *   func_02172D20  0x02172D20  thumb  ov012
 *   func_021734A8  0x021734A8  thumb  ov012
 *   d_021807E8     0x021807E8  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad00[7];
    u8 x0 : 3;
    u8 b3 : 1;
} Sub;

typedef struct {
    u8 f00;
    u8 f01;
    u8 pad02[0x14 - 0x02];
    Sub *f14;
    u8 pad18[0x5a - 0x18];
    u8 b0 : 1;
    u8 b1 : 1;
} Obj;

extern int func_0217BB04(u8 *a);
extern int func_020399A8(void);
extern void func_02039C68(int a, int b, int c);
extern int func_02039CB4(int a, int b, int c);
extern int func_0217F1EC(u8 *a);
extern void *func_02030734(int heap, int size, int clear, void *file, int line);
extern void *func_02012934(void *p);
extern int func_02012EBC(int a);
extern int func_02012F2C(int a);
extern void func_0217422C(u8 *a, int b, void *c);
extern int func_02174268(u8 *a);
extern void func_020307B0(void *p);
extern int func_0200FB24(void);
extern void func_0217B8E4(u8 *a, int b);
extern void func_02172D50(u8 *a);
extern int func_02172D68(u8 *a);
extern int func_02173D38(u8 *a);
extern u16 func_0217EE10(int i);
extern u16 func_0217EDEC(int i);
extern u16 func_0217EE1C(int i);
extern u16 func_0217EDF8(int i);
extern void func_0217F210(u8 *a, int b, int c);
extern void func_02172D20(u8 *a);
extern void func_021734A8(u8 *a, int b, void *c);
extern u8 d_021807E8[];

int func_0217D5B8(u8 *a, Obj *b, int c, u8 *d)
{
    int *p;
    if (*d != 4 && *d != 5 && *d != 8 && func_0217BB04(a) == 1)
        return 1;
    switch (*d) {
    case 0:
        if (b->b1 == 1)
            *d = 6;
        else
            (*d)++;
        break;
    case 1:
        func_02039C68(func_020399A8(), 8, 0x14);
        (*d)++;
        break;
    case 2:
        if (func_02039CB4(func_020399A8(), 8, 0x14) == 1)
            (*d)++;
        break;
    case 3:
        if (func_0217F1EC(a) == 1) {
            if (b->f01 == 0xe) {
                p = func_02030734(0x41, 8, 1, d_021807E8, 0xB9A);
                p[1] = (*(int **)a)[2];
                *(int **)(a + 0x3558) = p;
                func_0217422C(a, 3, p);
            } else {
                p = func_02030734(0x41, 0x18, 1, d_021807E8, 0xBA2);
                p[1] = (*(int **)a)[2];
                p[2] = (int)func_02012934((void *)(*(int **)a)[2]);
                p[3] = func_02012EBC((*(int **)a)[2]);
                p[4] = func_02012F2C((*(int **)a)[2]);
                *(int **)(a + 0x3558) = p;
                func_0217422C(a, 4, p);
            }
            (*d)++;
        }
        break;
    case 4:
        if (func_02174268(a) == 0) {
            func_020307B0(*(int **)(a + 0x3558));
            *(int **)(a + 0x3558) = 0;
            if (func_0200FB24() != 0) {
                func_0217B8E4(a, 1);
                return 1;
            }
            func_02172D50(a);
            (*d)++;
        }
        break;
    case 5:
        if (func_02172D68(a) == 0)
            return 1;
        break;
    case 6:
        if (func_02173D38(a) == 1)
            (*d)++;
        break;
    case 7:
        switch (a[0x282B]) {
        case 1:
            if (b->f01 == 0xe)
                func_0217F210(a, c, func_0217EE10(b->f14->b3));
            else
                func_0217F210(a, c, func_0217EDEC(b->f14->b3));
            *d = 3;
            break;
        case 2:
            if (b->f01 == 0xe)
                func_0217F210(a, c, func_0217EE1C(b->f14->b3));
            else
                func_0217F210(a, c, func_0217EDF8(b->f14->b3));
            func_02172D20(a);
            *d = 8;
            break;
        }
        break;
    case 8:
        if (func_0217F1EC(a) == 1 && func_02172D68(a) == 0) {
            func_021734A8(a, 3, 0);
            return 1;
        }
        break;
    }
    return 0;
}
