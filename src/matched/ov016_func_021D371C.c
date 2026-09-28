/*
 * function: DWCi_MOV_WH_StateOutInitialize
 * address:  0x021D371C
 * packet:   pkt_ov016_021D39C0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_MOV_WH_SetError             0x021D2A44  arm
 *   DWCi_MOV_WH_ChangeSysState       0x021D29C8  arm
 *   WM_SetIndCallback                0x0208EAC8  arm
 *   DWCi_MOV_WH_IndicateHandler      0x021D36B0  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(dwc_mov_wh.o), symbol DWCi_MOV_WH_StateOutInitialize (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021D371C.c \n *       --func DWCi_MOV_WH_StateOutInitialize --addr 0x021D371C --region ov016 --cc 1.1p1 --arm
 */
typedef struct { unsigned short apiid; unsigned short errcode; } WMCallback;

extern void DWCi_MOV_WH_SetError(int code);
extern void DWCi_MOV_WH_ChangeSysState(int state);
extern int WM_SetIndCallback(void (*callback)(void *));
extern void DWCi_MOV_WH_IndicateHandler(void *arg);

static void DWCi_MOV_WH_StateOutInitialize(void *arg)
{
    int result;
    WMCallback *cb = (WMCallback *)arg;

    if (cb->errcode != 0) {
        DWCi_MOV_WH_SetError(cb->errcode);
        DWCi_MOV_WH_ChangeSysState(10);
        return;
    }
    result = WM_SetIndCallback(DWCi_MOV_WH_IndicateHandler);
    if (result != 0) {
        DWCi_MOV_WH_SetError(result);
        DWCi_MOV_WH_ChangeSysState(10);
        return;
    }
    DWCi_MOV_WH_ChangeSysState(1);
}
