/*
 * function: func_02156BA8
 * address: 0x02156BA8
 * packet: pkt_ov009_02156BA8
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: BL sites in ov099021BF6E0 target this Thumb word-run start;
 *   full body reads nullable global +0x780 as a signed halfword, else -1.
 * symbols:
 *   g_021A8264 0x021A8264 data ov009
 */
extern char *g_021A8264;
int func_02156BA8(void)
{
    char *p=g_021A8264;
    if(p)return *(short *)(p+0x780);
    return -1;
}
