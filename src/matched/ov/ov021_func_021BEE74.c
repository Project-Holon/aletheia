/*
 * function: func_021BEE74
 * address:  0x021BEE74
 * packet:   pkt_ov021_021BEE74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0204E720(u32 a, u32 b, u32 c, u32 d);
extern u32 func_0204E804(void);

int func_021BEE74(u32 p0, int *st, u8 *q)
{
    switch (*st) {
    case 0:
        func_0204E720(*(u32 *)(q + 0xC), 0, 0x10, 0x10 - 0x11);
        *st = *st + 1;
        break;
    case 1:
        if (*(u32 *)(q + 0x14) == 1)
            return 1;
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}
