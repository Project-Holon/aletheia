/*
 * function: func_02184174
 * address:  0x02184174
 * packet:   pkt_ov022_02184174
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (a .word run in asm/overlays/ov022.s): sets the word at
 * 0x20. Blocker of ov023 func_02184674.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

void func_02184174(u8 *p)
{
    *(u32 *)(p + 0x20) = 1;
}
