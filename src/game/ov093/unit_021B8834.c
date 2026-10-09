/*
 * file:     unit_021B8834.c
 * function: func_021B8834
 * address:  0x021B8834
 * packet:   pkt_ov093_021B8834
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B8C50  0x021B8C50  thumb  ov093
 *   func_021B8CB0  0x021B8CB0  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Unk021B8CB0;
extern u8 func_021B8C50(char **p, u32 v, int k);
extern u8 func_021B8CB0(struct Unk021B8CB0 **p, u8 x);

u8 func_021B8834(void *p, u32 k, u8 v, u8 *out)
{
    u8 t;

    switch (k) {
    case 0:
    default:
        return 0;
    case 1:
    case 6:
        out[0] = func_021B8C50(p, v, 0);
        out[1] = func_021B8C50(p, v, 1);
        return 2;
    case 2:
        out[0] = func_021B8C50(p, v, 0);
        out[1] = func_021B8C50(p, v, 1);
        out[2] = func_021B8CB0(p, v);
        return 3;
    case 3:
        out[0] = v;
        out[1] = func_021B8CB0(p, v);
        if (out[0] > out[1]) {
            t = out[0];
            out[0] = out[1];
            out[1] = t;
        }
        return 2;
    case 4:
    case 9:
        out[0] = func_021B8CB0(p, v);
        return 1;
    case 7:
        out[0] = v;
        out[1] = func_021B8CB0(p, v);
        return 2;
    case 5:
    case 8:
        out[0] = 0;
        out[1] = 1;
        out[2] = 2;
        out[3] = 3;
        return 4;
    }
}
