/*
 * function: func_0217BD9C
 * address:  0x0217BD9C
 * packet:   pkt_ov019_0217BD9C
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_021736A0 is an unlabelled ov012 thumb leaf, now filed as
 * src/matched/ov/ov012_func_021736A0.c (pkt_ov012_021736A0), which resolves its call.
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *   func_02030734  0x02030734  arm
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0217422C  0x0217422C  thumb  ov012
 *   func_02174268  0x02174268  thumb  ov012
 *   func_021736A0  0x021736A0  thumb  ov012
 *   func_020307B0  0x020307B0  arm
 *   d_021807E8     0x021807E8  data  a4
 */

typedef unsigned char u8;

extern void func_020061E4(int a);
extern int *func_02030734(int a, int b, int c, int *d, int e);
extern int func_02012EBC(int a);
extern void func_0217422C(u8 *a, int b, int *c);
extern int func_02174268(u8 *a);
extern void func_021736A0(u8 *a, int b);
extern void func_020307B0(int *a);
extern int d_021807E8[];

int func_0217BD9C(u8 *a, int b, int c, u8 *d)
{
    int *p;
    int *q;
    int x, y;
    switch (*d) {
    case 0:
        if (a[0x282E] == 0)
            return 1;
        a[0x282E] = 0;
        func_020061E4(0x54B);
        p = func_02030734(4, 12, 1, d_021807E8, 0x41A);
        *p = func_02012EBC(*(int *)(*(int *)a + 8));
        *(int **)(a + 0x3558) = p;
        func_0217422C(a, 0x1d, p);
        (*d)++;
        break;
    case 1:
        if (func_02174268(a) == 0)
            (*d)++;
        break;
    case 2:
        q = *(int **)(a + 0x3558);
        x = q[2];
        y = q[1];
        if (y == 0)
            func_021736A0(a, x);
        func_020307B0(*(int **)(a + 0x3558));
        *(int **)(a + 0x3558) = 0;
        return 1;
    }
    return 0;
}
