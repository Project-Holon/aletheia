/*
 * function: func_021B87E8
 * address:  0x021B87E8
 * packet:   pkt_ov093_021B87E8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B8C50  0x021B8C50  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 func_021B8C50(char **p, u32 v, int k);

u8 func_021B87E8(void *p, u32 k, u32 v, u8 *out)
{
    switch (k) {
    case 0:
    case 4:
    case 7:
    default:
        return 0;
    case 1:
    case 2:
    case 6:
        *out = func_021B8C50(p, v, 0);
        break;
    case 3:
        *out = v;
        break;
    case 5:
    case 8:
        out[0] = 0;
        out[1] = 1;
        return 2;
    }
    return 1;
}
