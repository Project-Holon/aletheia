/*
 * function: startScan
 * address:  0x021D0CB8
 * packet:   pkt_ov016_021D0CB8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      startScan (libdwcutil.TWL.HYB.a usbap.o)
 *
 * symbols:
 *   WM_StartScanEx  0x0208F698  arm
 *   gUsbapWork     0x021DE654  data
 *   func_021D0DE0  0x021D0DE0  arm  ov016
 */

extern int WM_StartScanEx();
extern char *gUsbapWork;
extern void func_021D0DE0(void *arg);

int startScan(void)
{
    int rs = WM_StartScanEx(func_021D0DE0, gUsbapWork + 0x1374);
    return rs == 2;
}
