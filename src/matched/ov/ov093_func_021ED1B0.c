/*
 * function: func_021ED1B0
 * address:  0x021ED1B0
 * packet:   pkt_ov093_021ED1B0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef int (*Cb)(void *, u32);

int func_021ED1B0(char *p)
{
    Cb f;

    f = *(Cb *)(p + 0xe0);
    if (f != 0) {
        if (f(p + 0xec, *(u32 *)(p + 0xe8)) != 0) {
            *(u32 *)(p + 0xe0) = 0;
            *(u32 *)(p + 0xec) = 0;
        }
        return 0;
    }
    f = *(Cb *)(p + 0xe4);
    if (f != 0) {
        if (f(p + 0xec, *(u32 *)(p + 0xe8)) != 0) {
            *(u32 *)(p + 0xe4) = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}
