/*
 * function: POKETRADE_SAVE_IsTouchOutsideArea
 * address: 0x021E2A80
 * packet: pkt_ov119_021E2A80
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   d_021E792C 0x021E792C data
 */
extern int TOUCHPANEL_HitTrg(const void *);
extern const char d_021E792C[];
int POKETRADE_SAVE_IsTouchOutsideArea(void *a0)
{
    if (TOUCHPANEL_HitTrg(d_021E792C) == 0) return 1;
    return 0;
}
