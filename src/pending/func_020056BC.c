/*
 * function: func_020056BC
 * address:  0x020056BC
 * packet:   pkt_020056BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_020AA194  0x020AA194  data
 *
 * Unlabelled Thumb leaf in the ARM9 module (disasm.py emits it as ARM
 * because nothing saves lr). Reads a pointer field out of the data object
 * d_020AA194 (+0x10), then a word at +0x20 of that. Called by the ov119
 * wrappers func_021E71F0/func_021E7208.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern unsigned char d_020AA194[];

u32 func_020056BC(void)
{
    return *(u32 *)(*(u32 *)(d_020AA194 + 0x10) + 0x20);
}
