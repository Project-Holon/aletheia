/*
 * function: func_021C54C8
 * address:  0x021C54C8
 * packet:   pkt_ov021_021C54C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020202FC  0x020202FC  thumb
 *   func_02020324  0x02020324  thumb
 *   func_021C59F8  0x021C59F8  thumb  ov021
 *   func_021C59A8  0x021C59A8  thumb  ov021
 *   func_021C58CC  0x021C58CC  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void func_020202FC(int a, int b, u16 *out);
extern u32 func_02020324(int a, int b);
extern void func_021C59F8(int *a, int b);
extern void func_021C59A8(int *a, int b, int c);
extern void func_021C58CC(int *a, int b, int c, int d);
extern void func_020061E4(int a);

void func_021C54C8(int *a, int b, int c, int *d)
{
    u16 v;
    u16 w;

    if (b == c - 1) {
        if (a[9] == 1) {
            func_020202FC(a[1], 0, &v);
            w = func_02020324(a[1], (u16)(v + 1)) >> 3;
            func_021C59F8(a, (w + 0xc) << 3);
            a[16] ^= 1;
        }
        if (a[16] == 0) {
            func_021C59A8(a, 0, 0);
            func_021C58CC(a, 0, 0, *(u16 *)((char *)a + 0x34));
        }
        func_020061E4(0x548);
        *d = 1;
        return;
    }
    a[16] = 0;
}
