/*
 * function: DWC_GetNumConnectionHost
 * address:  0x0216B804
 * packet:   pkt_ov009_0216B804
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_GetNumConnectionHost (dwc_main.o)
 *
 * symbols:
 *   func_0216C82C  0x0216C82C  arm  ov009
 *   func_0217603C  0x0217603C  arm  ov009
 *   g_021AA878     0x021AA878  data
 */

extern char g_021AA878[];
extern int func_0216C82C(void);
extern int func_0217603C(void);

int DWC_GetNumConnectionHost(void)
{
    int num;

    if (*(char **)(g_021AA878 + 4) == 0 || func_0216C82C() == 0) {
        num = 0;
    } else {
        num = func_0217603C();
    }
    return num;
}
