/*
 * function: func_021B88EC
 * address:  0x021B88EC
 * packet:   pkt_ov093_021B88EC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B99F0  0x021B99F0  thumb  ov093
 *   func_021B8C50  0x021B8C50  thumb  ov093
 *   func_021B8C20  0x021B8C20  thumb  ov093
 *   func_021B8C38  0x021B8C38  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 func_021B99F0(u32 x);
extern u8 func_021B8C50(void *p, u32 v, int k);
extern u8 func_021B8C20(int kind, u32 flags, u32 v);
extern u8 func_021B8C38(u32 flags, u32 v);

u8 func_021B88EC(void *p, u32 k, u32 v, u8 *out)
{
    u8 b = func_021B99F0(v);
    u8 x;

    switch (k) {
    case 0:
    case 1:
    default:
        if (b) {
            out[0] = func_021B8C50(p, v, 0);
            out[1] = func_021B8C50(p, v, 1);
            out[2] = func_021B8C50(p, v, 2);
            return 3;
        }
        out[0] = func_021B8C50(p, v, 1);
        x = (u8)(v >> 1);
        if (x == 0) x = 2;
        else if (x == 2) x = 0;
        out[1] = func_021B8C20(2, v, x);
        return 2;
    case 6:
        out[0] = func_021B8C50(p, v, 0);
        out[1] = func_021B8C50(p, v, 1);
        out[2] = func_021B8C50(p, v, 2);
        return 3;
    case 7:
        out[0] = func_021B8C38(v, 0);
        out[1] = func_021B8C38(v, 1);
        out[2] = func_021B8C38(v, 2);
        return 3;
    case 8:
        out[0] = func_021B8C50(p, v, 0);
        out[1] = func_021B8C50(p, v, 1);
        out[2] = func_021B8C50(p, v, 2);
        out[3] = func_021B8C38(v, 0);
        out[4] = func_021B8C38(v, 1);
        out[5] = func_021B8C38(v, 2);
        return 6;
    case 2:
        if (b) {
            out[0] = func_021B8C50(p, v, 0);
            out[1] = func_021B8C50(p, v, 1);
            out[2] = func_021B8C50(p, v, 2);
            out[3] = func_021B8C38(v, 0);
            out[4] = func_021B8C38(v, 2);
            return 5;
        }
        out[0] = func_021B8C50(p, v, 1);
        x = (u8)(v >> 1);
        if (x == 0) x = 2;
        else if (x == 2) x = 0;
        out[1] = func_021B8C20(2, v, x);
        out[2] = func_021B8C38(v, 1);
        return 3;
    case 3:
        if (b) {
            out[0] = v;
            out[1] = func_021B8C38(v, 0);
            out[2] = func_021B8C38(v, 2);
            return 3;
        }
        out[0] = v;
        out[1] = func_021B8C38(v, 1);
        return 2;
    case 9:
        if (b) {
            out[0] = func_021B8C38(v, 0);
            out[1] = func_021B8C38(v, 2);
            return 2;
        }
        out[0] = func_021B8C38(v, 1);
        return 1;
    case 4:
        if (b) {
            out[0] = func_021B8C38(v, 0);
            out[1] = func_021B8C38(v, 2);
            return 2;
        }
        out[0] = func_021B8C38(v, 1);
        return 1;
    case 5:
        if (b) {
            out[0] = func_021B8C50(p, v, 0);
            out[1] = func_021B8C50(p, v, 1);
            out[2] = func_021B8C50(p, v, 2);
            out[3] = func_021B8C38(v, 0);
            out[4] = func_021B8C38(v, 2);
            out[5] = v;
            return 6;
        }
        out[0] = func_021B8C50(p, v, 1);
        x = (u8)(v >> 1);
        if (x == 0) x = 2;
        else if (x == 2) x = 0;
        out[1] = func_021B8C20(2, v, x);
        out[2] = func_021B8C38(v, 1);
        out[3] = v;
        return 4;
    }
}
