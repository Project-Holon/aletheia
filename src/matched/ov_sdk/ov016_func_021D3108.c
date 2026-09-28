/*
 * function: DWCi_MOV_WH_StateOutEndChildMP
 * address:  0x021D3108
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
 *   DWCi_MOV_WH_Finalize             0x021D39C0  arm
 *   DWCi_MOV_WH_StateInEndChild      0x021D313C  arm
 *   DWCi_MOV_WH_ChangeSysState       0x021D29C8  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(dwc_mov_wh.o), symbol DWCi_MOV_WH_StateOutEndChildMP (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021D3108.c \n *       --func DWCi_MOV_WH_StateOutEndChildMP --addr 0x021D3108 --region ov016 --cc 1.1p1 --arm
 */
typedef struct { unsigned short apiid; unsigned short errcode; } WMCallback;

extern void DWCi_MOV_WH_SetError(int code);
extern void DWCi_MOV_WH_Finalize(void);
extern int DWCi_MOV_WH_StateInEndChild(void);
extern void DWCi_MOV_WH_ChangeSysState(int state);

static void DWCi_MOV_WH_StateOutEndChildMP(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;

    if (cb->errcode != 0) {
        DWCi_MOV_WH_SetError(cb->errcode);
        DWCi_MOV_WH_Finalize();
        return;
    }
    if (DWCi_MOV_WH_StateInEndChild())
        return;
    DWCi_MOV_WH_ChangeSysState(9);
}
