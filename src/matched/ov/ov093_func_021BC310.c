/*
 * function: func_021BC310
 * address:  0x021BC310
 * packet:   pkt_ov093_021BC310
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8B9C  0x021B8B9C  thumb  ov093
 *   func_021B8BC4  0x021B8BC4  thumb  ov093
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021B9B98  0x021B9B98  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int func_021B8B9C(u8 *p, u8 k);
extern u8 func_021B8BC4(u8 *p, u8 k);
extern u8 func_021B8FF4(u8 *p);
extern char *func_021B9AEC(char *p, int i);
extern u8 func_021B9B98(char *p);

int func_021BC310(u8 *p)
{
    u32 i;

    for (i = 0; i < 4; i++) {
        if (func_021B8B9C(*(u8 **)(p + 4), i) != 0) {
            u8 a = func_021B8BC4(*(u8 **)(p + 4), i);
            u8 b = func_021B8BC4(*(u8 **)(p + 4), func_021B8FF4(*(u8 **)(p + 4)));

            if (a == b) {
                if (func_021B9B98(func_021B9AEC(*(char **)(p + 8), i)) != 0)
                    return 1;
            }
        }
    }
    return 0;
}
