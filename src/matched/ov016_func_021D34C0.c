/*
 * function: WHi_MeasureChannel
 * address:  0x021D34C0
 * packet:   pkt_ov016_021D39C0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   WM_MeasureChannel                0x02090E50  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(dwc_mov_wh.o), symbol WHi_MeasureChannel (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021D34C0.c \n *       --func WHi_MeasureChannel --addr 0x021D34C0 --region ov016 --cc 1.1p1 --arm
 */
extern int WM_MeasureChannel(void (*callback)(void *), unsigned short ccaMode, unsigned short edThreshold,
                             unsigned short channel, unsigned short measureTime);

static int WHi_MeasureChannel(void (*func)(void *), unsigned short channel)
{
    return WM_MeasureChannel(func, 3, 17, channel, 30);
}
