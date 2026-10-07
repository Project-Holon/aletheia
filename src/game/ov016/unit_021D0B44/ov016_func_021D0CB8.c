/*
 * function: func_021D0CB8
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
 *   func_0208F698  0x0208F698  arm
 *   g_021DE654     0x021DE654  data
 *   func_021D0DE0  0x021D0DE0  arm  ov016
 */

extern int func_0208F698();
extern char *g_021DE654;
extern void func_021D0DE0(void *arg);

int func_021D0CB8(void)
{
    int rs = func_0208F698(func_021D0DE0, g_021DE654 + 0x1374);
    return rs == 2;
}
