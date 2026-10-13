/*
 * function: MYSTERY_DATA_GetWorkSize
 * address:  0x02009ED4
 * packet:   pkt_02009ED4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Save-table size callback: returns 0xA94, the size of the block whose
 * init is MYSTERY_DATA_Init.  Pointer word 0x02009ED5 at 0x0209DBC4 (the
 * save table's (size, init, id) row for id 0x22).
 */

typedef unsigned int u32;

u32 MYSTERY_DATA_GetWorkSize(void)
{
    return 0xA94;
}
