/*
 * function: PDC_MAIN_ExitGraphics
 * address: 0x021B6438
 * packet: pkt_ov098_021B6438
 * region: ov098
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 */
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void CLACT_ExitSystem(void);
extern void G3D_SYSTEM_Exit(void);
void PDC_MAIN_ExitGraphics(void)
{
    BMP_WIN_Exit(); BG_SYS_Delete(); CLACT_ExitSystem(); G3D_SYSTEM_Exit();
}
