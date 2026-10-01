/*
 * function: func_021C5FC0
 * address:  0x021C5FC0
 * packet:   pkt_ov021_021C5FC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Wait step: 1 on a key press, 2 on timeout, otherwise 0.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 func_020362DC(void);

int func_021C5FC0(u8 *p, u32 lim)
{
    u32 n = *(u32 *)(p + 0x60);

    *(u32 *)(p + 0x60) = n + 1;
    if (n < lim) {
        if (func_020362DC() & 1) {
            *(u32 *)(p + 0x60) = 0;
            return 1;
        }
    } else {
        *(u32 *)(p + 0x60) = 0;
        return 2;
    }
    return 0;
}
