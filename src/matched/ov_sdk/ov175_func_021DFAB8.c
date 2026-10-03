/*
 * function: func_021DFAB8
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
 *   func_021E26BC  0x021E26BC  arm  ov175
 *   func_021E0774  0x021E0774  arm  ov175
 */

typedef unsigned int u32;

struct GSLoginCertificate;
extern int func_021E26BC(struct GSLoginCertificate *cert);
extern int func_021E0774(void *, u32, u32, u32, u32, u32, u32);

int func_021DFAB8(u32 *p, u32 a, u32 b, u32 c, u32 d, u32 e)
{
    if (func_021E26BC((void *)a) == 0)
        return 2;
    return func_021E0774(p, p[0x4c / 4], a, b, c, d, e);
}
