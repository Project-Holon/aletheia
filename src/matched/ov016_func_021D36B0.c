/*
 * function: DWCi_MOV_WH_IndicateHandler
 * address:  0x021D36B0
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
 *   OS_Terminate                     0x02088234  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(dwc_mov_wh.o), symbol DWCi_MOV_WH_IndicateHandler (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021D36B0.c \n *       --func DWCi_MOV_WH_IndicateHandler --addr 0x021D36B0 --region ov016 --cc 1.1p1 --arm
 */
typedef struct { unsigned short apiid; unsigned short errcode; unsigned short state; } WMIndCallback;

extern void DWCi_MOV_WH_ChangeSysState(int state);
extern void OS_Terminate(void);

static void DWCi_MOV_WH_IndicateHandler(void *arg)
{
    WMIndCallback *cb = (WMIndCallback *)arg;

    if (cb->errcode == 8) {
        DWCi_MOV_WH_ChangeSysState(9);
        OS_Terminate();
    }
}
