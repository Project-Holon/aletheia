/*
 * function: SYMBOL_SAVE_GetBlockSize
 * address:  0x0200E090
 * packet:   pkt_0200E090
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Save-table size callback: returns 0x850, the size of the block whose
 * init is SYMBOL_SAVE_InitBlock.  Pointer word 0x0200E091 at 0x0209DD08.
 */

typedef unsigned int u32;

u32 SYMBOL_SAVE_GetBlockSize(void)
{
    return 0x850;
}
