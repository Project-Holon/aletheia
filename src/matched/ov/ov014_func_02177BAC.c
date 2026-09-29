/*
 * function: func_02177BAC
 * address:  0x02177BAC
 * packet:   pkt_ov014_02177BAC
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: clears halfword idx of the table at +0xC40 of the
 * object pointed to by the global at 0x021797A4. Blocks func_02177BF4.
 *
 * symbols:
 *   d_021797A4  0x021797A4  data  ov014  a4
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *d_021797A4;

void func_02177BAC(u32 idx)
{
    u8 *p = d_021797A4;
    u16 *h;
    if (p != 0) {
        h = (u16 *)(p + 0xc40);
        if (h[idx] != 0) {
            h[idx] = 0;
        }
    }
}
