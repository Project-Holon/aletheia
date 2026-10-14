/*
 * function: MB_SEQ_SetVramBanks
 * address:  0x021C5508
 * packet:   pkt_ov136_021C5508
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MB_SEQ_SetVramBanks 0x021C5508 thumb
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   d_021C78E0 0x021C78E0 data a1
 */
extern const char d_021C78E0[];
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
void MB_SEQ_SetVramBanks(void)
{
    BG_SYS_SetVramBanks((const struct DispVram *)d_021C78E0);
}
