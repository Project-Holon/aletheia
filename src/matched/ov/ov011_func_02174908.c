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
void *func_020399A8(void);
unsigned int func_0203D1A4(void *p);
void *func_020127A4(int a);
unsigned short func_02012AC8(void *p);
unsigned int func_02013D9C(unsigned int id);

void func_02174908(int a, int b, int c, unsigned char *d)
{
    int h;

    h = func_02026478(*(int *)(d + 4));
    if (a != func_0203D1A4(func_020399A8()) && ((unsigned)(*(unsigned short *)(d + 0x86) << 29) >> 29) == a) {
        if (func_02013D9C(func_02012AC8(func_020127A4(h))) != 0) {
            d[0x8F8] |= 4;
        }
    }
}
