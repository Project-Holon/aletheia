/*
 * function: func_0217392C
 * address:  0x0217392C
 * packet:   pkt_ov011_0217392C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_020264B4  0x020264B4  thumb
 *   func_02174F54  0x02174F54  thumb ov011
 */

int func_020399A8(void);
int func_0203D1A4(int a);
void func_020264B4(int a, int b, int c, unsigned char d, int e, int f);
void func_02174F54(void *a, int b, const void *c, int d);

typedef struct C {
    char pad[0x14];
    unsigned short w14;
    unsigned short f : 3;
} C;

void func_0217392C(int a, int b, const C *c, unsigned char *d)
{
    if (a == func_0203D1A4(func_020399A8())) {
        func_020264B4(*(int *)(d + 4), a, c->w14, c->f, 0x15, 0);
    } else if ((d[0x8FB] & (1 << a)) != 0) {
        func_02174F54(d, a, c, 0);
    }
}
