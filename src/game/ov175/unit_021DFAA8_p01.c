/*
 * file:     unit_021DFAA8_p01.c
 * unit:     yes
 * function: func_021DFAA8, func_021DFAB8
 * address:  0x021DFAA8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DF928  0x021DF928  arm
 *   func_021E26BC  0x021E26BC  arm  ov175
 *   func_021E0774  0x021E0774  arm  ov175
 */
struct GSLoginCertificate;
typedef unsigned int u32;

extern void func_021DF928(char *obj, int v);
extern int func_021E26BC(struct GSLoginCertificate *cert);
extern int func_021E0774(void *, u32, u32, u32, u32, u32, u32);
int func_021DFAA8(char *a, int b);
int func_021DFAB8(u32 *p, u32 a, u32 b, u32 c, u32 d, u32 e);


/*
 * Fire-and-forget wrapper: kick 0x021DF928 and report success.
 */
int func_021DFAA8(char *a, int b)
{
    func_021DF928(a, b);
    return 0;
}


/*
 * SDK provenance: scCreateMatchlessSession (TwlDWC/libdwcgssc.TWL.HYB.a,
 * scimain.o), ov175.  Validate the certificate, then hand the session request
 * to sciWsCreateMatchlessSession with the stored host list.
 */
int func_021DFAB8(u32 *p, u32 a, u32 b, u32 c, u32 d, u32 e)
{
    if (func_021E26BC((void *)a) == 0)
        return 2;
    return func_021E0774(p, p[0x4c / 4], a, b, c, d, e);
}
