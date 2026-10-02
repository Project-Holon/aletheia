/*
 * function: func_02174320
 * address:  0x02174320
 * packet:   pkt_ov011_02174320
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
 *   func_020127AC  0x020127AC  thumb
 *   func_02082D44  0x02082D44  arm
 */

typedef struct H {
    unsigned short f : 3;
} H;

int func_02026478(int a);
int func_020399A8(void);
int func_0203D1A4(int p);
int func_020127AC(int p, int a);
void func_02082D44(void *d, int s, int n);

void func_02174320(int a, int b, void *c, char *d)
{
    int p;

    p = func_02026478(((int *)d)[1]);
    if (a != func_0203D1A4(func_020399A8()) && ((unsigned char)d[0x8fb] & (1 << a))) {
        func_02082D44(c, func_020127AC(p, a), 0x10);
        if (a == ((H *)(d + 0x86))->f) {
            d[0x8fb + 0xb] = 1;
        }
    }
}
