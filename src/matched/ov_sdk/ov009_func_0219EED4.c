/*
 * function: ServerBrowserLimitUpdateA
 * address:  0x0219EED4
 * packet:   pkt_ov009_0219EED4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ServerBrowserLimitUpdateA (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 *
 * symbols:
 *   ServerBrowserBeginUpdate2  0x0219ED80  arm  ov009
 */

struct ServerBrowser;

extern int ServerBrowserBeginUpdate2(struct ServerBrowser *sb, int async, int disconnectOnComplete,
                         unsigned char *basicFields, int numBasicFields, char *serverFilter,
                         int updateOptions, int maxServers);

int ServerBrowserLimitUpdateA(struct ServerBrowser *sb, int async, int disconnectOnComplete,
                  unsigned char *basicFields, int numBasicFields, char *serverFilter, int maxServers)
{
    return ServerBrowserBeginUpdate2(sb, async, disconnectOnComplete, basicFields, numBasicFields,
                         serverFilter, 0x80, maxServers);
}
