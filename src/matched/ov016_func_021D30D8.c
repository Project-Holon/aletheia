/*
 * function: DWCi_MOV_WH_StateInEndChildMP
 * address:  0x021D30D8
 * packet:   pkt_ov016_021D39C0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_MOV_WH_ChangeSysState       0x021D29C8  arm
 *   WM_EndMP                         0x0208FDEC  arm
 *   DWCi_MOV_WH_SetError             0x021D2A44  arm
 *   DWCi_MOV_WH_StateOutEndChildMP   0x021D3108  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(dwc_mov_wh.o), symbol DWCi_MOV_WH_StateInEndChildMP (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021D30D8.c \n *       --func DWCi_MOV_WH_StateInEndChildMP --addr 0x021D30D8 --region ov016 --cc 1.1p1 --arm
 */
extern void DWCi_MOV_WH_ChangeSysState(int state);
extern int WM_EndMP(void (*callback)(void *));
extern void DWCi_MOV_WH_SetError(int code);
extern void DWCi_MOV_WH_StateOutEndChildMP(void *arg);

static int DWCi_MOV_WH_StateInEndChildMP(void)
{
    int result;

    DWCi_MOV_WH_ChangeSysState(3);
    result = WM_EndMP(DWCi_MOV_WH_StateOutEndChildMP);
    if (result == 2)
        return 1;
    DWCi_MOV_WH_SetError(result);
    return 0;
}
