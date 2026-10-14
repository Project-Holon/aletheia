/*
 * function: HALL_OF_FAME_SetVramBanks
 * address: 0x021B61D4
 * packet: pkt_ov180_021B61D4
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gHallOfFameVramBanksMain 0x021B8060 data a4
 *   gHallOfFameVramBanksSub 0x021B8090 data a4
 *   BG_SYS_ClearGraphicsMemory  0x0204335C  arm  arm9
 *   BG_SYS_SetVramBanks  0x020433E0  arm  arm9
 */
typedef unsigned int u32;
struct DispVram;
extern const struct DispVram gHallOfFameVramBanksMain;
extern const struct DispVram gHallOfFameVramBanksSub;
extern void BG_SYS_ClearGraphicsMemory(u32);
extern void BG_SYS_SetVramBanks(const struct DispVram *);
void HALL_OF_FAME_SetVramBanks(int flag)
{
    BG_SYS_ClearGraphicsMemory(0);
    if (flag == 0)
        BG_SYS_SetVramBanks(&gHallOfFameVramBanksMain);
    else
        BG_SYS_SetVramBanks(&gHallOfFameVramBanksSub);
}
