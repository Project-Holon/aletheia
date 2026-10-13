/*
 * function: func_021DC484
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
 *   func_0203F9B4 0x0203F9B4 arm
 */
extern void CLACT_ExitSystem(void);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
void func_021DC484(void *a0)
{
    CLACT_ExitSystem();
    BMP_WIN_Exit();
    func_0203F9B4();
}
