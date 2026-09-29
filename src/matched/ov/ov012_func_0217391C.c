/*
 * function: func_0217391C
 * address:  0x0217391C
 * packet:   pkt_ov012_0217391C
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (a .word run in the ov012 listing): reads the word at
 * +0x3568.  Callee of ov021 func_0218A0E4.
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

int func_0217391C(u8 *p)
{
    return *(int *)(p + 0x3568);
}
