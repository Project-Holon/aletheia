/*
 * function: MBi_calc_nextsendblock
 * address:  0x021F2ED4
 * packet:   pkt_ov107_021F2ED4
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_parent.o).  decl_line 1239.
 */
typedef unsigned short u16;

u16 MBi_calc_nextsendblock(unsigned long next_block, unsigned long next_block_req)
{
    if (next_block_req <= next_block)
        next_block_req = next_block;
    return next_block_req;
}
