/*
 * function: func_021E3E84
 * address:  0x021E3E84
 * packet:   pkt_ov093_021E3E84
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D6920  0x021D6920  thumb  ov093
 *   func_021D6940  0x021D6940  thumb  ov093
 *   func_021C7D00  0x021C7D00  thumb  ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C7F68  0x021C7F68  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern void *func_021C7CF4(void *a, int b);
extern int func_021D6920(void *q, u8 i);
extern void func_021D6940(void *q, u8 i, int z, u8 *out);
extern int func_021C7D00(void *a, int x);
extern int func_021C8010(void *a, int c);
extern int func_021C7F68(void *a, u16 k, u8 *buf);
extern int func_021D78AC(int r);

int func_021E3E84(int u, void *a, int c)
{
    u8 buf[16];
    void *q;
    unsigned i;
    int x;
    int t;
    int r;

    q = func_021C7CF4(a, c);
    for (i = 0; i < 3; i++) {
        if (func_021D6920(q, i) != 0) {
            func_021D6940(q, i, 0, &buf[6]);
            x = buf[0xb];
            if (func_021C7D00(a, x) == 6) {
                t = func_021C8010(a, c);
                r = func_021C7F68(a, 0x100 | t, buf);
                if (r != 0)
                    x = buf[(u8)func_021D78AC(r)];
                else
                    x = 0x1f;
            }
            return x;
        }
    }
    return 0x1f;
}
