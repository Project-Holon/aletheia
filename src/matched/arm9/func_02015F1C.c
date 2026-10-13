/*
 * function: MCSS_GetOfsY
 * address:  0x02015F1C
 * packet:   pkt_02015EE8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Reads the s16 at
 * +0xA of the table the word at +0x2C points to; sibling of
 * MCSS_GetOfsX.
 *
 * Addresses are Black-image addresses.
 */

typedef signed short s16;

s16 MCSS_GetOfsY(void *p)
{
    return (*(s16 **)((char *)p + 0x2C))[5];
}
