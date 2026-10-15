/*
 * function: ghiParseURL
 * address:  0x021C3A38
 * packet:   pkt_ov114_021C3A38
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiParseURL (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 *
 * symbols:
 *   strncmp  0x020949F4  arm
 *   strcspn  0x02094A60  arm
 *   strchr  0x02094A28  arm
 *   atoi  0x020964E0  arm
 *   goastrdup  0x0217F1E0  arm   ov009
 *   sGhttpHttp2     0x021CEFDC  data
 *   sGhttpHttps3     0x021CEFE4  data
 *   sGhttpUrlServerTerminators     0x021CEFF0  data
 *   sGhttpRootPath     0x021CEFF4  data
 */

typedef struct GHIConnection {
    unsigned char pad0[0x14];
    char *url;
    char *server;
    unsigned char pad1[4];
    unsigned short port;
    unsigned char pad2[2];
    char *path;
    int ssl;
} GHIConnection;

extern int strncmp(const unsigned char *s1, const unsigned char *s2, unsigned int n);
typedef unsigned char  u8;
extern int strcspn(const u8 *s, const u8 *reject);
extern char *strchr(const char *, int);
typedef unsigned int   u32;
extern int atoi(u32 a0);
extern char *goastrdup(char *);
extern char sGhttpHttp2[];
extern char sGhttpHttps3[];
extern char sGhttpUrlServerTerminators[];
extern char sGhttpRootPath[];

typedef enum { GHI_FALSE, GHI_TRUE } GHIBool;

GHIBool ghiParseURL(GHIConnection *connection)
{
    char *URL;
    int nIndex;
    char tempChar;
    char *p;
    char *path;

    if (connection == 0)
        return GHI_FALSE;
    URL = connection->url;
    if (URL == 0)
        return GHI_FALSE;
    if (strncmp((const unsigned char *)URL, (const unsigned char *)sGhttpHttp2, 7) == 0) {
        connection->ssl = 0;
        URL += 7;
    } else if (strncmp((const unsigned char *)URL, (const unsigned char *)sGhttpHttps3, 8) == 0) {
        connection->ssl = 1;
        URL += 8;
    } else {
        return GHI_FALSE;
    }
    nIndex = strcspn((const u8 *)URL, (const u8 *)sGhttpUrlServerTerminators);
    tempChar = URL[nIndex];
    URL[nIndex] = 0;
    connection->server = goastrdup(URL);
    if (connection->server == 0)
        return GHI_FALSE;
    URL[nIndex] = tempChar;
    URL += nIndex;
    if (*URL == ':') {
        URL++;
        connection->port = (unsigned short)atoi((u32)URL);
        if (connection->port == 0)
            return GHI_FALSE;
        while (*++URL != 0 && *URL != '/')
            ;
    } else if (connection->ssl == 1) {
        connection->port = 443;
    } else {
        connection->port = 80;
    }
    if (*URL == 0)
        URL = sGhttpRootPath;
    path = goastrdup(URL);
    connection->path = path;
    while ((p = strchr(path, ' ')) != 0) {
        *p = '+';
        path = connection->path;
    }
    if (path == 0)
        return GHI_FALSE;
    return GHI_TRUE;
}
