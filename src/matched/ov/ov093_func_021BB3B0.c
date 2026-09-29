/*
 * function: func_021BB3B0
 * address:  0x021BB3B0
 * packet:   pkt_ov093_021BB3B0
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
 */

typedef unsigned char u8;

extern void func_021BB724(u8 *, int, u8 *, int);
extern int func_021BB798(u8 *);
extern void func_021BB7D0(u8 *);
extern void func_021BABEC(u8 *, void *);
extern int func_021BB320(u8 *, int *);

int func_021BB3B0(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        func_021BB724(p, 0xf, p + 0xa8, 4);
        (*s)++;
        break;
    case 1:
        if (func_021BB798(p) != 0) {
            func_021BB7D0(p);
            (*s)++;
        }
        break;
    case 2:
        func_021BABEC(p, (void *)func_021BB320);
        break;
    }
    return 0;
}
