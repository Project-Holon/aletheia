/*
 * function: wsGetServiceUrl
 * address:  0x021E22E4
 * packet:   pkt_021E22E4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02084F80  0x02084F80  arm
 *   func_0217D254  0x0217D254  arm
 *   g_021ACEF8     0x021ACEF8  data
 *   g_021ACEFC     0x021ACEFC  data
 *   sWsAuthUrlFormat     0x021E49D0  data
 *   sWsNoAvailabilityMessage     0x021E4A18  data
 *   gWsAuthServiceUrl     0x021E53BC  data
 *
 * Session state probe: state 1 initialises the 0x021E53BC flag through
 * func_02084F80 and reports the flag; any other state asks func_0217D254 to
 * bring the 0x021E4A18 scene up (3/1).
 */

typedef unsigned int u32;
typedef signed int s32;
typedef signed char s8;

extern u32 g_021ACEF8;
extern u32 g_021ACEFC[];
extern u32 sWsAuthUrlFormat[];
extern u32 sWsNoAvailabilityMessage[];
extern s8 gWsAuthServiceUrl[];
extern int func_02084F80(char *dst, unsigned int len, const char *fmt, ...);
extern void func_0217D254(int, int, int, u32 *);

s32 wsGetServiceUrl(void)
{
    if (g_021ACEF8 == 1) {
        if (gWsAuthServiceUrl[0] == 0)
            func_02084F80((char *)gWsAuthServiceUrl, 0x80, (const char *)sWsAuthUrlFormat, g_021ACEFC);
        return (s32)gWsAuthServiceUrl;
    }
    func_0217D254(0, 3, 1, sWsNoAvailabilityMessage);
    return 0;
}
