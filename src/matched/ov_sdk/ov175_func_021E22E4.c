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
 *   OS_SNPrintf  0x02084F80  arm
 *   gsDebugFormat  0x0217D254  arm
 *   g_021ACEF8     0x021ACEF8  data
 *   g_021ACEFC     0x021ACEFC  data
 *   sWsAuthUrlFormat     0x021E49D0  data
 *   sWsNoAvailabilityMessage     0x021E4A18  data
 *   gWsAuthServiceUrl     0x021E53BC  data
 *
 * Session state probe: state 1 initialises the 0x021E53BC flag through
 * OS_SNPrintf and reports the flag; any other state asks gsDebugFormat to
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
extern int OS_SNPrintf(char *dst, unsigned int len, const char *fmt, ...);
extern void gsDebugFormat(int, int, int, u32 *);

s32 wsGetServiceUrl(void)
{
    if (g_021ACEF8 == 1) {
        if (gWsAuthServiceUrl[0] == 0)
            OS_SNPrintf((char *)gWsAuthServiceUrl, 0x80, (const char *)sWsAuthUrlFormat, g_021ACEFC);
        return (s32)gWsAuthServiceUrl;
    }
    gsDebugFormat(0, 3, 1, sWsNoAvailabilityMessage);
    return 0;
}
