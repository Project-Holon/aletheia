/*
 * function: func_02174374
 * address:  0x02174374
 * packet:   pkt_ov011_02174374
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_020127B8  0x020127B8  thumb
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 */

int func_02026478(int a);
int func_020127B8(int a);
int func_021736D8(void);
int func_020399A8(void);
int func_0203D3A8(void *a, unsigned int b, unsigned int c, unsigned int d);

int func_02174374(int *a)
{
    int r;

    r = func_020127B8(func_02026478(a[1]));
    if (func_021736D8() == 0) {
        return 0;
    }
    return func_0203D3A8(func_020399A8(), 0x21c, 0x10, r);
}
