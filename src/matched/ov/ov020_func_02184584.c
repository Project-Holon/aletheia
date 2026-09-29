/*
 * function: func_02184584
 * address:  0x02184584
 * packet:   pkt_ov020_02184584
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012374  0x02012374  thumb
 *   func_02161824  0x02161824  thumb  ov010
 *   func_0218403C  0x0218403C  thumb  ov020
 *   func_02184360  0x02184360  thumb  ov020
 *   func_021BE89C  0x021BE89C  thumb  ov021
 *   func_021BE8B8  0x021BE8B8  thumb  ov021
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern int func_02161824(int a, int b);
extern void func_02012374(int a, int b);
extern void func_0218403C(u8 *p);
extern int func_02184360(u8 *p, int a);
extern int func_021BE89C(int a, int b);
extern int func_021BE8B8(int a, int b);
extern int func_021BE8D4(int a, int b, int c, int d);
extern int func_021BE92C(int a, int b, int c, int d, int e, int f, int g);

int func_02184584(int ctx, int *state, u8 *p)
{
    int x;
    int z;

    x = *(int *)(p + 0);
    z = *(int *)(p + 8);

    switch (*state) {
    case 0:
        func_0218403C(p);
        func_02012374(ctx, func_02161824(x, z));
        (*state)++;
        break;
    case 1:
        if (*(int *)(p + 0x40) != 0 && *(int *)(p + 0x44) != 0) {
            func_02012374(ctx, func_021BE8D4(x, z, 0, 0));
        } else {
            func_02012374(ctx, func_021BE8D4(x, z, func_021BE89C(*(u16 *)(p + 0xc), *(u16 *)(p + 0x14)), 0));
        }
        (*state)++;
        break;
    case 2:
        func_02012374(ctx, func_02184360(p, *(u8 *)(p + 0x30)));
        (*state)++;
        break;
    case 3:
        if (*(int *)(p + 0x40) != 0 && *(int *)(p + 0x44) != 0) {
            func_02012374(ctx, func_021BE92C(x, z, 3, 0, 0, (u8)*(u16 *)(p + 0x48), (u8)*(u16 *)(p + 0x4a)));
        } else {
            func_02012374(ctx, func_021BE92C(x, z, func_021BE8B8(*(u16 *)(p + 0xc), *(u16 *)(p + 0x14)), 0, 1, 0, 0));
        }
        (*state)++;
        break;
    case 4:
        return 1;
    }
    return 0;
}
