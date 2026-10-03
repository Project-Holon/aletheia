/*
 * function: func_0217CFA8
 * address:  0x0217CFA8
 * packet:   pkt_ov019_0217CFA8
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0217BB04  0x0217BB04  thumb  ov019
 *   func_02034714  0x02034714  arm
 *   func_02030734  0x02030734  arm
 *   func_0216F40C  0x0216F40C  thumb  ov010
 *   func_02082D44  0x02082D44  arm
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0217EE4C  0x0217EE4C  thumb  ov019
 *   func_0217F210  0x0217F210  thumb  ov019
 *   func_02173BB0  0x02173BB0  thumb  ov012
 *   func_0217F1EC  0x0217F1EC  thumb  ov019
 *   func_0216F7F4  0x0216F7F4  thumb  ov010
 *   func_0217422C  0x0217422C  thumb  ov012
 *   func_02174268  0x02174268  thumb  ov012
 *   func_020307B0  0x020307B0  arm
 *   func_0203D378  0x0203D378  arm
 *   func_0217B8E4  0x0217B8E4  thumb  ov019
 *   d_021807E4     0x021807E4  data  a4
 *   d_021807E8     0x021807E8  data  a4
 */

typedef unsigned char u8;

typedef struct {
    u8 pad00[0x14];
    u8 *f14;
    u8 pad18[0x5d - 0x18];
    u8 f5d;
} Obj;

extern int func_0217BB04(u8 *a);
extern void func_02034714(void *a, int b, void *c);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern void func_0216F40C(void *a, int b, int c, int d, int e);
extern void func_02082D44(void *a, void *b, int c);
extern int func_020399A8(void);
extern void func_02039C68(int a, int b, int c);
extern int func_02039CB4(int a, int b, int c);
extern int func_0217EE4C(u8 *a, int b, int c);
typedef unsigned int   u32;
extern void func_0217F210(u8 *p, int a, u32 b);
extern int func_02173BB0(u8 *a);
extern u32 func_0217F1EC(u8 *p);
extern void *func_0216F7F4(int a, void *b, int c);
extern void func_0217422C(u8 *a, int b, void *c);
extern int func_02174268(u8 *a);
extern void func_020307B0(void *p);
extern u32 func_0203D378(void);
extern void func_0217B8E4(u8 *a, int b);
extern u8 d_021807E4[];
extern u8 d_021807E8[];

int func_0217CFA8(u8 *a, Obj *b, int c, u8 *d)
{
    u8 *q;
    if (func_0217BB04(a) == 1)
        return 1;
    switch (*d) {
    case 0:
        if (*(void **)(a + 0x3540) != 0 || *(void **)(a + 0x3544) != 0)
            func_02034714(d_021807E4, 0, d_021807E4);
        *(void **)(a + 0x3540) = func_02030734(0x41, 0x678, 1, (const char *)d_021807E8, 0x9B3);
        *(void **)(a + 0x3544) = func_02030734(0x41, 0x678, 1, (const char *)d_021807E8, 0x9B5);
        func_0216F40C(*(void **)(a + 0x3540), (*(int **)a)[2], 1, 0, 0x41);
        func_02082D44(*(void **)(a + 0x3540), *(void **)(a + 0x3544), 0x678);
        func_02039C68(func_020399A8(), 3, 0x14);
        func_0217F210(a, c, func_0217EE4C(a, b->f14[0x26], b->f14[0x27]));
        (*d)++;
        break;
    case 1:
        if (func_02039CB4(func_020399A8(), 3, 0x14) == 1)
            (*d)++;
        break;
    case 2:
        if (func_02173BB0(a) == 1)
            (*d)++;
        break;
    case 3:
        if (b->f5d == 1 && func_0217F1EC(a) == 1) {
            q = *(u8 **)(a + 0x3544);
            q[4] |= 0x20;
            *(void **)(a + 0x353C) = func_0216F7F4((*(int **)a)[2], *(void **)(a + 0x3544), 0x41);
            (*d)++;
        }
        break;
    case 4:
        func_02039C68(func_020399A8(), 4, 0x14);
        (*d)++;
        break;
    case 5:
        if (func_02039CB4(func_020399A8(), 4, 0x14) == 1)
            (*d)++;
        break;
    case 6:
        func_0217422C(a, 1, *(void **)(a + 0x353C));
        (*d)++;
        break;
    case 7:
        if (func_02174268(a) == 0)
            (*d)++;
        break;
    case 8:
        func_0217F210(a, c, 0x10);
        func_02039C68(func_020399A8(), 5, 0x14);
        (*d)++;
        break;
    case 9:
        if (func_0217F1EC(a) != 0 && func_02039CB4(func_020399A8(), 5, 0x14) == 1) {
            func_020307B0(*(void **)(a + 0x3540));
            func_020307B0(*(void **)(a + 0x3544));
            *(void **)(a + 0x353C) = 0;
            *(void **)(a + 0x3540) = 0;
            *(void **)(a + 0x3544) = 0;
            if (func_0203D378() == 1)
                func_0217B8E4(a, 7);
            else
                func_0217B8E4(a, 9);
            return 1;
        }
        break;
    }
    return 0;
}
