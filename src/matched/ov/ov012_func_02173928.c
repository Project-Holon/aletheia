/*
 * function: func_02173928
 * address:  0x02173928
 * packet:   pkt_ov012_02173928
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (a .word run in the ov012 listing): reads the word at
 * +0x356C.  Callee of ov021 func_0218A0E4.
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

int func_02173928(u8 *p)
{
    return *(int *)(p + 0x356C);
}
