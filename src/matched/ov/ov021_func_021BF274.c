/*
 * function: func_021BF274
 * address:  0x021BF274
 * packet:   pkt_ov021_021BF274
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204E720  0x0204E720  arm
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_0202208C  0x0202208C  thumb
 *   func_020221A4  0x020221A4  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0204E720(u32 a, u32 b, u32 c, u32 d);
extern u16 func_02188C84(u32 p);
extern void func_0202208C(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern int func_020221A4(void);

int func_021BF274(u32 p0, int *st, u8 *q)
{
    u32 x = *(u32 *)(q + 4);

    switch (*st) {
    case 0:
        func_0204E720(*(u32 *)(q + 0xC), 0, 0x10, 0x10 - 0x11);
        *st = *st + 1;
        break;
    case 1:
        func_0202208C(3, 10, 10, 0, 6, 1, func_02188C84(x));
        *st = *st + 1;
        break;
    case 2:
        if (func_020221A4() != 0)
            *st = *st + 1;
        break;
    case 3:
        return 1;
    }
    return 0;
}
