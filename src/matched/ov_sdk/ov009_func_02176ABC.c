/*
 * function: DWCi_RegisterMatchmakeKeys
 * address:  0x02176ABC
 * packet:   pkt_ov009_02176ABC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_RegisterMatchmakeKeys (dwc_match.o)
 *
 * symbols:
 *   func_0219D158  0x0219D158  arm  ov009
 *   g_021A20A4     0x021A20A4  data
 *   g_021A2170     0x021A2170  data
 *   g_021A2164     0x021A2164  data
 *   g_021A21BC     0x021A21BC  data
 *   g_021A20D4     0x021A20D4  data
 *   g_021A20E0     0x021A20E0  data
 *   g_021A217C     0x021A217C  data
 */

extern char g_021A20A4[];
extern char g_021A2170[];
extern char g_021A2164[];
extern char g_021A21BC[];
extern char g_021A20D4[];
extern char g_021A20E0[];
extern char g_021A217C[];
extern void func_0219D158(int keyid, char *key);

void DWCi_RegisterMatchmakeKeys(void)
{
    func_0219D158(0x32, g_021A20A4);
    func_0219D158(0x33, g_021A2170);
    func_0219D158(0x34, g_021A2164);
    func_0219D158(0x35, g_021A21BC);
    func_0219D158(0x36, g_021A20D4);
    func_0219D158(0x37, g_021A20E0);
    func_0219D158(0x38, g_021A217C);
}
