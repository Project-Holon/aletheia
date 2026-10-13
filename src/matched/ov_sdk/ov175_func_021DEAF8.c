/*
 * function: sakeiSearchForRecordsFreeData
 * address:  0x021DEAF8
 * packet:   pkt_021DEAF8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sakeiFreeOutputRecords  0x021DE8AC  arm
 *   (none)
 *
 * If the +0x0c cursor is live, forwards its first two words as the
 *  *  second and third arguments and the +0x08 block's +0x08 word as the
 *  *  first to sakeiFreeOutputRecords (ov175).
 */

typedef unsigned long u32;

extern void sakeiFreeOutputRecords(u32 a, u32 b, u32 c);

void sakeiSearchForRecordsFreeData(char *obj)
{
    u32 *cur = *(u32 **)(obj + 0xc);
    char *blk = *(char **)(obj + 8);
    if (cur == 0)
        return;
    sakeiFreeOutputRecords(*(u32 *)(blk + 8), cur[0], cur[1]);
}

