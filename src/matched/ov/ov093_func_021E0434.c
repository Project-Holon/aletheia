/*
 * function: func_021E0434
 * address:  0x021E0434
 * packet:   pkt_ov093_021E0434
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D732C  0x021D732C  thumb  ov093
 *   func_021D7040  0x021D7040  thumb  ov093
 */

typedef unsigned char u8;

extern u8 func_021D5440(u8 *p);
extern void *func_021D732C(int a, int b);
extern void func_021D7040(void *n);

void func_021E0434(u8 *p)
{
    int n = func_021D5440(p);
    void *a;

    while ((a = func_021D732C(0, n)) != 0)
        func_021D7040(a);
}
