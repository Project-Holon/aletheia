/*
 * function: func_021E3B14
 * address:  0x021E3B14
 * packet:   pkt_ov093_021E3B14
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D67A8  0x021D67A8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F284C     0x021F284C  data   a2
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern int func_021D775C(int);
extern void *func_021C7CF4(void *a, int b);
extern int func_021D67A8(void);
extern u8 *func_021C88A4(void *a, int k, int c);
extern void func_021C88C8(void *a, void *p);
extern const u16 d_021F284C[];

void func_021E3B14(int u, void *a, int c)
{
    unsigned i;
    int r;
    u8 *p;

    if (c == func_021D775C(3)) {
        func_021C7CF4(a, c);
        r = func_021D67A8();
        for (i = 0; i < 5; i++) {
            if (r == d_021F284C[i])
                return;
        }
        p = func_021C88A4(a, 0x26, c);
        p[4] = c;
        p[5] = 3;
        p[6] = 0;
        func_021C88C8(a, p);
    }
}
