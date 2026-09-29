/*
 * function: func_021746AC
 * address:  0x021746AC
 * packet:   pkt_ov011_021746AC
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
 *   func_0203D3F8  0x0203D3F8  arm
 */

int func_021736D8(void);
int func_020399A8(void);
int func_0203D3F8(int a, int b, int c, int d, void *e, int f, int g, int h);

int func_021746AC(char *a, int b)
{
    int r;

    if (func_021736D8() == 0) {
        return 0;
    }
    r = func_0203D3F8(func_020399A8(), b, 0x224, 0, 0, 0, 0, 0);
    if (r == 1) {
        a[0x90c] = 0;
    }
    return r;
}
