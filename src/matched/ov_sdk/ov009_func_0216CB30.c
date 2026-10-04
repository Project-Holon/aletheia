/*
 * function: func_0216CB30
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
 *   func_02059F38  0x02059F38  arm
 *   func_0219F058  0x0219F058  arm  ov009
 *   func_0219E120  0x0219E120  arm  ov009
 */

extern int func_02175F3C(void);
extern int func_02059F38(void);
extern int func_0219F058(int a, int b);
struct SBServer;
extern int func_0219E120(struct SBServer *server, char *key, int idefault);

int func_0216CB30(int a, int b, int c)
{
    int t;

    if (func_02175F3C() == 0 || func_02059F38() != 0) {
        return c;
    }
    t = func_0219F058(*(int *)(func_02175F3C() + 0x5e0), a);
    if (t != 0) {
        c = func_0219E120((struct SBServer *)t, (char *)b, c);
    }
    return c;
}
