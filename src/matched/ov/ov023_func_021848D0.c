/*
 * function: OEKAKI_SetVramBanks
 * address:  0x021848D0
 * packet:   pkt_ov023_021848D0
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call: apply the VRAM bank descriptor at 0x02186ACC.
 *
 * symbols:
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   gOekakiVramBanks     0x02186ACC  data  ov023  a4
 */
struct DispVram;
extern const struct DispVram gOekakiVramBanks;
extern void BG_SYS_SetVramBanks(const struct DispVram *);

void OEKAKI_SetVramBanks(void)
{
    BG_SYS_SetVramBanks(&gOekakiVramBanks);
}
