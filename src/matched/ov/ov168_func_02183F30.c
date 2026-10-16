/*
 * function: MICTEST_SetupVramBanks
 * address:  0x02183F30
 * packet:   pkt_02183F30
 * region:   ov168
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

void MICTEST_SetupVramBanks(void)
{
    BG_SYS_SetVramBanks((void *)0x021848D4);
}
