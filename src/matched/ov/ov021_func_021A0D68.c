/*
 * function: func_021A0D68
 * address:  0x021A0D68
 * packet:   pkt_ov021_021A0D68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02189A2C  0x02189A2C  thumb  ov021
 *   func_0202208C  0x0202208C  thumb
 *   func_020221A4  0x020221A4  thumb
 *   d_021D872C  0x021D872C  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

typedef struct {
    void (*init)(u32 *a, u32 prev);
    void (*update)(u32 *a, s32 flag);
    u32 f8;
    u32 fC;
    void (*exit)(u32 *a);
    u32 f14;
    u32 f18;
} Mode;

extern Mode d_021D872C[];
extern s32 func_02189A2C(u32 a);
extern void func_0202208C(int a, int b, int c, int d, int e, int f, int g);
extern int func_020221A4(void);

void func_021A0D68(u32 *a)
{
    switch (a[2]) {
    case 0:
        d_021D872C[a[0]].update(a, func_02189A2C(a[5]) == 0);
        break;
    case 1:
        func_0202208C(4, 0, 0, 0, 1, 1, *(u16 *)(a + 3));
        a[2] = 2;
        break;
    case 2:
        if (func_020221A4() == 1) {
            d_021D872C[a[0]].exit(a);
            d_021D872C[a[1]].init(a, a[0]);
            a[0] = a[1];
            a[2] = 4;
        }
        break;
    case 3:
        break;
    case 4:
        func_0202208C(4, 1, 1, 0, 1, 1, *(u16 *)(a + 3));
        a[2] = 5;
        break;
    case 5:
        if (func_020221A4() == 1) {
            a[2] = 0;
        }
        d_021D872C[a[0]].update(a, func_02189A2C(a[5]) == 0);
        break;
    }
}
