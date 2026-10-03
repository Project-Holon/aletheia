/*
 * function: func_0218466C
 * address:  0x0218466C
 * packet:   pkt_ov020_0218466C
 * region:   ov020
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012374  0x02012374  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02029D44  0x02029D44  thumb
 *   func_02029D7C  0x02029D7C  thumb
 *   func_02161824  0x02161824  thumb  ov010
 *   func_02184360  0x02184360  thumb  ov020
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC550  0x021BC550  thumb  ov021
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short s16;

extern int func_02012A30(int a);
extern int func_02161824(int a, int b);
extern void func_02012374(int a, int b);
typedef unsigned int   u32;
extern void func_02029D44(u32 a, u32 b, u32 c, u32 d);
extern void func_02029D7C(int a, int b);
extern int func_02184360(u8 *p, int a);
extern int func_02188D20(int a);
extern void func_021BC550(int a, int b);
extern int func_021BE8D4(int a, int b, int c, int d);
extern int func_021BE92C(int a, int b, int c, int d, int e, int f, int g);

int func_0218466C(int ctx, int *state, u8 *p)
{
    int v;
    int x;
    int z;
    int y;

    x = *(int *)(p + 0);
    y = *(int *)(p + 4);
    z = *(int *)(p + 8);
    v = func_02012A30(y);

    switch (*state) {
    case 0:
        func_02012374(ctx, func_02161824(x, z));
        (*state)++;
        break;
    case 8:
        func_02012374(ctx, func_021BE8D4(x, z, 2, 0));
        (*state)++;
        break;
    case 9:
        func_02029D44(v, y, *(u16 *)(p + 0x14), (u8)*(u16 *)(p + 0x4a));
        func_02029D7C(v, y);
        (*state)++;
        break;
    case 10:
        func_02012374(ctx, func_02184360(p, *(u8 *)(p + 0x30)));
        (*state)++;
        break;
    case 11:
        func_02012374(ctx, func_021BE92C(x, z, 2, 0, 0, 0, 0));
        (*state)++;
        break;
    case 12:
        func_021BC550(func_02188D20(z), *(s16 *)(p + 0x14));
        return 1;
    default:
        (*state)++;
        break;
    }
    return 0;
}
