/*
 * function: func_021BB484
 * address:  0x021BB484
 * packet:   pkt_ov093_021BB484
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB724  0x021BB724  thumb  ov093
 *   func_021BB798  0x021BB798  thumb  ov093
 *   func_021BB7D0  0x021BB7D0  thumb  ov093
 *   func_021BABEC  0x021BABEC  thumb  ov093
 *   func_021BB320  0x021BB320  thumb  ov093
 *   func_021B86C0  0x021B86C0  thumb  ov093
 */

typedef unsigned char u8;

extern void func_021BB724(u8 *, int, u8 *, int);
extern int func_021BB798(u8 *);
extern void func_021BB7D0(const u8 *p);
extern void func_021BABEC(u8 *, void *);
extern int func_021BB320(u8 *, int *);
extern u8 func_021B86C0(u8 **);

int func_021BB484(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        func_021BB724(p, 0xc, p + 0xa8, 4);
        (*s)++;
        break;
    case 1:
        if (func_021BB798(p) != 0) {
            func_021BB7D0(p);
            (*s)++;
        }
        break;
    case 2:
        if (func_021B86C0(*(u8 ***)(p + 0xc)) == 0) {
            func_021BABEC(p, (void *)func_021BB320);
        } else {
            return 1;
        }
        break;
    }
    return 0;
}
