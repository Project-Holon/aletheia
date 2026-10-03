/*
 * function: func_0219470C
 * address:  0x0219470C
 * packet:   pkt_ov021_0219470C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020310C4  0x020310C4  arm
 *   func_0219545C  0x0219545C  thumb  ov021
 *   func_021953D4  0x021953D4  thumb  ov021
 *   func_02194B84  0x02194B84  thumb  ov021
 *   func_02194C60  0x02194C60  thumb  ov021
 *   func_02195490  0x02195490  thumb  ov021
 */

typedef unsigned char  u8;
struct Tcbl;
extern void func_020310C4(struct Tcbl *p);
extern void func_0219545C(void *a);
extern void func_021953D4(u8 *p, int m);
extern void func_02194B84(u8 *p, u8 *e);
extern void func_02194C60(u8 *p, u8 *e);
extern void func_02195490(void *a);

void func_0219470C(unsigned char *a)
{
    int i;

    func_020310C4(*(void **)(a + 0xc98));
    func_0219545C(a);
    func_021953D4(a, 0);
    for (i = 0; i < 0x20; i++) {
        if (a[i * 0x64 + 0x1a] == 0)
            func_02194B84(a, a + 0x18 + i * 0x64);
        else
            func_02194C60(a, a + 0x18 + i * 0x64);
    }
    func_02195490(a);
}
