/*
 * function: func_021847CC
 * address:  0x021847CC
 * packet:   pkt_ov020_021847CC
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012374  0x02012374  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02029D44  0x02029D44  thumb
 *   func_02029D7C  0x02029D7C  thumb
 *   func_02161824  0x02161824  thumb  ov010
 *   func_0218403C  0x0218403C  thumb  ov020
 *   func_02184360  0x02184360  thumb  ov020
 *   func_02185F48  0x02185F48  thumb  ov020
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC550  0x021BC550  thumb  ov021
 *   func_021BF5B4  0x021BF5B4  thumb  ov021
 *   func_021BFD70  0x021BFD70  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short s16;

struct BigObj;
extern unsigned int func_02012A30(const struct BigObj *p);
extern int func_02161824(int a, int b);
extern void func_02012374(int a, int b);
typedef unsigned int   u32;
extern void func_02029D44(u32 a, u32 b, u32 c, u32 d);
extern void func_02029D7C(int a, int b);
extern void func_0218403C(u8 *p);
extern int func_02184360(u8 *p, int a);
extern void func_02185F48(int a);
extern int func_02188D20(int a);
extern void func_021BC550(int a, int b);
extern int func_021BF5B4(int ctx, int a, int b, int c, int d, int e);
extern int func_021BFD70(int ctx, int a, int b, int c);

int func_021847CC(int ctx, int *state, u8 *p)
{
    int v;
    int x;
    int z;
    int y;

    x = *(int *)(p + 0);
    y = *(int *)(p + 4);
    z = *(int *)(p + 8);
    v = func_02012A30((const struct BigObj *)y);

    switch (*state) {
    case 0:
        func_0218403C(p);
        func_02012374(ctx, func_02161824(x, z));
        (*state)++;
        break;
    case 1:
        func_02012374(ctx, func_021BFD70(ctx, x, z, *(int *)(p + 0x44)));
        (*state)++;
        break;
    case 2:
        func_02185F48(y);
        func_02029D44(v, y, *(u16 *)(p + 0x14), (u8)*(u16 *)(p + 0x4a));
        func_02029D7C(v, y);
        (*state)++;
        break;
    case 3:
        func_02012374(ctx, func_02184360(p, 2));
        (*state)++;
        break;
    case 4:
        func_02012374(ctx, func_021BF5B4(ctx, x, z, *(int *)(p + 0x44),
                                         *(u16 *)(p + 0x48), *(u16 *)(p + 0x4a)));
        (*state)++;
        break;
    case 5:
        func_021BC550(func_02188D20(z), *(s16 *)(p + 0x14));
        return 1;
    }
    return 0;
}
