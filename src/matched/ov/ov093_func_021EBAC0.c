/*
 * function: func_021EBAC0
 * address:  0x021EBAC0
 * packet:   pkt_ov093_021EBAC0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EB660  0x021EB660  thumb  ov093
 *   d_021F38E8  0x021F38E8  data  a4
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 */

typedef unsigned char u8;

extern int func_021EB660(u8 *, int *);
extern u8 func_021B8FF4(u8 *);
extern int (*const d_021F38E8[][2])(u8 *, int *);


int func_021EBAC0(int *a, u8 *b)
{
    if (b[0x150] != 0)
        return func_021EB660(b, a);
    if (b[0x14f] < 3) {
        if (d_021F38E8[b[0x14f]][func_021B8FF4(*(u8 **)(b + 0x134))](b, a) != 0) {
            b[0x14f] = b[0x14f] + 1;
            *a = 0;
        }
        return 0;
    }
    return 1;
}
