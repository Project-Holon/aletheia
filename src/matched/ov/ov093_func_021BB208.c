/*
 * function: func_021BB208
 * address:  0x021BB208
 * packet:   pkt_ov093_021BB208
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EE9A4  0x021EE9A4  thumb  ov093
 *   func_021BB724  0x021BB724  thumb  ov093
 *   func_021BB718  0x021BB718  thumb  ov093
 *   func_021BB798  0x021BB798  thumb  ov093
 *   func_021BB7D0  0x021BB7D0  thumb  ov093
 *   func_021C84D8  0x021C84D8  thumb  ov093
 *   func_021B916C  0x021B916C  thumb  ov093
 *   func_021BABEC  0x021BABEC  thumb  ov093
 *   func_021BB280  0x021BB280  thumb  ov093
 */

typedef unsigned char u8;

extern u8 *func_021EE9A4(u8 *, int *);
extern void func_021BB724(u8 *, int, u8 *, int);
extern void func_021BB718(u8 *, int);
extern int func_021BB798(u8 *);
extern void func_021BB7D0(const u8 *p);
extern int func_021C84D8(int);
extern void func_021B916C(int, int);
extern void func_021BABEC(u8 *, void *);
extern int func_021BB280(u8 *);

int func_021BB208(u8 *p, int *s)
{
    int n;

    switch (*s) {
    case 0: {
        u8 *r = func_021EE9A4(p + 0x68, &n);
        func_021BB724(p, 0xa, r, n);
        (*s)++;
        break;
    }
    case 1:
        if (func_021BB798(p) != 0) {
            func_021BB7D0(p);
            func_021BB718(p, 0x10);
            (*s)++;
        }
        break;
    case 2:
        if (func_021BB798(p) != 0) {
            func_021BB7D0(p);
            func_021B916C(*(int *)(p + 0xc), func_021C84D8(*(int *)(p + 0x44)));
            func_021BABEC(p, (void *)func_021BB280);
        }
        break;
    }
    return 0;
}
