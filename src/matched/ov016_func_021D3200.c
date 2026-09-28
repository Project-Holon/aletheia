/*
 * function: DWCi_MOV_WH_StateOutEnd
 * address:  0x021D3200
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
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(dwc_mov_wh.o), symbol DWCi_MOV_WH_StateOutEnd (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021D3200.c \n *       --func DWCi_MOV_WH_StateOutEnd --addr 0x021D3200 --region ov016 --cc 1.1p1 --arm
 */
extern void DWCi_MOV_WH_ChangeSysState(int state);

typedef struct { unsigned short apiid; unsigned short errcode; } WMCallback;

static void DWCi_MOV_WH_StateOutEnd(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;

    if (cb->errcode != 0) {
        DWCi_MOV_WH_ChangeSysState(10);
        return;
    }
    DWCi_MOV_WH_ChangeSysState(0);
}
