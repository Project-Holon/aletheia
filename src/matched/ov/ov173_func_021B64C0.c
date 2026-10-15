/*
 * function: POKE_SUMMARY_MAIN_SetVramBanks
 * address:  0x021B64C0
 * packet:   pkt_021B64C0
 * region:   ov173
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

void POKE_SUMMARY_MAIN_SetVramBanks(void)
{
    BG_SYS_SetVramBanks((void *)0x021B8250);
}
