/*
 * function: func_02173FF4
 * address:  0x02173FF4
 * packet:   pkt_ov011_02173FF4
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D4D0  0x0203D4D0  arm
 */

int func_021736D8(void);
struct Entry;
struct Entry *func_020399A8(void);
int func_0203D4D0(int a, int b, int c, int d, void *e, int f, int g, int h);

int func_02173FF4(int a, int b, int c, int d)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    return func_0203D4D0((int)func_020399A8(), (unsigned char)c, 0x215, 4, &b, 0, 0, 0);
}
