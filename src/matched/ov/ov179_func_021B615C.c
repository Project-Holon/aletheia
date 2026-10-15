/*
 * function: CDEMO_MAIN_SetupVram
 * address:  0x021B615C
 * packet:   pkt_021B615C
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 */

struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);

void CDEMO_MAIN_SetupVram(void)
{
    BG_SYS_SetVramBanks((void *)0x021B68F0);
}
