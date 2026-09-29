/*
 * function: func_021EBE28
 * address:  0x021EBE28
 * packet:   pkt_ov093_021EBE28
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EB670  0x021EB670  thumb  ov093
 *   d_021F3900  0x021F3900  data  a4
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 */

typedef unsigned char u8;

extern int func_021EB670(u8 *, int *);
extern u8 func_021B8FF4(u8 *);
extern int (*const d_021F3900[][2])(u8 *, int *);


int func_021EBE28(int *a, u8 *b)
{
    if (b[0x150] != 0)
        return func_021EB670(b, a);
    if (b[0x14f] < 3) {
        if (d_021F3900[b[0x14f]][func_021B8FF4(*(u8 **)(b + 0x134))](b, a) != 0) {
            b[0x14f] = b[0x14f] + 1;
            *a = 0;
        }
        return 0;
    }
    return 1;
}
