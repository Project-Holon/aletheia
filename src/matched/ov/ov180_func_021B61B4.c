/*
 * function: HALL_OF_FAME_VBlankTrainer
 * address: 0x021B61B4
 * packet: pkt_ov180_021B61B4
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SDK_AUTOLOAD_DTCM_START 0x02FE0000 data a4
 *   CLACT_VBlankSystem  0x0204A648  arm  arm9
 *   BG_SYS_Update  0x020419E4  arm  arm9
 * volatile: SDK IRQ check buffer read/write at 021B61C4/021B61C8.
 */
typedef unsigned int u32;
extern u32 SDK_AUTOLOAD_DTCM_START[];
extern void BG_SYS_Update(void);
extern void CLACT_VBlankSystem(void);
void HALL_OF_FAME_VBlankTrainer(void)
{
    BG_SYS_Update();
    CLACT_VBlankSystem();
    *(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3FF8) |= 1;
}
