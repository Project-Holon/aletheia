/*
 * function: STARTMENU_SetupDisplayBanks
 * address:  0x021B9910
 * packet:   pkt_ov088_021B9910
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   d_021BD508     0x021BD508  data  a4  ov088
 *   d_021BD420     0x021BD420  data  a4  ov088
 */

struct DispConfig;
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern char d_021BD508[];
extern char d_021BD420[];

void STARTMENU_SetupDisplayBanks(void)
{
    BG_SYS_SetVramBanks((const struct DispVram *)d_021BD508);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021BD420);
}
