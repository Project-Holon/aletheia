/*
 * function: func_021C0230
 * address:  0x021C0230
 * packet:   pkt_ov217_021C0230
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C0F48  0x021C0F48  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
extern void func_021C0F48(u8 *p);

void func_021C0230(int *p)
{
    int i;
    for (i = 0; i < 9; i++) {
        func_021C0F48((u8 *)p[i + 0xD1]);
        p[i + 0xD1] = 0;
    }
}
