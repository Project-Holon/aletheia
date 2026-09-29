/*
 * function: func_021A0E58
 * address:  0x021A0E58
 * packet:   pkt_ov021_021A0E58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02189A2C  0x02189A2C  thumb  ov021
 *   d_021D8734  0x021D8734  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern s32 func_02189A2C(u32 a);
extern u8 d_021D8734[];

void func_021A0E58(u32 *a)
{
    s32 r;

    switch (a[2]) {
    case 0:
        if (*(u32 *)(d_021D8734 + a[0] * 0x1c) != 0) {
            r = func_02189A2C(a[5]);
            ((void (*)(u32 *, s32))*(u32 *)(d_021D8734 + a[0] * 0x1c))(a, r == 0);
        }
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        break;
    }
}
