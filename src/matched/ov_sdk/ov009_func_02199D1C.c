/*
 * function: func_02199D1C
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
 *   func_02084F80  0x02084F80  arm
 *   func_02199CE8  0x02199CE8  arm  ov009
 *   g_021A5CA8  0x021A5CA8  data
 *   gGsAvailabilityGameName  0x021ACEFC  data
 */

extern char g_021A5CA8[];
extern char gGsAvailabilityGameName[];
extern int func_02084F80(char *dst, unsigned long len, const char *fmt, ...);
extern unsigned int func_02199CE8(char *name);

unsigned int func_02199D1C(char *overrideHostname, char *defaultHostname)
{
    char hostnameBuffer[64];
    char *hostname;

    hostname = overrideHostname;
    if (!hostname) {
        hostname = hostnameBuffer;
        func_02084F80(hostname, 64, g_021A5CA8, gGsAvailabilityGameName, defaultHostname);
    }
    return func_02199CE8(hostname);
}
