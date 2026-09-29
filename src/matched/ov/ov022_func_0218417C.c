/*
 * function: func_0218417C
 * address:  0x0218417C
 * packet:   pkt_ov022_0218417C
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (a .word run in asm/overlays/ov022.s): returns the word
 * at 0x28. Blocker of ov023 func_02184674.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

u32 func_0218417C(u8 *p)
{
    return *(u32 *)(p + 0x28);
}
