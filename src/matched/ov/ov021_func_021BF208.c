/*
 * function: func_021BF208
 * address:  0x021BF208
 * packet:   pkt_ov021_021BF208
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

typedef signed int     s32;
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern u16 func_02188C84(u8 *p);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_020221A4(void);

int func_021BF208(u32 p0, int *st, u8 *q)
{
    u32 x = *(u32 *)(q + 4);

    switch (*st) {
    case 0:
        func_0204E720(*(u32 *)(q + 0xC), 0, 0x10, 0x10 - 0x11);
        *st = *st + 1;
        break;
    case 1:
        func_0202208C((void *)3, 4, 4, 0, 6, 1, func_02188C84((u8 *)x));
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
