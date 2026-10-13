/*
 * function: PMS_INPUT_HitDoubleWordButtons
 * address: 0x021BDA94
 * packet: pkt_ov110_021BDA94
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * input: caller's incoming pointer in r0 is ignored; stub replaces it with the table.
 * symbols:
 *   gPmsInputDoubleWordButtonHits 0x021C3948 data ov110 a1
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 */
typedef unsigned char u8;
extern u8 gPmsInputDoubleWordButtonHits[];
extern int TOUCHPANEL_HitTrg(const void *p);
int PMS_INPUT_HitDoubleWordButtons(u8 *unused)
{
    return TOUCHPANEL_HitTrg(gPmsInputDoubleWordButtonHits);
}
