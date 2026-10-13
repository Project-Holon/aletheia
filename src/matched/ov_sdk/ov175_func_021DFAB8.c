/*
 * function: scCreateSession
 * address:  0x021DFAB8
 * packet:   pkt_ov175_021DFAB8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: scCreateMatchlessSession (TwlDWC/libdwcgssc.TWL.HYB.a,
 * scimain.o), ov175.  Validate the certificate, then hand the session request
 * to sciWsCreateMatchlessSession with the stored host list.
 *
 * symbols:
 *   wsLoginCertIsValid  0x021E26BC  arm  ov175
 *   sciWsCreateSession  0x021E0774  arm  ov175
 */

typedef unsigned int u32;

struct GSLoginCertificate;
extern int wsLoginCertIsValid(struct GSLoginCertificate *cert);
extern int sciWsCreateSession(void *, u32, u32, u32, u32, u32, u32);

int scCreateSession(u32 *p, u32 a, u32 b, u32 c, u32 d, u32 e)
{
    if (wsLoginCertIsValid((void *)a) == 0)
        return 2;
    return sciWsCreateSession(p, p[0x4c / 4], a, b, c, d, e);
}
