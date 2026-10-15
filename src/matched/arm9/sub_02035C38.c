/*
 * function: TOUCHPANEL_GetCont
 * address:  0x02035C38
 * packet:   pkt_02035C38
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A two-call forwarder in the ARM SDK-style block at 0x02035000..0x02038000:
 * "push {r3, lr}; bl UI_GetContext; bl TOUCHPANEL_GetContSys; pop {r3, pc}", sixteen
 * bytes, no register setup between the calls: the first call's result is
 * still in r0 as the second call's argument, and the second call's result
 * is returned.
 *
 * Byte-correct.  UI_GetContext resolves on the `label` class (58 branches to
 * it image-wide, e.g. 0x02035460).  TOUCHPANEL_GetContSys does not: this call is its
 * only reference anywhere in the image, so that site stays wildcarded and
 * caps the file at MATCH.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/TOUCHPANEL_GetCont.c \
 *       --func TOUCHPANEL_GetCont --addr 0x02035C38 --cc 1.1p1 --arm
 *
 * symbols:
 *   TOUCHPANEL_GetContSys  0x02035C20  arm
 *   UI_GetContext  0x02035224  arm
 */

struct UiCtx;
extern struct UiCtx *UI_GetContext(void);
extern int TOUCHPANEL_GetContSys(const void *p);

int TOUCHPANEL_GetCont(void)
{
    return TOUCHPANEL_GetContSys(UI_GetContext());
}
