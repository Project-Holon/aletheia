/*
 * function: func_021BE218
 * address:  0x021BE218
 * packet:   pkt_ov021_021BE218
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE218  0x021BE218  thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3AC  0x0200B3AC  thumb
 *   func_02034A5C  0x02034A5C  arm
 *   d_021D9BE0     0x021D9BE0  data  ov021  a4
 *   d_021D9D98     0x021D9D98  data  ov021  a4
 */

extern void func_02188C80(void);
extern void func_020120F4(void);
extern void func_02012EC4(void);
extern int func_0200B3AC(void);
extern void func_02034A5C(void *);

extern void (*d_021D9BE0[])(void *);
extern void *d_021D9D98[];

void func_021BE218(void *arg)
{
    int i;

    func_02188C80();
    func_020120F4();
    func_02012EC4();
    i = func_0200B3AC();
    if (i != -1) {
        if (d_021D9BE0[i] != 0) {
            d_021D9BE0[i](arg);
        }
        if (d_021D9D98[i] != 0) {
            func_02034A5C(d_021D9D98[i]);
        }
    }
}
