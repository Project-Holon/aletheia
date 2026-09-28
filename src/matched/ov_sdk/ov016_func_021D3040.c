/*
 * function: DWCi_MOV_WH_StateInEndParent
 * address:  0x021D3040
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
 *   WM_EndParent                     0x0208F654  arm
 *   DWCi_MOV_WH_SetError             0x021D2A44  arm
 *   DWCi_MOV_WH_StateOutEndParent    0x021D3068  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(dwc_mov_wh.o), symbol DWCi_MOV_WH_StateInEndParent (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021D3040.c \n *       --func DWCi_MOV_WH_StateInEndParent --addr 0x021D3040 --region ov016 --cc 1.1p1 --arm
 */
extern void DWCi_MOV_WH_ChangeSysState(int state);
extern int WM_EndParent(void (*callback)(void *));
extern void DWCi_MOV_WH_SetError(int code);
extern void DWCi_MOV_WH_StateOutEndParent(void *arg);

static int DWCi_MOV_WH_StateInEndParent(void)
{
    int result;

    result = WM_EndParent(DWCi_MOV_WH_StateOutEndParent);
    if (result == 2)
        return 1;
    DWCi_MOV_WH_SetError(result);
    return 0;
}
