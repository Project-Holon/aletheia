/*
 * function: DWCi_MOV_WH_StateInMeasureChannel
 * address:  0x021D3340
 * packet:   pkt_ov016_021D39C0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   WM_GetAllowedChannel             0x0208EE60  arm
 *   DWCi_MOV_WH_SetError             0x021D2A44  arm
 *   DWCi_MOV_WH_ChangeSysState       0x021D29C8  arm
 *   WHi_MeasureChannel               0x021D34C0  arm
 *   DWCi_MOV_WH_StateOutMeasureChannel 0x021D33E0  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(dwc_mov_wh.o), symbol DWCi_MOV_WH_StateInMeasureChannel (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021D3340.c \n *       --func DWCi_MOV_WH_StateInMeasureChannel --addr 0x021D3340 --region ov016 --cc 1.1p1 --arm
 */
extern unsigned short WM_GetAllowedChannel(void);
extern void DWCi_MOV_WH_SetError(int code);
extern void DWCi_MOV_WH_ChangeSysState(int state);
extern int WHi_MeasureChannel(void (*func)(void *), unsigned short channel);
extern void DWCi_MOV_WH_StateOutMeasureChannel(void *arg);

static unsigned short DWCi_MOV_WH_StateInMeasureChannel(unsigned short channel)
{
    unsigned short allowedChannel;

    allowedChannel = WM_GetAllowedChannel();
    if (allowedChannel == 0x8000) {
        DWCi_MOV_WH_SetError(3);
        DWCi_MOV_WH_ChangeSysState(9);
        return 3;
    }
    if (allowedChannel == 0) {
        DWCi_MOV_WH_SetError(22);
        DWCi_MOV_WH_ChangeSysState(9);
        return 24;
    }
    while ((allowedChannel & (1 << (channel - 1))) == 0) {
        channel++;
        if (channel > 16)
            return 24;
    }
    return WHi_MeasureChannel(DWCi_MOV_WH_StateOutMeasureChannel, channel);
}
