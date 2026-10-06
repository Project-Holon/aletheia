/*
 * function: func_021B3258
 * address:  0x021B3258
 * packet:   pkt_ov021_021B3258
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B3258 0x021B3258 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02012944 0x02012944 thumb
 *   func_021B3B14 0x021B3B14 thumb ov021
 *   func_02012F08 0x02012F08 thumb
 *   func_0200C258 0x0200C258 thumb
 *   func_021B38E0 0x021B38E0 thumb ov021
 *   func_021B39C4 0x021B39C4 thumb ov021
 *   func_021B3A64 0x021B3A64 thumb ov021
 *   func_021B331C 0x021B331C thumb ov021
 *   func_021B3BD8 0x021B3BD8 thumb ov021
 *   func_021B3FA0 0x021B3FA0 thumb ov021
 *   func_021B3F00 0x021B3F00 thumb ov021
 *   func_021B40D4 0x021B40D4 thumb ov021
 *   func_021B43EC 0x021B43EC thumb ov021
 */

typedef unsigned char u8;

struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern int func_021B3B14(char *p, int a);
extern void *func_02012F08(int *p);
extern int func_0200C258(void);
extern void func_021B38E0(char *p, int a, int b, int c);
extern void func_021B39C4(u8 *, int);
extern void func_021B3A64(char *p, int i);
extern void func_021B331C(u8 *, int);
extern void func_021B3BD8(char *p);
extern void func_021B3FA0(char *w);
extern void func_021B3F00(u8 *);
extern void func_021B40D4(char *w);
extern void func_021B43EC(char *w);

void func_021B3258(int ctx, u8 *a, int b, int c)
{
    void *t = func_020120F4((void *)ctx);
    int r;

    func_02012944(t);
    a[354] = 0;
    b = func_021B3B14((char *)a, b);
    r = b;
    switch (r) {
    case 255:
        func_02012F08(t);
        func_021B38E0((char *)a, r, c, func_0200C258());
        break;
    case 254:
        func_021B39C4(a, 0);
        a[355] = 1;
        break;
    case 253:
        a[355] = 1;
        a[354] = 1;
        func_021B39C4(a, 1);
        break;
    case 247:
    case 248:
    case 249:
    case 250:
    case 251:
        func_021B3A64((char *)a, r);
        break;
    default:
        func_021B38E0((char *)a, r, c, 0);
        break;
    }
    func_021B331C(a, a[355]);
    func_021B3BD8((char *)a);
    func_021B3FA0((char *)a);
    func_021B3F00(a);
    func_021B40D4((char *)a);
    func_021B43EC((char *)a);
}
