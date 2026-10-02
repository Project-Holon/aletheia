/*
 * function: func_021C670C
 * address:  0x021C670C
 * packet:   pkt_ov136_021C670C
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B688  0x0204B688  arm
 */

typedef unsigned char u8;
extern void func_0204B688(void *, int);
void func_021C670C(u8 *p, int i, int on)
{
    if (on == 1) {
        func_0204B688(*(void **)(p + i * 4 + 0x1F0), 1);
    } else {
        func_0204B688(*(void **)(p + i * 4 + 0x1F0), 0);
    }
}
