/*
 * function: func_02155204
 * address:  0x02155204
 * packet:   pkt_ov009_02155204
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215677C  0x0215677C  thumb  ov009
 *   func_020307B0  0x020307B0  arm
 *   func_021570B8  0x021570B8  thumb  ov009
 *   d_021A8260     0x021A8260  data  ov009  a4
 */

extern int *d_021A8260;
void func_0215677C(void);
void func_020307B0(int *p);
void func_021570B8(void);

int func_02155204(void (*cb)(int))
{
    if (d_021A8260 != 0) {
        func_0215677C();
        if (cb != 0)
            cb(1);
        func_020307B0(d_021A8260);
        d_021A8260 = 0;
    }
    func_021570B8();
    return 1;
}
