/*
 * function: func_02174734
 * address:  0x02174734
 * packet:   pkt_ov011_02174734
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D578  0x0203D578  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0203D4D0  0x0203D4D0  arm
 */

int func_021736D8(void);
int func_020399A8(void);
int func_0203D578(int a, int b);
void func_02082D44(void *d, void *s, int n);
int func_0203D4D0(int a, int b, int c, int d, void *e, int f, int g, int h);

int func_02174734(char *p, int b, void *c)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    if (func_0203D578(func_020399A8(), 0x225) == 1) {
        return 0;
    }
    func_02082D44(c, p + 0x460, 0x1E8);
    return func_0203D4D0(func_020399A8(), b & 0xFF, 0x225, 0x1E8, c, 0, 0, 1);
}
