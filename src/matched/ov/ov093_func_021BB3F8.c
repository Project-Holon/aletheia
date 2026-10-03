/*
 * function: func_021BB3F8
 * address:  0x021BB3F8
 * packet:   pkt_ov093_021BB3F8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent 68, compiled 66, trailing padding)
 *
 * symbols:
 *   func_021BB724  0x021BB724  thumb  ov093
 *   func_021BB798  0x021BB798  thumb  ov093
 *   func_021BB7D0  0x021BB7D0  thumb  ov093
 */

typedef unsigned char u8;

extern void func_021BB724(u8 *, int, u8 *, int);
extern int func_021BB798(u8 *);
extern void func_021BB7D0(const u8 *p);

int func_021BB3F8(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        func_021BB724(p, 0xd, p + 0xa8, 4);
        (*s)++;
        break;
    case 1:
        if (func_021BB798(p) != 0) {
            func_021BB7D0(p);
            (*s)++;
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}
