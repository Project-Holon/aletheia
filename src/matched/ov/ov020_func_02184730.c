/*
 * function: func_02184730
 * address:  0x02184730
 * packet:   pkt_ov020_02184730
 * region:   ov020
 * compiler: 1.1p1
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
 *   func_02184360  0x02184360  thumb  ov020
 *   func_021BF58C  0x021BF58C  thumb  ov021
 *   func_021BFD34  0x021BFD34  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;

struct BigObj;
extern unsigned int func_02012A30(const struct BigObj *p);
extern int func_02161824(int a, int b);
extern void func_02012374(int a, int b);
typedef unsigned int   u32;
extern void func_02029D44(u32 a, u32 b, u32 c, u32 d);
extern void func_02029D7C(int a, int b);
extern int func_02184360(u8 *p, int a);
extern int func_021BF58C(int ctx, int a, int b);
extern int func_021BFD34(int ctx, int a, int b, u8 *p);

int func_02184730(int ctx, int *state, u8 *p)
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
        func_02012374(ctx, func_02161824(x, z));
        (*state)++;
        break;
    case 1:
        func_02012374(ctx, func_021BFD34(ctx, x, z, p + 0x34));
        (*state)++;
        break;
    case 2:
        func_02029D44(v, y, *(u16 *)(p + 0x14), (u8)*(u16 *)(p + 0x4a));
        func_02029D7C(v, y);
        (*state)++;
        break;
    case 3:
        func_02012374(ctx, func_02184360(p, 0));
        (*state)++;
        break;
    case 4:
        func_02012374(ctx, func_021BF58C(ctx, x, z));
        (*state)++;
        break;
    case 5:
        return 1;
    }
    return 0;
}
