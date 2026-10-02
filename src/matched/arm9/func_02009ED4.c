/*
 * function: func_02009ED4
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
 * init is func_02009EDC.  Pointer word 0x02009ED5 at 0x0209DBC4 (the
 * save table's (size, init, id) row for id 0x22).
 */

typedef unsigned int u32;

u32 func_02009ED4(void)
{
    return 0xA94;
}
