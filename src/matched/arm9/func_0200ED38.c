/*
 * function: MISC_SAVEDATA_GetShortBlockSize
 * address:  0x0200ED38
 * packet:   pkt_0200ED38
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Save-table size callback: returns 0xFC, the size of the block that
 * MISC_SAVEDATA_InitShortBlock clears.  Pointer word 0x0200ED39 at 0x0209DD5C.
 */

typedef unsigned int u32;

u32 MISC_SAVEDATA_GetShortBlockSize(void)
{
    return 0xFC;
}
