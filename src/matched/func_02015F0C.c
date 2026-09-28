/*
 * function: func_02015F0C
 * address:  0x02015F0C
 * packet:   pkt_02015EE8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Reads the u16 at
 * +6 of the table the word at +0x2C points to (`ldrh` proves unsigned).
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

u16 func_02015F0C(void *p)
{
    return (*(u16 **)((char *)p + 0x2C))[3];
}
