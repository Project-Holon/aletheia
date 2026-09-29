/*
 * function: func_02184AB4
 * address:  0x02184AB4
 * packet:   pkt_ov020_02184AB4
 * region:   ov020
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012374  0x02012374  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02161824  0x02161824  thumb  ov010
 *   func_02184504  0x02184504  thumb  ov020
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC550  0x021BC550  thumb  ov021
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short s16;

typedef struct { int f[39]; } S9C;

extern void func_02012374(int a, int b);
extern int func_020122C0(int a, int b, void (*cb)(void), int n);
extern S9C *func_020124E8(int a);
extern int func_02161824(int a, int b);
extern void func_02184504(void);
extern int func_02188D20(int a);
extern void func_021BC550(int a, int b);
extern int func_021BE8D4(int a, int b, int c, int d);
extern int func_021BE92C(int a, int b, int c, int d, int e, int f, int g);

int func_02184AB4(int ctx, int *state, u8 *p)
{
    int x = *(int *)(p + 0);
    int z = *(int *)(p + 8);
    int r;
    S9C *o;

    switch (*state) {
    case 0:
        func_02012374(ctx, func_02161824(x, z));
        (*state)++;
        break;
    case 1:
        func_02012374(ctx, func_021BE8D4(x, z, 0, 0));
        (*state)++;
        break;
    case 2:
        r = func_020122C0(x, 0, func_02184504, 0x9c);
        o = func_020124E8(r);
        *o = *(S9C *)p;
        func_02012374(ctx, r);
        (*state)++;
        break;
    case 3:
        func_02012374(ctx, func_021BE92C(x, z, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 4:
        func_021BC550(func_02188D20(z), *(s16 *)(p + 0x14));
        return 1;
    }
    return 0;
}
