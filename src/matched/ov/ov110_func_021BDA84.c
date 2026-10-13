/*
 * function: PMS_INPUT_HitSingleWordButtons
 * address: 0x021BDA84
 * packet: pkt_ov110_021BDA84
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * input: caller's incoming pointer in r0 is ignored; stub replaces it with the table.
 * symbols:
 *   gPmsInputSingleWordButtonHits 0x021C3938 data ov110 a1
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 */
typedef unsigned char u8;
extern u8 gPmsInputSingleWordButtonHits[];
extern int TOUCHPANEL_HitTrg(const void *p);
int PMS_INPUT_HitSingleWordButtons(u8 *unused)
{
    return TOUCHPANEL_HitTrg(gPmsInputSingleWordButtonHits);
}
