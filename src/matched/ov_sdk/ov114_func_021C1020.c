/*
 * function: ghiGetServerAddressFromUrl
 * address:  0x021C1020
 * packet:   pkt_ov114_021C1020
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiGetServerAddressFromUrl (ghttpconnection)
 *
 * symbols:
 *   strncmp                 0x020949F4  arm
 *   strcspn                 0x02094A60  arm
 *   goastrdup               0x0217F1E0  arm
 *   g_021CE66C              0x021CE66C  data
 *   g_021CE660              0x021CE660  data
 *   g_021CE674              0x021CE674  data
 */

extern int strncmp(const char *s1, const char *s2, unsigned int n);
extern int strcspn(const char *s1, const char *s2);
extern char *goastrdup(char *src);
extern char g_021CE66C[];
extern char g_021CE660[];
extern char g_021CE674[];

char *ghiGetServerAddressFromUrl(char *serverUrl)
{
    int nIndex;
    char *url;
    char tempChar;
    char *serverAddress;

    if (strncmp(serverUrl, g_021CE66C, 7) == 0)
        url = serverUrl + 7;
    else if (strncmp(serverUrl, g_021CE660, 8) == 0)
        url = serverUrl + 8;
    else
        return 0;

    nIndex = strcspn(url, g_021CE674);
    tempChar = url[nIndex];
    url[nIndex] = 0;
    serverAddress = goastrdup(url);
    url[nIndex] = tempChar;
    return serverAddress;
}
