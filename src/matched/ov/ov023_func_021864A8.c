/*
 * function: OEKAKI_IsQuitTouched
 * address: 0x021864A8
 * packet: pkt_ov023_021864A8
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   gOekakiQuitHitTable 0x02186AAC data a4
 */
extern int TOUCHPANEL_HitTrg(const void *p);
extern char gOekakiQuitHitTable[];
int OEKAKI_IsQuitTouched(char *p)
{
    if (TOUCHPANEL_HitTrg(gOekakiQuitHitTable) != -1)
        return 1;
    return 0;
}
