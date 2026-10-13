/*
 * function: MAP_MATRIX_PosToBlock
 * address: 0x02159D68
 * packet: pkt_ov010_02159D68
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding at 0x02159D82.
 */
int MAP_MATRIX_PosToBlock(int x)
{
    return x / 4096 / 16 / 32;
}
