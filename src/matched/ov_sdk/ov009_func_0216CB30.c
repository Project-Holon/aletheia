/*
 * function: DWC_GetMatchIntValue
 * address:  0x0216CB30
 * packet:   pkt_ov009_0216CB30
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_GetMatchIntValue (libdwcmatch.TWL.HYB.a(dwc_match.o))
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   DWCi_IsError  0x02059F38  arm
 *   ServerBrowserGetServer  0x0219F058  arm  ov009
 *   SBServerGetIntValueA  0x0219E120  arm  ov009
 */

extern int func_02175F3C(void);
extern int DWCi_IsError(void);
extern int ServerBrowserGetServer(int a, int b);
struct SBServer;
extern int SBServerGetIntValueA(struct SBServer *server, char *key, int idefault);

int DWC_GetMatchIntValue(int a, int b, int c)
{
    int t;

    if (func_02175F3C() == 0 || DWCi_IsError() != 0) {
        return c;
    }
    t = ServerBrowserGetServer(*(int *)(func_02175F3C() + 0x5e0), a);
    if (t != 0) {
        c = SBServerGetIntValueA((struct SBServer *)t, (char *)b, c);
    }
    return c;
}
