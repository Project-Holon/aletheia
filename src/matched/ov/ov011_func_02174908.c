/*
 * function: func_02174908
 * address:  0x02174908
 * packet:   pkt_ov011_02174908
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02013D9C  0x02013D9C  thumb
 */

int func_02026478(int a);
int func_020399A8(void);
int func_0203D1A4(void);
void func_020127A4(int a);
void func_02012AC8(void);
int func_02013D9C(void);

void func_02174908(int a, int b, int c, unsigned char *d)
{
    int h;

    h = func_02026478(*(int *)(d + 4));
    func_020399A8();
    if (a != func_0203D1A4() && ((unsigned)(*(unsigned short *)(d + 0x86) << 29) >> 29) == a) {
        func_020127A4(h);
        func_02012AC8();
        if (func_02013D9C() != 0) {
            d[0x8F8] |= 4;
        }
    }
}
