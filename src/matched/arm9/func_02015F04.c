/*
 * function: func_02015F04
 * address:  0x02015F04
 * packet:   pkt_02015F04
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Reads the u16 at
 * +4 of the table the word at +0x2C points to (`ldrh` proves unsigned).
 * Witness for the call from ov119 func_021E33FC at 0x021E3520.
 */

typedef unsigned short u16;

u16 func_02015F04(void *p)
{
    return (*(u16 **)((char *)p + 0x2C))[2];
}
