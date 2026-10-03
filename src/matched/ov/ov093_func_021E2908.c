/*
 * unit:     yes
 * function: func_021E2908, func_021E293C
 * address:  0x021E2908
 * packet:   pkt_ov093_021E2908
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
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F2444     0x021F2444  data   ov093  a4
 */

extern int func_021D775C(int key);
struct Unk021D62A8;
extern void *func_021C7CF4(int *p, int i);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern void func_021D7704(int a, int b);
extern int d_021F2444[];

void func_021E2908(int a, void *b, int c)
{
    int k;

    if (c == func_021D775C(3)) {
        k = func_021D62A8(func_021C7CF4(b, c));
        if (k == 5 || k == 1 || k == 4)
            func_021D7704(0x31, 2 << 12);
    }
}

int *func_021E293C(int *p)
{
    *p = 1;
    return d_021F2444;
}
