/*
 * function: BTLV_CORE_ExitDisplay
 * address:  0x021E8F08
 * packet:   pkt_ov093_021E8F08
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F7808  0x021F7808  thumb  ov094
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   G3D_SYSTEM_Exit  0x02046788  arm
 */
extern void func_021F7808(void);
extern void CLACT_ExitSystem(void);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern void G3D_SYSTEM_Exit(void);

void BTLV_CORE_ExitDisplay(void)
{
    func_021F7808();
    CLACT_ExitSystem();
    BMP_WIN_Exit();
    func_0203F9B4();
    G3D_SYSTEM_Exit();
}
