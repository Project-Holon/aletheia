/*
 * function: func_02173B44
 * address:  0x02173B44
 * packet:   pkt_ov011_02173B44
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
 *   func_0203D3F8  0x0203D3F8  arm
 */

int func_021736D8(void);
int func_020399A8(void);
int func_0203D3F8(int a, int b, int c, int d, void *e, int f, int g, int h);

int func_02173B44(int a, int b, int c, int d)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3F8(func_020399A8(), (unsigned char)b, 0x209, 1, &c, 0, 0, 0);
}
