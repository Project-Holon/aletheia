/*
 * function: PMS_WORD_GetSaveSize
 * address:  0x02024934
 * packet:   pkt_02024934
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Save-table size callback: returns 0xA8, the size of the block whose
 * init is PMS_WORD_InitSave.  Pointer word 0x02024935 at 0x0209DC00.
 */

typedef unsigned int u32;

u32 PMS_WORD_GetSaveSize(void)
{
    return 0xA8;
}
