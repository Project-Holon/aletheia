/*
 * function: MISC_SAVEDATA_GetRecordSize
 * address:  0x0200EA14
 * packet:   pkt_0200EA14
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Save-table size callback: returns 0x16C, the size of the block that
 * MISC_SAVEDATA_InitRecord clears.  Pointer word 0x0200EA15 at 0x0209DD44.
 */

typedef unsigned int u32;

u32 MISC_SAVEDATA_GetRecordSize(void)
{
    return 0x16C;
}
