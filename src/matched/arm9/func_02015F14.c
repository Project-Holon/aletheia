/*
 * function: MCSS_GetOfsX
 * address:  0x02015F14
 * packet:   pkt_02015EE8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Reads the s16 at
 * +8 of the table the word at +0x2C points to (`ldrsh` with a register
 * offset proves signed).
 *
 * Addresses are Black-image addresses.
 */

typedef signed short s16;

s16 MCSS_GetOfsX(void *p)
{
    return (*(s16 **)((char *)p + 0x2C))[4];
}
