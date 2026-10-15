/*
 * function: sciGetServiceUrl
 * address:  0x021DF968
 * packet:   pkt_ov175_021DF968
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      sciGetServiceUrl (libdwcgssc.TWL.HYB.a(sciinterface.o))
 *
 * symbols:
 *   OS_SNPrintf  0x02084F80  arm
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   g_021ACEF8  0x021ACEF8  data
 *   g_021ACEFC  0x021ACEFC  data
 *   gScStatsServiceUrl  0x021E52B4  data
 *   sSciServiceUrlFormat  0x021E412C  data
 *   sSciNoAvailabilityMessage  0x021E4184  data
 */

extern int OS_SNPrintf(char *dst, unsigned int len, const char *fmt, ...);
extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
extern int g_021ACEF8;
extern char g_021ACEFC[];
extern char gScStatsServiceUrl[128];
extern char sSciServiceUrlFormat[];
extern char sSciNoAvailabilityMessage[];

char *sciGetServiceUrl(void)
{
    if (g_021ACEF8 == 1) {
        if (gScStatsServiceUrl[0] == 0)
            OS_SNPrintf(gScStatsServiceUrl, 128, sSciServiceUrlFormat, g_021ACEFC);
        return gScStatsServiceUrl;
    }
    gsDebugFormat(0, (char *)3, 1, sSciNoAvailabilityMessage);
    return 0;
}
