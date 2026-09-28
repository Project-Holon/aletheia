/*
 * function: DWCi_MOV_WH_StateOutReset
 * address:  0x021D31CC
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
 *   DWCi_MOV_WH_SetError             0x021D2A44  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(dwc_mov_wh.o), symbol DWCi_MOV_WH_StateOutReset (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021D31CC.c \n *       --func DWCi_MOV_WH_StateOutReset --addr 0x021D31CC --region ov016 --cc 1.1p1 --arm
 */
extern void DWCi_MOV_WH_ChangeSysState(int state);
extern void DWCi_MOV_WH_SetError(int code);

typedef struct { unsigned short apiid; unsigned short errcode; } WMCallback;

static void DWCi_MOV_WH_StateOutReset(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;

    if (cb->errcode != 0) {
        DWCi_MOV_WH_ChangeSysState(9);
        DWCi_MOV_WH_SetError(cb->errcode);
        return;
    }
    DWCi_MOV_WH_ChangeSysState(1);
}
