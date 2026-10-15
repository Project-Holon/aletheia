/*
 * function: POKETRADE_PROC_ExitDisplay
 * address: 0x021DC484
 * packet: pkt_ov119_021DC484
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 */
extern void CLACT_ExitSystem(void);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
void POKETRADE_PROC_ExitDisplay(void *a0)
{
    CLACT_ExitSystem();
    BMP_WIN_Exit();
    BG_SYS_Delete();
}
