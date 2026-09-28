/*
 * function: DWCi_MOV_WH_Reset
 * address:  0x021D39A4
 * packet:   pkt_ov016_021D39C0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_MOV_WH_StateInReset         0x021D319C  arm
 *   DWCi_MOV_WH_ChangeSysState       0x021D29C8  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(dwc_mov_wh.o), symbol DWCi_MOV_WH_Reset (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021D39A4.c \n *       --func DWCi_MOV_WH_Reset --addr 0x021D39A4 --region ov016 --cc 1.1p1 --arm
 */
extern int DWCi_MOV_WH_StateInReset(void);
extern void DWCi_MOV_WH_ChangeSysState(int state);

void DWCi_MOV_WH_Reset(void)
{
    if (DWCi_MOV_WH_StateInReset())
        return;
    DWCi_MOV_WH_ChangeSysState(10);
}
