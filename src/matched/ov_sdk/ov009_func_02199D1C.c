/*
 * function: ResolveServer
 * address:  0x02199D1C
 * packet:   pkt_ov009_02199D1C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ResolveServer (natify.o)
 *
 * symbols:
 *   OS_SNPrintf  0x02084F80  arm
 *   NameToIp  0x02199CE8  arm  ov009
 *   gNatNegHostnameFmt  0x021A5CA8  data
 *   gGsAvailabilityGameName  0x021ACEFC  data
 */

extern char gNatNegHostnameFmt[];
extern char gGsAvailabilityGameName[];
extern int OS_SNPrintf(char *dst, unsigned long len, const char *fmt, ...);
extern unsigned int NameToIp(char *name);

unsigned int ResolveServer(char *overrideHostname, char *defaultHostname)
{
    char hostnameBuffer[64];
    char *hostname;

    hostname = overrideHostname;
    if (!hostname) {
        hostname = hostnameBuffer;
        OS_SNPrintf(hostname, 64, gNatNegHostnameFmt, gGsAvailabilityGameName, defaultHostname);
    }
    return NameToIp(hostname);
}
